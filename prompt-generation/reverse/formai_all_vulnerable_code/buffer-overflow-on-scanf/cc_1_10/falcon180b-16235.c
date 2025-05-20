//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits.h>

#define MAX_PROCESSES 1024

typedef struct {
    pid_t pid;
    char name[16];
    int status;
} process_t;

void print_processes(process_t *processes, int num_processes) {
    printf("Process ID\tName\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    int num_processes = 0;
    process_t processes[MAX_PROCESSES];

    while (1) {
        printf("\nRAM Usage Monitor\n");
        printf("=================\n");
        printf("1. Display current processes\n");
        printf("2. Display RAM usage\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &num_processes);

        switch (num_processes) {
            case 1:
                printf("\nCurrent Processes:\n");
                system("ps -ef");
                break;
            case 2:
                printf("\nRAM Usage:\n");
                system("free -h");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}