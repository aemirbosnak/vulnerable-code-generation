//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to clear the console
void clearScreen(void)
{
    printf("\033[H\033[J");
}

// Function to print the game menu
void printMenu(void)
{
    printf("************************\n");
    printf("**   GUESS THE WORD   **\n");
    printf("************************\n\n");
    printf("1. Play Game\n");
    printf("2. Exit\n\n");
    printf("Enter your choice: ");
}

// Function to print the game status and prompt player for guess
void printStatus(char *word, int length, char *guessed)
{
    int i;
    printf("Word: ");
    for (i = 0; i < length; i++) {
        if (guessed[i] == '1') {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n\n");
    printf("Enter your guess: ");
}

int main(void)
{
    // Declare variables
    int choice, i, length, guesses = 0, correct = 0, isGuessed;
    char words[][10] = {"hello", "world", "apple", "banana", "carrot", "orange"};
    char word[10], letter, guessed[10];
    srand(time(NULL));

    // Show menu
    do {
        clearScreen();
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Choose a random word
                length = rand() % 6 + 1;
                for (i = 0; i < length; i++) {
                    word[i] = words[rand() % 6][i];
                    guessed[i] = '0';
                }
                clearScreen();
                // Play game
                do {
                    printStatus(word, length, guessed);
                    scanf(" %c", &letter);
                    isGuessed = 0;
                    for (i = 0; i < length; i++) {
                        if (word[i] == letter && guessed[i] == '0') {
                            guessed[i] = '1';
                            correct++;
                            isGuessed = 1;
                        }
                    }
                    if (!isGuessed) {
                        guesses++;
                    }
                } while (correct < length && guesses < 6);
                // Show result
                clearScreen();
                printf("The word was: ");
                for (i = 0; i < length; i++) {
                    printf("%c", word[i]);
                }
                printf("\n\n");
                if (correct == length) {
                    printf("Congratulations! You won!\n");
                } else {
                    printf("Sorry, you lost! Better luck next time!\n");
                }
                printf("Press Enter to continue...");
                getchar();
                getchar();
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                printf("Press Enter to continue...");
                getchar();
                getchar();
        }
    } while (choice != 2);

    return 0;
}