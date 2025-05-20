//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int n, i, j, flag;
    char choice;
    
    printf("Welcome to the Bingo Simulator! \n\n");
    
    do 
    {
        printf("Enter the number of players (2-6): ");
        scanf("%d", &n);
    } while (n < 2 || n > 6);
    
    int score[n], card[n][5][5]; // Initializing score and card arrays
    
    for (i=0; i<n; i++) 
    {
        for (j=0; j<5; j++) 
        {
            for (int k=0; k<5; k++) 
            {
                card[i][j][k] = 0; // Initializing each card with zero
            }
        }
    }
    
    srand(time(NULL)); // Seed for generating random numbers
    
    for (i=0; i<5; i++) 
    {
        for (j=0; j<5; j++) 
        {
            for (int k=0; k<n; k++) 
            {
                do 
                {
                    flag = 0; // Flag for checking if the number is already present in any card
                    
                    int num = rand()%15 + 1 + i*15; // Generate number between (1, 15), (16, 30), ...
                    
                    for (int l=0; l<5; l++) // Checking entire row of card
                    {
                        if (card[k][i][l] == num) // If number is already present in the row
                        {
                            flag = 1;
                            break;
                        }
                    }
                    
                    for (int l=0; l<5; l++) // Checking entire column of card
                    {
                        if (card[k][l][j] == num) // If number is already present in the column
                        {
                            flag = 1;
                            break;
                        }
                    }
                    
                    if (flag == 0) // If number is not present in the row or column, add it to the card
                    {
                        card[k][i][j] = num;
                    }
                } while (flag != 0); // Repeat until a new unique number is generated
            }
        }
    }
    
    printf("\n\nCards for each player:\n\n");
    
    for (i=0; i<n; i++)
    {
        for (j=0; j<5; j++)
        {
            for (int k=0; k<5; k++)
            {
                printf("%d\t", card[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    printf("\n");
    
    for (i=0; i<n; i++) 
    {
        score[i] = 0; // Initialize score of each player to zero
    }
    
    int num[75], x, y, count = 0, win = -1;
    
    for (i=0; i<75; i++) 
    {
        num[i] = i+1; // Assign numbers from 1 to 75
    }
    
    for (i=0; i<75; i++) // Shuffle the numbers array using Fisher-Yates algorithm
    {
        x = rand()%(i+1);
        y = num[i];
        num[i] = num[x];
        num[x] = y;
    }
    
    printf("\n\nLet's begin the game!\n\n");
    
    while (win == -1) // Continue game until someone wins
    {
        printf("Number drawn: %d\n\n", num[count]);
        
        for (i=0; i<n; i++) 
        {
            for (j=0; j<5; j++) 
            {
                for (int k=0; k<5; k++) 
                {
                    if (card[i][j][k] == num[count]) // If the drawn number is present in player's card
                    {
                        card[i][j][k] = -1; // Mark the number as 'drawn' for that player
                        score[i]++; // Increment the player's score
                    }
                }
            }
            
            if (score[i] == 5) // If player has all 5 numbers marked, he wins
            {
                printf("Player %d wins the game!\n\n", i+1);
                win = 1;
                break;
            }
        }
        
        count++; // Increment the count of drawn numbers
        
        if (count == 75 && win == -1) // If all numbers are drawn and no one wins
        {
            printf("All numbers have been drawn. It's a tie!\n\n");
            win = 0;
        }
        
        printf("Player\tScore\n\n");
        for (i=0; i<n; i++)
        {
            printf("%d\t%d\n", i+1, score[i]);
        }
        printf("\n\n");
    }
    
    do 
    {
        printf("Do you want to play again? (Y/N)");
        scanf(" %c", &choice);
        if (choice != 'Y' && choice != 'N' && choice != 'y' && choice != 'n') // Invalid choice
        {
            printf("Invalid choice. Try again.\n\n");
        }
    } while (choice != 'Y' && choice != 'N' && choice != 'y' && choice != 'n'); // Repeat until valid choice is entered
    
    if (choice == 'Y' || choice == 'y') // If user wants to play again, call the main function again
    {
        main();
    }
    else // Otherwise, exit the program
    {
        printf("\n\nThanks for playing!\n\n");
        exit(0);
    }
    
    return 0;
}