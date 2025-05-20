//FormAI DATASET v1.0 Category: Memory Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_MOVES 10

int board[BOARD_SIZE][BOARD_SIZE];
int flipped[BOARD_SIZE][BOARD_SIZE];
int num_moves = 0;
int num_paired = 0;
int completed = 0;

void generate_board()
{
    int size = BOARD_SIZE * BOARD_SIZE / 2;
    int pairs[size];
    int count = 0;
    
    for (int i = 1; i <= size; i++) {
        pairs[count++] = i;
        pairs[count++] = i; 
    }
    
    srand(time(NULL));
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int r = rand() % size;
            board[i][j] = pairs[r];
            pairs[r] = pairs[--size];
        }
    }
}

void print_board()
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (flipped[i][j]) {
                printf("%3d", board[i][j]);
            } else {
                printf("%3c", '-');
            }
        }
        printf("\n");
    }
}

void flip(int row, int col)
{
    if (!flipped[row][col]) {
        flipped[row][col] = 1;
        printf("Flip (%d, %d)\n", row+1, col+1);
        print_board();
        if (num_moves++ == MAX_MOVES) {
            printf("Maximum number of moves reached!\n");
            completed = 1;
        }
    }
}

void unflip(int row, int col)
{
    if (flipped[row][col]) {
        flipped[row][col] = 0;
        printf("Unflip (%d, %d)\n", row+1, col+1);
        print_board();
        num_moves--;
    }
}

int match(int r1, int c1, int r2, int c2)
{
    if (board[r1][c1] == board[r2][c2]) {
        printf("Pair found! (%d, %d) and (%d, %d)\n", r1+1, c1+1, r2+1, c2+1);
        num_paired++;
        if (num_paired == BOARD_SIZE * BOARD_SIZE / 2) {
            printf("Congratulations, you have completed the game in %d moves!\n", num_moves);
            completed = 1;
        }
        return 1;
    }
    return 0;
}

void run_game()
{
    while (!completed) {
        int r1, c1, r2, c2;
        printf("Enter first card coordinates: ");
        scanf("%d %d", &r1, &c1);
        r1--; c1--;
        flip(r1, c1);
        
        printf("Enter second card coordinates: ");
        scanf("%d %d", &r2, &c2);
        r2--; c2--;
        flip(r2, c2);
        
        if (board[r1][c1] != board[r2][c2]) {
            sleep(1);
            unflip(r1, c1);
            unflip(r2, c2);
        } else {
            match(r1, c1, r2, c2);
        }
    }
}

int main()
{
    generate_board();
    printf("Memory Game\n");
    print_board();
    run_game();
    return 0;
}