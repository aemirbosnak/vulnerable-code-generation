//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// the board
char board[3][3];

// the player
char player = 'X';

// the AI
char ai = 'O';

// the winner
char winner = ' ';

// the game state
enum GameState {
    PLAYING,
    DRAW,
    X_WINS,
    O_WINS
};

// initialize the board
void init_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// print the board
void print_board() {
    printf("  1 2 3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// get the player's move
int get_player_move() {
    int move;
    while (1) {
        printf("Enter your move (1-9): ");
        scanf("%d", &move);
        if (move < 1 || move > 9) {
            printf("Invalid move!\n");
        } else if (board[(move - 1) / 3][(move - 1) % 3] != ' ') {
            printf("That square is already taken!\n");
        } else {
            return move;
        }
    }
}

// get the AI's move
int get_ai_move() {
    // TODO: implement the AI's move

    // for now, just return a random move
    srand(time(NULL));
    int move;
    do {
        move = rand() % 9 + 1;
    } while (board[(move - 1) / 3][(move - 1) % 3] != ' ');
    return move;
}

// check if the game is over
enum GameState check_game_over() {
    // check for a winner
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0] == 'X' ? X_WINS : O_WINS;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i] == 'X' ? X_WINS : O_WINS;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0] == 'X' ? X_WINS : O_WINS;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2] == 'X' ? X_WINS : O_WINS;
    }

    // check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return PLAYING;
            }
        }
    }

    return DRAW;
}

// play the game
void play_game() {
    init_board();

    while (1) {
        // print the board
        print_board();

        // get the player's move
        int move = get_player_move();

        // update the board
        board[(move - 1) / 3][(move - 1) % 3] = player;

        // check if the game is over
        enum GameState state = check_game_over();
        if (state != PLAYING) {
            break;
        }

        // get the AI's move
        move = get_ai_move();

        // update the board
        board[(move - 1) / 3][(move - 1) % 3] = ai;

        // check if the game is over
        state = check_game_over();
        if (state != PLAYING) {
            break;
        }
    }

    // print the final board
    print_board();

    // print the winner
    switch (winner) {
    case X_WINS:
        printf("X wins!\n");
        break;
    case O_WINS:
        printf("O wins!\n");
        break;
    case DRAW:
        printf("Draw!\n");
        break;
    }
}

int main() {
    play_game();

    return 0;
}