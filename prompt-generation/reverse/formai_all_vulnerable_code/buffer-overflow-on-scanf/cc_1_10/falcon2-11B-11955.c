//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIN 10
#define LOSE -10

int main() {
    // initialize random number generator
    srand(time(NULL));

    // get user's name
    char name[30];
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0'; // remove newline character

    // welcome message
    printf("Welcome, %s!\n", name);

    // display intro
    printf("You are in a dark and spooky forest. What do you do?\n");

    // display options
    printf("1. Go straight\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");

    // get user's choice
    int choice;
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    // handle user's choice
    switch (choice) {
        case 1:
            if (rand() % 2 == 0) {
                printf("You found a treasure chest!\n");
                printf("You win!\n");
                return WIN;
            } else {
                printf("You stumbled upon a giant spider!\n");
                printf("You lost!\n");
                return LOSE;
            }
            break;
        case 2:
            if (rand() % 2 == 0) {
                printf("You found a treasure chest!\n");
                printf("You win!\n");
                return WIN;
            } else {
                printf("You fell into a pit!\n");
                printf("You lost!\n");
                return LOSE;
            }
            break;
        case 3:
            if (rand() % 2 == 0) {
                printf("You found a treasure chest!\n");
                printf("You win!\n");
                return WIN;
            } else {
                printf("You stumbled upon a giant spider!\n");
                printf("You lost!\n");
                return LOSE;
            }
            break;
        default:
            printf("Invalid choice. Please enter a valid choice (1-3).\n");
            return LOSE;
    }
}