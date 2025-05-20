//FormAI DATASET v1.0 Category: System boot optimizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the boot option
#define MAX_LEN 50

// Define the maximum number of boot options
#define MAX_OPT 10

// Define the boot option struct
typedef struct option {
    char name[MAX_LEN];
    int priority;
} Option;

// Function to print the boot options
void print_options(Option options[], int count) {
    printf("Boot Options:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Priority: %d)\n", i + 1, options[i].name, options[i].priority);
    }
}

// Function to add a boot option
void add_option(Option options[], int *count) {
    if (*count >= MAX_OPT) {
        printf("Cannot add more boot options.\n");
        return;
    }

    char name[MAX_LEN];
    int priority;

    printf("Enter boot option name: ");
    scanf("%s", name);

    printf("Enter priority (1-10): ");
    scanf("%d", &priority);

    if (priority < 1 || priority > 10) {
        printf("Invalid priority.\n");
        return;
    }

    options[*count].priority = priority;
    strcpy(options[*count].name, name);
    *count += 1;

    printf("Boot option added successfully.\n");
}

// Function to delete a boot option
void delete_option(Option options[], int *count) {
    if (*count == 0) {
        printf("No boot options available.\n");
        return;
    }

    int option_num;
    printf("Enter option number to delete: ");
    scanf("%d", &option_num);

    if (option_num < 1 || option_num > *count) {
        printf("Invalid option number.\n");
        return;
    }

    for (int i = option_num - 1; i < *count - 1; i++) {
        options[i] = options[i + 1];
    }

    *count -= 1;

    printf("Boot option deleted successfully.\n");
}

// Sort boot options based on priority using selection sort
void sort_options(Option options[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < count; j++) {
            if (options[j].priority < options[min_index].priority) {
                min_index = j;
            }
        }
        if (min_index != i) {
            Option temp = options[i];
            options[i] = options[min_index];
            options[min_index] = temp;
        }
    }
}

int main() {
    Option options[MAX_OPT];
    int count = 0;

    while (1) {
        printf("\n");
        printf("1. View boot options\n");
        printf("2. Add a boot option\n");
        printf("3. Delete a boot option\n");
        printf("4. Sort boot options by priority\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_options(options, count);
                break;
            case 2:
                add_option(options, &count);
                break;
            case 3:
                delete_option(options, &count);
                break;
            case 4:
                sort_options(options, count);
                printf("Boot options sorted by priority.\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}