//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>

#define MAX_PROCESS 100
#define MAX_COMMAND_LENGTH 1024
#define DELIM " "

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void print_processes(process_t *processes, int num_processes) {
    printf("PID\tCOMMAND\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    int num_processes = 0;
    process_t *processes = (process_t *) malloc(MAX_PROCESS * sizeof(process_t));

    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                char path[50];
                sprintf(path, "/proc/%s/cmdline", ent->d_name);
                int fd = open(path, O_RDONLY);

                if (fd > 0) {
                    char command[MAX_COMMAND_LENGTH] = {0};
                    int bytes_read = read(fd, command, MAX_COMMAND_LENGTH);
                    close(fd);

                    if (bytes_read > 0) {
                        process_t *new_process = (process_t *) realloc(processes, (num_processes + 1) * sizeof(process_t));

                        if (new_process!= NULL) {
                            processes = new_process;
                            processes[num_processes].pid = atoi(ent->d_name);
                            strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH);
                            num_processes++;
                        }
                    }
                }
            }
        }

        closedir(dir);
        print_processes(processes, num_processes);
        free(processes);
    }

    return 0;
}