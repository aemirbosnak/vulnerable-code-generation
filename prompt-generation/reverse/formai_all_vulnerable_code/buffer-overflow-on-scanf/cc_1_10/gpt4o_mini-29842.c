//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESSES 10
#define CONFIG_FILE "boot_config.txt"

typedef struct {
    char name[50];
    int priority;
    int execution_time;
} Process;

Process process_list[MAX_PROCESSES];
int process_count = 0;

void load_processes() {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) {
        perror("Error opening config file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d %d", process_list[process_count].name,
                  &process_list[process_count].priority,
                  &process_list[process_count].execution_time) != EOF) {
        process_count++;
        if (process_count >= MAX_PROCESSES) break;
    }
    fclose(file);
}

int compare_priority(const void *a, const void *b) {
    return ((Process *)b)->priority - ((Process *)a)->priority;
}

void optimize_boot_process() {
    qsort(process_list, process_count, sizeof(Process), compare_priority);
    printf("Processes sorted by priority:\n");
    for (int i = 0; i < process_count; i++) {
        printf("Process: %s, Priority: %d, Execution time: %d\n",
               process_list[i].name, process_list[i].priority,
               process_list[i].execution_time);
    }
}

void simulate_boot() {
    printf("\nStarting boot optimization...\n");
    sleep(1);
    for (int i = 0; i < process_count; i++) {
        printf("Executing %s for %d seconds...\n",
               process_list[i].name, process_list[i].execution_time);
        sleep(process_list[i].execution_time);
        printf("%s completed!\n", process_list[i].name);
    }
    printf("\nAll processes executed. Boot optimization complete!\n");
}

void display_menu() {
    printf("\nBoot Optimizer Menu:\n");
    printf("1. Load Processes\n");
    printf("2. Optimize Boot\n");
    printf("3. Simulate Boot\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                load_processes();
                break;
            case 2:
                optimize_boot_process();
                break;
            case 3:
                simulate_boot();
                break;
            case 4:
                printf("Exiting Boot Optimizer. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}