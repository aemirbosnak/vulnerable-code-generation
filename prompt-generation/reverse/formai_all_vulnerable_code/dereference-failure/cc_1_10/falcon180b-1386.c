//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>
#include <errno.h>

#define MAX_LINE 1024
#define MAX_PROCESS 1000

typedef struct {
    char name[MAX_LINE];
    int pid;
    int status;
} process_t;

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ;
}

void print_processes(process_t processes[], int num_processes) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

void kill_process(int pid) {
    kill(pid, SIGKILL);
}

int main() {
    signal(SIGCHLD, sigchld_handler);
    process_t processes[MAX_PROCESS];
    int num_processes = 0;

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                char path[MAX_LINE];
                snprintf(path, MAX_LINE, "/proc/%s", ent->d_name);
                if (access(path, F_OK) == 0) {
                    FILE *file;
                    if ((file = fopen(path, "r"))!= NULL) {
                        char line[MAX_LINE];
                        if (fgets(line, MAX_LINE, file)!= NULL) {
                            sscanf(line, "%d", &processes[num_processes].pid);
                            fclose(file);
                        } else {
                            perror("fgets");
                        }
                    } else {
                        perror("fopen");
                    }
                }
            }
        }
        closedir(dir);
    } else {
        perror("opendir");
    }

    while (1) {
        print_processes(processes, num_processes);
        sleep(1);
    }

    return 0;
}