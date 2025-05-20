//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

// Function to check if there is any cell left to play or not
int check_win(char board[3][3], char mark) {
    int i, j, count = 0;

    // Check horizontal lines
    for(i=0; i<3; i++) {
        if(board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
            count++;
        }
    }

    // Check vertical lines
    for(j=0; j<3; j++) {
        if(board[0][j] == mark && board[1][j] == mark && board[2][j] == mark) {
            count++;
        }
    }

    // Check diagonal lines
    if(board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
        count++;
    }
    if(board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
        count++;
    }

    return count;
}

// Function to check if there is any cell left to play or not
int check_draw(char board[3][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == '\0') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to get the user input and update the board
void get_input(char board[3][3]) {
    int i, j;
    printf("Enter your move (row and column): ");
    scanf("%d%d", &i, &j);
    if(board[i-1][j-1] == '\0') {
        board[i-1][j-1] = 'X';
    } else {
        printf("Sorry, this cell is already occupied.\n");
        get_input(board);
    }
}

// Function to check if the user has won or not
void check_win_lose(char board[3][3], char mark) {
    int win_count = check_win(board, mark);
    int draw_count = check_draw(board);

    if(win_count > 0) {
        printf("Congratulations! You won.\n");
        exit(0);
    } else if(draw_count == 1) {
        printf("It's a draw.\n");
        exit(0);
    }
}

int main() {
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char mark = 'X';
    int player = 1;
    int i, j;

    while(1) {
        system("clear");
        printf("Player %d's turn\n", player);
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        get_input(board);
        check_win_lose(board, mark);
        player++;
        if(player > 2) {
            player = 1;
        }
    }

    return 0;
}