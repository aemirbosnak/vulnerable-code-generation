//Falcon-180B DATASET v1.0 Category: System administration ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

struct process {
    int pid;
    int priority;
    char command[MAX];
};

void main() {
    int num_processes, i;
    struct process processes[10];

    printf("Enter the number of processes to be executed: ");
    scanf("%d", &num_processes);

    for(i=0; i<num_processes; i++) {
        printf("Enter the command for process %d: ", i+1);
        scanf("%s", processes[i].command);
        processes[i].pid = fork();

        if(processes[i].pid == 0) {
            execlp(processes[i].command, processes[i].command, NULL);
        }
        else if(processes[i].pid < 0) {
            printf("Error in creating process %d\n", i+1);
        }
        else {
            printf("Process %d created successfully\n", i+1);
        }
    }

    printf("Enter the priority of each process (0-9): ");
    for(i=0; i<num_processes; i++) {
        scanf("%d", &processes[i].priority);
    }

    for(i=0; i<num_processes; i++) {
        wait(NULL);
    }

    for(i=0; i<num_processes; i++) {
        if(processes[i].priority > 0) {
            printf("Process %d has been executed\n", i+1);
        }
        else {
            printf("Process %d has not been executed\n", i+1);
        }
    }
}