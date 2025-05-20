//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void drawBoard(int **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

Node* createNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void insertMove(Node* node, int **board) {
    board[node->x][node->y] = 'X';
}

int checkWin(int **board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != ' ') {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }

    // If all cells are occupied and there is no winner, it's a draw
    return 0;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    // Seed the random number generator
    srand(time(NULL));

    // Create the AI's move list
    Node* head = createNode(-1, -1);

    // Game loop
    while (1) {
        // Get the player's move
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Check if the move is valid
        if (board[x][y] != ' ' || x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            printf("Invalid move.\n");
            continue;
        }

        // Insert the player's move into the board
        insertMove(createNode(x, y), board);

        // Check if the player has won or there is a draw
        if (checkWin(board) == 1) {
            printf("You win!\n");
            break;
        } else if (checkWin(board) == 0) {
            printf("It's a draw.\n");
            break;
        }

        // Draw the board
        drawBoard(board);

        // Make the AI's move
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;

        // Insert the AI's move into the board
        insertMove(createNode(x, y), board);

        // Check if the AI has won or there is a draw
        if (checkWin(board) == 1) {
            printf("The AI wins!\n");
            break;
        } else if (checkWin(board) == 0) {
            printf("It's a draw.\n");
            break;
        }

        // Draw the board
        drawBoard(board);
    }

    return 0;
}