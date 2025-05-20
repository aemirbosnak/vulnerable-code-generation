//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the welcome message
void welcome() {
    printf("Welcome to the Happy Adventure Game!\n\n");
    printf("You wake up in a beautiful meadow on a sunny day.\n");
    printf("The birds are singing and the flowers are blooming.\n");
    printf("What would you like to do?\n");
}

// Function to print the available options
void options() {
    printf("1. Go for a walk\n");
    printf("2. Pick some flowers\n");
    printf("3. Take a nap\n");
}

// Function to execute the selected option
void execute_option(int choice) {
    switch(choice) {
        case 1:
            printf("You go for a walk and find a magical tree.\n");
            printf("The tree grants you three wishes.\n");
            printf("What would you like to wish for?\n");
            break;
        case 2:
            printf("You pick some flowers and make a beautiful bouquet.\n");
            printf("A kind passerby offers to buy the bouquet for $50.\n");
            printf("Do you want to sell the bouquet? (y/n)\n");
            break;
        case 3:
            printf("You take a nap and have a sweet dream.\n");
            printf("In your dream, you find a treasure chest.\n");
            printf("When you wake up, you realize it was just a dream.\n");
            break;
        default:
            printf("Invalid option selected.\n");
    }
}

int main() {
    srand(time(0)); // Seed the random number generator

    welcome();

    int choice;

    while(1) {
        options();
        scanf("%d", &choice);

        execute_option(choice);

        if(choice == 3) {
            printf("You had a great adventure and it's time to go home.\n");
            printf("Thanks for playing!\n");
            break;
        }
    }

    return 0;
}