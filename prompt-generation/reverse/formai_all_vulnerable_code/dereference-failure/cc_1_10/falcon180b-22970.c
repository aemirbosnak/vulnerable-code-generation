//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PROCESSES 1024

struct process {
    char name[64];
    pid_t pid;
    int status;
};

void print_processes(struct process *processes, int count) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    DIR *dir;
    struct dirent *ent;
    char path[64];
    sprintf(path, "/proc");
    dir = opendir(path);

    if (dir == NULL) {
        printf("Error: could not open /proc directory.\n");
        return 1;
    }

    struct process processes[MAX_PROCESSES];
    int count = 0;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            sprintf(path, "/proc/%s", ent->d_name);
            int fd = open(path, O_RDONLY);
            if (fd!= -1) {
                char buffer[64];
                if (read(fd, buffer, sizeof(buffer)) > 0) {
                    close(fd);
                    processes[count].pid = atoi(ent->d_name);
                    strcpy(processes[count].name, buffer);
                    processes[count].status = 1;
                    count++;
                }
            }
        }
    }

    closedir(dir);

    print_processes(processes, count);

    return 0;
}