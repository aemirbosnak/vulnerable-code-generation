//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define NUM_CARDS 16

struct card {
    int value;
    int matched;
};

void init_board(struct card board[BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i].value = i + 1;
        board[i].matched = 0;
    }
}

void shuffle_cards(struct card deck[NUM_CARDS]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_board(struct card board[BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i].matched) {
            printf("%d ", board[i].value);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int find_match(struct card board[BOARD_SIZE], int card1, int card2) {
    if (board[card1].value == board[card2].value) {
        return 1;
    }
    return 0;
}

int main() {
    struct card deck[NUM_CARDS];
    init_board(deck);
    shuffle_cards(deck);

    struct card board[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i].value = -1;
        board[i].matched = 0;
    }

    int moves = 0;
    while (1) {
        system("clear");
        print_board(board);
        printf("Moves: %d\n", moves);

        int choice1, choice2;
        printf("Choose two cards: ");
        scanf("%d %d", &choice1, &choice2);

        if (choice1 < 0 || choice1 >= BOARD_SIZE || choice2 < 0 || choice2 >= BOARD_SIZE) {
            printf("Invalid choice.\n");
            continue;
        }

        if (board[choice1].value == -1 || board[choice2].value == -1) {
            printf("Card not revealed.\n");
            continue;
        }

        if (find_match(board, choice1, choice2)) {
            board[choice1].matched = 1;
            board[choice2].matched = 1;
            moves++;
        } else {
            board[choice1].matched = 0;
            board[choice2].matched = 0;
            moves = 0;
        }

        if (moves == 8) {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}