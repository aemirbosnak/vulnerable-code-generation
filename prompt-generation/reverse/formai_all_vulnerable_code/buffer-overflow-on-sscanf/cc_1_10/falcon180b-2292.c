//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LEN 16

struct process {
    int pid;
    char name[MAX_PROCESS_NAME_LEN];
    float cpu_usage;
};

void get_process_info(struct process *processes, int num_processes) {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/stat.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= num_processes) {
            break;
        }

        token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }

        sscanf(token, "%d", &processes[i].pid);
        processes[i].cpu_usage = 0.0;

        token = strtok(NULL, " ");
        while (token!= NULL) {
            if (strcmp(token, "cpu") == 0) {
                sscanf(token, "%f", &processes[i].cpu_usage);
                break;
            }
            token = strtok(NULL, " ");
        }

        i++;
    }

    fclose(fp);
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;
    char input[1024];
    int i;

    printf("Enter number of processes to monitor (up to %d):\n", MAX_PROCESSES);
    scanf("%d", &num_processes);

    printf("Enter process IDs to monitor:\n");
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        sscanf(input, "%d", &processes[num_processes].pid);
        num_processes++;
    }

    get_process_info(processes, num_processes);

    printf("PID\tName\tCPU Usage\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%.2f%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage);
    }

    return 0;
}