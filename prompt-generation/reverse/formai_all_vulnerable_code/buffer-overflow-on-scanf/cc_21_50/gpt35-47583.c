//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int userChoice, computerChoice, flag = 1, userScore = 0, computerScore = 0;
    
    printf("Welcome to Rock-Paper-Scissors!\n");

    while (flag) {
    
        printf("\nChoose your weapon:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("4. Quit game\n");
        
        scanf("%d", &userChoice);

        switch(userChoice) {

            case 1: 
                printf("\nYou chose Rock!\n");
                break;

            case 2:
                printf("\nYou chose Paper!\n");
                break;

            case 3:
                printf("\nYou chose Scissors!\n");
                break;

            case 4:
                printf("\nThank you for playing!\n");
                flag = 0;
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                continue;
        }

        if (flag == 0) {
            break;
        }

        srand(time(NULL));
        computerChoice = rand() % 3 + 1;

        switch(computerChoice) {

            case 1: 
                printf("The computer chose Rock!\n");
                break;

            case 2:
                printf("The computer chose Paper!\n");
                break;

            case 3:
                printf("The computer chose Scissors!\n");
                break;

            default:
                printf("The computer has malfunctioned.\n");
                break;
        }

        if (userChoice == 1 && computerChoice == 3) {
            printf("\nRock crushes Scissors! You win!\n");
            userScore++;
        }
        else if (userChoice == 1 && computerChoice == 2) {
            printf("\nPaper covers Rock! You lose!\n");
            computerScore++;
        }
        else if (userChoice == 2 && computerChoice == 1) {
            printf("\nPaper covers Rock! You win!\n");
            userScore++;
        }
        else if (userChoice == 2 && computerChoice == 3) {
            printf("\nScissors cuts Paper! You lose!\n");
            computerScore++;
        }
        else if (userChoice == 3 && computerChoice == 1) {
            printf("\nRock crushes Scissors! You lose!\n");
            computerScore++;
        }
        else if (userChoice == 3 && computerChoice == 2) {
            printf("\nScissors cuts Paper! You win!\n");
            userScore++;
        }
        else {
            printf("\nIt's a tie!\n");
        }

        printf("\nScore:\n You: %d\n Computer: %d\n", userScore, computerScore);
    }

    return 0;
}