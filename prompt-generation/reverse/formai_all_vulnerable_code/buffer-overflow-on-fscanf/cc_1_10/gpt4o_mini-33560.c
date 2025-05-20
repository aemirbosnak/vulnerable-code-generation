//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 256
#define MAX_OPTIONS 5

typedef struct {
    char name[BUFFER_SIZE];
    int priority;
} BootOption;

void printBootMenu(BootOption *options, int count) {
    printf("==== Boot Menu ====\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Priority: %d)\n", i + 1, options[i].name, options[i].priority);
    }
}

void optimizeBootOptions(BootOption *options, int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (options[i].priority > options[j].priority) {
                BootOption temp = options[i];
                options[i] = options[j];
                options[j] = temp;
            }
        }
    }
}

void loadBootOption(const char *option) {
    printf("Loading %s...\n", option);
    sleep(1);  // Simulate loading time
    printf("%s loaded successfully!\n", option);
}

void savePreferences(const char *filename, BootOption *options, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to save preferences");
        return;
    }
    for (int i = 0; i < count; ++i) {
        fprintf(file, "%s,%d\n", options[i].name, options[i].priority);
    }
    fclose(file);
    printf("Preferences saved to %s\n", filename);
}

void loadPreferences(const char *filename, BootOption *options, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to load preferences");
        return;
    }
    *count = 0;
    while (fscanf(file, "%[^,],%d\n", options[*count].name, &options[*count].priority) == 2) {
        (*count)++;
    }
    fclose(file);
    printf("Loaded preferences from %s\n", filename);
}

int main() {
    BootOption bootOptions[MAX_OPTIONS] = {
        {"Linux Fedora", 2},
        {"Windows 10", 3},
        {"Ubuntu", 1},
        {"Arch Linux", 4},
        {"Backup OS", 5}
    };

    int optionCount = 5;
    char preferencesFile[] = "boot_preferences.txt";

    loadPreferences(preferencesFile, bootOptions, &optionCount);
    
    printf("=== Boot Optimization Tool ===\n\n");
    
    optimizeBootOptions(bootOptions, optionCount);
    
    printBootMenu(bootOptions, optionCount);
    
    int choice;
    printf("Select a boot option (1-%d): ", optionCount);
    scanf("%d", &choice);

    if (choice > 0 && choice <= optionCount) {
        loadBootOption(bootOptions[choice - 1].name);
    } else {
        printf("Invalid choice! Exiting...\n");
    }

    char saveOption;
    printf("Do you want to save current preferences? (y/n): ");
    scanf(" %c", &saveOption);
    if (saveOption == 'y') {
        savePreferences(preferencesFile, bootOptions, optionCount);
    }

    return 0;
}