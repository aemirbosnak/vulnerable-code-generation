//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define the board size
#define BOARD_SIZE 3

// Define the player symbols
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Define the game state
#define GAME_STATE_PLAYING 0
#define GAME_STATE_X_WIN 1
#define GAME_STATE_O_WIN 2
#define GAME_STATE_TIE 3

// Define the AI difficulty level
#define AI_DIFFICULTY_EASY 0
#define AI_DIFFICULTY_MEDIUM 1
#define AI_DIFFICULTY_HARD 2

// Create a struct to represent a game board
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int game_state;
} game_board;

// Create a function to initialize a game board
void initialize_game_board(game_board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = ' ';
        }
    }
    board->game_state = GAME_STATE_PLAYING;
}

// Create a function to print a game board
void print_game_board(game_board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
}

// Create a function to check if a player has won
int check_for_win(game_board *board, char player) {
    // Check for horizontal wins
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[i][0] == player && board->board[i][1] == player && board->board[i][2] == player) {
            return 1;
        }
    }

    // Check for vertical wins
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[0][j] == player && board->board[1][j] == player && board->board[2][j] == player) {
            return 1;
        }
    }

    // Check for diagonal wins
    if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player) {
        return 1;
    }
    if (board->board[0][2] == player && board->board[1][1] == player && board->board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Create a function to get the AI's move
int get_ai_move(game_board *board, int difficulty) {
    // Easy difficulty: Random move
    if (difficulty == AI_DIFFICULTY_EASY) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        while (board->board[row][col] != ' ') {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        }
        return row * BOARD_SIZE + col;
    }

    // Medium difficulty: Block the player from winning
    else if (difficulty == AI_DIFFICULTY_MEDIUM) {
        // Check for potential winning moves for the player
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board->board[i][j] == ' ') {
                    board->board[i][j] = PLAYER_X;
                    if (check_for_win(board, PLAYER_X)) {
                        board->board[i][j] = ' ';
                        return i * BOARD_SIZE + j;
                    }
                    board->board[i][j] = ' ';
                }
            }
        }

        // Check for potential winning moves for the AI
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board->board[i][j] == ' ') {
                    board->board[i][j] = PLAYER_O;
                    if (check_for_win(board, PLAYER_O)) {
                        board->board[i][j] = ' ';
                        return i * BOARD_SIZE + j;
                    }
                    board->board[i][j] = ' ';
                }
            }
        }

        // Random move
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        while (board->board[row][col] != ' ') {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        }
        return row * BOARD_SIZE + col;
    }

    // Hard difficulty: Use minimax algorithm to find the best move
    else if (difficulty == AI_DIFFICULTY_HARD) {
        // TODO: Implement minimax algorithm
        return -1;
    }

    return -1;
}

// Create a function to play the game
void play_game(int ai_difficulty) {
    // Initialize the game board
    game_board board;
    initialize_game_board(&board);

    // Print the initial game board
    print_game_board(&board);

    // While the game is still playing
    while (board.game_state == GAME_STATE_PLAYING) {
        // Get the player's move
        int row, col;
        printf("Enter your move (row, col): ");
        scanf("%d %d", &row, &col);

        // Check if the player's move is valid
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board.board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Place the player's symbol on the board
        board.board[row][col] = PLAYER_X;

        // Print the updated game board
        print_game_board(&board);

        // Check if the player has won
        if (check_for_win(&board, PLAYER_X)) {
            board.game_state = GAME_STATE_X_WIN;
            printf("Player X wins!\n");
            break;
        }

        // Get the AI's move
        int ai_move = get_ai_move(&board, ai_difficulty);

        // Check if the AI's move is valid
        if (ai_move < 0 || ai_move >= BOARD_SIZE * BOARD_SIZE || board.board[ai_move / BOARD_SIZE][ai_move % BOARD_SIZE] != ' ') {
            printf("Invalid AI move. Try again.\n");
            continue;
        }

        // Place the AI's symbol on the board
        board.board[ai_move / BOARD_SIZE][ai_move % BOARD_SIZE] = PLAYER_O;

        // Print the updated game board
        print_game_board(&board);

        // Check if the AI has won
        if (check_for_win(&board, PLAYER_O)) {
            board.game_state = GAME_STATE_O_WIN;
            printf("Player O wins!\n");
            break;
        }

        // Check if the game is a tie
        int tie = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board.board[i][j] == ' ') {
                    tie = 0;
                }
            }
        }
        if (tie) {
            board.game_state = GAME_STATE_TIE;
            printf("Tie game!\n");
            break;
        }
    }
}

// Main function
int main() {
    // Get the AI difficulty level from the user
    int ai_difficulty;
    printf("Enter the AI difficulty level (0 for easy, 1 for medium, 2 for hard): ");
    scanf("%d", &ai_difficulty);

    // Play the game
    play_game(ai_difficulty);

    return 0;
}