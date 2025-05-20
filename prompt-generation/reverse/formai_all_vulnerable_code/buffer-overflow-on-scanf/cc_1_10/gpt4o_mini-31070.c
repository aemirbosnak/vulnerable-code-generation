//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int priority;
    int required_time; // in seconds
} Process;

Process process_list[MAX_PROCESSES];
int process_count = 0;

void add_process(const char *name, int priority, int required_time) {
    if (process_count < MAX_PROCESSES) {
        strncpy(process_list[process_count].name, name, MAX_NAME_LENGTH);
        process_list[process_count].priority = priority;
        process_list[process_count].required_time = required_time;
        process_count++;
    } else {
        printf("Max process limit reached!\n");
    }
}

int compare_priority(const void *a, const void *b) {
    return ((Process *)b)->priority - ((Process *)a)->priority;
}

void optimize_processes() {
    qsort(process_list, process_count, sizeof(Process), compare_priority);
    printf("Processes sorted by priority:\n");
    for (int i = 0; i < process_count; i++) {
        printf("%d. %s (Priority: %d, Time: %d seconds)\n", 
                i + 1, process_list[i].name, process_list[i].priority, process_list[i].required_time);
    }
}

void execute_processes() {
    for (int i = 0; i < process_count; i++) {
        printf("Executing process: %s\n", process_list[i].name);
        sleep(process_list[i].required_time);
        printf("Completed process: %s\n", process_list[i].name);
    }
}

void display_menu() {
    printf("\n=== C System Boot Optimizer ===\n");
    printf("1. Add Process\n");
    printf("2. Optimize Processes\n");
    printf("3. Execute Processes\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int option;
    char name[MAX_NAME_LENGTH];
    int priority, required_time;

    while (1) {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter process name: ");
                scanf("%s", name);
                printf("Enter process priority (1-10): ");
                scanf("%d", &priority);
                printf("Enter required time in seconds: ");
                scanf("%d", &required_time);
                add_process(name, priority, required_time);
                break;
            case 2:
                optimize_processes();
                break;
            case 3:
                execute_processes();
                break;
            case 4:
                printf("Exiting the system optimizer.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}