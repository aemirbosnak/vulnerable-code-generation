//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to check if all elements of a row are marked
int isRowMarked(int row, int card[ROWS][COLS]) 
{
    int col;
    for (col = 0; col < COLS; col++) 
    {
        if (card[row][col] == 0) // if an element is not marked
        {
            return 0; // return false
        }
    }
    return 1; // if all elements are marked, return true
}

// Function to check if all elements of a column are marked
int isColumnMarked(int col, int card[ROWS][COLS]) 
{
    int row;
    for (row = 0; row < ROWS; row++) 
    {
        if (card[row][col] == 0) // if an element is not marked
        {
            return 0; // return false
        }
    }
    return 1; // if all elements are marked, return true
}

// Function to check if either of the two diagonals are marked
int isDiagonalMarked(int card[ROWS][COLS]) 
{
    int row, col;
    int firstDiagonal = 1; // First diagonal that starts from top-left corner
    int secondDiagonal = 1; // Second diagonal that starts from top-right corner
    
    // Check first diagonal
    for (row = 0, col = 0; row < ROWS && col < COLS; row++, col++)
    {
        if (card[row][col] == 0) 
        {
            firstDiagonal = 0;
            break;
        }
    }
    
    // Check second diagonal
    for (row = 0, col = COLS-1; row < ROWS && col >= 0; row++, col--)
    {
        if (card[row][col] == 0) 
        {
            secondDiagonal = 0;
            break;
        }
    }
    
    // Return true only if either of the two diagonals are marked
    return (firstDiagonal || secondDiagonal);
}

// Function to print the bingo card
void printCard(int card[ROWS][COLS]) 
{
    int row, col;
    printf("-----------------\n");
    for (row = 0; row < ROWS; row++) 
    {
        printf("|");
        for (col = 0; col < COLS; col++) 
        {
            printf(" %d |", card[row][col]);
        }
        printf("\n-----------------\n");
    }
}

int main() 
{
    int card[ROWS][COLS] = {{0}};
    int i, num;
    srand(time(NULL)); // Initialize random seed
    
    // Fill the card with random numbers between 1 and 75
    for (i = 0; i < ROWS*COLS; i++) 
    {
        num = rand()%75 + 1; // Generate a random number between 1 and 75
        int row = num/15; // Calculate the row number for this number
        if (num % 15 == 0) 
        {
            row -= 1; // If a multiple of 15, decrement row number by 1
        }
        int col = (num-1) % 15; // Calculate the column number for this number
        card[row][col] = num; // Set the element in the card to this number
    }
    
    // Print the initial card
    printf("Your bingo card:\n");
    printCard(card);
    
    int numCalls = 0;
    int ball; // current ball number
    
    // Play the game
    while (1) 
    {
        printf("Enter the called ball number (or 0 to quit): ");
        scanf("%d", &ball);
        if (ball == 0) // If user enters 0, exit the game
        {
            break;
        }
        if (ball < 1 || ball > 75) // If user enters an invalid number, ask again
        {
            printf("Invalid number. Please enter a number between 1 and 75.\n");
            continue;
        }
        numCalls++; // Increment number of balls called
        printf("Ball %d!\n", ball);
        // Mark the called ball on the card
        for (i = 0; i < ROWS*COLS; i++) 
        {
            int row = i/15; // Calculate row number of element
            if (ball == card[row][(i-15*row)]) // If the element contains the called ball
            {
                card[row][(i-15*row)] = 0; // Mark the element (set to 0)
                break;
            }
        }
        // Print the new card
        printf("Updated card:\n");
        printCard(card);
        // Check if any row, column or diagonal is marked
        for (i = 0; i < ROWS; i++) 
        {
            if (isRowMarked(i, card)) 
            {
                printf("Bingo! Row %d is marked.\n", i+1);
                printf("Number of balls called: %d\n", numCalls);
                return 0; // Exit the game
            }
        }
        for (i = 0; i < COLS; i++) 
        {
            if (isColumnMarked(i, card)) 
            {
                printf("Bingo! Column %d is marked.\n", i+1);
                printf("Number of balls called: %d\n", numCalls);
                return 0; // Exit the game
            }
        }
        if (isDiagonalMarked(card)) 
        {
            printf("Bingo! A diagonal is marked.\n");
            printf("Number of balls called: %d\n", numCalls);
            return 0; // Exit the game
        }
    }
    
    printf("Thanks for playing. Goodbye!\n");
    
    return 0;
}