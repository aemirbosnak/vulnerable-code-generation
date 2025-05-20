//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define BOARD_SIZE 3

int arr[MAX_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

void print_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void check_win() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {
            printf("Player %d wins!\n", arr[0][i]);
            exit(0);
        }
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
            printf("Player %d wins!\n", arr[0][0]);
            exit(0);
        }
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
        printf("Player %d wins!\n", arr[0][0]);
        exit(0);
    }
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
        printf("Player %d wins!\n", arr[0][2]);
        exit(0);
    }
}

void play_game() {
    int player = 1;
    int choice;
    while (1) {
        system("clear");
        print_board();
        printf("Player %d's turn\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 9) {
            printf("Invalid choice!\n");
            continue;
        }
        if (arr[0][choice-1]!= 0) {
            printf("Cell already chosen!\n");
            continue;
        }
        arr[0][choice-1] = player;
        player++;
        if (player > 2) {
            player = 1;
        }
        check_win();
    }
}

int main() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            arr[i][j] = 0;
        }
    }
    play_game();
    return 0;
}