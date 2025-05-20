//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Colors
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"

// Game Board
char board[3][3];

// Game State
enum { PLAYING, WON, DRAW };
int state = PLAYING;

// Player Turn
int turn = 1;

// Winning Combinations
int winning_combinations[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
};

// Initialize Game Board
void init_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print Game Board
void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                printf(RED " X " RESET);
            } else if (board[i][j] == 'O') {
                printf(GREEN " O " RESET);
            } else {
                printf(BLUE "   " RESET);
            }
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

// Get Player Move
int get_move() {
    int move;
    printf("Player %d, enter your move (1-9): ", turn);
    scanf("%d", &move);
    return move - 1;
}

// Check if Move is Valid
int is_valid_move(int move) {
    return move >= 0 && move < 9 && board[move / 3][move % 3] == ' ';
}

// Make Player Move
void make_move(int move) {
    if (turn == 1) {
        board[move / 3][move % 3] = 'X';
    } else {
        board[move / 3][move % 3] = 'O';
    }
}

// Check if Game is Over
int check_game_over() {
    // Check for Winning Combinations
    for (int i = 0; i < 8; i++) {
        if (board[winning_combinations[i][0] / 3][winning_combinations[i][0] % 3] != ' ' &&
            board[winning_combinations[i][0] / 3][winning_combinations[i][0] % 3] ==
                board[winning_combinations[i][1] / 3][winning_combinations[i][1] % 3] &&
            board[winning_combinations[i][0] / 3][winning_combinations[i][0] % 3] ==
                board[winning_combinations[i][2] / 3][winning_combinations[i][2] % 3]) {
            return WON;
        }
    }

    // Check for Draw
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == 9) {
        return DRAW;
    }

    return PLAYING;
}

// Play Game
void play_game() {
    init_board();

    while (state == PLAYING) {
        print_board();

        int move = get_move();
        while (!is_valid_move(move)) {
            printf("Invalid move. Try again.\n");
            move = get_move();
        }

        make_move(move);

        state = check_game_over();

        turn = 3 - turn;
    }

    print_board();

    if (state == WON) {
        printf(YELLOW "Player %d wins!" RESET, 3 - turn);
    } else if (state == DRAW) {
        printf(MAGENTA "Draw!" RESET);
    }
}

int main() {
    srand(time(NULL));

    // Play the game
    play_game();

    return 0;
}