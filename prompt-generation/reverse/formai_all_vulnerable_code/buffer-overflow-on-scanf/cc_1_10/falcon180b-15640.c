//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 50
#define MAX_PRIORITY 10

typedef struct {
    char name[MAX_PROCESS_NAME];
    int priority;
    int num_requests;
} Process;

int main() {
    int num_processes, i, j, highest_priority = 0, current_priority;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the name, priority and number of requests for each process:\n");
    for (i = 0; i < num_processes; i++) {
        scanf("%s %d %d", processes[i].name, &processes[i].priority, &processes[i].num_requests);
        if (processes[i].priority > highest_priority) {
            highest_priority = processes[i].priority;
        }
    }

    printf("Process ID\tProcess Name\tPriority\tNumber of Requests\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\t%d\n", i, processes[i].name, processes[i].priority, processes[i].num_requests);
    }

    printf("\nProcess ID\tPriority\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\n", i, processes[i].priority);
    }

    printf("\nEnter the number of time slices: ");
    scanf("%d", &current_priority);

    printf("\nProcess ID\tProcess Name\tPriority\tNumber of Requests\tNumber of Time Slices\n");
    for (i = 0; i < num_processes; i++) {
        for (j = 0; j < processes[i].num_requests; j++) {
            printf("%d\t%s\t%d\t%d\t%d\n", i, processes[i].name, processes[i].priority, processes[i].num_requests, current_priority);
            current_priority--;
        }
    }

    return 0;
}