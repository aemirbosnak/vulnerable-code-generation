//FormAI DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10
#define BOARD_SIZE 16

void print_board(int board[]);
void shuffle_board(int board[]);
int get_choice();
void make_move(int board[], int choice1, int choice2);

int main() {
    int board[BOARD_SIZE];
    int num_pairs = BOARD_SIZE / 2;
    int matches_remaining = num_pairs;
    int choice1, choice2;

    // Initialize board with pairs of numbers
    for (int i = 0; i < num_pairs; i++) {
        board[i] = i + 1;
        board[i + num_pairs] = i + 1;
    }

    shuffle_board(board);
    print_board(board);

    // Game loop
    while(matches_remaining > 0) {
        printf("Choose first card: ");
        choice1 = get_choice();
        printf("Choose second card: ");
        choice2 = get_choice();

        make_move(board, choice1, choice2);
        print_board(board);

        if (board[choice1] == board[choice2]) {
            printf("Match found!\n");
            matches_remaining--;
        } else {
            printf("No match found. Try again.\n");
        }
    }

    printf("Congratulations, you won!\n");
    return 0;
}

void print_board(int board[]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("[%d] ", board[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

void shuffle_board(int board[]) {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        int j = rand() % BOARD_SIZE;
        int temp = board[i];
        board[i] = board[j];
        board[j] = temp;
    }
}

int get_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

void make_move(int board[], int choice1, int choice2) {
    int temp = board[choice1];
    board[choice1] = board[choice2];
    board[choice2] = temp;
}