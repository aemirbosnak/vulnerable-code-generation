//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

// RAM usage function
long long ram_usage() {
    struct sysinfo info;
    sysinfo(&info);
    return info.totalram - info.freeram;
}

int main() {
    // Declare variables
    int choice, choice2, size;
    long long ram, ram_initial, ram_final;

    // Header
    printf("======== RAM Usage Monitor ========\n");

    // Loop until user quits
    while (1) {
        // Display options
        printf("\nOptions:\n");
        printf("1. Monitor RAM usage constantly\n");
        printf("2. Monitor RAM usage for a specific time period\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Constant monitoring
                printf("Press any key to stop monitoring.\n");
                while (!getchar()) {
                    // Display RAM usage
                    ram = ram_usage();
                    printf("Current RAM usage: %lld bytes\n", ram);
                }
                break;
            case 2:
                // Timed monitoring
                printf("Enter the time period (in seconds): ");
                scanf("%d", &size);
                ram_initial = ram_usage();

                // Start monitoring
                sleep(size);
                ram_final = ram_usage();

                // Display RAM usage
                printf("Initial RAM usage: %lld bytes\n", ram_initial);
                printf("Final RAM usage: %lld bytes\n", ram_final);
                printf("RAM usage after %d seconds: %lld bytes\n", size, ram_final - ram_initial);
                break;
            case 3:
                // Exit
                printf("Exiting...\n");
                exit(0);
            default:
                // Invalid choice
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}