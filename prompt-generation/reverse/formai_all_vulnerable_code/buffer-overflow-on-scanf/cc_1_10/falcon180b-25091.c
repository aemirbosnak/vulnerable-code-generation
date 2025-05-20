//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 100

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int ram_usage;
} Process;

void print_header() {
    printf("+------------------------+\n");
    printf("| Process Name            |\n");
    printf("| PID                     |\n");
    printf("| RAM Usage (Bytes)       |\n");
    printf("+------------------------+\n");
}

void print_process(Process process) {
    printf("| %-40s | %5d | %10d |\n", process.name, process.pid, process.ram_usage);
}

void print_footer() {
    printf("+------------------------+\n");
}

int main() {
    char command[100];
    FILE *file;
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    printf("Welcome to the Retro RAM Usage Monitor!\n");
    printf("Please enter the path to the process list file: ");
    scanf("%s", command);

    file = fopen(command, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fscanf(file, "%s %d %d", processes[num_processes].name, &processes[num_processes].pid, &processes[num_processes].ram_usage)!= EOF) {
        num_processes++;
        if (num_processes == MAX_PROCESSES) {
            break;
        }
    }

    fclose(file);

    print_header();

    for (int i = 0; i < num_processes; i++) {
        print_process(processes[i]);
    }

    print_footer();

    return 0;
}