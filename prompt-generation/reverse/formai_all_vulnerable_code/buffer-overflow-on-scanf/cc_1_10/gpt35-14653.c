//FormAI DATASET v1.0 Category: Table Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TABLE_SIZE 9 // number of cells in the table

int table[TABLE_SIZE] = {0}; // initialize all cells to 0
int player_turn = 1; // player 1 starts the game
int game_over = 0; // game not over yet

/* function to display the table */
void print_table() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", table[i * 3 + j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* function to check if a move is valid */
int is_valid_move(int cell) {
    if (cell < 0 || cell >= TABLE_SIZE) {
        return 0;
    }
    if (table[cell] != 0) {
        return 0;
    }
    return 1;
}

/* function to check if the game is over */
int is_game_over() {
    // check horizontal lines
    for (int i = 0; i < 3; i++) {
        if (table[i*3] == table[i*3+1] && table[i*3+1] == table[i*3+2] && table[i*3] != 0) {
            return 1;
        }
    }
    // check vertical lines
    for (int i = 0; i < 3; i++) {
        if (table[i] == table[i+3] && table[i+3] == table[i+6] && table[i] != 0) {
            return 1;
        }
    }
    // check diagonal lines
    if (table[0] == table[4] && table[4] == table[8] && table[0] != 0) {
        return 1;
    }
    if (table[2] == table[4] && table[4] == table[6] && table[2] != 0) {
        return 1;
    }
    // check for tie game
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == 0) {
            return 0;
        }
    }
    return 2; // tie game
}

/* function for player to make a move */
void make_move(int cell, int player) {
    if (is_valid_move(cell)) {
        table[cell] = player;
        print_table();
        int game_result = is_game_over();
        if (game_result) {
            printf("Player %d wins!\n", player);
            game_over = 1;
            return;
        } else if (game_result == 2) {
            printf("Tie game!\n");
            game_over = 1;
            return;
        }
        player_turn = (player_turn == 1) ? 2 : 1;
    } else {
        printf("Invalid move!\n");
    }
}

/* function for player to take a turn */
void* player_turn_func(void* arg) {
    int player = *(int*)arg;
    while (!game_over) {
        if (player_turn == player) {
            printf("Player %d, enter cell (0-8): ", player);
            int cell;
            scanf("%d", &cell);
            make_move(cell, player);
        }
    }
    pthread_exit(NULL);
}

int main() {
    printf("Welcome to the Table Game!\n");
    print_table();
    // create two player threads
    pthread_t player1, player2;
    int player1_id = 1, player2_id = 2;
    pthread_create(&player1, NULL, player_turn_func, (void*)&player1_id);
    pthread_create(&player2, NULL, player_turn_func, (void*)&player2_id);
    // wait for game to end
    pthread_join(player1, NULL);
    pthread_join(player2, NULL);
    return 0;
}