//FormAI DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 4
#define CARD_COUNT BOARD_SIZE*BOARD_SIZE/2

typedef struct _Card {
    int value;
    int revealed;
} Card;

typedef struct _Board {
    Card cards[BOARD_SIZE][BOARD_SIZE];
    int revealed_count;
} Board;

void print_board(Board* board);
void initialize_board(Board* board);
void shuffle_cards(int* cards, int card_count);
int is_game_over(Board* board);
int is_valid_input(Board* board, int x, int y);
void reveal_card(Board* board, int x, int y);
void play_game();

int main() {
    play_game();
    return 0;
}

void print_board(Board* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cards[i][j].revealed) {
                printf("%d ", board->cards[i][j].value);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void initialize_board(Board* board) {
    int cards[CARD_COUNT*2];
    for (int i = 0; i < CARD_COUNT*2; i++) {
        cards[i] = i % CARD_COUNT + 1;
    }
    shuffle_cards(cards, CARD_COUNT*2);
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->cards[i][j].value = cards[index/2];
            board->cards[i][j].revealed = 0;
            index++;
        }
    }
    board->revealed_count = 0;
}

void shuffle_cards(int* cards, int card_count) {
    srand(time(NULL));
    for (int i = 0; i < card_count/2; i++) {
        int j = rand() % card_count;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

int is_game_over(Board* board) {
    return board->revealed_count == BOARD_SIZE*BOARD_SIZE;
}

int is_valid_input(Board* board, int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        printf("Invalid input! Please enter numbers between 1 and %d.\n", BOARD_SIZE);
        return 0;
    } else if (board->cards[x][y].revealed) {
        printf("Card already revealed!\n");
        return 0;
    } else {
        return 1;
    }
}

void reveal_card(Board* board, int x, int y) {
    board->cards[x][y].revealed = 1;
    board->revealed_count++;
}

void play_game() {
    Board board;
    initialize_board(&board);
    printf("Welcome to the Memory Game!\n\n");
    while (!is_game_over(&board)) {
        print_board(&board);
        printf("Enter the coordinates of the card you want to reveal (e.g. '2 3'): ");
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        if (is_valid_input(&board, x, y)) {
            reveal_card(&board, x, y);
            if (board.revealed_count % 2 == 0) {
                int i, j;
                for (i = 0; i < BOARD_SIZE; i++) {
                    for (j = 0; j < BOARD_SIZE; j++) {
                        if (board.cards[i][j].revealed && board.cards[i][j].value == board.cards[x][y].value && (i != x || j != y)) {
                            printf("You found a matching pair!\n");
                            break;
                        }
                    }
                    if (j < BOARD_SIZE) {
                        break;
                    }
                }
                if (i == BOARD_SIZE) {
                    board.cards[x][y].revealed = 0;
                    board.revealed_count--;
                    printf("No match! Try again.\n");
                }
            }
        }
    }
    printf("Congratulations! You won the game!\n");
}