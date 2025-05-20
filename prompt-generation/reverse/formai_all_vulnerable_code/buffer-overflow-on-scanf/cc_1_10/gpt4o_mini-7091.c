//GPT-4o-mini DATASET v1.0 Category: Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
int rollDice();
void playGame();
void displayResults(int playerScore, int computerScore);

int main() {
    srand(time(NULL)); // Seed the random number generator
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                printf("Thank you for playing!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}

void displayMenu() {
    printf("\n--- Dice Roll Game ---\n");
    printf("1. Play Game\n");
    printf("2. Exit\n");
}

int rollDice() {
    return (rand() % 6) + 1; // Simulate a dice roll (1-6)
}

void playGame() {
    int playerScore = 0;
    int computerScore = 0;
    char choice;

    printf("Welcome to the Dice Roll Game!\n");

    while (1) {
        playerScore += rollDice();
        printf("You rolled! Your current score: %d\n", playerScore);

        // Checking if the player wants to continue
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'n' || choice == 'N') {
            break;
        }

        computerScore += rollDice();
        printf("Computer rolled! Computer's current score: %d\n\n", computerScore);
    }

    displayResults(playerScore, computerScore);
}

void displayResults(int playerScore, int computerScore) {
    printf("\n--- Game Over ---\n");
    printf("Your final score: %d\n", playerScore);
    printf("Computer's final score: %d\n", computerScore);

    if (playerScore > computerScore) {
        printf("Congratulations! You win!\n");
    } else if (playerScore < computerScore) {
        printf("The computer wins! Better luck next time!\n");
    } else {
        printf("It's a tie! What a close game!\n");
    }
}