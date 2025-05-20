//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_BOOT_OPTIONS 10
#define MAX_OPTION_LENGTH 50

typedef struct {
    char option[MAX_OPTION_LENGTH];
    int priority;
} BootOption;

void displayBootOptions(BootOption options[], int count) {
    printf("Available Boot Options:\n");
    for(int i = 0; i < count; i++) {
        printf(" %d: %s (Priority: %d)\n", i + 1, options[i].option, options[i].priority);
    }
}

void sortBootOptions(BootOption options[], int count) {
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(options[j].priority < options[j + 1].priority) {
                BootOption temp = options[j];
                options[j] = options[j + 1];
                options[j + 1] = temp;
            }
        }
    }
}

void addBootOption(BootOption options[], int *count, const char *option, int priority) {
    if(*count < MAX_BOOT_OPTIONS) {
        strncpy(options[*count].option, option, MAX_OPTION_LENGTH);
        options[*count].priority = priority;
        (*count)++;
    } else {
        printf("Maximum boot options reached!\n");
    }
}

void displayAndOptimizeBootOrder(BootOption options[], int *count) {
    printf("\nCurrent Boot Order:\n");
    displayBootOptions(options, *count);

    printf("\nSorting options based on priority...\n");
    sortBootOptions(options, *count);
    
    printf("Optimized Boot Order:\n");
    displayBootOptions(options, *count);
}

void waitForUser() {
    printf("\nPress Enter to continue...");
    getchar();
}

int main() {
    BootOption bootOptions[MAX_BOOT_OPTIONS];
    int bootCount = 0;
    int choice;
    char option[MAX_OPTION_LENGTH];
    int priority;

    printf("Welcome to the Boot Optimizer! 🌟\n");

    while(1) {
        printf("\nMenu:\n");
        printf("1: Add Boot Option\n");
        printf("2: Display and Optimize Boot Order\n");
        printf("3: Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

        switch(choice) {
            case 1:
                printf("Enter Boot Option: ");
                fgets(option, MAX_OPTION_LENGTH, stdin);
                option[strcspn(option, "\n")] = 0; // Remove newline character
                
                printf("Enter Priority (1-10, where 10 is highest): ");
                scanf("%d", &priority);
                
                if(priority < 1 || priority > 10) {
                    printf("Priority must be between 1 and 10!\n");
                } else {
                    addBootOption(bootOptions, &bootCount, option, priority);
                    printf("Boot option added successfully! 🎉\n");
                }
                break;

            case 2:
                displayAndOptimizeBootOrder(bootOptions, &bootCount);
                waitForUser();
                break;

            case 3:
                printf("Exiting Boot Optimizer. Goodbye! 👋\n");
                exit(0);
                break;

            default:
                printf("Invalid option, please try again! 🤔\n");
                break;
        }
    }

    return 0;
}