//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: scalable
#include<stdio.h>

#define ROW 6
#define COL 6

int maze[ROW][COL] = {
    {1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 1},
    {1, 1, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 1},
    {0, 1, 1, 1, 1, 1}
};

int visited[ROW][COL];
int destX, destY;

int is_valid(int x, int y)
{
    if(x < 0 || x > ROW-1 || y < 0 || y > COL-1)
        return 0;

    if(maze[x][y] == 0)
        return 0;

    if(visited[x][y] == 1)
        return 0;

    return 1;
}

int find_path(int x, int y)
{
    visited[x][y] = 1;

    if(x == destX && y == destY) {
        return 1;
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    int i;
    for(i=0; i<4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if(is_valid(newX, newY)) {
            if(find_path(newX, newY) == 1) {
                printf("(%d, %d) -> ", newX, newY);
                return 1;
            }
        }
    }

    return 0;
}

int main(void)
{
    int startX, startY;
    printf("Enter starting position: ");
    scanf("%d %d", &startX, &startY);

    printf("Enter destination position: ");
    scanf("%d %d", &destX, &destY);

    if(find_path(startX, startY)) {
        printf("(%d, %d)\n", destX, destY);
    } else {
        printf("No path found\n");
    }

    return 0;
}