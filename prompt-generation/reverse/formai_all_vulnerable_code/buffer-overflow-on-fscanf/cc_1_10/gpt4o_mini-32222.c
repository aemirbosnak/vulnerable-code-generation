//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BOOT_OPTIONS 10
#define CONFIG_FILE "boot_config.txt"

typedef struct BootOption {
    char name[50];
    char command[256];
    int priority;
} BootOption;

BootOption bootOptions[MAX_BOOT_OPTIONS];
int optionCount = 0;

void loadBootOptions() {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) {
        perror("Error opening boot config file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%49s %255s %d", bootOptions[optionCount].name,
                  bootOptions[optionCount].command, 
                  &bootOptions[optionCount].priority) == 3) {
        optionCount++;
        if (optionCount >= MAX_BOOT_OPTIONS) {
            break;
        }
    }
    fclose(file);
}

void swap(BootOption *a, BootOption *b) {
    BootOption temp = *a;
    *a = *b;
    *b = temp;
}

void sortBootOptions() {
    for (int i = 0; i < optionCount - 1; i++) {
        for (int j = 0; j < optionCount - i - 1; j++) {
            if (bootOptions[j].priority < bootOptions[j + 1].priority) {
                swap(&bootOptions[j], &bootOptions[j + 1]);
            }
        }
    }
}

void displayBootOptions() {
    printf("Available Boot Options:\n");
    for (int i = 0; i < optionCount; i++) {
        printf("%d. %s (Priority: %d)\n", i + 1, 
               bootOptions[i].name, 
               bootOptions[i].priority);
    }
}

void executeBootOption(int index) {
    if (index < 0 || index >= optionCount) {
        fprintf(stderr, "Invalid boot option\n");
        return;
    }

    printf("Executing: %s\n", bootOptions[index].command);
    int result = system(bootOptions[index].command);
    if (result == -1) {
        perror("Execution failed");
    }
}

void runBootOptimizer() {
    loadBootOptions();
    sortBootOptions();
    displayBootOptions();

    int choice;
    printf("Select a boot option to execute (1-%d): ", optionCount);
    scanf("%d", &choice);

    executeBootOption(choice - 1);
}

void printUsage() {
    printf("Usage: boot_optimizer\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printUsage();
        return EXIT_FAILURE;
    }

    runBootOptimizer();
    return EXIT_SUCCESS;
}