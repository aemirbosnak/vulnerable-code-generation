//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define WHITE_PAWN 'P'
#define BLACK_PAWN 'p'
#define WHITE_ROOK 'R'
#define BLACK_ROOK 'r'
#define WHITE_KNIGHT 'N'
#define BLACK_KNIGHT 'n'
#define WHITE_BISHOP 'B'
#define BLACK_BISHOP 'b'
#define WHITE_QUEEN 'Q'
#define BLACK_QUEEN 'q'
#define WHITE_KING 'K'
#define BLACK_KING 'k'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *board) {
    const char *initialSetup[BOARD_SIZE] = {
        "RNBQKBNR",
        "PPPPPPPP",
        "        ",
        "        ",
        "        ",
        "        ",
        "pppppppp",
        "rnbqkbnr"
    };
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = initialSetup[i][j];
        }
    }
}

void printBoard(const ChessBoard *board) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int startX, int startY, int endX, int endY, const ChessBoard *board) {
    // Basic validation: Check if within bounds and not moving to own piece
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0;
    }
    
    char movingPiece = board->board[startX][startY];
    char destinationPiece = board->board[endX][endY];
    
    // Ensure the destination does not contain same color piece
    if ((movingPiece >= 'A' && movingPiece <= 'Z' && destinationPiece >= 'A' && destinationPiece <= 'Z') ||
        (movingPiece >= 'a' && movingPiece <= 'z' && destinationPiece >= 'a' && destinationPiece <= 'z')) {
        return 0;
    }
    
    return 1;
}

void movePiece(ChessBoard *board, int startX, int startY, int endX, int endY) {
    if (isValidMove(startX, startY, endX, endY, board)) {
        board->board[endX][endY] = board->board[startX][startY];
        board->board[startX][startY] = EMPTY;
    } else {
        printf("Invalid move from (%d, %d) to (%d, %d).\n", startX, startY, endX, endY);
    }
}

int main() {
    ChessBoard board;
    initializeBoard(&board);
    
    int startX, startY, endX, endY;
    char input[5];

    while (1) {
        printBoard(&board);
        printf("Enter your move (e.g. 'e2 e4') or 'exit' to quit: ");
        
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't') {
            break;
        }

        if (sscanf(input, "%c%d %c%d", &input[0], &startY, &input[2], &endY) == 4) {
            startX = BOARD_SIZE - (startY - '0');
            endX = BOARD_SIZE - (endY - '0');
            startY = input[0] - 'a';
            endY = input[2] - 'a';
            movePiece(&board, startX, startY, endX, endY);
        } else {
            printf("Invalid input format. Use 'e.g. e2 e4'.\n");
        }
    }

    printf("Game exited.\n");
    return 0;
}