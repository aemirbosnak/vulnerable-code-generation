//FormAI DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define TOTAL_CARDS 8

void shuffle_cards(int cards[]) {
    for (int i = TOTAL_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

int initialize_board(int board[][BOARD_SIZE], int cards[]) {
    int card_count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = cards[card_count++];
        }
    }
    return card_count;
}

void print_board(int board[][BOARD_SIZE], int flipped_cards[][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (flipped_cards[i][j]) {
                printf("%d\t", board[i][j]);
            } else {
                printf("*\t");
            }
        }
        printf("\n");
    }
}

int are_all_cards_flipped(int flipped_cards[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!flipped_cards[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int cards[TOTAL_CARDS * 2];
    for (int i = 0; i < TOTAL_CARDS; i++) {
        cards[2 * i] = i + 1;
        cards[2 * i + 1] = i + 1;
    }
    shuffle_cards(cards);

    int board[BOARD_SIZE][BOARD_SIZE];
    int flipped_cards[BOARD_SIZE][BOARD_SIZE] = {0};
    int card_count = initialize_board(board, cards);

    printf("Welcome to Memory Game!\n");
    printf("You need to flip the cards and match them in pairs.\n");
    printf("You win when all the cards on the board are flipped!\n\n");

    print_board(board, flipped_cards);

    while (1) {
        int card_1_x, card_1_y, card_2_x, card_2_y;

        printf("\nEnter the row and column of the first card to flip (separated by space): ");
        scanf("%d %d", &card_1_x, &card_1_y);

        if (card_1_x < 1 || card_1_x > BOARD_SIZE || card_1_y < 1 || card_1_y > BOARD_SIZE) {
            printf("Invalid input! Please try again.\n");
            continue;
        }

        if (flipped_cards[card_1_x - 1][card_1_y - 1]) {
            printf("Card is already flipped! Please try again.\n");
            continue;
        }

        flipped_cards[card_1_x - 1][card_1_y - 1] = 1;
        print_board(board, flipped_cards);

        printf("\nEnter the row and column of the second card to flip (separated by space): ");
        scanf("%d %d", &card_2_x, &card_2_y);

        if (card_2_x < 1 || card_2_x > BOARD_SIZE || card_2_y < 1 || card_2_y > BOARD_SIZE) {
            printf("Invalid input! Please try again.\n");
            flipped_cards[card_1_x - 1][card_1_y - 1] = 0;
            continue;
        }

        if (flipped_cards[card_2_x - 1][card_2_y - 1]) {
            printf("Card is already flipped! Please try again.\n");
            flipped_cards[card_1_x - 1][card_1_y - 1] = 0;
            continue;
        }

        flipped_cards[card_2_x - 1][card_2_y - 1] = 1;
        print_board(board, flipped_cards);

        if (board[card_1_x - 1][card_1_y - 1] != board[card_2_x - 1][card_2_y - 1]) {
            printf("\nSorry, the cards do not match! Please try again.\n");
            flipped_cards[card_1_x - 1][card_1_y - 1] = 0;
            flipped_cards[card_2_x - 1][card_2_y - 1] = 0;
        } else {
            printf("\nGreat job! You found a match!\n");
        }

        if (are_all_cards_flipped(flipped_cards)) {
            printf("\n\nCongratulations! You won the game!\n");
            break;
        }
    }

    return 0;
}