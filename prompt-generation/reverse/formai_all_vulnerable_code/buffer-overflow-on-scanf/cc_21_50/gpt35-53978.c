//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // initialize the game board
int difficulty; // initialize the difficulty level of the game

// Function to initialize the game board
void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to print the game board
void print_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game has ended
int check_endgame() {
    int i, j, count;
    
    // Check for rows
    for (i = 0; i < 3; i++) {
        count = 0;
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                count++;
            }
            else if (board[i][j] == 'O') {
                count--;
            }
        }
        if (count == 3 || count == -3) {
            return 1;
        }
    }
    
    // Check for columns
    for (i = 0; i < 3; i++) {
        count = 0;
        for (j = 0; j < 3; j++) {
            if (board[j][i] == 'X') {
                count++;
            }
            else if (board[j][i] == 'O') {
                count--;
            }
        }
        if (count == 3 || count == -3) {
            return 1;
        }
    }
    
    // Check for diagonals
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
        return 1;
    }
    else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
        return 1;
    }
    else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
        return 1;
    }
    else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
        return 1;
    }
    
    // Check for tie game
    count = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] != '-') {
                count++;
            }
        }
    }
    if (count == 9) {
        return 2;
    }
    
    return 0;
}

// Function to make a move
int make_move(char player) {
    int row, col;
    srand(time(NULL));
    
    // If the player is the computer
    if (player == 'O') {
        switch (difficulty) { // determine difficulty level
            case 1: // Easy mode (Random move)
                row = rand() % 3;
                col = rand() % 3;
                while (board[row][col] != '-') {
                    row = rand() % 3;
                    col = rand() % 3;
                }
                board[row][col] = player;
                break;
            case 2: // Medium mode (Defensive move)
                // Check for available defensive moves in rows
                for (row = 0; row < 3; row++) {
                    if (board[row][0] == '-' && board[row][1] == 'X' && board[row][2] == 'X') {
                        board[row][0] = player;
                        return 1;
                    }
                    else if (board[row][0] == 'X' && board[row][1] == '-' && board[row][2] == 'X') {
                        board[row][1] = player;
                        return 1;
                    }
                    else if (board[row][0] == 'X' && board[row][1] == 'X' && board[row][2] == '-') {
                        board[row][2] = player;
                        return 1;
                    }
                }
                // Check for available defensive moves in columns
                for (col = 0; col < 3; col++) {
                    if (board[0][col] == '-' && board[1][col] == 'X' && board[2][col] == 'X') {
                        board[0][col] = player;
                        return 1;
                    }
                    else if (board[0][col] == 'X' && board[1][col] == '-' && board[2][col] == 'X') {
                        board[1][col] = player;
                        return 1;
                    }
                    else if (board[0][col] == 'X' && board[1][col] == 'X' && board[2][col] == '-') {
                        board[2][col] = player;
                        return 1;
                    }
                }
                // Check for available defensive moves in diagonals
                if (board[0][0] == '-' && board[1][1] == 'X' && board[2][2] == 'X') {
                    board[0][0] = player;
                    return 1;
                }
                else if (board[0][0] == 'X' && board[1][1] == '-' && board[2][2] == 'X') {
                    board[1][1] = player;
                    return 1;
                }
                else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == '-') {
                    board[2][2] = player;
                    return 1;
                }
                else if (board[0][2] == '-' && board[1][1] == 'X' && board[2][0] == 'X') {
                    board[0][2] = player;
                    return 1;
                }
                else if (board[0][2] == 'X' && board[1][1] == '-' && board[2][0] == 'X') {
                    board[1][1] = player;
                    return 1;
                }
                else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == '-') {
                    board[2][0] = player;
                    return 1;
                }
                // If no defensive moves are available, make a random move
                row = rand() % 3;
                col = rand() % 3;
                while (board[row][col] != '-') {
                    row = rand() % 3;
                    col = rand() % 3;
                }
                board[row][col] = player;
                break;
            case 3: // Hard mode (Offensive move)
                // Check for available offensive moves in rows
                for (row = 0; row < 3; row++) {
                    if (board[row][0] == '-' && board[row][1] == 'O' && board[row][2] == 'O') {
                        board[row][0] = player;
                        return 1;
                    }
                    else if (board[row][0] == 'O' && board[row][1] == '-' && board[row][2] == 'O') {
                        board[row][1] = player;
                        return 1;
                    }
                    else if (board[row][0] == 'O' && board[row][1] == 'O' && board[row][2] == '-') {
                        board[row][2] = player;
                        return 1;
                    }
                }
                // Check for available offensive moves in columns
                for (col = 0; col < 3; col++) {
                    if (board[0][col] == '-' && board[1][col] == 'O' && board[2][col] == 'O') {
                        board[0][col] = player;
                        return 1;
                    }
                    else if (board[0][col] == 'O' && board[1][col] == '-' && board[2][col] == 'O') {
                        board[1][col] = player;
                        return 1;
                    }
                    else if (board[0][col] == 'O' && board[1][col] == 'O' && board[2][col] == '-') {
                        board[2][col] = player;
                        return 1;
                    }
                }
                // Check for available offensive moves in diagonals
                if (board[0][0] == '-' && board[1][1] == 'O' && board[2][2] == 'O') {
                    board[0][0] = player;
                    return 1;
                }
                else if (board[0][0] == 'O' && board[1][1] == '-' && board[2][2] == 'O') {
                    board[1][1] = player;
                    return 1;
                }
                else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == '-') {
                    board[2][2] = player;
                    return 1;
                }
                else if (board[0][2] == '-' && board[1][1] == 'O' && board[2][0] == 'O') {
                    board[0][2] = player;
                    return 1;
                }
                else if (board[0][2] == 'O' && board[1][1] == '-' && board[2][0] == 'O') {
                    board[1][1] = player;
                    return 1;
                }
                else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == '-') {
                    board[2][0] = player;
                    return 1;
                }
                // If no offensive moves are available, make a random move
                row = rand() % 3;
                col = rand() % 3;
                while (board[row][col] != '-') {
                    row = rand() % 3;
                    col = rand() % 3;
                }
                board[row][col] = player;
                break;
        }
        return 1;
    }
    // If the player is a human
    else {
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        row--;
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        col--;
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid input, please try again.\n");
            return 0;
        }
        if (board[row][col] != '-') {
            printf("This cell is already occupied, please try again.\n");
            return 0;
        }
        board[row][col] = player;
        return 1;
    }
}

int main() {
    int endgame = 0, turn = 1;
    char player = 'X';
    printf("Welcome to Tic Tac Toe!\n");
    printf("Please select the difficulty level (1-3):\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    scanf("%d", &difficulty);
    initialize_board();
    print_board();
    while (endgame == 0) {
        printf("TURN %d\n", turn);
        if (!make_move(player)) {
            continue;
        }
        print_board();
        endgame = check_endgame();
        if (endgame == 1) {
            printf("Player %c wins!\n", player);
        }
        else if (endgame == 2) {
            printf("It's a tie game!\n");
        }
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
        turn++;
    }
    return 0;
}