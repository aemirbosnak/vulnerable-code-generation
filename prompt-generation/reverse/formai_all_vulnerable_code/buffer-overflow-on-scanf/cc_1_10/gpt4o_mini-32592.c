//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BOOT_TIME 5 // Maximum boot time in seconds.
#define MIN_BOOT_TIME 1 // Minimum boot time in seconds.

void tell_joke() {
    printf("Why did the computer go to school? Because it wanted to improve its 'byte' of knowledge!\n");
}

void optimize_boot_sequence() {
    printf("Engaging super-duper optimization sequence!\n");
    sleep(1); // Just a little suspense
    printf("Checking for unnecessary pre-boot services...\n");
    sleep(1);
    printf("Identifying lazy processes...\n");
    sleep(1);
    printf("Eliminating any rogue applications...\n");
    sleep(1);
    printf("And... cleaning up the boot sequence! Voila!\n");
    sleep(1);
}

void boot_time_simulation() {
    printf("Starting the boot process...\n");
    int boot_time = rand() % (MAX_BOOT_TIME - MIN_BOOT_TIME + 1) + MIN_BOOT_TIME;
    
    for(int i = boot_time; i > 0; i--) {
        printf("Booting... %d seconds remaining.\n", i);
        sleep(1);
    }
    
    printf("Boot complete! Time taken: %d seconds.\n", boot_time);
}

void boot_optimizer() {
    printf("Welcome to the C System Boot Optimizer!\n");
    printf("We aim to make your boot process snappier than a caffeinated squirrel!\n\n");

    while (1) {
        printf("Let's perform some boot optimization, shall we?\n");
        sleep(1);
        
        optimize_boot_sequence();
        printf("\n");

        boot_time_simulation();
        
        tell_joke();
        printf("\nWould you like to try another boot optimization? (y/n): ");
        
        char choice;
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y') {
            printf("Thanks for using the C System Boot Optimizer!\n");
            printf("Remember, a fast boot is a happy boot! Goodbye!\n");
            break;
        } else {
            printf("Awesome! Let's zap those boot times again!\n\n");
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    boot_optimizer();

    return 0;
}