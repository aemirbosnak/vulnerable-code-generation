//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_LINE_SIZE 1024
#define MAX_PROCESSES 1000
#define MAX_PID_SIZE 10

typedef struct {
    int pid;
    char name[MAX_LINE_SIZE];
} Process;

void print_processes(Process processes[], int num_processes) {
    printf("PID\tName\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }
}

int read_processes(char *directory, Process processes[], int max_processes) {
    DIR *dir;
    struct dirent *ent;
    int num_processes = 0;

    if ((dir = opendir(directory))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                if (num_processes >= max_processes) {
                    break;
                }
                sprintf(processes[num_processes].name, "%s", ent->d_name);
                processes[num_processes].pid = -1;
                num_processes++;
            }
        }
        closedir(dir);
    }

    return num_processes;
}

void update_processes(Process processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid!= -1) {
            kill(processes[i].pid, 0);
        }
    }
}

int main() {
    char directory[MAX_LINE_SIZE];
    printf("Enter directory to monitor: ");
    scanf("%s", directory);

    Process processes[MAX_PROCESSES];
    int num_processes = read_processes(directory, processes, MAX_PROCESSES);

    while (1) {
        sleep(1);
        update_processes(processes, num_processes);

        int num_running_processes = 0;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].pid!= -1) {
                num_running_processes++;
            }
        }

        if (num_running_processes!= num_processes) {
            printf("\n");
            print_processes(processes, num_processes);
        }
    }

    return 0;
}