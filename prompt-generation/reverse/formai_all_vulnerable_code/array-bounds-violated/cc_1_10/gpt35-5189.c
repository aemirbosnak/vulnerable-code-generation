//FormAI DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void print_board(char board[][COLS], int rows, int cols);
void shuffle_board(char board[][COLS], int rows, int cols);
void clear_screen();

int main()
{
    char board[ROWS][COLS] = {'A','B','C','D','E','F','G','H','A','B','C','D','E','F','G','H'};
    int score = 0;
    int attempts = 0;
    int first_choice_row, first_choice_col, second_choice_row, second_choice_col;

    srand(time(0));
    shuffle_board(board, ROWS, COLS);
    print_board(board, ROWS, COLS);

    do {
        printf("Score: %d\tAttempts: %d\n", score, attempts);
        printf("Enter the row and column numbers of the first choice (e.g. 1 2): ");
        scanf("%d %d", &first_choice_row, &first_choice_col);
        clear_screen();
        printf("Enter the row and column numbers of the second choice (e.g. 3 4): ");
        scanf("%d %d", &second_choice_row, &second_choice_col);
        clear_screen();

        printf("You chose %c at (%d,%d) and %c at (%d,%d)\n\n",board[first_choice_row-1][first_choice_col-1], first_choice_row, first_choice_col, board[second_choice_row-1][second_choice_col-1], second_choice_row, second_choice_col);

        if(board[first_choice_row-1][first_choice_col-1] == board[second_choice_row-1][second_choice_col-1]) {
            printf("You made a match!\n");
            board[first_choice_row-1][first_choice_col-1] = ' ';
            board[second_choice_row-1][second_choice_col-1] = ' ';
            score += 5;
        }
        else {
            printf("Sorry, not a match.\n");
            score -= 2;
        }

        attempts++;
        print_board(board, ROWS, COLS);

    } while(score < 40);

    printf("Congratulations, you won the game with a score of %d in %d attempts!\n", score, attempts);

    return 0;
}

void print_board(char board[][COLS], int rows, int cols)
{
    printf("  ");
    for(int i = 1; i <= rows; i++)
        printf("%d ", i);
    printf("\n");

    for(int i = 0; i < rows; i++) {
        printf("%d ", i+1);
        for(int j = 0; j < cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void shuffle_board(char board[][COLS], int rows, int cols)
{
    int i, j, temp_row, temp_col;
    char temp;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            temp = board[i][j];
            temp_row = rand() % rows;
            temp_col = rand() % cols;
            board[i][j] = board[temp_row][temp_col];
            board[temp_row][temp_col] = temp;
        }
    }
}

void clear_screen()
{
    system("clear");
}