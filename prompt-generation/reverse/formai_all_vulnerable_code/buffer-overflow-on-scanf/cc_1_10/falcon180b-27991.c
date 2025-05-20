//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIM 10
#define MAX_TRIES 100
#define MAX_ALIENS 100
#define INVASION_THRESHOLD 0.5

int rand_coord(int max) {
    return rand() % max;
}

int count_invaders(int *board, int dim) {
    int count = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (board[i * dim + j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void print_board(int *board, int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("%d ", board[i * dim + j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int dim;
    printf("Enter board dimensions (1-10): ");
    scanf("%d", &dim);

    if (dim < 1 || dim > MAX_DIM) {
        printf("Invalid board dimensions.\n");
        return 1;
    }

    int board[dim * dim];
    for (int i = 0; i < dim * dim; i++) {
        board[i] = 0;
    }

    int tries = 0;
    while (tries < MAX_TRIES) {
        int x, y;
        do {
            x = rand_coord(dim);
            y = rand_coord(dim);
        } while (board[y * dim + x]!= 0);

        board[y * dim + x] = 1;
        tries++;
    }

    int num_invaders = count_invaders(board, dim);
    double invasion_probability = (double) num_invaders / (dim * dim);

    printf("Alien invasion probability: %.2f%%\n", invasion_probability * 100);

    return 0;
}