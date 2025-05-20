//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 100
#define DEATH 0
#define BIRTH 1
#define SURVIVE 2

int board[MAX_SIZE][MAX_SIZE];
int size;

void init(int x, int y) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            board[i][j] = rand() % 3;
        }
    }
}

void printBoard() {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (board[i][j] == DEATH) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int countNeighbors(int x, int y) {
    int count = 0;
    int i, j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if ((i!= 0 || j!= 0) && board[(x + i + size) % size][(y + j + size) % size] == BIRTH) {
                count++;
            }
        }
    }
    return count;
}

void nextGeneration() {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (board[i][j] == DEATH) {
                board[i][j] = rand() % 3;
            } else {
                int neighbors = countNeighbors(i, j);
                if (neighbors < 2) {
                    board[i][j] = DEATH;
                } else if (neighbors > 3) {
                    board[i][j] = DEATH;
                } else {
                    board[i][j] = BIRTH;
                }
            }
        }
    }
}

int main() {
    int x, y;
    printf("Enter board size: ");
    scanf("%d %d", &x, &y);
    size = x;
    init(x, y);
    int t = 0;
    while (1) {
        printBoard();
        nextGeneration();
        t++;
        if (t == 10) {
            break;
        }
        usleep(100000);
    }
    return 0;
}