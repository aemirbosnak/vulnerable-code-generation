//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

typedef struct {
    int pid;
    char command[MAX_LINE];
    int state;
} process_t;

void print_processes(process_t *processes, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d - %s - %d\n", processes[i].pid, processes[i].command, processes[i].state);
    }
}

void update_processes(process_t *processes, int count) {
    for (int i = 0; i < count; i++) {
        char status_file[20];
        sprintf(status_file, "/proc/%d/status", processes[i].pid);
        FILE *status = fopen(status_file, "r");

        if (status == NULL) {
            processes[i].state = -1;
        } else {
            char line[MAX_LINE];
            while (fgets(line, MAX_LINE, status)!= NULL) {
                if (strncmp(line, "State:", 6) == 0) {
                    sscanf(line, "State: %d", &processes[i].state);
                    break;
                }
            }
            fclose(status);
        }
    }
}

int main() {
    process_t *processes = malloc(sizeof(process_t) * 100);
    int count = 0;

    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            int pid = atoi(ent->d_name);

            if (count >= 100) {
                printf("Maximum number of processes reached. ");
                break;
            }

            char command_file[20];
            sprintf(command_file, "/proc/%d/cmdline", pid);
            FILE *command = fopen(command_file, "r");

            if (command == NULL) {
                continue;
            }

            char line[MAX_LINE];
            fgets(line, MAX_LINE, command);
            strtok(line, "\0");

            strncpy(processes[count].command, line, MAX_LINE);
            processes[count].command[strcspn(processes[count].command, "\n")] = '\0';
            processes[count].pid = pid;

            fclose(command);
            count++;
        }

        closedir(dir);
    }

    while (1) {
        update_processes(processes, count);
        print_processes(processes, count);
        sleep(1);
    }

    free(processes);
    return 0;
}