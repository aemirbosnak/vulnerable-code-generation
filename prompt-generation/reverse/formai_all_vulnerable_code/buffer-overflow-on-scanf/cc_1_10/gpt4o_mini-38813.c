//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_BOOT_OPTIONS 5
#define OPTION_LENGTH 50
#define CONFIG_FILE "boot_config.txt"

typedef struct {
    char name[OPTION_LENGTH];
    int priority;
} BootOption;

BootOption bootOptions[MAX_BOOT_OPTIONS];
int optionCount = 0;

void loadBootOptions() {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) {
        perror("Could not open config file");
        return;
    }

    while (fscanf(file, "%49s %d", bootOptions[optionCount].name, &bootOptions[optionCount].priority) == 2) {
        optionCount++;
        if (optionCount >= MAX_BOOT_OPTIONS) {
            break;
        }
    }
    fclose(file);
}

void sortBootOptions() {
    for (int i = 0; i < optionCount - 1; i++) {
        for (int j = 0; j < optionCount - i - 1; j++) {
            if (bootOptions[j].priority < bootOptions[j + 1].priority) {
                BootOption temp = bootOptions[j];
                bootOptions[j] = bootOptions[j + 1];
                bootOptions[j + 1] = temp;
            }
        }
    }
}

void displayBootOptions() {
    printf("Available Boot Options:\n");
    for (int i = 0; i < optionCount; i++) {
        printf("%d. %s (Priority: %d)\n", i + 1, bootOptions[i].name, bootOptions[i].priority);
    }
}

void executeBootOption(int index) {
    if (index < 0 || index >= optionCount) {
        printf("Invalid boot option selected.\n");
        return;
    }

    printf("Booting %s...\n", bootOptions[index].name);
    sleep(1); // Simulate boot time
    printf("%s has successfully booted!\n", bootOptions[index].name);
}

int main() {
    loadBootOptions();
    sortBootOptions();
    
    displayBootOptions();

    int selection;
    printf("Select the boot option (1 to %d): ", optionCount);
    scanf("%d", &selection);

    executeBootOption(selection - 1);

    return 0;
}