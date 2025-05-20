//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player_choice, computer_choice, player_score = 0, computer_score = 0, round = 1;
    srand(time(0)); // seed the random number generator with current time
    
    while(round <= 10) // play 10 rounds
    {
        printf("Round %d:\n", round);
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &player_choice);
        
        if(player_choice < 1 || player_choice > 3)
        {
            printf("Invalid choice!\n\n");
            continue; // skip to next iteration of loop
        }
        
        computer_choice = rand() % 3 + 1; // computer randomly chooses between 1 and 3
        
        printf("Computer chooses ");
        switch(computer_choice)
        {
            case 1:
                printf("Rock.\n");
                break;
            case 2:
                printf("Paper.\n");
                break;
            case 3:
                printf("Scissors.\n");
                break;
        }
        
        // compare choices and update scores
        if(player_choice == computer_choice)
        {
            printf("Draw! No points awarded.\n\n");
        }
        else if((player_choice == 1 && computer_choice == 3) ||
                (player_choice == 2 && computer_choice == 1) ||
                (player_choice == 3 && computer_choice == 2))
        {
            printf("You win this round!\n");
            player_score++;
        }
        else
        {
            printf("Computer wins this round!\n");
            computer_score++;
        }
        
        // print current scores
        printf("Your score: %d\n", player_score);
        printf("Computer's score: %d\n\n", computer_score);
        
        round++;
    }
    
    // print final result
    printf("Final score:\n");
    printf("Your score: %d\n", player_score);
    printf("Computer's score: %d\n", computer_score);
    
    if(player_score > computer_score)
    {
        printf("Congratulations, you win!\n");
    }
    else if(player_score < computer_score)
    {
        printf("Sorry, you lose.\n");
    }
    else
    {
        printf("It's a draw!\n");
    }
    
    return 0;
}