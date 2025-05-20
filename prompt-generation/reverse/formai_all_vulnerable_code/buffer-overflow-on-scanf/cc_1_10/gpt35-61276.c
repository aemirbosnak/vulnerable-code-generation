//FormAI DATASET v1.0 Category: System boot optimizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_loading_screen() {
    printf("Welcome to the C System boot optimizer!\n\n");
    printf("Initializing system components...\n");
    printf("Checking hardware configuration...\n");
    printf("Loading kernel...\n");
    printf("Starting optimization process...\n\n");
    printf("Please wait...\n\n");
}

void perform_optimization() {
    // simulate optimization process by generating random numbers
    srand(time(NULL));
    int i;

    for (i = 0; i < 10; i++) {
        int random_num = rand() % 100;
        printf("Optimizing system resources: %d%%\n", random_num);
        // sleep for 1 second to simulate processing time
        sleep(1);
    }

    printf("\nSystem optimization completed successfully!\n\n");
}

void display_menu() {
    printf("What would you like to do?\n\n");
    printf("1. Perform System Optimization\n");
    printf("2. View Boot Time\n");
    printf("3. Exit Program\n\n");
}

int main() {
    int choice, boot_time;

    display_loading_screen();

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                perform_optimization();
                break;

            case 2:
                printf("Enter boot time (in seconds): ");
                scanf("%d", &boot_time);
                printf("\nBoot time set to %d seconds.\n\n", boot_time);
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    return 0;
}