//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void intro();
void game();
void playAgain();

int main() {
    srand(time(0));
    intro();
    game();
    playAgain();
    return 0;
}

// Function to display introduction
void intro() {
    printf("\n\n\t\t\t\t\t\t\t\t Welcome to the Adventure Game!\n");
    printf("\n\t\t\t\t\t\t\t\t In this game, you will go on an adventure to find the lost treasure.\n");
    printf("\n\t\t\t\t\t\t\t\t You will encounter many obstacles on your journey, but don't give up!\n");
    printf("\n\t\t\t\t\t\t\t\t The treasure is waiting for you at the end.\n");
    printf("\n\n\t\t\t\t\t\t\t\t Press any key to begin...");
    getchar();
}

// Function to play the game
void game() {
    int choice;
    char name[20];

    // Ask player for their name
    printf("\n\n\t\t\t\t\t\t\t\t What is your name? ");
    scanf("%s", name);

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;

    // Loop until player guesses the correct number
    while(1) {
        // Ask player for their guess
        printf("\n\n\t\t\t\t\t\t\t\t Guess a number between 1 and 100: ");
        scanf("%d", &choice);

        // Check if guess is correct
        if(choice == randomNumber) {
            printf("\n\n\t\t\t\t\t\t\t\t Congratulations %s! You guessed the correct number: %d", name, randomNumber);
            break;
        } else if(choice < randomNumber) {
            printf("\n\n\t\t\t\t\t\t\t\t Too low %s. Guess again.", name);
        } else {
            printf("\n\n\t\t\t\t\t\t\t\t Too high %s. Guess again.", name);
        }
    }
}

// Function to ask player if they want to play again
void playAgain() {
    char choice;

    // Ask player if they want to play again
    printf("\n\n\t\t\t\t\t\t\t\t Do you want to play again? (y/n): ");
    scanf(" %c", &choice);

    // Check if player wants to play again
    if(choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("\n\n\t\t\t\t\t\t\t\t Thank you for playing!");
        exit(0);
    }
}