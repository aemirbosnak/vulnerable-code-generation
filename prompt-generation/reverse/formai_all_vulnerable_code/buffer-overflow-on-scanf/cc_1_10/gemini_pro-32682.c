//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare the game board
char board[3][3];

// Declare the player symbols
char player1_symbol = 'X';
char player2_symbol = 'O';

// Declare the game state
enum game_state {
    GAME_IN_PROGRESS,
    PLAYER1_WON,
    PLAYER2_WON,
    TIE
};

// Initialize the game board
void init_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Get the player's move
int get_move(char player_symbol) {
    int move;
    while (1) {
        printf("Player %c's turn: ", player_symbol);
        scanf("%d", &move);
        if (move < 1 || move > 9) {
            printf("Invalid move. Please enter a number between 1 and 9.\n");
        } else {
            break;
        }
    }
    return move;
}

// Place the player's symbol on the board
void place_symbol(int move, char player_symbol) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (board[row][col] == ' ') {
        board[row][col] = player_symbol;
    } else {
        printf("Invalid move. The space is already occupied.\n");
    }
}

// Check if the game is over
enum game_state check_game_over() {
    // Check for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0] == player1_symbol ? PLAYER1_WON : PLAYER2_WON;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i] == player1_symbol ? PLAYER1_WON : PLAYER2_WON;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0] == player1_symbol ? PLAYER1_WON : PLAYER2_WON;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2] == player1_symbol ? PLAYER1_WON : PLAYER2_WON;
    }

    // Check for a tie
    int num_empty_spaces = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                num_empty_spaces++;
            }
        }
    }
    if (num_empty_spaces == 0) {
        return TIE;
    }

    // The game is still in progress
    return GAME_IN_PROGRESS;
}

// Play the game
void play_game() {
    // Initialize the game board
    init_board();

    // Print the game board
    print_board();

    // Get the players' names
    char player1_name[20];
    char player2_name[20];
    printf("Player 1's name: ");
    scanf("%s", player1_name);
    printf("Player 2's name: ");
    scanf("%s", player2_name);

    // Set the current player
    char current_player = player1_symbol;

    // Loop until the game is over
    while (check_game_over() == GAME_IN_PROGRESS) {
        // Get the player's move
        int move = get_move(current_player);

        // Place the player's symbol on the board
        place_symbol(move, current_player);

        // Print the game board
        print_board();

        // Switch the current player
        current_player = current_player == player1_symbol ? player2_symbol : player1_symbol;
    }

    // Print the game result
    enum game_state game_result = check_game_over();
    switch (game_result) {
        case PLAYER1_WON:
            printf("%s wins!\n", player1_name);
            break;
        case PLAYER2_WON:
            printf("%s wins!\n", player2_name);
            break;
        case TIE:
            printf("Tie game!\n");
            break;
    }
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Play the game
    play_game();

    return 0;
}