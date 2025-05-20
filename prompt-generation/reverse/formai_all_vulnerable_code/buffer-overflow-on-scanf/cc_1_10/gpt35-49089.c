//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void initialize_board(int board[][3]);
void print_board(int board[][3]);
int check_winner(int board[][3], int player);
void play_game();

int main() {
    srand(time(NULL)); // initialize random seed

    printf("Welcome to the Tic-Tac-Toe game!\n");
    printf("---------------------------------\n");

    int option;
    do {
        printf("Select an option:\n");
        printf("1. Play game\n");
        printf("2. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                play_game(); // start game
                break;
            case 2:
                printf("Thanks for playing!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }

    } while(option != 2);

    return 0;
}

void initialize_board(int board[][3]) {
    // set all board elements to 0
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board(int board[][3]) {
    printf("\n    1   2   3\n");
    printf("  +---+---+---+\n");
    for(int i=0; i<3; i++) {
        printf("%d | ", i+1);
        for(int j=0; j<3; j++) {
            if(board[i][j] == 0) {
                printf("  | ");
            } else if(board[i][j] == 1) {
                printf("X | ");
            } else {
                printf("O | ");
            }
        }
        printf("\n");
        printf("  +---+---+---+\n");
    }
    printf("\n");
}

int check_winner(int board[][3], int player) {
    // check for horizontal win
    for(int i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return player;
        }
    }

    // check for vertical win
    for(int j=0; j<3; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return player;
        }
    }

    // check for diagonal win
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return player;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return player;
    }

    return 0; // no winner yet
}

void play_game() {
    int board[3][3];
    initialize_board(board);
    print_board(board);

    int player = 1;
    int row, col;

    // game loop
    while(1) {
        // get row and column from player
        printf("Player %d's turn (enter row and column): ", player);
        scanf("%d %d", &row, &col);

        // check if valid row and column are entered
        if(row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid row or column! Please try again.\n");
            continue;
        }

        // check if the cell is already occupied
        if(board[row-1][col-1] != 0) {
            printf("Cell already occupied! Please try again.\n");
            continue;
        }

        // mark the cell as owned by the player
        board[row-1][col-1] = player;

        // print the updated board
        print_board(board);

        // check if a winner has emerged
        int winner = check_winner(board, player);
        if(winner == player) {
            printf("Player %d wins!\n", player);
            break;
        }

        // check if game is a draw
        int count = 0; // count number of occupied cells
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] != 0) {
                    count++;
                }
            }
        }
        if(count == 9) {
            printf("Game is a draw!\n");
            break;
        }

        // switch to other player for next turn
        if(player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }
}