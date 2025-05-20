//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int priority;
    int enabled; // 1 for enabled, 0 for disabled
} Process;

Process processes[MAX_PROCESSES];
int process_count = 0;

void load_processes() {
    // In a real scenario, this would load processes from the system
    strcpy(processes[0].name, "systemd");
    processes[0].priority = 1;
    processes[0].enabled = 1;

    strcpy(processes[1].name, "cron");
    processes[1].priority = 2;
    processes[1].enabled = 1;

    strcpy(processes[2].name, "network-manager");
    processes[2].priority = 1;
    processes[2].enabled = 1;

    strcpy(processes[3].name, "cups");
    processes[3].priority = 3;
    processes[3].enabled = 1;

    strcpy(processes[4].name, "bluetooth");
    processes[4].priority = 2;
    processes[4].enabled = 1;

    process_count = 5; // Total processes loaded
}

void display_processes() {
    printf("\nCurrent Startup Processes:\n");
    printf("%-20s %-10s %-10s\n", "Process", "Priority", "Enabled");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < process_count; i++) {
        printf("%-20s %-10d %-10s\n", processes[i].name, processes[i].priority, processes[i].enabled ? "Yes" : "No");
    }
}

void toggle_process(int index) {
    if (index >= 0 && index < process_count) {
        processes[index].enabled = !processes[index].enabled;
        printf("Toggled %s to %s.\n", processes[index].name, processes[index].enabled ? "Enabled" : "Disabled");
    } else {
        printf("Invalid process index!\n");
    }
}

void optimize_boot() {
    printf("\nOptimizing bootup processes...\n");
    // In a real scenario, this function would implement optimizations
    for (int i = 0; i < process_count; i++) {
        if (!processes[i].enabled) {
            printf("Disabling %s for faster boot.\n", processes[i].name);
        }
    }
}

int main() {
    load_processes();
    int choice;

    while (1) {
        display_processes();
        printf("\nOptions:\n");
        printf("1. Toggle Process\n");
        printf("2. Optimize Boot\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int process_index;
            printf("Enter process index to toggle (0 to %d): ", process_count - 1);
            scanf("%d", &process_index);
            toggle_process(process_index);
        } else if (choice == 2) {
            optimize_boot();
        } else if (choice == 3) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}