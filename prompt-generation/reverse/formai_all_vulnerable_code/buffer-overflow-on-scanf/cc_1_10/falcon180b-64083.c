//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void start_game(void);
void play_game(void);
void end_game(int score);

int main(void) {
    srand(time(NULL));
    start_game();
    return 0;
}

void start_game(void) {
    char choice;
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Do you want to start a new game? (y/n): ");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        play_game();
    } else {
        printf("Thanks for playing!\n");
        exit(0);
    }
}

void play_game(void) {
    int score = 0;
    char choice;

    printf("\nYou are in a magical forest.\n");
    printf("What do you want to do?\n");
    printf("1. Explore the forest\n");
    printf("2. Look for treasure\n");
    printf("3. Fight monsters\n");
    printf("4. Quit\n");

    scanf("%c", &choice);

    switch (choice) {
        case '1':
            printf("\nYou explore the forest and find a beautiful waterfall.\n");
            score++;
            break;
        case '2':
            printf("\nYou search for treasure and find a chest full of gold!\n");
            score += 5;
            break;
        case '3':
            printf("\nYou encounter a fierce monster and defeat it!\n");
            score += 10;
            break;
        case '4':
            printf("\nThanks for playing! Your final score is: %d\n", score);
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }

    if (choice!= '4') {
        play_game();
    }
}

void end_game(int score) {
    printf("\nCongratulations! You have completed the game with a score of %d!\n", score);
    printf("Thanks for playing!\n");
    exit(0);
}