//FormAI DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

void print_board(char arr[][COLS], char arr_cpy[][COLS], int rows, int cols);
void shuffle_board(char arr[][COLS], int rows, int cols);
void check_match(char arr_cpy[][COLS], int row1, int col1, int row2, int col2);

int main() {
    char board[ROWS][COLS] = {{'A','B','C','D','E'},
                              {'F','G','H','I','J'},
                              {'K','L','M','N','O'},
                              {'P','Q','R','S','T'}};
    char board_copy[ROWS][COLS] = {{'*','*','*','*','*'},
                                   {'*','*','*','*','*'},
                                   {'*','*','*','*','*'},
                                   {'*','*','*','*','*'}};
    int row1, col1, row2, col2;
    shuffle_board(board, ROWS, COLS);
    print_board(board_copy, board_copy, ROWS, COLS);

    while(1) {
        printf("Enter the first coordinate: ");
        scanf("%d %d", &row1, &col1);

        printf("Enter the second coordinate: ");
        scanf("%d %d", &row2, &col2);

        if(row1 < 1 || col1 < 1 || row2 < 1 || col2 < 1 ||
           row1 > ROWS || col1 > COLS || row2 > ROWS || col2 > COLS) {
            printf("Invalid input, please enter coordinates between 1 and %d.\n\n", ROWS);
            continue;
        }

        if(board_copy[row1-1][col1-1] != '*' || board_copy[row2-1][col2-1] != '*') {
            printf("Coordinates already chosen, please choose different coordinates.\n\n");
            continue;
        }

        print_board(board_copy, board_copy, ROWS, COLS);

        check_match(board_copy, row1-1, col1-1, row2-1, col2-1);
        if(board_copy[row1-1][col1-1] != board_copy[row2-1][col2-1]) {
            sleep(2);
            system("clear");
            print_board(board_copy, board_copy, ROWS, COLS);
            board_copy[row1-1][col1-1] = '*';
            board_copy[row2-1][col2-1] = '*';
        }

        if(board_copy[0][0] != '*' && board_copy[0][1] != '*' &&
           board_copy[0][2] != '*' && board_copy[0][3] != '*' &&
           board_copy[0][4] != '*' && board_copy[1][0] != '*' &&
           board_copy[1][4] != '*' && board_copy[2][0] != '*' &&
           board_copy[2][4] != '*' && board_copy[3][0] != '*' &&
           board_copy[3][1] != '*' && board_copy[3][2] != '*' &&
           board_copy[3][3] != '*' && board_copy[3][4] != '*') {
            printf("Congratulations! You have won the game!\n");
            break;
        }
    }

    return 0;
}

void print_board(char arr[][COLS], char arr_cpy[][COLS], int rows, int cols) {
    system("clear");
    printf(" ");
    for(int i=1; i<=cols; i++) {
        printf("  %d", i);
    }
    printf("\n");

    for(int i=1; i<=rows; i++) {
        printf("%d|", i);
        for(int j=1; j<=cols; j++) {
            if(arr_cpy[i-1][j-1] == '*') {
                printf("  %c", arr[i-1][j-1]);
            } else {
                printf("   ");
            }
        }
        printf(" |\n");
    }
    printf(" ");
    for(int i=1; i<=cols; i++) {
        printf("  %d", i);
    }
    printf("\n\n");
}

void shuffle_board(char arr[][COLS], int rows, int cols) {
    srand(time(NULL));
    char temp;
    int rand_row, rand_col;

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            rand_row = rand() % rows;
            rand_col = rand() % cols;

            temp = arr[rand_row][rand_col];
            arr[rand_row][rand_col] = arr[i][j];
            arr[i][j] = temp;
        }
    }
}

void check_match(char arr_cpy[][COLS], int row1, int col1, int row2, int col2) {
    if(arr_cpy[row1][col1] == arr_cpy[row2][col2]) {
        printf("MATCHED!\n\n");
        arr_cpy[row1][col1] = arr_cpy[row2][col2] = '-';
    } else {
        printf("NOT MATCHED!\n\n");
    }
}