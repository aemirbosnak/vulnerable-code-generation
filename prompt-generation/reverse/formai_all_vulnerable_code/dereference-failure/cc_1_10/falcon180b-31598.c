//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 30
#define MAX_COMMAND_LINE 100

typedef struct {
    pid_t pid;
    char name[MAX_PROCESS_NAME];
    char command_line[MAX_COMMAND_LINE];
} process_t;

int get_processes(process_t *processes) {
    char path[MAX_PROCESS_NAME];
    sprintf(path, "/proc");
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }
    int count = 0;
    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            int len = strlen(ent->d_name);
            if (len > 1 && ent->d_name[len - 1] == '0' && ent->d_name[len - 2] >= '0' && ent->d_name[len - 2] <= '9') {
                sprintf(processes[count].name, "PID %s", ent->d_name);
                FILE *fp = fopen(sprintf("/proc/%s/cmdline", ent->d_name), "r");
                if (fp!= NULL) {
                    fgets(processes[count].command_line, MAX_COMMAND_LINE, fp);
                    fclose(fp);
                }
            }
        }
        count++;
        if (count >= MAX_PROCESSES) {
            break;
        }
    }
    closedir(dir);
    return count;
}

int main() {
    process_t processes[MAX_PROCESSES];
    int count = get_processes(processes);
    printf("Name\t\tCommand Line\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\n", processes[i].name, processes[i].command_line);
    }
    return 0;
}