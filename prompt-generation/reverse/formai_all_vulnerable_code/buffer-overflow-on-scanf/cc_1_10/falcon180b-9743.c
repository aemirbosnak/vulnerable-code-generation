//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PROCESSES 1000

typedef struct process {
    int pid;
    char name[64];
    int status;
} process_t;

int main(int argc, char *argv[]) {
    int num_processes = 0, i;
    process_t *processes = malloc(MAX_PROCESSES * sizeof(process_t));

    if (processes == NULL) {
        printf("Error: Could not allocate memory for processes.\n");
        exit(1);
    }

    printf("Enter the number of processes to monitor (up to %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        printf("Enter process %d name: ", i + 1);
        scanf("%s", processes[i].name);
        processes[i].pid = fork();

        if (processes[i].pid < 0) {
            printf("Error: Could not fork process %d.\n", i + 1);
            exit(1);
        } else if (processes[i].pid == 0) {
            // Child process
            execlp(processes[i].name, processes[i].name, NULL);
            exit(1);
        } else {
            // Parent process
            waitpid(processes[i].pid, &processes[i].status, 0);
        }
    }

    printf("Process ID   Process Name    Status\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d           %s          %d\n", processes[i].pid, processes[i].name, processes[i].status);
    }

    free(processes);
    return 0;
}