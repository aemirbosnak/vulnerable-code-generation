//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define the game board size and moves

#define BOARD_SIZE 3
#define PLAYER_1_MOVE 'X'
#define PLAYER_2_MOVE 'O'
#define EMPTY_SPACE '-'

// Define AI training variables and constants

#define LEARNING_RATE 0.1
#define DISCOUNT_FACTOR 0.9
#define MAX_EPISODES 10000
#define RANDOM_MOVE_CHANCE 0.1

// Define the game board struct

struct Board {
    char spaces[BOARD_SIZE][BOARD_SIZE];
};

// Declare functions for game play and AI training

int get_random_move(); 
int get_best_move(struct Board board, float q_values[][BOARD_SIZE], char player_move);
void update_q_values(struct Board board, float q_values[][BOARD_SIZE], float reward);
void train_ai();
void print_board(struct Board board);
void player_turn(struct Board *board, char move);
void ai_turn(struct Board *board, char move, float q_values[][BOARD_SIZE]);

int main() {
    // Initialize the game board and the AI's Q values
    struct Board board;
    float q_values[BOARD_SIZE * BOARD_SIZE][BOARD_SIZE] = {0};

    // Start the game loop
    while (1) {
        // Ask the user if they want to play or train the AI
        printf("Enter 1 to play the game or 2 to train the AI: ");
        int choice;
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) {
            // Play the game
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    board.spaces[i][j] = EMPTY_SPACE;
                }
            }

            print_board(board);

            for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
                if (i % 2 == 0) {
                    player_turn(&board, PLAYER_1_MOVE);
                } else {
                    player_turn(&board, PLAYER_2_MOVE);
                }

                print_board(board);

                if (i >= BOARD_SIZE*2-2) {
                    // Check for a win
                    for (int j = 0; j < BOARD_SIZE; j++) {
                        if (board.spaces[j][0] == board.spaces[j][1] && board.spaces[j][1] == board.spaces[j][2] && board.spaces[j][0] != EMPTY_SPACE) {
                            printf("%c wins!\n\n", board.spaces[j][0]);
                            goto endgame;
                        }
                        if (board.spaces[0][j] == board.spaces[1][j] && board.spaces[1][j] == board.spaces[2][j] && board.spaces[0][j] != EMPTY_SPACE) {
                            printf("%c wins!\n\n", board.spaces[0][j]);
                            goto endgame;
                        }
                    }
                    if (board.spaces[0][0] == board.spaces[1][1] && board.spaces[1][1] == board.spaces[2][2] && board.spaces[0][0] != EMPTY_SPACE) {
                        printf("%c wins!\n\n", board.spaces[0][0]);
                        goto endgame;
                    }
                    if (board.spaces[2][0] == board.spaces[1][1] && board.spaces[1][1] == board.spaces[0][2] && board.spaces[2][0] != EMPTY_SPACE) {
                        printf("%c wins!\n\n", board.spaces[2][0]);
                        goto endgame;
                    }
                }
            }

            // Check for a draw
            printf("The game is a draw!\n\n");
            endgame:
            continue;
        } else if (choice == 2) {
            // Train the AI
            train_ai(q_values);
        } else {
            printf("Invalid input!\n\n");
            continue;
        }
    }
}

void player_turn(struct Board *board, char move) {
    // Get the user's move and update the board
    int row, col;
    while (1) {
        printf("Enter the row and column of your move (0-%d): ", BOARD_SIZE-1);
        scanf("%d %d", &row, &col);
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            printf("Invalid input!\n");
            continue;
        }
        if (board->spaces[row][col] != EMPTY_SPACE) {
            printf("That space is already taken!\n");
            continue;
        }
        break;
    }

    board->spaces[row][col] = move;
}

void ai_turn(struct Board *board, char move, float q_values[][BOARD_SIZE]) {
    // Let the AI make a move and update the board and Q values
    int row, col;

    if ((float)rand()/(float)RAND_MAX < RANDOM_MOVE_CHANCE) {
        // Take a random move
        while (1) {
            row = get_random_move();
            col = get_random_move();
            if (board->spaces[row][col] == EMPTY_SPACE) {
                break;
            }
        }
    } else {
        // Use the Q values to make the best move
        int action = get_best_move(*board, q_values, move);
        row = action / BOARD_SIZE;
        col = action % BOARD_SIZE;
    }

    board->spaces[row][col] = move;

    update_q_values(*board, q_values, 0.0);
}

int get_random_move() {
    // Get a random move
    return rand() % BOARD_SIZE;
}

int get_best_move(struct Board board, float q_values[][BOARD_SIZE], char player_move) {
    // Get the best move according to current Q values
    int best_action = -1;
    float best_q_value = -9999.0;

    // If there is a winning move, take it
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board.spaces[i][j] == EMPTY_SPACE) {
                board.spaces[i][j] = player_move;

                for (int k = 0; k < BOARD_SIZE; k++) {
                    if ((board.spaces[k][0] == board.spaces[k][1] && board.spaces[k][1] == board.spaces[k][2] && board.spaces[k][0] != EMPTY_SPACE) ||
                        (board.spaces[0][k] == board.spaces[1][k] && board.spaces[1][k] == board.spaces[2][k] && board.spaces[0][k] != EMPTY_SPACE) ||
                        (board.spaces[0][0] == board.spaces[1][1] && board.spaces[1][1] == board.spaces[2][2] && board.spaces[0][0] != EMPTY_SPACE) ||
                        (board.spaces[2][0] == board.spaces[1][1] && board.spaces[1][1] == board.spaces[0][2] && board.spaces[2][0] != EMPTY_SPACE)) {

                        best_action = i*BOARD_SIZE + j;
                        best_q_value = 1.0;
                    }
                }

                board.spaces[i][j] = EMPTY_SPACE;
            }
        }
    }

    if (best_action != -1) {
        return best_action;
    }

    // Otherwise, take the move with the highest Q value
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board.spaces[i][j] == EMPTY_SPACE) {
                int action = i*BOARD_SIZE + j;
                float q_value = q_values[action][player_move == PLAYER_1_MOVE ? 0 : 1];
                if (q_value > best_q_value) {
                    best_q_value = q_value;
                    best_action = action;
                }
            }
        }
    }

    return best_action;
}

void update_q_values(struct Board board, float q_values[][BOARD_SIZE], float reward) {
    // Update the Q values according to the Bellman equation
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board.spaces[i][j] != EMPTY_SPACE) {
                int action = i*BOARD_SIZE + j;
                for (int k = 0; k < BOARD_SIZE; k++) {
                    q_values[action][k] = (1 - LEARNING_RATE)*q_values[action][k];
                }
                continue;
            }
            int action = i*BOARD_SIZE + j;
            float temp_q_values[BOARD_SIZE][BOARD_SIZE];
            for (int k = 0; k < BOARD_SIZE; k++) {
                for (int l = 0; l < BOARD_SIZE; l++) {
                    temp_q_values[k][l] = q_values[k*BOARD_SIZE+l][0];
                }
            }

            float max_q_value = -9999.0;
            for (int k = 0; k < BOARD_SIZE*BOARD_SIZE; k++) {
                if (temp_q_values[k/BOARD_SIZE][k%BOARD_SIZE] > max_q_value) {
                    max_q_value = temp_q_values[k/BOARD_SIZE][k%BOARD_SIZE];
                }
            }

            q_values[action][0] = q_values[action][0] + LEARNING_RATE*(reward + DISCOUNT_FACTOR*max_q_value - q_values[action][0]);
            q_values[action][1] = q_values[action][1] + LEARNING_RATE*(reward + DISCOUNT_FACTOR*max_q_value - q_values[action][1]);
        }
    }
}

void print_board(struct Board board) {
    // Print the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board.spaces[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void train_ai(float q_values[][BOARD_SIZE]) {
    // Train the AI using Q-learning
    for (int i = 0; i < MAX_EPISODES; i++) {
        // Initialize the board and the AI's moves
        struct Board board;
        for (int j = 0; j < BOARD_SIZE; j++) {
            for (int k = 0; k < BOARD_SIZE; k++) {
                board.spaces[j][k] = EMPTY_SPACE;
            }
        }
        char ai_move = PLAYER_1_MOVE;

        // Play the game until there is a winner or a draw
        for (int j = 0; j < BOARD_SIZE*BOARD_SIZE; j++) {
            if (j % 2 == 0) {
                ai_turn(&board, ai_move, q_values);
                if ((board.spaces[0][0] == board.spaces[1][1] && board.spaces[1][1] == board.spaces[2][2] && board.spaces[0][0] != EMPTY_SPACE) ||
                    (board.spaces[2][0] == board.spaces[1][1] && board.spaces[1][1] == board.spaces[0][2] && board.spaces[2][0] != EMPTY_SPACE) ||
                    (board.spaces[0][1] == board.spaces[1][1] && board.spaces[1][1] == board.spaces[2][1] && board.spaces[0][1] != EMPTY_SPACE) ||
                    (board.spaces[1][0] == board.spaces[1][1] && board.spaces[1][1] == board.spaces[1][2] && board.spaces[1][0] != EMPTY_SPACE)) {

                    update_q_values(board, q_values, 1.0);
                    break;
                }
            } else {
                ai_move = PLAYER_2_MOVE;
                ai_turn(&board, ai_move, q_values);
                if ((board.spaces[0][0] == board.spaces[1][1] && board.spaces[1][1] == board.spaces[2][2] && board.spaces[0][0] != EMPTY_SPACE) ||
                    (board.spaces[2][0] == board.spaces[1][1] && board.spaces[1][1] == board.spaces[0][2] && board.spaces[2][0] != EMPTY_SPACE) ||
                    (board.spaces[0][1] == board.spaces[1][1] && board.spaces[1][1] == board.spaces[2][1] && board.spaces[0][1] != EMPTY_SPACE) ||
                    (board.spaces[1][0] == board.spaces[1][1] && board.spaces[1][1] == board.spaces[1][2] && board.spaces[1][0] != EMPTY_SPACE)) {

                    update_q_values(board, q_values, -1.0);
                    break;
                }
            }
            if (j == BOARD_SIZE*BOARD_SIZE-1) {
                update_q_values(board, q_values, 0.0);
            }
        }
    }
}