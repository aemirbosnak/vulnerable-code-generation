//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int z;
} Coordinate;

int main(int argc, char *argv[]) {
    int boardWidth = 100;
    int boardHeight = 100;
    int boardSize = boardWidth * boardHeight;
    int* board = (int*) malloc(boardSize * sizeof(int));

    Coordinate* coords = (Coordinate*) malloc(boardSize * sizeof(Coordinate));

    // Initialize the board
    for (int i = 0; i < boardSize; i++) {
        board[i] = rand() % 2;
        coords[i].x = i % boardWidth;
        coords[i].y = i / boardWidth;
        coords[i].z = i;
    }

    int numOfOpen = 0;
    int numOfClosed = 0;

    // Perform percolation
    for (int i = 0; i < boardSize; i++) {
        if (board[i] == 0) {
            numOfClosed++;
            if (numOfClosed == 1) {
                coords[i].z = 1;
            } else if (numOfClosed > 1) {
                for (int j = 0; j < boardSize; j++) {
                    if (i!= j && board[j] == 0 && coords[j].z == 0) {
                        coords[j].z = 1;
                        numOfOpen++;
                        break;
                    }
                }
            }
        } else {
            numOfOpen++;
            if (numOfOpen == 1) {
                coords[i].z = 1;
            } else if (numOfOpen > 1) {
                for (int j = 0; j < boardSize; j++) {
                    if (i!= j && board[j] == 1 && coords[j].z == 1) {
                        coords[j].z = 0;
                        numOfClosed++;
                        break;
                    }
                }
            }
        }
    }

    // Output the results
    for (int i = 0; i < boardSize; i++) {
        if (coords[i].z == 1) {
            printf("Open: (%d, %d, %d)\n", coords[i].x, coords[i].y, coords[i].z);
        } else {
            printf("Closed: (%d, %d, %d)\n", coords[i].x, coords[i].y, coords[i].z);
        }
    }

    free(board);
    free(coords);

    return 0;
}