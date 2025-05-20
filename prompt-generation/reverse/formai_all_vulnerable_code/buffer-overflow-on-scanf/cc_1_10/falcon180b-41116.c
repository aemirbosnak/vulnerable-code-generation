//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME 64

typedef struct {
    char name[MAX_PROCESS_NAME];
    int pid;
    int memory;
} Process;

void get_processes(Process *processes, int count) {
    char buffer[1024];
    FILE *fp;
    char *token;
    int i = 0;

    fp = popen("ps -eo 'pid,comm'", "r");
    if (fp == NULL) {
        printf("Error executing ps.\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        token = strtok(buffer, " ");
        processes[i].pid = atoi(token);
        token = strtok(NULL, " ");
        strncpy(processes[i].name, token, MAX_PROCESS_NAME);
        processes[i].name[MAX_PROCESS_NAME - 1] = '\0';
        processes[i].memory = 0;
        i++;

        if (i >= count) {
            break;
        }
    }

    pclose(fp);
}

int compare_processes(const void *a, const void *b) {
    const Process *p1 = a;
    const Process *p2 = b;

    return strcmp(p1->name, p2->name);
}

void print_processes(Process *processes, int count) {
    qsort(processes, count, sizeof(Process), compare_processes);

    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %8d KB\n", processes[i].pid, processes[i].name, processes[i].memory / 1024);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int count;

    printf("Enter the number of processes to monitor (up to %d): ", MAX_PROCESSES);
    scanf("%d", &count);

    get_processes(processes, count);
    print_processes(processes, count);

    return 0;
}