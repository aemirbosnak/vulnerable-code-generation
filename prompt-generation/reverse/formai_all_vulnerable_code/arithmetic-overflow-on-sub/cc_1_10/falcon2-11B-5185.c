//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int grid[5][5] = {{1, 0, 0, 0, 1},
                        {0, 1, 1, 0, 1},
                        {0, 1, 0, 1, 0},
                        {1, 1, 0, 1, 1},
                        {1, 1, 0, 0, 1}};

    int startX = 0;
    int startY = 0;
    int endX = 4;
    int endY = 4;

    printf("Enter start coordinates: ");
    scanf("%d %d", &startX, &startY);
    printf("Enter end coordinates: ");
    scanf("%d %d", &endX, &endY);

    int row = startX;
    int col = startY;

    int rowDiff = row - endX;
    int colDiff = col - endY;

    if (rowDiff == 0) {
        if (colDiff == 0) {
            printf("Start and end points are the same!\n");
        } else if (colDiff < 0) {
            printf("Move right %d times and then move down %d times\n", abs(colDiff), abs(colDiff));
        } else {
            printf("Move left %d times and then move down %d times\n", abs(colDiff), abs(colDiff));
        }
    } else if (rowDiff < 0) {
        if (colDiff == 0) {
            printf("Move down %d times and then move left %d times\n", abs(rowDiff), abs(rowDiff));
        } else if (colDiff < 0) {
            printf("Move down %d times and then move right %d times\n", abs(rowDiff), abs(rowDiff));
        } else {
            printf("Move up %d times and then move right %d times\n", abs(rowDiff), abs(rowDiff));
        }
    } else {
        if (colDiff == 0) {
            printf("Move up %d times and then move right %d times\n", abs(rowDiff), abs(rowDiff));
        } else if (colDiff < 0) {
            printf("Move up %d times and then move left %d times\n", abs(rowDiff), abs(rowDiff));
        } else {
            printf("Move down %d times and then move left %d times\n", abs(rowDiff), abs(rowDiff));
        }
    }

    return 0;
}