//FormAI DATASET v1.0 Category: Table Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player1_score = 0, player2_score = 0;
    int die1, die2, sum;
    char player1_name[20], player2_name[20];
    
    // Get player names
    printf("Enter player 1 name: ");
    scanf("%s", player1_name);
    
    printf("Enter player 2 name: ");
    scanf("%s", player2_name);
    
    // Seed random number generator
    srand(time(NULL));
    
    // Loop for 5 rounds
    for(int i=1; i<=5; i++)
    {
        printf("\n-----Round %d-----\n", i);
        
        // Player 1's turn
        printf("%s's turn. Press enter to roll the dice.", player1_name);
        getchar(); // Wait for user to press enter
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
        sum = die1 + die2;
        
        printf("You rolled %d and %d for a total of %d.\n", die1, die2, sum);
        
        if(sum % 2 == 0) // Even sum
        {
            player1_score += 10;
            printf("Congratulations, you scored 10 points for rolling an even sum!\n");
        }
        else if(die1 == die2) // Doubles
        {
            player1_score += 5;
            printf("Congratulations, you scored 5 points for rolling doubles!\n");
        }
        else // Odd sum
        {
            printf("Sorry, no points scored for rolling an odd sum.\n");
        }
        
        printf("%s's score: %d\n", player1_name, player1_score);
        
        // Player 2's turn
        printf("\n%s's turn. Press enter to roll the dice.", player2_name);
        getchar(); // Wait for user to press enter
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
        sum = die1 + die2;
        
        printf("You rolled %d and %d for a total of %d.\n", die1, die2, sum);
        
        if(sum % 2 == 0) // Even sum
        {
            player2_score += 10;
            printf("Congratulations, you scored 10 points for rolling an even sum!\n");
        }
        else if(die1 == die2) // Doubles
        {
            player2_score += 5;
            printf("Congratulations, you scored 5 points for rolling doubles!\n");
        }
        else // Odd sum
        {
            printf("Sorry, no points scored for rolling an odd sum.\n");
        }
        
        printf("%s's score: %d\n", player2_name, player2_score);
    }
    
    // Determine winner
    if(player1_score > player2_score)
    {
        printf("\n%s wins with a score of %d!", player1_name, player1_score);
    }
    else if(player2_score > player1_score)
    {
        printf("\n%s wins with a score of %d!", player2_name, player2_score);
    }
    else // Tie
    {
        printf("\nIt's a tie with a score of %d each!", player1_score);
    }
    
    return 0;
}