//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <limits.h>

#define MAX_PROCESSES 1024
#define MAX_PATH 1024

typedef struct {
    pid_t pid;
    char path[MAX_PATH];
} Process;

int main() {
    DIR *dir;
    struct dirent *ent;
    int num_processes = 0;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (isdigit(ent->d_name[0])) {
                num_processes++;
            }
        }
        closedir(dir);
    } else {
        perror("");
        exit(1);
    }

    Process processes[MAX_PROCESSES];
    num_processes = 0;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (isdigit(ent->d_name[0])) {
                if (num_processes >= MAX_PROCESSES) {
                    break;
                }

                snprintf(processes[num_processes].path, MAX_PATH, "/proc/%s", ent->d_name);
                processes[num_processes].pid = atoi(ent->d_name);
                num_processes++;
            }
        }
        closedir(dir);
    } else {
        perror("");
        exit(1);
    }

    for (int i = 0; i < num_processes; i++) {
        printf("PID: %d\n", processes[i].pid);
        printf("Path: %s\n\n", processes[i].path);
    }

    return 0;
}