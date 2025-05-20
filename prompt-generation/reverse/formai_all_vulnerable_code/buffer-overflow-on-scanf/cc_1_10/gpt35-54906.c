//FormAI DATASET v1.0 Category: Table Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS]; // tic tac toe board
int player = 1; // start with player 1
int choices = 0; // keep track of number of available choices
pthread_mutex_t lock; // mutex lock for thread synchronization

/* Initialize the board with underscores */
void init_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '_';
            choices++; // increment available choice count
        }
    }
}

/* Display the current state of the board */
void display_board() {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

/* Check if the given player has won */
int check_win(int p) {
    char symbol = (p == 1) ? 'x' : 'o'; // player 1 has 'x', player 2 has 'o'
    if ((board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) ||
        (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol) ||
        (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol) ||
        (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) ||
        (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol) ||
        (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol) ||
        (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return 1; // player has won
    }
    return 0; // player has not won
}

/* Make the move for the current player */
void make_move(int r, int c) {
    if (board[r][c] == '_') {
        char symbol = (player == 1) ? 'x' : 'o'; // player 1 has 'x', player 2 has 'o'
        board[r][c] = symbol;
        choices--; // decrement available choice count
    }
}

/* Function to execute the game */
void* start_game(void* arg) {
    int i = *((int*)arg); // get player number from argument
    while (choices > 0) { // continue playing until all choices used up
        printf("Player %d's turn\n", i);
        int r, c;
        do {
            printf("Enter row and column (0-2): ");
            scanf("%d %d", &r, &c);
        } while (r < 0 || r > 2 || c < 0 || c > 2); // repeat until valid row and column entered
        pthread_mutex_lock(&lock);
        make_move(r, c); // make the move for the current player
        display_board(); // display the current state of the board
        if (check_win(i)) {
            printf("Player %d wins!\n", i);
            break; // exit loop if player has won
        }
        player = (player == 1) ? 2 : 1; // change to other player
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL); // exit thread
}

int main() {
    pthread_t threads[2];
    int rc1, rc2;
    int player1 = 1;
    int player2 = 2;
    init_board(); // initialize the game board
    display_board(); // display the initial state of the board
    rc1 = pthread_create(&threads[0], NULL, start_game, (void*)&player1); // create thread for player 1
    rc2 = pthread_create(&threads[1], NULL, start_game, (void*)&player2); // create thread for player 2
    if (rc1 || rc2) { // error checking for thread creation
        printf("Error: Unable to create threads!\n");
        exit(-1);
    }
    pthread_join(threads[0], NULL); // join thread for player 1
    pthread_join(threads[1], NULL); // join thread for player 2
    printf("Game Over!\n");
    return 0;
}