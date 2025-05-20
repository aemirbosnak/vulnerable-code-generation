//FormAI DATASET v1.0 Category: System process viewer ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
// defining the maximum number of processes
#define MAX_PROCESSES 100
 
int main(void) {
    printf("====================================\n");
    printf("Welcome to the medieval process viewer\n");
    printf("====================================\n\n");

    int num_processes = 0;
    printf("Enter the number of processes: ");
    scanf("%i", &num_processes);

    if (num_processes > MAX_PROCESSES) {
        printf("Sorry, cannot handle that many processes.\n");
        return 1;
    }

    printf("\n====================================\n");
    printf("Here are the processes in your kingdom\n");
    printf("====================================\n\n");

    printf("+---------+-----------------+------------------------+\n");
    printf("|  PID    |    NAME         |         STATUS         |\n");
    printf("+---------+-----------------+------------------------+\n");

    // Generating our own data in a loop for the processes
    for (int i = 1; i <= num_processes; i++) {
        int pid = rand() % 1000 + 1;
        char* process_name;
        int status = rand() % 4 + 1;

        switch (status) {
            case 1:
                process_name = "Idle";
                break;
            case 2:
                process_name = "Running";
                break;
            case 3:
                process_name = "Sleeping";
                break;
            case 4:
                process_name = "Zombie";
                break;
        }

        printf("| %-7i | %-15s | %-22s|\n", pid, process_name, "");

    }
    printf("+---------+-----------------+------------------------+\n\n");
    return 0;
}