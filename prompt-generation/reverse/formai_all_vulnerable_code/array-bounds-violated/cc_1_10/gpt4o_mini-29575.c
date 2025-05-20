//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4  // 4x4 grid
#define MAX_TRIES 10

void initialize_board(char board[SIZE][SIZE], char display[SIZE][SIZE]);
void shuffle_cards(char board[SIZE][SIZE]);
void print_board(char display[SIZE][SIZE]);
int check_win(char display[SIZE][SIZE]);
void flip_card(char board[SIZE][SIZE], char display[SIZE][SIZE], int row, int col);
void clear_buffer();

int main() {
    char board[SIZE][SIZE], display[SIZE][SIZE];
    int first_row, first_col, second_row, second_col;
    int tries = 0;

    initialize_board(board, display);
    shuffle_cards(board);

    printf("Welcome to the Memory Game!\n");
    printf("You have %d tries to match all the cards.\n", MAX_TRIES);

    while (tries < MAX_TRIES) {
        print_board(display);
        
        printf("Pick the first card (row [0-%d] column [0-%d]): ", SIZE-1, SIZE-1);
        scanf("%d %d", &first_row, &first_col);
        flip_card(board, display, first_row, first_col);
        print_board(display);
        
        printf("Pick the second card (row [0-%d] column [0-%d]): ", SIZE-1, SIZE-1);
        scanf("%d %d", &second_row, &second_col);
        flip_card(board, display, second_row, second_col);
        print_board(display);
        
        if (board[first_row][first_col] == board[second_row][second_col]) {
            printf("Match found!\n");
        } else {
            printf("No match! Try again.\n");
            display[first_row][first_col] = '*';  // reset the display
            display[second_row][second_col] = '*'; // reset the display
        }
        
        tries++;

        if (check_win(display)) {
            printf("Congratulations! You've matched all the cards!\n");
            break;
        }
    }

    if (tries == MAX_TRIES) {
        printf("Game Over! You've used all your tries.\n");
    }

    printf("Thanks for playing!\n");
    return 0;
}

void initialize_board(char board[SIZE][SIZE], char display[SIZE][SIZE]) {
    char cards[SIZE*SIZE/2];
    for (int i = 0; i < SIZE*SIZE/2; i++) {
        cards[i] = 'A' + i;  // fill cards A, B, C, ...
    }

    for (int i = 0; i < SIZE*SIZE/2; i++) {
        board[i / SIZE][i % SIZE] = cards[i]; // put cards in board
        board[(i + SIZE*SIZE/2) / SIZE][(i + SIZE*SIZE/2) % SIZE] = cards[i]; // duplicate them
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            display[i][j] = '*';  // initialize display with '*'
        }
    }
}

void shuffle_cards(char board[SIZE][SIZE]) {
    srand(time(NULL));  // seed for random number generation
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r = rand() % SIZE, c = rand() % SIZE;
            char temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }
}

void print_board(char display[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", display[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int check_win(char display[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (display[i][j] == '*') {
                return 0;  // Not all cards matched
            }
        }
    }
    return 1;  // All cards matched
}

void flip_card(char board[SIZE][SIZE], char display[SIZE][SIZE], int row, int col) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
        display[row][col] = board[row][col]; // reveal the card
    } else {
        printf("Invalid card location. Please choose again.\n");
        clear_buffer();
    }
}

void clear_buffer() {
    while (getchar() != '\n');
}