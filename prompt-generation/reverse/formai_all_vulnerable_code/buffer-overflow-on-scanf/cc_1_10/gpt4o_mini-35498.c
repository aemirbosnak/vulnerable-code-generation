//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_OPTIONS 5

typedef struct {
    char name[30];
    int value;
} BootOption;

void displayBootOptions(BootOption options[], int count) {
    printf("\nCurrent Boot Options:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s = %d\n", i + 1, options[i].name, options[i].value);
    }
}

void modifyBootOption(BootOption *option) {
    int newValue;

    printf("Enter new value for %s (current: %d): ", option->name, option->value);
    while (true) {
        if (scanf("%d", &newValue) != 1) {
            printf("Invalid input. Please enter an integer: ");
            while (getchar() != '\n'); // Clear invalid input
        } else {
            option->value = newValue;
            printf("%s updated to %d\n", option->name, option->value);
            break;
        }
    }
    while (getchar() != '\n'); // Clear the buffer
}

void runBootProcess(BootOption options[], int count) {
    printf("\nBooting the system with the following parameters:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", options[i].name, options[i].value);
    }
    printf("Boot process completed successfully!\n");
}

void displayMenu() {
    printf("\n=== Boot Optimizer ===\n");
    printf("1. Display Boot Options\n");
    printf("2. Modify a Boot Option\n");
    printf("3. Run Boot Process\n");
    printf("4. Exit\n");
    printf("=======================\n");
    printf("Choose an option: ");
}

int main() {
    BootOption bootOptions[MAX_OPTIONS] = {
        {"CPU Frequency", 3000},       // in MHz
        {"RAM Allocation", 4096},      // in MB
        {"Disk Speed", 7200},          // in RPM
        {"Boot Timeout", 30},          // in Seconds
        {"Network Initialization", 1}   // Enabled (1) or Disabled (0)
    };

    int choice;
    bool running = true;

    while (running) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }
        
        switch (choice) {
            case 1:
                displayBootOptions(bootOptions, MAX_OPTIONS);
                break;
            case 2:
                printf("Enter the number of the option to modify (1-%d): ", MAX_OPTIONS);
                int optionNumber;
                if (scanf("%d", &optionNumber) != 1 || optionNumber < 1 || optionNumber > MAX_OPTIONS) {
                    printf("Invalid option number.\n");
                    break;
                }
                modifyBootOption(&bootOptions[optionNumber - 1]);
                break;
            case 3:
                runBootProcess(bootOptions, MAX_OPTIONS);
                break;
            case 4:
                running = false;
                printf("Exiting Boot Optimizer...\n");
                break;
            default:
                printf("Invalid choice. Please select an option between 1 and 4.\n");
                break;
        }
        while (getchar() != '\n'); // Clear the input buffer
    }

    return 0;
}