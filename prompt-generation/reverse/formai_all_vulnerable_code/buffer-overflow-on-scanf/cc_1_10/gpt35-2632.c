//FormAI DATASET v1.0 Category: System boot optimizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between a minimum and maximum value
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int boot_time = 60; // Default boot time in seconds
    int optimization_level = 0; // Default optimization level
    int reboot_required = 0; // Default reboot required flag
    printf("Welcome to the C System Boot Optimizer!\n\n");

    // Prompt user to enter their desired optimization level
    printf("Please enter your desired optimization level (0-3): ");
    scanf("%d", &optimization_level);

    // Validate input and adjust boot time based on optimization level
    switch (optimization_level) {
        case 0:
            printf("You have selected no optimization.\n");
            break;
        case 1:
            printf("You have selected low optimization.\n");
            boot_time -= 10; // Decrease boot time by 10 seconds
            break;
        case 2:
            printf("You have selected medium optimization.\n");
            boot_time -= 20; // Decrease boot time by 20 seconds
            break;
        case 3:
            printf("You have selected high optimization.\n");
            boot_time -= 30; // Decrease boot time by 30 seconds
            break;
        default:
            printf("Invalid optimization level selected. Defaulting to no optimization.\n");
            break;
    }

    // Generate random delays and display progress to the user
    printf("\nBooting system...\n");
    for (int i = 0; i < boot_time; i++) {
        int delay = random_number(1, 3); // Generate a random delay between 1-3 seconds
        printf("%d%% complete. Delaying for %d seconds...\n", (int)(((double)i / (double)boot_time) * 100), delay);
        sleep(delay); // Delay execution for the random amount of time
    }

    // Prompt user to reboot the system
    printf("\nSystem boot complete. Would you like to reboot now? (y/n): ");
    char reboot_choice;
    scanf(" %c", &reboot_choice);
    if (reboot_choice == 'y' || reboot_choice == 'Y') {
        reboot_required = 1; // Set reboot required flag to true
    }

    // Display final message to the user and exit
    if (reboot_required) {
        printf("\nRebooting system...\n");
    }
    else {
        printf("\nThank you for using the C System Boot Optimizer!\n");
    }
    return 0;
}