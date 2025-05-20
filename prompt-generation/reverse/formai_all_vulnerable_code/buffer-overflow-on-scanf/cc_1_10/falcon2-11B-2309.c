//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

char grid[10][10] = {
    '.'};

int row, col;
bool turnLeft, turnRight;

void move(int dir) {
    switch (dir) {
        case 0: // up
            if (row > 0) {
                row--;
            }
            break;
        case 1: // down
            if (row < 9) {
                row++;
            }
            break;
        case 2: // left
            if (col > 0) {
                col--;
            }
            break;
        case 3: // right
            if (col < 9) {
                col++;
            }
            break;
        case 4: // turn left
            turnLeft = true;
            turnRight = false;
            break;
        case 5: // turn right
            turnLeft = false;
            turnRight = true;
            break;
        default:
            break;
    }
}

void printGrid() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int dir;
    printf("Enter direction (0-3 for movement, 4 for left, 5 for right): ");
    scanf("%d", &dir);
    while (true) {
        move(dir);
        if (turnLeft && turnRight) {
            turnLeft = false;
            turnRight = false;
        }
        if (row < 0 || row >= 10 || col < 0 || col >= 10) {
            printf("Robot hit a wall! Game over.\n");
            break;
        }
        printGrid();
        printf("Enter direction (0-3 for movement, 4 for left, 5 for right): ");
        scanf("%d", &dir);
    }
    return 0;
}