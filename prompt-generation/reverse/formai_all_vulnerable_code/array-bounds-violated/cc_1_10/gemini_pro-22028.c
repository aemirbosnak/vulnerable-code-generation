//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 3

// player types
#define HUMAN 1
#define AI 2

// game state
#define PLAYING 0
#define DRAW 1
#define WIN 2

// winning combinations
int winning_combinations[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
};

// game board
char board[SIZE][SIZE];

// current player
int current_player;

// game state
int game_state;

// function to initialize the game
void init_game() {
    // clear the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // set the current player to human
    current_player = HUMAN;

    // set the game state to playing
    game_state = PLAYING;
}

// function to print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if a player has won
int check_win() {
    // check if any of the winning combinations are present on the board
    for (int i = 0; i < 8; i++) {
        if (board[winning_combinations[i][0]][winning_combinations[i][1]] == board[winning_combinations[i][1]][winning_combinations[i][2]] &&
            board[winning_combinations[i][1]][winning_combinations[i][2]] == board[winning_combinations[i][2]][winning_combinations[i][0]] &&
            board[winning_combinations[i][0]][winning_combinations[i][1]] != ' ') {
            return WIN;
        }
    }

    // check if the game is a draw
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == SIZE * SIZE) {
        return DRAW;
    }

    // otherwise, the game is still playing
    return PLAYING;
}

// function to get the AI's move
int get_ai_move() {
    // find all possible moves
    int possible_moves[SIZE * SIZE];
    int num_possible_moves = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                possible_moves[num_possible_moves++] = i * SIZE + j;
            }
        }
    }

    // if there are no possible moves, return -1
    if (num_possible_moves == 0) {
        return -1;
    }

    // evaluate each possible move
    int best_move = -1;
    int best_score = -10000;
    for (int i = 0; i < num_possible_moves; i++) {
        // make the move
        int move = possible_moves[i];
        board[move / SIZE][move % SIZE] = 'O';

        // check the game state
        int score = minimax(0, AI);

        // undo the move
        board[move / SIZE][move % SIZE] = ' ';

        // update the best move and score
        if (score > best_score) {
            best_move = move;
            best_score = score;
        }
    }

    return best_move;
}

// function to perform minimax
int minimax(int depth, int player) {
    // check the game state
    int game_state = check_win();

    // if the game is over, return the score
    if (game_state == WIN) {
        if (player == HUMAN) {
            return -10;
        } else {
            return 10;
        }
    } else if (game_state == DRAW) {
        return 0;
    }

    // find all possible moves
    int possible_moves[SIZE * SIZE];
    int num_possible_moves = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                possible_moves[num_possible_moves++] = i * SIZE + j;
            }
        }
    }

    // if there are no possible moves, return the score
    if (num_possible_moves == 0) {
        return 0;
    }

    // evaluate each possible move
    int best_score;
    if (player == HUMAN) {
        best_score = -10000;
        for (int i = 0; i < num_possible_moves; i++) {
            // make the move
            int move = possible_moves[i];
            board[move / SIZE][move % SIZE] = 'X';

            // recursively call minimax
            int score = minimax(depth + 1, AI);

            // undo the move
            board[move / SIZE][move % SIZE] = ' ';

            // update the best score
            if (score > best_score) {
                best_score = score;
            }
        }
    } else {
        best_score = 10000;
        for (int i = 0; i < num_possible_moves; i++) {
            // make the move
            int move = possible_moves[i];
            board[move / SIZE][move % SIZE] = 'O';

            // recursively call minimax
            int score = minimax(depth + 1, HUMAN);

            // undo the move
            board[move / SIZE][move % SIZE] = ' ';

            // update the best score
            if (score < best_score) {
                best_score = score;
            }
        }
    }

    return best_score;
}

// main function
int main() {
    // initialize the game
    init_game();

    // print the welcome message
    printf("Welcome to Tic Tac Toe!\n");

    // game loop
    while (game_state == PLAYING) {
        // print the game board
        print_board();

        // get the player's move
        int move;
        if (current_player == HUMAN) {
            printf("Enter your move (1-9): ");
            scanf("%d", &move);
            move--;
        } else {
            move = get_ai_move();
        }

        // check if the move is valid
        while (move < 0 || move >= SIZE * SIZE || board[move / SIZE][move % SIZE] != ' ') {
            printf("Invalid move. Please enter a valid move (1-9): ");
            scanf("%d", &move);
            move--;
        }

        // make the move
        if (current_player == HUMAN) {
            board[move / SIZE][move % SIZE] = 'X';
        } else {
            board[move / SIZE][move % SIZE] = 'O';
        }

        // check the game state
        game_state = check_win();

        // switch the current player
        current_player = (current_player == HUMAN) ? AI : HUMAN;
    }

    // print the game board
    print_board();

    // print the game result
    if (game_state == WIN) {
        if (current_player == HUMAN) {
            printf("Congratulations! You win!\n");
        } else {
            printf("Sorry, you lose.\n");
        }
    } else {
        printf("Draw!\n");
    }

    return 0;
}