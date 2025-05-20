//FormAI DATASET v1.0 Category: Memory Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void generateGame(int gameBoard[][SIZE]);
void printGame(int gameBoard[][SIZE], int row, int col);
void playGame(int gameBoard[][SIZE], int row1, int col1, int row2, int col2, int count, int *score, int visited[][SIZE]);
int checkWin(int gameBoard[][SIZE]);

int main()
{
    int gameBoard[SIZE][SIZE], visited[SIZE][SIZE] = {0}, row1, col1, row2, col2, count=0, score = 0;
    generateGame(gameBoard);
    printGame(gameBoard, 0, 0);
    printf("Welcome to Memory Game!\n\n");
    printf("Enter two positions to uncover the numbers.\n");
    printf("If the two numbers match, they will be removed from the board.\n");
    printf("The game ends when all the pairs have been removed.\n");
    printf("You need to finish the game in minimum moves possible.\n\n");
    playGame(gameBoard, row1, col1, row2, col2, count, &score, visited);
    printf("Congratulations! You won the game with %d moves.\n", score);

    return 0;
}

// Function to generate the game board with random numbers
void generateGame(int gameBoard[][SIZE])
{
    int arr[SIZE*SIZE/2], k = 0;
    for(int i=0; i<SIZE*SIZE/2; i++)
    {
        arr[i] = i+1;
    }
    srand(time(NULL));
    for (int i = SIZE*SIZE-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            gameBoard[i][j] = arr[k];
            k++;
        }
    }
}

// Function to print the game board
void printGame(int gameBoard[][SIZE], int row, int col)
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            if(i == row && j == col)
                printf("%d* ", gameBoard[i][j]);
            else
                printf("%d ", gameBoard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to play the game recursively
void playGame(int gameBoard[][SIZE], int row1, int col1, int row2, int col2, int count, int *score, int visited[][SIZE])
{
    printf("Enter position 1: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter position 2: ");
    scanf("%d %d", &row2, &col2);
    printf("\n");

    if(visited[row1][col1] == 1 || visited[row2][col2] == 1)
    {
        printf("One or both cells already uncovered!\n\n");
        playGame(gameBoard, row1, col1, row2, col2, count, score, visited);
    }
    else if(row1<0 || col1<0 || row1>=SIZE || col1>=SIZE || row2<0 || col2<0 || row2>=SIZE || col2>=SIZE)
    {
        printf("Invalid position entered!\n\n");
        playGame(gameBoard, row1, col1, row2, col2, count, score, visited);
    }
    else if(row1 == row2 && col1 == col2)
    {
        printf("Both positions cannot be same, please try again!\n\n");
        playGame(gameBoard, row1, col1, row2, col2, count, score, visited);
    }
    else if(gameBoard[row1][col1] != gameBoard[row2][col2])
    {
        printGame(gameBoard, row1, col1);
        visited[row1][col1] = 1;
        visited[row2][col2] = 1;
        count++;
        *score += count;
        playGame(gameBoard, row1, col1, row2, col2, count, score, visited);
    }
    else
    {
        printGame(gameBoard, row1, col1);
        visited[row1][col1] = 1;
        visited[row2][col2] = 1;
        gameBoard[row1][col1] = 0;
        gameBoard[row2][col2] = 0;
        count++;
        *score += count;
        int winner = checkWin(gameBoard);
        if(winner == 1)
            return;
        playGame(gameBoard, 0, 0, 0, 0, count, score, visited);

    }
}

// Function to check if all the pairs have been uncovered
int checkWin(int gameBoard[][SIZE])
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            if(gameBoard[i][j] != 0)
                return 0;
        }
    }
    return 1;
}