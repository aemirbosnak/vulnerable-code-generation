//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_NAME_LENGTH 20
#define MAX_PLAYERS 10
#define BOARD_SIZE 10
#define MAX_MOVES 50

// Struct to store player information
typedef struct Player {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

// Struct to store move information
typedef struct Move {
    int row;
    int col;
    char symbol;
} Move;

// Global variables
Player players[MAX_PLAYERS];
int num_players = 0;
char board[BOARD_SIZE][BOARD_SIZE];
Move moves[MAX_MOVES];
int num_moves = 0;

// Function to initialize the board
void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

// Function to print the board
void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get a random move
Move get_random_move() {
    Move move;
    move.row = rand() % BOARD_SIZE;
    move.col = rand() % BOARD_SIZE;
    move.symbol = 'X';
    return move;
}

// Thread function for AI player
void* ai_player(void* args) {
    while (num_moves < MAX_MOVES) {
        Move move = get_random_move();
        moves[num_moves] = move;
        num_moves++;
    }
    pthread_exit(NULL);
}

// Function to get a user move
Move get_user_move() {
    Move move;
    printf("Enter row and column (0-%d): ", BOARD_SIZE-1);
    scanf("%d %d", &move.row, &move.col);
    getchar();
    printf("Enter symbol (X or O): ");
    scanf("%c", &move.symbol);
    getchar();
    return move;
}

// Thread function for human player
void* human_player(void* args) {
    int player_num = *(int*)args;
    while (num_moves < MAX_MOVES) {
        printf("Player %d, make your move:\n", player_num);
        Move move = get_user_move();
        moves[num_moves] = move;
        num_moves++;
    }
    pthread_exit(NULL);
}

// Function to update the board with moves
void update_board() {
    for (int i = 0; i < num_moves; i++) {
        board[moves[i].row][moves[i].col] = moves[i].symbol;
    }
}

// Function to calculate and update player scores
void update_scores() {
    for (int i = 0; i < num_players; i++) {
        players[i].score = 0;
        for (int j = 0; j < num_moves; j++) {
            if (moves[j].symbol == 'X' && strcmp(players[i].name, "AI") == 0) {
                players[i].score++;
            } else if (moves[j].symbol == 'O' && strcmp(players[i].name, "AI") != 0) {
                players[i].score++;
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    // Initialize board
    init_board();

    // Get number of players
    while (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Enter number of players (1-%d): ", MAX_PLAYERS);
        scanf("%d", &num_players);
        getchar();
    }

    // Get player names
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d name (max %d characters): ", i+1, MAX_NAME_LENGTH);
        fgets(players[i].name, MAX_NAME_LENGTH, stdin);
        players[i].name[strlen(players[i].name)-1] = '\0'; // Remove newline character from fgets
        players[i].score = 0;
    }

    // Create threads for players
    pthread_t players_threads[num_players];
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, "AI") == 0) {
            pthread_create(&players_threads[i], NULL, ai_player, NULL);
        } else {
            pthread_create(&players_threads[i], NULL, human_player, &i);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < num_players; i++) {
        pthread_join(players_threads[i], NULL);
    }

    // Update board with moves
    update_board();

    // Update player scores
    update_scores();

    // Print final scores
    printf("Final scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}