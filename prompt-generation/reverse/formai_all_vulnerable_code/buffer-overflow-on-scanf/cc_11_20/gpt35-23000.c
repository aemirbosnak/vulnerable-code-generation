//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// This is a silly program to manage the system's coffee supply and keep the developers happy!

int main() {
    int coffee_amount = rand() % 100 + 1; // initialize the coffee supply level randomly

    printf("Welcome to the Coffee Management System!\n");
    printf("Current coffee supply level: %d\n\n", coffee_amount);

    while(1) { // infinite loop for user input

        printf("What would you like to do? (Type the corresponding number)\n");
        printf("1. Refill coffee supply\n");
        printf("2. Check coffee supply level\n");
        printf("3. Make a cup of coffee\n");
        printf("4. Exit\n");

        int input;
        scanf("%d", &input);

        switch(input) {
            case 1:
                printf("\nStarting the coffee refill process...\n");
                printf("...");
                for(int i = 0; i < 3; i++) { // fake loading bar
                    printf("...");
                    fflush(stdout);
                    sleep(1);
                }
                coffee_amount += rand() % 20 + 1; // refill with random amount between 1 and 20
                printf("\nCoffee supply level is now %d\n\n", coffee_amount);
                break;

            case 2:
                printf("\nChecking coffee supply level...\n");
                printf("...");
                for(int i = 0; i < 3; i++) { // another fake loading bar
                    printf("...");
                    fflush(stdout);
                    sleep(1);
                }
                if(coffee_amount < 20) {
                    printf("\nWARNING: Coffee supply level is critically low!\n\n");
                } else {
                    printf("\nCoffee supply level is currently %d\n\n", coffee_amount);
                }
                break;

            case 3:
                if(coffee_amount > 0) {
                    printf("\nMaking a cup of coffee...\n");
                    printf("...");
                    for(int i = 0; i < 3; i++) { // yet another fake loading bar
                        printf("...");
                        fflush(stdout);
                        sleep(1);
                    }
                    coffee_amount--;
                    printf("\nEnjoy your fresh cup of coffee!\n");
                    printf("Coffee supply level is now %d\n\n", coffee_amount);
                } else {
                    printf("\nSorry, there is no coffee left! Please refill the supply.\n\n");
                }
                break;

            case 4:
                printf("\nGoodbye!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid input, please select an option.\n\n");
                break;
        }
    }

    return 0;
}