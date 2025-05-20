//FormAI DATASET v1.0 Category: System boot optimizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the C System Boot Optimizer\n");
    printf("This program will optimize your system's boot time\n\n");

    // Declare and initialize variables
    int num_processes, num_devices, num_services, num_startup_items;
    float startup_time = 0;

    // Get user input
    printf("Enter number of processes running at startup: ");
    scanf("%d", &num_processes);

    printf("Enter number of devices connected at startup: ");
    scanf("%d", &num_devices);

    printf("Enter number of services running at startup: ");
    scanf("%d", &num_services);

    printf("Enter number of startup items enabled: ");
    scanf("%d", &num_startup_items);

    // Calculate and display startup time
    startup_time = num_processes * 0.5 + num_devices * 1.0 + num_services * 0.2 + num_startup_items * 0.1;
    printf("\nYour startup time is %.2f seconds\n\n", startup_time);

    // Determine if startup time is optimal or not
    if (startup_time < 10) {
        printf("Your system is optimized for fast boot time\n");
    } else {
        printf("Your system may benefit from a boot time optimization\n");

        printf("Would you like to optimize your system's boot time? (Y/N): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y') {
            // Simulate optimization process
            printf("Optimizing system boot time...\n");

            // Generate random delay time
            srand(time(NULL)); // seed random number generator
            int delay_time = rand() % 5 + 1; // generate random delay between 1 and 5 seconds

            // Simulate delay
            printf("Delaying startup by %d seconds...\n", delay_time);
            for (int i = delay_time; i >= 0; i--) {
                printf("%d seconds remaining...\n", i);
                sleep(1);
            }

            // Display success message
            printf("System boot time successfully optimized!\n");
        } else {
            printf("Okay, maybe another time!\n");
        }
    }

    return 0;
}