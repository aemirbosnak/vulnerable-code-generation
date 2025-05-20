//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: peaceful
#include <stdio.h>

/* Function to check if there is a winning move for the given player */
int is_win(char *board, char player) {
    if ((board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)) {
        return 1;
    }
    return 0;
}

/* Function to print the tic-tac-toe board on the console */
void print_board(char *board) {
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

/* Function to make a move for the given player */
void make_move(char *board, int position, char player) {
    board[position] = player;
}

/* Function to clone the current board */
void clone_board(char *src, char *dest) {
    for (int i=0; i<9; i++) {
        dest[i] = src[i];
    }
}

/* Function to return the optimal move for the given player */
int get_optimal_move(char *board, char player) {

    char temp_board[9];
    int move_value;
    int best_move = -1;
    int best_value = -2;

    for (int i=0; i<9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            clone_board(board, temp_board);  // Clone the current board
            make_move(temp_board, i, player);  // Make the move for the given player
            if (is_win(temp_board, player)) {
                return i;  // If this is a winning move, return it immediately
            }
            move_value = -get_optimal_move(temp_board, (player == 'X' ? 'O' : 'X'));  // Calculate the value of this move for the other player
            if (move_value > best_value) {
                best_move = i;
                best_value = move_value;
            }
        }
    }

    if (best_move == -1) {
        return 0;
    }

    return best_move;

}

int main() {

    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player_move;
    char player = 'X';
    int round = 1;

    printf("===== Tic-Tac-Toe =====\n");

    while (1) {

        printf("Round %d - %c's Turn\n", round, player);
        print_board(board);

        if (player == 'X') {
            printf("Enter Position: ");
            scanf("%d", &player_move);
            printf("\n");
            player_move -= 1;  // Convert the position entered by the player to 0-based index
            if (board[player_move] != 'X' && board[player_move] != 'O') {
                make_move(board, player_move, player);
            } else {
                printf("Invalid Move!\n");
                continue;
            }
        } else {
            player_move = get_optimal_move(board, player);
            printf("AI Move: %d\n", player_move+1);
            make_move(board, player_move, player);
        }

        if (is_win(board, player)) {
            printf("Congratulations! %c Wins!\n", player);
            print_board(board);
            break;
        }

        if (round == 9) {
            printf("It's a draw!\n");
            print_board(board);
            break;
        }

        player = (player == 'X' ? 'O' : 'X');
        round++;

    }

    return 0;
}