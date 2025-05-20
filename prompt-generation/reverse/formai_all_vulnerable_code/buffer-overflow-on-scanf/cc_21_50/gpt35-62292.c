//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: lively
#include <stdio.h>
#define ROW 5
#define COL 5

int main() {
    int maze[ROW][COL] = {
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1}
    };

    int start[] = {0, 0};
    int end[] = {4, 4};
    int x = start[0], y = start[1];
    int visited[ROW][COL] = {0};

    printf("The maze:\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(maze[i][j] == 1) {
                printf(" ");
            }
            else {
                printf("#");
            }
        }
        printf("\n");
    }
    printf("\n");

    while(x != end[0] || y != end[1]) {
        visited[x][y] = 1;
        int up = 0, down = 0, left = 0, right = 0;

        if(x-1 >= 0 && !visited[x-1][y] && maze[x-1][y] == 1) {
            up = 1;
        }
        if(x+1 < ROW && !visited[x+1][y] && maze[x+1][y] == 1) {
            down = 1;
        }
        if(y-1 >= 0 && !visited[x][y-1] && maze[x][y-1] == 1) {
            left = 1;
        }
        if(y+1 < COL && !visited[x][y+1] && maze[x][y+1] == 1) {
            right = 1;
        }

        if(up || down || left || right) {
            printf("Which direction do you want to take?\n");
            if(up) {
                printf("Up (w)\n");
            }
            if(down) {
                printf("Down (s)\n");
            }
            if(left) {
                printf("Left (a)\n");
            }
            if(right) {
                printf("Right (d)\n");
            }

            char direction;
            scanf(" %c", &direction);

            if(direction == 'w' && up) {
                x--;
            }
            else if(direction == 's' && down) {
                x++;
            }
            else if(direction == 'a' && left) {
                y--;
            }
            else if(direction == 'd' && right) {
                y++;
            }
            else {
                printf("Invalid direction\n");
            }
        }
        else {
            printf("No available direction, going back\n");
            if(x-1 >= 0 && visited[x-1][y]) {
                x--;
            }
            else if(x+1 < ROW && visited[x+1][y]) {
                x++;
            }
            else if(y-1 >= 0 && visited[x][y-1]) {
                y--;
            }
            else if(y+1 < COL && visited[x][y+1]) {
                y++;
            }
        }

        printf("Location: (%d, %d)\n", x, y);
    }

    printf("Congratulations, you have reached the end!\n");

    return 0;
}