//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell {
    int x, y;
    char symbol;
} Cell;

Cell createCell(int x, int y) {
    Cell cell;
    cell.x = x;
    cell.y = y;
    cell.symbol = '\0';
    return cell;
}

int isCellEmpty(Cell cell) {
    return cell.symbol == '\0';
}

void placeSymbol(Cell cell, char symbol) {
    cell.symbol = symbol;
}

int checkWin(Cell board[]) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board[r].symbol == board[r + 1].symbol && board[r + 1].symbol == board[r + 2].symbol && board[r].symbol != '\0') {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board[c].symbol == board[c + 1].symbol && board[c + 1].symbol == board[c + 2].symbol && board[c].symbol != '\0') {
            return 1;
        }
    }

    // Check diagonals
    if (board[0].symbol == board[4].symbol && board[4].symbol == board[8].symbol && board[0].symbol != '\0') {
        return 1;
    }

    // If all cells are occupied and there is no winner, it's a draw
    return 2;
}

int main() {
    // Create a game board
    Cell board[BOARD_SIZE * BOARD_SIZE] = {
        createCell(0, 0),
        createCell(1, 0),
        createCell(2, 0),
        createCell(0, 1),
        createCell(1, 1),
        createCell(2, 1),
        createCell(0, 2),
        createCell(1, 2),
        createCell(2, 2)
    };

    // Initialize the game
    char current_player = 'X';
    int game_status = 0;

    // Play the game
    while (!game_status) {
        // Get the player's move
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Check if the move is valid
        if (!isCellEmpty(createCell(x, y))) {
            printf("Invalid move.\n");
            continue;
        }

        // Place the player's symbol on the board
        placeSymbol(createCell(x, y), current_player);

        // Check if the player has won or if there is a draw
        game_status = checkWin(board);

        // Switch to the next player
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    // Print the game result
    if (game_status == 1) {
        printf("Congratulations! You won!\n");
    } else if (game_status == 2) {
        printf("It's a draw.\n");
    }

    return 0;
}