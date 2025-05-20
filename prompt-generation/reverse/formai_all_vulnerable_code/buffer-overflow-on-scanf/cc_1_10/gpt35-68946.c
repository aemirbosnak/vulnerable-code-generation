//FormAI DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void init_board(int board[][BOARD_SIZE]);
void print_board(int board[][BOARD_SIZE]);
void shuffle(int *array, size_t n);
int check_match(int x1, int y1, int x2, int y2, int board[][BOARD_SIZE]);

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);

    printf("Welcome to Memory Game!\n");
    printf("-----------------------\n\n");

    printf("Here is the board:\n\n");
    print_board(board);

    // shuffle the board
    int temp[BOARD_SIZE * BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        temp[i] = i / 2;
    }
    shuffle(temp, BOARD_SIZE * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = temp[i * BOARD_SIZE + j];
        }
    }

    int x1, y1, x2, y2;
    int matched_count = 0;
    while (matched_count < BOARD_SIZE * BOARD_SIZE / 2)
    {
        printf("\nEnter the positions of two cards to flip: ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE || x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE)
        {
            printf("\nInvalid position. Please enter valid positions.\n");
            continue;
        }

        if (check_match(x1, y1, x2, y2, board))
        {
            printf("\nMatched!\n");
            board[x1][y1] = -1;
            board[x2][y2] = -1;
            matched_count++;
        }
        else
        {
            printf("\nNot matched. Try again.\n");
        }

        printf("\nCurrent board:\n\n");
        print_board(board);
    }

    printf("\nCongratulations! You have completed the Memory Game!\n");

    return 0;
}

// Initialize the board with -1's to indicate unflipped cards
void init_board(int board[][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = -1;
        }
    }
}

// Print the current board
void print_board(int board[][BOARD_SIZE])
{
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d: ", i);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == -1)
            {
                printf("* ");
            }
            else
            {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

// Shuffle an array
// Implementation of Fisher–Yates shuffle algorithm
void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        for (size_t i = n - 1; i > 0; i--)
        {
            size_t j = rand() % (i + 1);
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
}

// Check whether the cards at (x1, y1) and (x2, y2) are a match.
// Return 1 if they are a match, 0 otherwise.
int check_match(int x1, int y1, int x2, int y2, int board[][BOARD_SIZE])
{
    if (board[x1][y1] == board[x2][y2])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}