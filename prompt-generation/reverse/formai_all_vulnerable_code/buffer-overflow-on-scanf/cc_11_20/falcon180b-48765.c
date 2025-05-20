//Falcon-180B DATASET v1.0 Category: Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int playerScore = 0;
    int computerScore = 0;

    char choice;
    int userChoice;

    do {
        system("clear");
        printf("Welcome to the Game!\n");
        printf("You will play against the computer.\n");
        printf("Choose Rock, Paper or Scissors.\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case 'r':
            case 'R':
                userChoice = 0;
                break;
            case 'p':
            case 'P':
                userChoice = 1;
                break;
            case's':
            case 'S':
                userChoice = 2;
                break;
            default:
                printf("Invalid input. Please try again.\n");
                continue;
        }

        int computerChoice = rand() % 3;

        if(userChoice == computerChoice) {
            printf("It's a tie!\n");
        } else if((userChoice == 0 && computerChoice == 2) || (userChoice == 1 && computerChoice == 0) || (userChoice == 2 && computerChoice == 1)) {
            printf("You win this round!\n");
            playerScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
        }

        printf("Score: You - %d, Computer - %d\n", playerScore, computerScore);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    return 0;
}