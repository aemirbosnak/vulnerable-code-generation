//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 20

typedef struct process_info {
    char name[MAX_PROCESS_NAME];
    int pid;
    int ram_usage;
} ProcessInfo;

void get_process_info(ProcessInfo* proc_info, int num_processes) {
    FILE* fp;
    char line[1024];
    char* token;

    fp = popen("ps -eo pid,comm,rss --sort=-rss", "r");

    if (fp == NULL) {
        printf("Error: Failed to run ps command.\n");
        exit(1);
    }

    int i = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= num_processes) {
            break;
        }

        token = strtok(line, " ");
        proc_info[i].pid = atoi(token);

        token = strtok(NULL, " ");
        strncpy(proc_info[i].name, token, MAX_PROCESS_NAME);

        token = strtok(NULL, " ");
        proc_info[i].ram_usage = atoi(token);

        i++;
    }

    pclose(fp);
}

void sort_processes(ProcessInfo* proc_info, int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (proc_info[j].ram_usage > proc_info[i].ram_usage) {
                ProcessInfo temp = proc_info[i];
                proc_info[i] = proc_info[j];
                proc_info[j] = temp;
            }
        }
    }
}

int main() {
    int num_processes = 0;
    ProcessInfo proc_info[MAX_PROCESSES];

    printf("Enter the number of processes to monitor (max %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    get_process_info(proc_info, num_processes);

    printf("\nProcess ID\tProcess Name\tRAM Usage (KB)\n");

    sort_processes(proc_info, num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t\t%d KB\n", proc_info[i].pid, proc_info[i].name, proc_info[i].ram_usage);
    }

    return 0;
}