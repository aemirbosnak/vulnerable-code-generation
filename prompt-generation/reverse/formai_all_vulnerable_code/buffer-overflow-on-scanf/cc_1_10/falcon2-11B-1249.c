//Falcon2-11B DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <time.h>

// Function to generate a random number between 0 and 9
int getRandomNumber() {
    return (rand() % 10);
}

int main() {
    // Set the seed for the random number generator
    srand(time(NULL));

    int playerScore = 0;
    int computerScore = 0;
    int choice = -1;

    while (choice!= 0) {
        // Print instructions
        printf("Welcome to the Game of Rock, Paper, Scissors!n");
        printf("Please choose one of the following options: \n");
        printf("0: Rock \n");
        printf("1: Paper \n");
        printf("2: Scissors \n");
        printf("0 to quit\n");

        // Get player's choice
        scanf("%d", &choice);

        // Check if the player chose to quit
        if (choice == 0) {
            printf("Game Over!\n");
            break;
        }

        // Generate a random number for the computer
        int computerChoice = getRandomNumber();

        // Compare the choices and update scores
        switch (computerChoice) {
            case 0:
                if (choice == 0) {
                    printf("Computer chose Rock.\n");
                    playerScore++;
                }
                else if (choice == 1) {
                    printf("Computer chose Paper.\n");
                    computerScore++;
                }
                else if (choice == 2) {
                    printf("Computer chose Scissors.\n");
                    playerScore++;
                }
                break;

            case 1:
                if (choice == 0) {
                    printf("Computer chose Paper.\n");
                    computerScore++;
                }
                else if (choice == 1) {
                    printf("Computer chose Scissors.\n");
                    playerScore++;
                }
                else if (choice == 2) {
                    printf("Computer chose Rock.\n");
                    computerScore++;
                }
                break;

            case 2:
                if (choice == 0) {
                    printf("Computer chose Scissors.\n");
                    playerScore++;
                }
                else if (choice == 1) {
                    printf("Computer chose Rock.\n");
                    computerScore++;
                }
                else if (choice == 2) {
                    printf("Computer chose Paper.\n");
                    playerScore++;
                }
                break;
        }
    }

    // Print the final scores
    printf("Player Score: %d\n", playerScore);
    printf("Computer Score: %d\n", computerScore);

    return 0;
}