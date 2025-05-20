//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PUZZLE_BOX_SIZE 5
#define PUZZLE_PIECE_SIZE 3

typedef struct puzzle_piece {
    char color[PUZZLE_PIECE_SIZE];
} puzzle_piece_t;

typedef struct puzzle_box {
    puzzle_piece_t pieces[PUZZLE_BOX_SIZE][PUZZLE_PIECE_SIZE];
    int num_pieces;
} puzzle_box_t;

void shuffle_pieces(puzzle_box_t *box) {
    int i, j, k;
    char temp[PUZZLE_PIECE_SIZE];

    for (i = 0; i < PUZZLE_BOX_SIZE; i++) {
        for (j = 0; j < PUZZLE_PIECE_SIZE; j++) {
            // Shuffle the pieces
            srand(time(NULL) + j + i);
            for (k = 0; k < PUZZLE_PIECE_SIZE; k++) {
                temp[k] = box->pieces[i][j].color[k];
            }
            for (k = 0; k < PUZZLE_PIECE_SIZE; k++) {
                box->pieces[i][j].color[k] = temp[k];
            }
        }
    }
}

void place_piece(puzzle_box_t *box, int x, int y) {
    int i, j;

    // Find an empty space in the box
    for (i = 0; i < PUZZLE_BOX_SIZE; i++) {
        for (j = 0; j < PUZZLE_PIECE_SIZE; j++) {
            if (box->pieces[i][j].color[0] == 0) {
                break;
            }
        }
        if (j == PUZZLE_PIECE_SIZE) {
            // No empty space found, so return
            return;
        }
    }

    // Place the piece in the found empty space
    for (j = 0; j < PUZZLE_PIECE_SIZE; j++) {
        box->pieces[x][y].color[j] = box->pieces[i][j].color[j];
    }
}

int main() {
    puzzle_box_t box;
    int x, y;

    // Initialize the box with random pieces
    for (int i = 0; i < PUZZLE_BOX_SIZE; i++) {
        for (int j = 0; j < PUZZLE_PIECE_SIZE; j++) {
            for (int k = 0; k < PUZZLE_PIECE_SIZE; k++) {
                box.pieces[i][j].color[k] = 'a' + (rand() % 7);
            }
        }
    }

    // Shuffle the pieces
    shuffle_pieces(&box);

    // Print the box
    for (int i = 0; i < PUZZLE_BOX_SIZE; i++) {
        for (int j = 0; j < PUZZLE_PIECE_SIZE; j++) {
            printf("%c", box.pieces[i][j].color[0]);
        }
        printf("\n");
    }

    // Solve the puzzle
    for (int i = 0; i < PUZZLE_BOX_SIZE; i++) {
        for (int j = 0; j < PUZZLE_PIECE_SIZE; j++) {
            place_piece(&box, i, j);
        }
    }

    // Print the solved puzzle
    for (int i = 0; i < PUZZLE_BOX_SIZE; i++) {
        for (int j = 0; j < PUZZLE_PIECE_SIZE; j++) {
            printf("%c", box.pieces[i][j].color[0]);
        }
        printf("\n");
    }

    return 0;
}