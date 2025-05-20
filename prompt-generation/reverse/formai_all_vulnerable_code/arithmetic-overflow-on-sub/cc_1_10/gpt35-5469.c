//FormAI DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>

// Function to print the board
void print_board(int n, int arr[][n]) {
    printf("Current Board:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Recursive function to play the game
int play_game(int n, int arr[][n], int row, int col, int player) {
    // Stop condition - check for a winner or draw
    int sum_row = 0, sum_col = 0, sum_diag1 = 0, sum_diag2 = 0;
    for (int i = 0; i < n; i++) {
        sum_row += arr[row][i];
        sum_col += arr[i][col];
        sum_diag1 += arr[i][i];
        sum_diag2 += arr[i][n - i - 1];
    }
    if (sum_row == n * player || sum_col == n * player || sum_diag1 == n * player || sum_diag2 == n * player) {
        printf("Player %d wins!\n", player);
        return player;
    } else if (row == n - 1 && col == n - 1 && arr[row][col] != 0) {
        printf("Draw!\n");
        return 0;
    }
    
    // Continue game recursively
    int next_row, next_col, next_player, value;
    // Calculate next row and column positions
    if (col < n - 1) {
        next_row = row;
        next_col = col + 1;
    } else {
        next_row = row + 1;
        next_col = 0;
    }
    // Calculate next player - either 1 or 2
    next_player = player == 1 ? 2 : 1;
    // If cell is already taken, skip it
    if (arr[row][col] != 0) {
        value = play_game(n, arr, next_row, next_col, next_player);
    } else {
        // Try player 1
        arr[row][col] = 1;
        print_board(n, arr);
        value = play_game(n, arr, next_row, next_col, next_player);
        if (value == 1) {
            return 1;
        }
        // Try player 2
        arr[row][col] = 2;
        print_board(n, arr);
        value = play_game(n, arr, next_row, next_col, next_player);
    }
    // Reset cell to empty
    arr[row][col] = 0;
    return value;
}

int main() {
    int n;
    printf("Welcome to C-Table Game!\nEnter the dimension of the board: ");
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    print_board(n, arr);
    play_game(n, arr, 0, 0, 1);
    return 0;
}