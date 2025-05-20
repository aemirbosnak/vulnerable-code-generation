//FormAI DATASET v1.0 Category: System boot optimizer ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int boot_time = 0;
    float boot_speed = 0.0;
    char* opt_choice;
    char* boot_devices[4] = {"USB", "CD-ROM", "Hard Disk", "Network"};

    printf("Welcome to the C System Boot Optimizer!\n");

    // Ask for boot time
    printf("How long does your computer take to boot in seconds? ");
    scanf("%d", &boot_time);

    // Calculate boot speed
    boot_speed = (float) 1 / (float) boot_time;

    printf("Your computer's boot speed is: %.2f boots per second.\n\n", boot_speed);

    // Ask for optimization choice
    printf("Would you like to:\n");
    printf("1. Optimize boot time\n");
    printf("2. Optimize boot speed\n");

    scanf("%s", opt_choice);

    if(strcmp(opt_choice, "1") == 0) {
        srand(time(0)); // Seed random number generator
        
        // Randomly select boot device from array
        int rand_device = rand() % 4; 
        char* chosen_device = boot_devices[rand_device];

        printf("Optimizing boot time by using %s as boot device.\n", chosen_device);
    } else if(strcmp(opt_choice, "2") == 0) {
        // Calculate optimal boot time
        float optimal_boot_time = 1 / 2.0 * boot_speed;
        printf("Optimizing boot speed by setting optimal boot time to %.2f seconds.\n", optimal_boot_time);
    } else {
        printf("Invalid choice. Exiting program.\n");
        return 0;
    }

    printf("Thank you for using the C System Boot Optimizer!");

    return 0;
}