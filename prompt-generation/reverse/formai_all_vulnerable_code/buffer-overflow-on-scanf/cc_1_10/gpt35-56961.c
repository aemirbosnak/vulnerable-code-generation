//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 3

// Create the multi-dimensional array
char board[SIZE][SIZE];

// Define the player and AI symbols
char player = 'X';
char ai = 'O';

// Define the win combinations
int win[8][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};

// Define the move struct for the AI
typedef struct {
    int x;
    int y;
} Move;

// Initialize the board to be empty
void init_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the tic-tac-toe board
void display_board() {
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            printf(" %c |", board[i][j]);
        }

        printf(" %c ", board[i][SIZE - 1]);

        if (i < SIZE - 1) {
            printf("\n---+---+---\n");
        }
    }

    printf("\n\n");
}

// Check the board to see if it's a tie
int is_tie() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 1;
}

// Check the board for a winner
int check_winner(char symbol) {
    for (int i = 0; i < 8; i++) {
        int count = 0;

        for (int j = 0; j < 3; j++) {
            if (board[win[i][j] / SIZE][win[i][j] % SIZE] == symbol) {
                count++;
            }
        }

        if (count == 3) {
            return 1;
        }
    }

    return 0;
}

// Get the player's move
void *get_player_move(void *arg) {
    int *player_move = (int*) arg;
    int row, col;

    // Loop until we get a valid move
    while (1) {
        printf("Enter row number (1-%d): ", SIZE);
        scanf("%d", &row);

        printf("Enter column number (1-%d): ", SIZE);
        scanf("%d", &col);

        // Convert to zero-based index
        row--;
        col--;

        // Check if the move is valid
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            *player_move = row * SIZE + col;
            return NULL;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}

// Get the AI's move
void *get_ai_move(void *arg) {
    Move *ai_move = (Move*) arg;

    // Simulate thinking
    sleep(1);

    // Check if there is a winning move
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = ai;

                if (check_winner(ai)) {
                    ai_move->x = i;
                    ai_move->y = j;
                    board[i][j] = ' ';
                    return NULL;
                }

                board[i][j] = ' ';
            }
        }
    }

    // Check if the player has a winning move and block it
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;

                if (check_winner(player)) {
                    ai_move->x = i;
                    ai_move->y = j;
                    board[i][j] = ' ';
                    return NULL;
                }

                board[i][j] = ' ';
            }
        }
    }

    // Otherwise, make a random move
    do {
        ai_move->x = rand() % SIZE;
        ai_move->y = rand() % SIZE;
    } while (board[ai_move->x][ai_move->y] != ' ');

    return NULL;
}

int main() {
    int player_move, turn = 0;
    pthread_t tid;

    // Initialize the random number generator
    srand((unsigned)time(NULL));

    // Initialize the board
    init_board();

    // Display the board
    display_board();

    // Loop until there is a winner or a tie
    while (1) {
        // Get the player's move
        if (turn % 2 == 0) {
            printf("Player's turn (X):\n");
            pthread_create(&tid, NULL, get_player_move, &player_move);
            pthread_join(tid, NULL);

            // Update the board
            board[player_move / SIZE][player_move % SIZE] = player;
        }

        // Get the AI's move
        else {
            printf("AI's turn (O):\n");
            Move ai_move;
            pthread_create(&tid, NULL, get_ai_move, &ai_move);
            pthread_join(tid, NULL);

            // Update the board
            board[ai_move.x][ai_move.y] = ai;
        }

        // Display the board
        display_board();

        // Check if there is a winner
        if (check_winner(player)) {
            printf("Player wins!\n");
            break;
        } else if (check_winner(ai)) {
            printf("AI wins!\n");
            break;
        }

        // Check if there is a tie
        if (is_tie()) {
            printf("It's a tie!\n");
            break;
        }

        // Switch turns
        turn++;
    }

    return 0;
}