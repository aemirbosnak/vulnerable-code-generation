//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void startGame(void);
void playGame(void);
void endGame(int score);

int main(void) {
    srand(time(NULL)); // Seed the random number generator
    startGame();
    return 0;
}

void startGame(void) {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to find the lost treasure.\n");
    printf("Are you ready to begin your journey? (y/n): ");
    char choice;
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y') {
        playGame();
    } else {
        printf("Thank you for playing!\n");
        endGame(0);
    }
}

void playGame(void) {
    int score = 0;
    int room = 1;
    char choice;

    while (room <= 5) {
        printf("\nYou are in room %d.\n", room);
        printf("What would you like to do? (1. Look around, 2. Go to next room): ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("You look around the room and find a shiny object on the floor.\n");
            printf("Do you want to pick it up? (y/n): ");
            char pickUp;
            scanf("%c", &pickUp);
            if (pickUp == 'y' || pickUp == 'Y') {
                score++;
            }
            break;
        case '2':
            room++;
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    endGame(score);
}

void endGame(int score) {
    if (score == 0) {
        printf("You didn't find any treasure. Better luck next time!\n");
    } else {
        printf("Congratulations! You found the lost treasure and scored %d points!\n", score);
    }
}