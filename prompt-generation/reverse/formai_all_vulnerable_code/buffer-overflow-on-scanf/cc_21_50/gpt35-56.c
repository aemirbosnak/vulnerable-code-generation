//FormAI DATASET v1.0 Category: Game ; Style: systematic
#include<stdio.h>

int main()
{
    int playerChoice, computerChoice, playerScore=0, computerScore=0, rounds=1;
    printf("Welcome to Rock Paper Scissors!\n");
    
    while(rounds<=5)
    {
        printf("\nRound %d\n", rounds);
        printf("Enter 1 for rock, 2 for paper, 3 for scissors: ");
        scanf("%d", &playerChoice);

        // Generate a random number for the computer's choice
        computerChoice = rand()%3 + 1;

        // Display the choices
        switch(playerChoice)
        {
            case 1:
                printf("You chose rock.\n");
                break;
            case 2:
                printf("You chose paper.\n");
                break;
            case 3:
                printf("You chose scissors.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                continue;
        }

        switch(computerChoice)
        {
            case 1:
                printf("The computer chose rock.\n");
                break;
            case 2:
                printf("The computer chose paper.\n");
                break;
            case 3:
                printf("The computer chose scissors.\n");
                break;
        }

        if((playerChoice == 1 && computerChoice == 3) || (playerChoice == 2 && computerChoice == 1) || (playerChoice == 3 && computerChoice == 2))
        {
            printf("You win!\n");
            playerScore++;
        }
        else if((computerChoice == 1 && playerChoice == 3) || (computerChoice == 2 && playerChoice == 1) || (computerChoice == 3 && playerChoice == 2))
        {
            printf("The computer wins!\n");
            computerScore++;
        }
        else {
            printf("It's a tie!\n");
        }

        rounds++;
    }

    printf("\nFinal score:\n");
    printf("You: %d\n", playerScore);
    printf("Computer: %d\n", computerScore);

    if(playerScore > computerScore)
    {
        printf("Congratulations, you win!");
    }
    else if(playerScore < computerScore)
    {
        printf("Better luck next time, the computer wins!");
    }
    else {
        printf("It's a tie!");
    }

    return 0;
}