//FormAI DATASET v1.0 Category: System boot optimizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define maximum number of boot processes */
#define MAX_BOOT_PROCESSES 100

/* define maximum length of boot process names */
#define MAX_BOOT_PROCESS_NAME_LENGTH 50

/* define structure for a single boot process */
typedef struct {
    char name[MAX_BOOT_PROCESS_NAME_LENGTH];
    int priority;
} boot_process;

/* function to read input and create boot process structures */
int read_boot_processes(boot_process processes[]) {
    int num_processes;
    printf("Enter the number of boot processes: ");
    scanf("%d", &num_processes);
    for (int i = 0; i < num_processes; i++) {
        printf("Enter the name of boot process %d: ", i+1);
        scanf("%s", processes[i].name);
        printf("Enter the priority of boot process %d: ", i+1);
        scanf("%d", &processes[i].priority);
    }
    return num_processes;
}

/* function to sort boot processes by priority (in descending order) */
void sort_boot_processes(boot_process processes[], int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i+1; j < num_processes; j++) {
            if (processes[i].priority < processes[j].priority) {
                boot_process temp_process = processes[i];
                processes[i] = processes[j];
                processes[j] = temp_process;
            }
        }
    }
}

/* function to print sorted boot processes */
void print_boot_processes(boot_process processes[], int num_processes) {
    printf("The sorted boot processes are:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Boot process %d: %s - priority %d\n", i+1, processes[i].name, processes[i].priority);
    }
}

/* main function */
int main() {
    boot_process processes[MAX_BOOT_PROCESSES];
    int num_processes = read_boot_processes(processes);
    sort_boot_processes(processes, num_processes);
    print_boot_processes(processes, num_processes);
    return 0;
}