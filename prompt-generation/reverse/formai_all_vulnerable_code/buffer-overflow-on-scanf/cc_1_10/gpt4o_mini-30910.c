//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BOOT_OPTIONS 5
#define MAX_OPTION_LENGTH 50

typedef struct {
    char name[MAX_OPTION_LENGTH];
    int priority;
} BootOption;

void initializeBootOptions(BootOption *options) {
    snprintf(options[0].name, MAX_OPTION_LENGTH, "Linux Kernel");
    options[0].priority = 1;

    snprintf(options[1].name, MAX_OPTION_LENGTH, "Windows Boot Manager");
    options[1].priority = 2;

    snprintf(options[2].name, MAX_OPTION_LENGTH, "Ubuntu Recovery Mode");
    options[2].priority = 3;

    snprintf(options[3].name, MAX_OPTION_LENGTH, "Minimal Shell");
    options[3].priority = 4;

    snprintf(options[4].name, MAX_OPTION_LENGTH, "Advanced Options");
    options[4].priority = 5;
}

void displayBootMenu(BootOption *options, int count) {
    printf("Welcome to the Boot Options Menu!\n");
    printf("Please select an option to boot:\n");
    
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Priority: %d)\n", i + 1, options[i].name, options[i].priority);
    }
}

int compareBootOptions(const void *a, const void *b) {
    BootOption *optionA = (BootOption *)a;
    BootOption *optionB = (BootOption *)b;
    return optionA->priority - optionB->priority;
}

void optimizeBootSequence(BootOption *options, int count) {
    qsort(options, count, sizeof(BootOption), compareBootOptions);
    printf("Boot options are now optimized by priority.\n");
}

void bootIntoOption(BootOption selectedOption) {
    printf("Booting into: %s...\n", selectedOption.name);
    sleep(2); // Simulate boot loading time
    printf("Boot complete!\n");
}

int main() {
    BootOption bootOptions[MAX_BOOT_OPTIONS];
    int selectedOption;

    initializeBootOptions(bootOptions);
    displayBootMenu(bootOptions, MAX_BOOT_OPTIONS);
    
    printf("Please enter the number of your selected option (1-%d): ", MAX_BOOT_OPTIONS);
    scanf("%d", &selectedOption);

    if (selectedOption < 1 || selectedOption > MAX_BOOT_OPTIONS) {
        printf("Invalid selection. Exiting...\n");
        return EXIT_FAILURE;
    }

    optimizeBootSequence(bootOptions, MAX_BOOT_OPTIONS);
    bootIntoOption(bootOptions[selectedOption - 1]);

    return EXIT_SUCCESS;
}