//FormAI DATASET v1.0 Category: System boot optimizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOT_OPTIONS 100

typedef struct BootOption {
    char label[20];
    int seconds_to_delay;
} BootOption;

int read_boot_options(BootOption options[]);
void sort_boot_options(BootOption options[], int num_options);
void print_boot_options(BootOption options[], int num_options);

int main() {
    BootOption options[MAX_BOOT_OPTIONS];
    int num_options = read_boot_options(options);

    // Sort the boot options by their delay time in ascending order
    sort_boot_options(options, num_options);

    // Add a debug output to show the sorted boot options
    printf("Sorted boot options:\n");
    print_boot_options(options, num_options);

    // Now simulate booting up and delay for the specified time for each option
    for (int i = 0; i < num_options; i++) {
        printf("Booting up %s in %d seconds...\n", options[i].label, options[i].seconds_to_delay);
        for (int j = options[i].seconds_to_delay; j > 0; j--) {
            printf("%d...\n", j);
            sleep(1);
        }
        printf("Booted up %s!\n\n", options[i].label);
    }
    printf("All boot options successfully launched!");
    return 0;
}

int read_boot_options(BootOption options[]) {
    printf("Welcome to the Genius Boot Optimizer!\n\nPlease enter the boot options you would like to optimize:\n");

    char input[50];
    int option_count = 0;

    while (1) {
        printf("Option %d - Label (max 20 characters): ", option_count+1);
        fgets(input, 50, stdin);
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        // Remove newline character from input
        input[strlen(input)-1] = '\0';
        strncpy(options[option_count].label, input, 20);

        printf("Option %d - Delay time (in seconds): ", option_count+1);
        fgets(input, 50, stdin);
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        options[option_count].seconds_to_delay = atoi(input);

        option_count++;
        if (option_count >= MAX_BOOT_OPTIONS) {
            printf("Maximum number of boot options reached (%d).\n", MAX_BOOT_OPTIONS);
            break;
        }
    }

    return option_count;
}

void sort_boot_options(BootOption options[], int num_options) {
    for (int i = 0; i < num_options; i++) {
        for (int j = i+1; j < num_options; j++) {
            if (options[j].seconds_to_delay < options[i].seconds_to_delay) {
                // Swap the two options
                BootOption temp = options[i];
                options[i] = options[j];
                options[j] = temp;
            }
        }
    }
}

void print_boot_options(BootOption options[], int num_options) {
    for (int i = 0; i < num_options; i++) {
        printf("%s (%d seconds delay)\n", options[i].label, options[i].seconds_to_delay);
    }
}