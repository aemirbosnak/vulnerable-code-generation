//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_bingo(int* board, int size) {
    printf("BINGO!\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i] == j) {
                printf("* ");
            } else {
                printf("%d ", board[i]);
            }
        }
        printf("\n");
    }
}

void generate_board(int* board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i] = rand() % 75 + 1;
        }
    }
}

int main() {
    int size = 5;
    int board[5][5] = {0};
    int winning_combination[5] = {1, 2, 3, 4, 5};

    srand(time(0));
    generate_board(board, size);

    int current_number = 1;
    int drawn_number = 0;
    int current_board_value = 0;
    int winning_board_value = 0;

    while (drawn_number < size && current_board_value!= 75) {
        printf("Current number: %d\n", current_number);
        current_board_value += board[drawn_number - 1][current_number - 1];
        if (current_board_value == 75) {
            winning_board_value = 75;
            winning_board_value = winning_board_value + 1;
            print_bingo(board, size);
            printf("Congratulations, you have won!\n");
            break;
        } else {
            drawn_number++;
            current_number++;
            current_board_value = 0;
        }
    }

    if (winning_board_value == 75) {
        print_bingo(board, size);
        printf("Congratulations, you have won!\n");
    } else {
        printf("Sorry, you didn't win this time.\n");
    }

    return 0;
}