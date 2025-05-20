//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 50

typedef struct {
    int pid;
    char name[20];
    int status;
} process;

void print_processes(process *processes, int num_processes) {
    printf("\nProcess ID\tName\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    process processes[MAX_PROCESSES];
    int num_processes = 0;

    printf("Enter the number of processes to monitor: ");
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", processes[i].name);
        processes[i].pid = fork();

        if (processes[i].pid == -1) {
            printf("Error forking process %s\n", processes[i].name);
            exit(1);
        } else if (processes[i].pid == 0) {
            // Child process
            execlp(processes[i].name, processes[i].name, NULL);
            exit(1);
        } else {
            // Parent process
            waitpid(processes[i].pid, &processes[i].status, WUNTRACED);
        }
    }

    print_processes(processes, num_processes);

    return 0;
}