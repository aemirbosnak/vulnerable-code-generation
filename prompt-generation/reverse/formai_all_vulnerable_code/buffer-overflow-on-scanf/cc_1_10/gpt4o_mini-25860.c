//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 100
#define SIMULATIONS 1000

void display_menu() {
    printf("\n=========================================\n");
    printf("     ALIEN INVASION PROBABILITY CALCULATOR  \n");
    printf("=========================================\n");
    printf("1. Calculate Probability of Alien Invasion\n");
    printf("2. Exit\n");
    printf("=========================================\n");
    printf("Choose an option: ");
}

void simulate_alien_invasion(int num_aliens) {
    int success_count = 0;

    for (int i = 0; i < SIMULATIONS; i++) {
        // Using a random threshold for invasion success
        int invasion_success = rand() % MAX_ALIENS < num_aliens;
        if (invasion_success) {
            success_count++;
        }
    }

    double probability = (double)success_count / SIMULATIONS * 100;
    printf("With %d aliens, the calculated probability of an invasion is: %.2f%%\n", num_aliens, probability);
}

int get_num_aliens() {
    int num_aliens;

    printf("Enter the number of aliens (0 - %d): ", MAX_ALIENS);
    while (1) {
        scanf("%d", &num_aliens);
        if (num_aliens >= 0 && num_aliens <= MAX_ALIENS) {
            break;
        } else {
            printf("Invalid input! Please enter a number between 0 and %d: ", MAX_ALIENS);
        }
    }

    return num_aliens;
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1: {
                int num_aliens = get_num_aliens();
                simulate_alien_invasion(num_aliens);
                break;
            }
            case 2:
                printf("Thank you for using the Alien Invasion Probability Calculator. Stay safe!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}