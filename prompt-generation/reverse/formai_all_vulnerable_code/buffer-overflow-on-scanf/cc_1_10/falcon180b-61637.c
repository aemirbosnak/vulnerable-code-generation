//Falcon-180B DATASET v1.0 Category: Table Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void init() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '0' + rand() % 9;
        }
    }
    srand(time(NULL));
}

void print_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void check_win() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            printf("Player %d wins!\n", i + 1);
            exit(0);
        }
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            printf("Player %d wins!\n", j + 1);
            exit(0);
        }
    }
}

void play() {
    int i, j;
    char choice;
    printf("Press 1 to start the game.\n");
    scanf("%c", &choice);
    if (choice!= '1') {
        printf("Invalid choice.\n");
        exit(1);
    }
    init();
    printf("Press a number to select your move.\n");
    scanf("%c", &choice);
    i = choice - '1';
    j = 0;
    while (j < BOARD_SIZE) {
        if (board[i][j] == '0') {
            board[i][j] = 'X';
            break;
        }
        j++;
    }
    print_board();
    check_win();
}

int main() {
    play();
    return 0;
}