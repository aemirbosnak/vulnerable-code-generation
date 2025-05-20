//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initBoard(char board[3][3]);
void printBoard(char board[3][3]);
int checkWin(char board[3][3]);
void swap(char* a, char* b);

int main() {
    int player = 1;
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    srand(time(NULL));
    int choice;

    do {
        system("clear");
        initBoard(board);
        printBoard(board);
        printf("\nPlayer %d's turn.\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 9 || board[choice/3][choice%3]!= (char)(choice + '0')) {
            printf("Invalid move! Try again.\n");
        } else {
            board[choice/3][choice%3] = (char)(player + '0');
            player = (player == 1)? 2 : 1;
        }
        if (checkWin(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }
    } while (1);

    return 0;
}

void initBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = (char)(i + j + '0');
        }
    }
}

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}