//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_OPTIONS 5

typedef struct {
    char name[30];
    int isEnabled;
} BootOption;

void displayOptions(BootOption options[], int count) {
    printf("\n=== Boot Options ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s [%s]\n", i + 1, options[i].name, options[i].isEnabled ? "Enabled" : "Disabled");
    }
    printf("=====================\n");
}

void toggleOption(BootOption options[], int index) {
    options[index].isEnabled = !options[index].isEnabled;
    printf("Toggled %s to %s!\n", options[index].name, options[index].isEnabled ? "Enabled" : "Disabled");
}

void optimizeBoot(BootOption options[], int count) {
    printf("\nOptimizing boot options...\n");
    for (int i = 0; i < count; i++) {
        if (options[i].isEnabled) {
            printf("Applying optimization: %s!\n", options[i].name);
            sleep(1); // Simulate time taken to apply each optimization
        }
    }
    printf("\nBoot optimization complete! Enjoy your speedy startup! 🚀\n");
}

int main() {
    BootOption bootOptions[MAX_OPTIONS] = {
        {"Fast Boot", 0},
        {"Disable Unnecessary Services", 0},
        {"Load Only Essential Drivers", 0},
        {"Enable Quick Startup", 0},
        {"Optimize System Resources", 0}
    };

    int choice;
    
    printf("Welcome to the Happy Boot Optimizer! 😊\n");
    
    while (1) {
        displayOptions(bootOptions, MAX_OPTIONS);
        
        printf("Choose an option to toggle or enter 0 to perform optimization: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            optimizeBoot(bootOptions, MAX_OPTIONS);
            break;
        } else if (choice > 0 && choice <= MAX_OPTIONS) {
            toggleOption(bootOptions, choice - 1);
        } else {
            printf("Please enter a valid choice!\n");
        }
    }

    return 0;
}