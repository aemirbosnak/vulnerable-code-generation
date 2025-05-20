//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void intro();
void game();
void playAgain();

int main() {
    srand(time(0)); // Seed the random number generator
    intro();
    game();
    return 0;
}

// Display the intro
void intro() {
    printf("\n\n");
    printf("Welcome to the Enchanted Forest!\n");
    printf("You are a brave adventurer on a quest to find the legendary treasure.\n");
    printf("Beware of the dangers that lurk within the forest.\n");
    printf("Good luck on your journey!\n\n");
}

// The game loop
void game() {
    int choice;
    int health = 100;

    while(health > 0) {
        system("clear"); // Clear the console
        printf("\n");
        printf("You are standing at the entrance of the Enchanted Forest.\n");
        printf("What would you like to do?\n");
        printf("1. Explore the forest\n");
        printf("2. Search for treasure\n");
        printf("3. Rest\n");
        printf("4. Quit\n");
        printf("\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n");
                printf("You venture deeper into the forest.\n");
                printf("Suddenly, you hear a rustling in the bushes.\n");
                printf("A wild boar charges at you!\n");
                health -= 30;
                if(health <= 0) {
                    printf("\n");
                    printf("You have been defeated by the wild boar.\n");
                    printf("Game Over!\n");
                    exit(1);
                }
                break;

            case 2:
                printf("\n");
                printf("You search for treasure in the forest.\n");
                printf("After hours of searching, you finally find it!\n");
                printf("You have found the legendary treasure!\n");
                printf("Congratulations, you win!\n");
                exit(0);

            case 3:
                printf("\n");
                printf("You take a rest and regain some health.\n");
                health += 20;
                break;

            case 4:
                printf("\n");
                printf("You decide to quit your adventure.\n");
                exit(1);

            default:
                printf("\n");
                printf("Invalid choice.\n");
        }
        printf("\n");
    }
}

// Ask the player if they want to play again
void playAgain() {
    char choice;

    printf("\n");
    printf("Would you like to play again? (y/n)\n");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("\n");
        printf("Thanks for playing!\n");
        exit(0);
    }
}