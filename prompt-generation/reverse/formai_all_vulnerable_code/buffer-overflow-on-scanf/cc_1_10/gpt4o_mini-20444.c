//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPTIONS 10
#define MAX_NAME_LENGTH 50

typedef struct BootOption {
    char name[MAX_NAME_LENGTH];
    int enabled;
} BootOption;

void initializeBootOptions(BootOption *options, int size) {
    for (int i = 0; i < size; i++) {
        snprintf(options[i].name, MAX_NAME_LENGTH, "Option %d", i + 1);
        options[i].enabled = 1; // All options enabled by default
    }
}

void displayBootOptions(BootOption *options, int size) {
    printf("Current Boot Options:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s [%s]\n", i + 1, options[i].name, options[i].enabled ? "Enabled" : "Disabled");
    }
}

void toggleBootOption(BootOption *options, int index) {
    if (index >= 0) {
        options[index].enabled = !options[index].enabled;
        printf("%s is now %s.\n", options[index].name, options[index].enabled ? "Enabled" : "Disabled");
    } else {
        printf("Invalid option.\n");
    }
}

void optimizeBootSequence(BootOption *options, int size) {
    int disabledCount = 0;
    for (int i = 0; i < size; i++) {
        if (!options[i].enabled) {
            disabledCount++;
        }
    }
    printf("Optimized Boot Sequence: %d options disabled.\n", disabledCount);
}

int main() {
    BootOption bootOptions[MAX_OPTIONS];
    int choice;
    int size = MAX_OPTIONS;

    initializeBootOptions(bootOptions, size);

    while (1) {
        printf("\nBoot Optimizer Menu:\n");
        printf("1. Display Boot Options\n");
        printf("2. Toggle Boot Option\n");
        printf("3. Optimize Boot Sequence\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            exit(EXIT_FAILURE);
        }

        switch (choice) {
            case 1:
                displayBootOptions(bootOptions, size);
                break;
            case 2:
                printf("Enter option number to toggle (1-%d): ", size);
                int optionIndex;
                if (scanf("%d", &optionIndex) != 1 || optionIndex < 1 || optionIndex > size) {
                    fprintf(stderr, "Invalid option. Please enter a valid option number.\n");
                    break;
                }
                toggleBootOption(bootOptions, optionIndex - 1);
                break;
            case 3:
                optimizeBootSequence(bootOptions, size);
                break;
            case 4:
                printf("Exiting Boot Optimizer.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}