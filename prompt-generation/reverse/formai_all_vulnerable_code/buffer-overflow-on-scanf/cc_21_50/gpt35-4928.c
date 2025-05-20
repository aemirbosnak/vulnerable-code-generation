//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: genious
#include <stdio.h>
#include <string.h>

#define ROW 10
#define COL 10

int main()
{
    int grid[ROW][COL] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,1,0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0,0},
        {0,0,0,1,1,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0},
        {0,0,0,0,0,1,1,0,0,0},
        {0,0,0,0,0,0,1,1,0,0},
        {0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,0,0,0,0},
    };

    printf("Welcome to the Genius Pathfinding Algorithm!\n");
    printf("Enter the source and destination coordinates: ");

    int startX, startY, endX, endY;
    scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

    if (startX < 0 || startX >= ROW || startY < 0 || startY >= COL || endX < 0 || endX >= ROW || endY < 0 || endY >= COL)
    {
        printf("Invalid coordinates entered. Try again.\n");
        return 0;
    }

    int visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    int queueX[ROW * COL];
    int queueY[ROW * COL];
    int queueSize = 0;

    queueX[queueSize] = startX;
    queueY[queueSize] = startY;
    queueSize++;

    visited[startX][startY] = 1;

    while (queueSize > 0)
    {
        int currentX = queueX[0];
        int currentY = queueY[0];

        if (currentX == endX && currentY == endY)
        {
            printf("Path found!\n");
            return 0;
        }

        queueSize--;
        memmove(queueX, queueX + 1, queueSize * sizeof(int));
        memmove(queueY, queueY + 1, queueSize * sizeof(int));

        // Check the neighbors
        if (currentX > 0 && grid[currentX - 1][currentY] == 1 && !visited[currentX - 1][currentY])
        {
            queueX[queueSize] = currentX - 1;
            queueY[queueSize] = currentY;
            queueSize++;
            visited[currentX - 1][currentY] = 1;
        }

        if (currentY > 0 && grid[currentX][currentY - 1] == 1 && !visited[currentX][currentY - 1])
        {
            queueX[queueSize] = currentX;
            queueY[queueSize] = currentY - 1;
            queueSize++;
            visited[currentX][currentY - 1] = 1;
        }

        if (currentX < ROW - 1 && grid[currentX + 1][currentY] == 1 && !visited[currentX + 1][currentY])
        {
            queueX[queueSize] = currentX + 1;
            queueY[queueSize] = currentY;
            queueSize++;
            visited[currentX + 1][currentY] = 1;
        }

        if (currentY < COL - 1 && grid[currentX][currentY + 1] == 1 && !visited[currentX][currentY + 1])
        {
            queueX[queueSize] = currentX;
            queueY[queueSize] = currentY + 1;
            queueSize++;
            visited[currentX][currentY + 1] = 1;
        }
    }

    printf("Destination is unreachable.\n");
    return 0;
}