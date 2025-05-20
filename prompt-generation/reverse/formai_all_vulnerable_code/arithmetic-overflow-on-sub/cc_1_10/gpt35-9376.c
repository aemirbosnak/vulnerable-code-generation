//FormAI DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define ROWS 4
#define COLUMNS 4

void init_board(int board[ROWS][COLUMNS]);
void print_board(int board[ROWS][COLUMNS]);
void shuffle(int *array, size_t n);
int check_win(int board[ROWS][COLUMNS]);
void swap(int *a, int *b);

int main() 
{ 
    int board[ROWS][COLUMNS], guess1, guess2, row1, row2, col1, col2, count = 0;
    init_board(board);
    shuffle((int*)board, ROWS*COLUMNS);
    printf("\nHere's the board: \n");
    print_board(board);

    while(!check_win(board)) {
        printf("\nGuess a card: ");
        scanf("%d", &guess1); 
        row1 = (guess1-1) / ROWS;
        col1 = (guess1-1) % COLUMNS;

        printf("Guess another card: "); 
        scanf("%d", &guess2); 
        row2 = (guess2-1) / ROWS;
        col2 = (guess2-1) % COLUMNS;

        if(board[row1][col1] == board[row2][col2] && guess1 != guess2) 
        { 
            printf("You found a match! \n"); 
            board[row1][col1] = -1; 
            board[row2][col2] = -1; 
            count++;
            print_board(board);
        } 
        else 
        { 
            printf("Sorry, try again.\n"); 
        } 
    } 

    printf("\nCongratulations! You won in %d attempts!", count);
    return 0; 
} 

void init_board(int board[ROWS][COLUMNS]) 
{ 
    int num = 1;
    for(int i = 0; i < ROWS; i++) 
    { 
        for(int j = 0; j < COLUMNS; j++) 
        { 
            board[i][j] = num; 
            num++; 
        } 
    } 
} 

void print_board(int board[ROWS][COLUMNS]) 
{ 
    for(int i = 0; i < ROWS; i++) 
    { 
        for(int j = 0; j < COLUMNS; j++) 
        { 
            if(board[i][j] == -1) 
            { 
                printf(" \t"); 
            } 
            else 
            { 
                printf("%d\t", board[i][j]); 
            } 
        } 
        printf("\n"); 
    } 
} 

void shuffle(int *array, size_t n) 
{ 
    if(n > 1) 
    { 
        size_t i; 
        for(i = 0; i < n - 1; i++) 
        { 
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1); 
            swap(&array[i], &array[j]); 
        } 
    } 
} 

int check_win(int board[ROWS][COLUMNS]) 
{ 
    for(int i = 0; i < ROWS; i++) 
    { 
        for(int j = 0; j < COLUMNS; j++) 
        { 
            if(board[i][j] != -1) 
            { 
                return 0; 
            } 
        } 
    } 
    return 1; 
} 

void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}