//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void start();
void play();
void end();

int main() {
    srand(time(NULL));
    start();
    play();
    end();
    return 0;
}

// Start of the game
void start() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are lost in a mysterious forest.\n");
    printf("Your goal is to find your way out.\n");
    printf("Good luck!\n");
}

// Gameplay
void play() {
    int choice, randomNum;
    char direction;

    printf("You see a path going north and another going east.\n");
    printf("Which way do you want to go? (n/e) ");
    scanf("%c", &direction);

    switch(direction) {
        case 'n':
            printf("You walk along the path for a while.\n");
            printf("You come across a river.\n");
            printf("Do you want to cross the river? (y/n) ");
            scanf("%c", &choice);

            if(choice == 'y') {
                printf("You cross the river safely.\n");
            } else {
                printf("You decide to turn back.\n");
            }
            break;

        case 'e':
            printf("You walk along the path for a while.\n");
            printf("You come across a fork in the road.\n");
            printf("Do you want to go left or right? (l/r) ");
            scanf("%c", &direction);

            if(direction == 'l') {
                printf("You walk along the left path for a while.\n");
                printf("You find a treasure!\n");
            } else {
                printf("You walk along the right path for a while.\n");
                printf("You stumble upon an old man.\n");
                printf("He tells you a secret about the forest.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
    }
}

// End of the game
void end() {
    printf("Thanks for playing the Text-Based Adventure Game!\n");
}