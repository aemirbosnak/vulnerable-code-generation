//FormAI DATASET v1.0 Category: Chess engine ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

#define BOARD_SIZE 8

// Piece representation using characters
#define KING 'K'
#define QUEEN 'Q'
#define ROOK 'R'
#define BISHOP 'B'
#define KNIGHT 'N'
#define PAWN 'P'
#define EMPTY '.'

// Piece color representation using integers
#define WHITE 1
#define BLACK 0

// Board representation using 2D array of characters
char board[BOARD_SIZE][BOARD_SIZE];

/*
* A structure to represent a chess piece with its color and type.
*/
struct ChessPiece {
    char pieceType;
    int pieceColor;
};

/*
* Function to initialize the chess board with starting positions of chess pieces.
*/
void initializeBoard() {
    int i, j;

    // Set up the pawns
    for(i=0;i<BOARD_SIZE;i++) {
        board[1][i] = board[6][i] = PAWN;
        board[1][i+((BOARD_SIZE-1)/2)+1] = board[6][i+((BOARD_SIZE-1)/2)+1] = EMPTY;
    }

    // Set up the rooks
    board[0][0] = board[0][BOARD_SIZE-1] = board[7][0] = board[7][BOARD_SIZE-1] = ROOK;

    // Set up the knights
    board[0][1] = board[0][BOARD_SIZE-2] = board[7][1] = board[7][BOARD_SIZE-2] = KNIGHT;

    // Set up the bishops
    board[0][2] = board[0][BOARD_SIZE-3] = board[7][2] = board[7][BOARD_SIZE-3] = BISHOP;

    // Set up the queens
    board[0][3] = board[7][3] = QUEEN;

    // Set up the kings
    board[0][4] = board[7][4] = KING;

    // Set the remaining squares to empty
    for(i=2;i<6;i++) {
        for(j=0;j<BOARD_SIZE;j++) {
            board[i][j] = EMPTY;
        }
    }
}

/*
* Function to print the chess board.
*/
void printBoard() {
    int i, j;

    for(i=0;i<BOARD_SIZE;i++) {
        for(j=0;j<BOARD_SIZE;j++) {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

/*
* Function to check if the given position is within the board.
*/
int isPositionOnBoard(int row, int col) {
    if(row>=0 && row<BOARD_SIZE && col>=0 && col<BOARD_SIZE) {
        return 1;
    }
    return 0;
}

/*
* Function to check if the given position is empty.
*/
int isPositionEmpty(int row, int col) {
    if(board[row][col] == EMPTY) {
        return 1;
    }
    return 0;
}

/*
* Function to check if the given position is occupied by an opponent.
*/
int isPositionOccupiedByOpponent(int row, int col, int currentPlayerColor) {
    if(board[row][col] != EMPTY && currentPlayerColor != board[row][col]) {
        return 1;
    }
    return 0;
}

/*
* Function to check if two positions are same.
*/
int isSamePosition(int row1, int col1, int row2, int col2) {
    if(row1==row2 && col1==col2) {
        return 1;
    }
    return 0;
}

/*
* Function to check if the given move is valid for a king piece.
*/
int isKingMoveValid(int row1, int col1, int row2, int col2, int currentPlayerColor) {
    if(isSamePosition(row1,col1,row2,col2)) {
        return 0; // Can't move to the same position
    }
    
    if(abs(row2-row1)>1 || abs(col2-col1)>1) {
        return 0; // Can't move more than 1 step in any direction
    }

    if(isPositionOccupiedByOpponent(row2,col2,currentPlayerColor)) {
        return 1; // Capture opponent's piece
    }

    if(isPositionEmpty(row2,col2)) {
        return 1; // Move to an empty position
    }

    return 0; // Invalid move
}

/*
* Function to check if the given move is valid for a queen piece.
*/
int isQueenMoveValid(int row1, int col1, int row2, int col2, int currentPlayerColor) {
    if(isSamePosition(row1,col1,row2,col2)) {
        return 0; // Can't move to the same position
    }

    int i, j;
    int maxStep = abs(row2-row1) > abs(col2-col1) ? abs(row2-row1) : abs(col2-col1);

    for(i=1;i<maxStep;i++) {
        // Check if the path is empty
        if(row1<row2 && col1<col2) {
            if(!isPositionEmpty(row1+i,col1+i)) {
                return 0;
            }
        }
        else if(row1<row2 && col1>col2) {
            if(!isPositionEmpty(row1+i,col1-i)) {
                return 0;
            }
        }
        else if(row1>row2 && col1>col2) {
            if(!isPositionEmpty(row1-i,col1-i)) {
                return 0;
            }
        }
        else if(row1>row2 && col1<col2) {
            if(!isPositionEmpty(row1-i,col1+i)) {
                return 0;
            }
        }
    }

    // Check the final position
    if(isPositionOccupiedByOpponent(row2,col2,currentPlayerColor)) {
        return 1; // Capture opponent's piece
    }

    if(isPositionEmpty(row2,col2)) {
        return 1; // Move to an empty position
    }

    return 0; // Invalid move
}

/*
* Function to check if the given move is valid for a rook piece.
*/
int isRookMoveValid(int row1, int col1, int row2, int col2, int currentPlayerColor) {
    if(isSamePosition(row1,col1,row2,col2)) {
        return 0; // Can't move to the same position
    }

    if(row1 != row2 && col1 != col2) {
        return 0; // Can only move in straight lines
    }

    int i, j;
    int maxStep = row1==row2 ? abs(col2-col1) : abs(row2-row1);

    for(i=1;i<maxStep;i++) {
        // Check if the path is empty
        if(row1==row2 && col1<col2) {
            if(!isPositionEmpty(row1,col1+i)) {
                return 0;
            }
        }
        else if(row1==row2 && col1>col2) {
            if(!isPositionEmpty(row1,col1-i)) {
                return 0;
            }
        }
        else if(row1<row2 && col1==col2) {
            if(!isPositionEmpty(row1+i,col1)) {
                return 0;
            }
        }
        else if(row1>row2 && col1==col2) {
            if(!isPositionEmpty(row1-i,col1)) {
                return 0;
            }
        }
    }

    // Check the final position
    if(isPositionOccupiedByOpponent(row2,col2,currentPlayerColor)) {
        return 1; // Capture opponent's piece
    }

    if(isPositionEmpty(row2,col2)) {
        return 1; // Move to an empty position
    }

    return 0; // Invalid move
}

/*
* Function to check if the given move is valid for a bishop piece.
*/
int isBishopMoveValid(int row1, int col1, int row2, int col2, int currentPlayerColor) {
    if(isSamePosition(row1,col1,row2,col2)) {
        return 0; // Can't move to the same position
    }

    if(abs(row2-row1) != abs(col2-col1)) {
        return 0; // Can only move in diagonal lines
    }

    int i, j;
    int maxStep = abs(row2-row1);

    for(i=1;i<maxStep;i++) {
        // Check if the path is empty
        if(row1<row2 && col1<col2) {
            if(!isPositionEmpty(row1+i,col1+i)) {
                return 0;
            }
        }
        else if(row1<row2 && col1>col2) {
            if(!isPositionEmpty(row1+i,col1-i)) {
                return 0;
            }
        }
        else if(row1>row2 && col1>col2) {
            if(!isPositionEmpty(row1-i,col1-i)) {
                return 0;
            }
        }
        else if(row1>row2 && col1<col2) {
            if(!isPositionEmpty(row1-i,col1+i)) {
                return 0;
            }
        }
    }

    // Check the final position
    if(isPositionOccupiedByOpponent(row2,col2,currentPlayerColor)) {
        return 1; // Capture opponent's piece
    }

    if(isPositionEmpty(row2,col2)) {
        return 1; // Move to an empty position
    }

    return 0; // Invalid move
}

/*
* Function to check if the given move is valid for a knight piece.
*/
int isKnightMoveValid(int row1, int col1, int row2, int col2, int currentPlayerColor) {
    if(isSamePosition(row1,col1,row2,col2)) {
        return 0; // Can't move to the same position
    }

    if(abs(row2-row1)==2 && abs(col2-col1)==1) {
        // L-shaped move
        if(isPositionOccupiedByOpponent(row2,col2,currentPlayerColor)) {
            return 1; // Capture opponent's piece
        }

        if(isPositionEmpty(row2,col2)) {
            return 1; // Move to an empty position
        }

        return 0; // Invalid move
    }

    if(abs(row2-row1)==1 && abs(col2-col1)==2) {
        // L-shaped move
        if(isPositionOccupiedByOpponent(row2,col2,currentPlayerColor)) {
            return 1; // Capture opponent's piece
        }

        if(isPositionEmpty(row2,col2)) {
            return 1; // Move to an empty position
        }

        return 0; // Invalid move
    }

    return 0; // Invalid move
}

/*
* Function to check if the given move is valid for a pawn piece.
*/
int isPawnMoveValid(int row1, int col1, int row2, int col2, int currentPlayerColor) {
    if(isSamePosition(row1,col1,row2,col2)) {
        return 0; // Can't move to the same position
    }

    if(currentPlayerColor == WHITE) {
        // White player's pawn moves upwards
        if(row2<=row1) {
            return 0; // Can only move forward
        }
    }
    else {
        // Black player's pawn moves downwards
        if(row2>=row1) {
            return 0; // Can only move forward
        }
    }

    int rowDiff = abs(row2-row1);
    int colDiff = abs(col2-col1);

    if(rowDiff > 2) {
        return 0; // Can't move more than 2 steps
    }

    if(colDiff > 1) {
        return 0; // Can't move more than 1 step sideways
    }

    if(rowDiff == 2) {
        if(currentPlayerColor == WHITE && row1 != 1) {
            return 0; // Can only move 2 steps from the starting position
        }
        else if(currentPlayerColor == BLACK && row1 != 6) {
            return 0; // Can only move 2 steps from the starting position
        }

        if(colDiff != 0) {
            return 0; // Can't move sideways while moving 2 steps
        }

        if(!isPositionEmpty((row1+row2)/2,col1)) {
            return 0; // Can't jump over any piece while moving 2 steps
        }
    }

    if(colDiff == 1) {
        if(isPositionEmpty(row2,col2)) {
            return 0; // Can only make a diagonal move while capturing opponent's piece
        }

        if(!isPositionOccupiedByOpponent(row2,col2,currentPlayerColor)) {
            return 0; // Can only capture opponent's piece
        }
    }
    else {
        if(!isPositionEmpty(row2,col2)) {
            return 0; // Can only move to an empty position
        }
    }

    return 1; // Valid move
}

/*
* Function to check if the given move is valid.
*/
int isMoveValid(int row1, int col1, int row2, int col2, int currentPlayerColor) {
    struct ChessPiece chessPiece;
    chessPiece.pieceType = board[row1][col1];
    chessPiece.pieceColor = currentPlayerColor;

    switch(chessPiece.pieceType) {
        case KING:
            return isKingMoveValid(row1, col1, row2, col2, currentPlayerColor);
        case QUEEN:
            return isQueenMoveValid(row1, col1, row2, col2, currentPlayerColor);
        case ROOK:
            return isRookMoveValid(row1, col1, row2, col2, currentPlayerColor);
        case BISHOP:
            return isBishopMoveValid(row1, col1, row2, col2, currentPlayerColor);
        case KNIGHT:
            return isKnightMoveValid(row1, col1, row2, col2, currentPlayerColor);
        case PAWN:
            return isPawnMoveValid(row1, col1, row2, col2, currentPlayerColor);
        default:
            return 0; // Invalid piece type
    }
}

/*
* Function to get the row and column indices from the given algebraic notation of a position.
*/
void getRowColFromAlgebraicNotation(char* algebraicNotation, int* row, int* col) {
    *col = algebraicNotation[0]-'a';
    *row = BOARD_SIZE-(algebraicNotation[1]-'0');
}

int main() {
    // Initialize the chess board
    initializeBoard();

    // Print the chess board
    printBoard();

    // Get input from the user
    char* input = (char*)malloc(100*sizeof(char));
    int currentPlayerColor = WHITE; // White player starts the game
    while(1) {
        printf("Enter your move (e.g. 'e2 e4'): ");
        scanf("%s",input);

        // Get the source and destination positions from the user input
        int srcRow, srcCol, dstRow, dstCol;
        getRowColFromAlgebraicNotation(input,&srcRow,&srcCol);
        getRowColFromAlgebraicNotation(&input[3],&dstRow,&dstCol);

        // Check if the move is valid
        if(isMoveValid(srcRow,srcCol,dstRow,dstCol,currentPlayerColor)) {
            // Make the move on the board
            board[dstRow][dstCol] = board[srcRow][srcCol];
            board[srcRow][srcCol] = EMPTY;

            // Switch the player turn
            currentPlayerColor = !currentPlayerColor;

            // Print the updated board
            printBoard();
        }
        else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}