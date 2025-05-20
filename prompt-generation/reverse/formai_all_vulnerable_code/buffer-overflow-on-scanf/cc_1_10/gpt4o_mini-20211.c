//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Declare the maximum number of boot options
#define MAX_BOOT_OPTIONS 5
#define MAX_OPTION_LENGTH 50

typedef struct BootOption {
    char name[MAX_OPTION_LENGTH];
    int priority;
} BootOption;

void init_boot_options(BootOption options[], int count) {
    for (int i = 0; i < count; i++) {
        snprintf(options[i].name, MAX_OPTION_LENGTH, "Boot Option %d", i + 1);
        options[i].priority = rand() % 100; // Random priority between 0 and 99
    }
}

void display_options(BootOption options[], int count) {
    printf("\nAvailable Boot Options:\n");
    for (int i = 0; i < count; i++) {
        printf(" %d: %s - Priority: %d\n", i + 1, options[i].name, options[i].priority);
    }
}

int compare_priority(const void *a, const void *b) {
    BootOption *optionA = (BootOption *)a;
    BootOption *optionB = (BootOption *)b;
    return optionB->priority - optionA->priority; // Sort in descending order
}

void optimize_boot_options(BootOption options[], int count) {
    qsort(options, count, sizeof(BootOption), compare_priority);
    printf("\nOptimized Boot Options (as per priority):\n");
    display_options(options, count);
}

void simulate_boot(BootOption options[], int count) {
    printf("\nSimulating the Boot Process...\n");
    for (int i = 0; i < count; i++) {
        printf("Booting: %s...\n", options[i].name);
        sleep(1); // simulate time taken for booting
        if (i == count - 1) {
            printf("All options have been attempted. System is up!\n");
        }
    }
}

void show_menu() {
    printf("\n~*~ Welcome to the Shocked Boot Optimizer ~*~\n");
    printf("1. Display Boot Options\n");
    printf("2. Optimize Boot Options\n");
    printf("3. Simulate Boot Process\n");
    printf("4. Exit\n");
}

int main() {
    srand(time(NULL)); // Seed random number generator
    BootOption bootOptions[MAX_BOOT_OPTIONS];
    init_boot_options(bootOptions, MAX_BOOT_OPTIONS);

    int choice;
    while(1) {
        show_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                display_options(bootOptions, MAX_BOOT_OPTIONS);
                break;
            case 2:
                optimize_boot_options(bootOptions, MAX_BOOT_OPTIONS);
                break;
            case 3:
                simulate_boot(bootOptions, MAX_BOOT_OPTIONS);
                break;
            case 4:
                printf("Exiting the Shocked Boot Optimizer. Goodbye!\n");
                exit(0);
            default:
                printf("ERROR: Invalid choice. Please select from the menu.\n");
                break;
        }
    }
    return 0;
}