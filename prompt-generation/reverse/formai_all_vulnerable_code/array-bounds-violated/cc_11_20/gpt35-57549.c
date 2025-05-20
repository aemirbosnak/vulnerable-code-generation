//FormAI DATASET v1.0 Category: Chess AI ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEPTH 3 // Maximum depth for minimax algorithm
#define INFINITY 10000000 // Define a large integer as infinity
#define MAX(a, b) ((a) > (b) ? (a) : (b)) // Define a max function
#define MIN(a, b) ((a) < (b) ? (a) : (b)) // Define a min function

char board[8][8] = { // Initialize the chess board
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

int values[6] = {100, 300, 300, 500, 900, 100000}; // Define values for each piece type

int pieceScore(char piece) { // Evaluate the score for each piece on the board
    switch(piece) {
        case 'P': return values[0];
        case 'N': return values[1];
        case 'B': return values[2];
        case 'R': return values[3];
        case 'Q': return values[4];
        case 'K': return values[5];
        case 'p': return -values[0];
        case 'n': return -values[1];
        case 'b': return -values[2];
        case 'r': return -values[3];
        case 'q': return -values[4];
        case 'k': return -values[5];
        default: return 0;
    }
}

int evaluate() { // Calculate the evaluation score of the board
    int score = 0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            score += pieceScore(board[i][j]);
        }
    }
    return score;
}

void makeMove(char move[4]) { // Make a move on the board
    int fx = move[0] - 'a'; int fy = move[1] - '1'; // Get starting position
    int tx = move[2] - 'a'; int ty = move[3] - '1'; // Get target position
    board[ty][tx] = board[fy][fx]; // Move the piece to the target position
    board[fy][fx] = ' '; // Remove the piece from the starting position
}

void undoMove(char move[4], char takenPiece) { // Undo a move on the board
    int fx = move[0] - 'a'; int fy = move[1] - '1'; // Get starting position
    int tx = move[2] - 'a'; int ty = move[3] - '1'; // Get target position
    board[fy][fx] = board[ty][tx]; // Move the piece back to the starting position
    board[ty][tx] = takenPiece; // Put the taken piece back to the target position
}

int alphaBeta(int depth, int alpha, int beta, int isMax) { // Alpha-beta pruning algorithm
    if(depth == 0) return evaluate(); // Reached maximum depth, evaluate the board
    int bestScore = isMax ? -INFINITY : INFINITY; // Set the initial best score
    char move[4]; // Array to store the move
    for(int i=0; i<8; i++) { // Iterate through all positions
        for(int j=0; j<8; j++) {
            if(board[i][j] == ' ') continue; // Skip empty positions
            if(isMax && board[i][j] < 91) continue; // Skip if not maximizing and piece is white
            if(!isMax && board[i][j] > 91) continue; // Skip if not minimizing and piece is black
            for(int ii=0; ii<8; ii++) {
                for(int jj=0; jj<8; jj++) {
                    if(i == ii && j == jj) continue; // Skip same position
                    if(!moves(i, j, ii, jj)) continue; // Skip invalid moves
                    char takenPiece = board[ii][jj]; // Save taken piece
                    board[i][j] ^= board[ii][jj]; board[ii][jj] ^= board[i][j]; board[i][j] ^= board[ii][jj]; // Move the piece
                    move[0] = j + 'a'; move[1] = i + '1'; move[2] = jj + 'a'; move[3] = ii + '1'; // Store the move
                    int score = alphaBeta(depth-1, alpha, beta, !isMax); // Recurse
                    undoMove(move, takenPiece); // Undo the move
                    if(isMax) { // Update alpha
                        alpha = MAX(alpha, score);
                        if(score > bestScore) { // Update best score
                            bestScore = score;
                        }
                    } else { // Update beta
                        beta = MIN(beta, score);
                        if(score < bestScore) { // Update best score
                            bestScore = score;
                        }
                    }
                    if(alpha >= beta) { // Prune
                        return bestScore;
                    }
                }
            }
        }
    }
    return bestScore; // Return the best score
}

char* getMove() { // Get the best move using the alpha-beta pruning algorithm
    char* bestMove = malloc(sizeof(char) * 5); // Allocate memory for the best move
    int bestScore = -INFINITY; // Initialize the best score
    char move[4]; // Array to store the move
    for(int i=0; i<8; i++) { // Iterate through all positions
        for(int j=0; j<8; j++) {
            if(board[i][j] == ' ') continue; // Skip empty positions
            if(board[i][j] < 91) continue; // Skip if piece is white
            for(int ii=0; ii<8; ii++) {
                for(int jj=0; jj<8; jj++) {
                    if(i == ii && j == jj) continue; // Skip same position
                    if(!moves(i, j, ii, jj)) continue; // Skip invalid moves
                    char takenPiece = board[ii][jj]; // Save taken piece
                    board[i][j] ^= board[ii][jj]; board[ii][jj] ^= board[i][j]; board[i][j] ^= board[ii][jj]; // Move the piece
                    move[0] = j + 'a'; move[1] = i + '1'; move[2] = jj + 'a'; move[3] = ii + '1'; // Store the move
                    int score = alphaBeta(DEPTH, -INFINITY, INFINITY, 0); // Calculate score
                    undoMove(move, takenPiece); // Undo the move
                    if(score > bestScore) { // Update best move
                        bestScore = score;
                        strcpy(bestMove, move);
                    }
                }
            }
        }
    }
    return bestMove; // Return the best move
}

int moves(int fx, int fy, int tx, int ty) { // Check if a move is valid
    if(board[fy][fx] == 'P') { // Check pawn move
        if(tx == fx && (ty == fy+1 || (ty == fy+2 && fy == 1))) { // Check move forward
            return 1;
        } else if(abs(ty - fy) == 1 && abs(tx - fx) == 1 && board[ty][tx] != ' ') { // Check capture
            return 1;
        }
    } else if(board[fy][fx] == 'p') { // Check pawn move
        if(tx == fx && (ty == fy-1 || (ty == fy-2 && fy == 6))) { // Check move forward
            return 1;
        } else if(abs(ty - fy) == 1 && abs(tx - fx) == 1 && board[ty][tx] != ' ') { // Check capture
            return 1;
        }
    } else if(board[fy][fx] == 'N' || board[fy][fx] == 'n') { // Check knight move
        if(abs(ty - fy) == 2 && abs(tx - fx) == 1) {
            return 1;
        } else if(abs(ty - fy) == 1 && abs(tx - fx) == 2) {
            return 1;
        }
    } else { // Check other pieces move
        int dirx = tx - fx > 0 ? 1 : tx - fx < 0 ? -1 : 0;
        int diry = ty - fy > 0 ? 1 : ty - fy < 0 ? -1 : 0;
        if(abs(tx-fx) == abs(ty-fy)) { // Diagonal move
            for(int i=1; i<abs(tx-fx); i++) {
                if(board[fy+i*diry][fx+i*dirx] != ' ') return 0;
            }
            return 1;
        } else if(dirx != 0 && diry == 0) { // Horizontal move
            for(int i=1; i<abs(tx-fx); i++) {
                if(board[fy][fx+i*dirx] != ' ') return 0;
            }
            return 1;
        } else if(diry != 0 && dirx == 0) { // Vertical move
            for(int i=1; i<abs(ty-fy); i++) {
                if(board[fy+i*diry][fx] != ' ') return 0;
            }
            return 1;
        }
    }
    return 0; // Invalid move
}

int main() {
    char* bestMove;
    while(1) {
        printf("Enter move: ");
        char move[5];
        scanf("%s",move);
        makeMove(move);
        bestMove = getMove();
        printf("AI Move: %s\n", bestMove);
        makeMove(bestMove);
        free(bestMove);
    }
    return 0;
}