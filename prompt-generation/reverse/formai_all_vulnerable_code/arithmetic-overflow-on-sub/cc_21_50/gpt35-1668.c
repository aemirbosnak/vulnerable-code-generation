//FormAI DATASET v1.0 Category: Checkers Game ; Style: funny
#include <stdio.h> 

int main() {
    // Welcome to the most epic Checkers Game!
    printf("Welcome to the most epic Checkers Game ever!\n");

    // Let's start by prompting the user to input their name
    printf("Please enter your name: ");
    char name[50];
    scanf("%s", name);
    printf("Welcome to the game, %s!\n", name);

    // Now let's get some information about the game
    printf("\nBefore we start playing, please provide some information:\n");

    // Number of pieces each player will start with
    printf("\nHow many pieces should each player start with? ");
    int starting_pieces;
    scanf("%d", &starting_pieces);

    // Board size
    printf("\nWhat should be the size of the board? ");
    int board_size;
    scanf("%d", &board_size);

    // Now, we can start the game
    printf("\nLet's start the game!\n");

    // We'll randomly choose which player will go first
    int random_number = rand() % 2;
    char* first_player;
    if (random_number == 0) {
        first_player = "Player 1";
    } else {
        first_player = "Player 2";
    }

    // Display the starting player
    printf("\n%s will go first!\n", first_player);

    // Let's set up the board
    int board[board_size][board_size];
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if ((i+j) % 2 == 0) {
                board[i][j] = 0;
            } else if (i < starting_pieces/2) {
                board[i][j] = 1;
            } else if (i >= board_size - starting_pieces/2) {
                board[i][j] = 2;
            } else {
                board[i][j] = 0;
            }
        }
    }

    // Let's print out the board
    printf("\nHere's the starting board:\n\n");
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // We'll take turns until someone wins or we reach a draw
    int winner = 0;
    int turn_counter = 0;
    while (!winner && turn_counter < board_size*board_size) {
        // First, we'll print out whose turn it is
        if (turn_counter % 2 == 0) {
            printf("\n%s's turn\n", first_player);
        } else if (random_number == 0) {
            printf("\n%s's turn\n", "Player 2");
        } else {
            printf("\n%s's turn\n", "Player 1");
        }
        
        // Let's prompt the player to make their move
        printf("\nPlease enter the position of the piece you want to move (row column): ");
        int from_x, from_y;
        scanf("%d %d", &from_x, &from_y);
        printf("Please enter the position you want to move to (row column): ");
        int to_x, to_y;
        scanf("%d %d", &to_x, &to_y);

        // Check if the move is valid
        if (board[from_x][from_y] == 0 || board[to_x][to_y] != 0) {
            printf("\nInvalid move!\n");
        } else if (abs(to_x - from_x) == abs(to_y - from_y)) {
            if (abs(to_x - from_x) == 1 && abs(to_y - from_y) == 1) {
                // Simple move
                board[to_x][to_y] = board[from_x][from_y];
                board[from_x][from_y] = 0;
                turn_counter++;
            } else if (abs(to_x - from_x) == 2 && abs(to_y - from_y) == 2) {
                // Capture move
                int capture_x = (from_x + to_x) / 2;
                int capture_y = (from_y + to_y) / 2;
                if (board[capture_x][capture_y] == 0) {
                    printf("\nInvalid move - no piece to capture!\n");
                } else if (board[capture_x][capture_y] == board[from_x][from_y]) {
                    printf("\nInvalid move - cannot capture own piece!\n");
                } else {
                    board[to_x][to_y] = board[from_x][from_y];
                    board[from_x][from_y] = 0;
                    board[capture_x][capture_y] = 0;
                    turn_counter++;
                }
            } else {
                printf("\nInvalid move - piece can only move one or two spaces diagonally!\n");
            }
        } else {
            printf("\nInvalid move - piece can only move diagonally!\n");
        }

        // Print the updated board
        printf("\nBoard after move:\n\n");
        for (int i = 0; i < board_size; i++) {
            for (int j = 0; j < board_size; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Check if someone won or we reached a draw
        if (turn_counter % 2 == 0) {
            winner = 2;
        } else {
            winner = 1;
        }
        for (int i = 0; i < board_size; i++) {
            for (int j = 0; j < board_size; j++) {
                if (board[i][j] == 1) {
                    winner = 0;
                } else if (board[i][j] == 2) {
                    winner = 0;
                }
            }
        }
    }

    // Check who won or if it was a draw
    if (winner == 0) {
        printf("\nIt's a draw!\n");
    } else {
        printf("\nCongratulations, %s! You are the winner!\n", winner == 1 ? "Player 1" : "Player 2");
    }

    return 0;
}