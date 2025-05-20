//FormAI DATASET v1.0 Category: Memory Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // Our game board is 4x4
#define MAX_ATTEMPTS 8 // The number of attempts to make a match

int generate_board(); // Function to generate a random board
void print_board(int board[][BOARD_SIZE]); // Function to print the game board
int is_match(int x1, int y1, int x2, int y2, int board[][BOARD_SIZE]); // Function to check if two cards match

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE]; // The game board
    int attempts = 0; // Counter for attempts
    int score = 0; // Player's score
    
    // Generate a random game board
    generate_board(board);
    
    // Keep playing until the player reaches the maximum number of attempts or all cards are matched
    while(attempts < MAX_ATTEMPTS && score < BOARD_SIZE*BOARD_SIZE/2)
    {
        printf("ATTEMPTS: %d\n", attempts+1);
        print_board(board);
        
        // Ask the player to select two cards
        int x1, y1, x2, y2;
        printf("Enter the row and column for the first card: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the row and column for the second card: ");
        scanf("%d %d", &x2, &y2);
        
        // Check if the selected cards are valid
        if(x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE || x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE)
        {
            printf("Invalid input!\n");
            continue;
        }
        
        // Check if the selected cards match
        if(is_match(x1, y1, x2, y2, board))
        {
            printf("Match found!\n");
            board[x1][y1] = 0;
            board[x2][y2] = 0;
            score++;
        }
        else
        {
            printf("No match found!\n");
            attempts++;
        }
    }
    
    // Print the final score
    printf("\nFinal score: %d\n", score);
    
    return 0;
}

int generate_board(int board[][BOARD_SIZE])
{
    int i, j, count;
    int cards[BOARD_SIZE*BOARD_SIZE/2];
    
    // Generate random cards and put them in a list
    for(i = 0; i < BOARD_SIZE*BOARD_SIZE/2; i++)
        cards[i] = rand() % 10 + 1; // Range: 1-10
    
    // Shuffle the cards using Fisher-Yates shuffle algorithm
    for(i = BOARD_SIZE*BOARD_SIZE/2-1; i > 0; i--)
    {
        j = rand() % (i+1);
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
    
    // Add the cards to the board
    count = 0;
    for(i = 0; i < BOARD_SIZE; i++)
        for(j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = cards[count/2];
            count++;
        }
}

void print_board(int board[][BOARD_SIZE])
{
    int i, j;
    
    printf("\n   ");
    for(i = 0; i < BOARD_SIZE; i++)
        printf("%d  ", i);
    printf("\n");
    
    for(i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d  ", i);
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == 0)
                printf(".  ");
            else
                printf("*  ");
        }
        printf("\n");
    }
}

int is_match(int x1, int y1, int x2, int y2, int board[][BOARD_SIZE])
{
    if(x1 == x2 && y1 == y2) // Same card
        return 0;
    if(board[x1][y1] == 0 || board[x2][y2] == 0) // Already matched card
        return 0;
    if(board[x1][y1] != board[x2][y2]) // Different numbers
        return 0;
    return 1; // Match found
}