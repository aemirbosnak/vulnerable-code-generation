//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>
#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] =
{{'#','#','#','#','#','#','#','#','#','#'},
{'#',' ',' ','#',' ','#',' ',' ',' ','#'},
{'#',' ',' ','#',' ','#','#','#',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ','#','#',' ','#','#','#',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#','#','#','#','#','#',' ','#',' ','#'},
{'#',' ',' ',' ',' ',' ',' ','#',' ','#'},
{'#',' ','#','#',' ','#','#','#',' ','#'},
{'#',' ',' ',' ',' ',' ',' ','#',' ','#'}};

int sr, sc, er, ec;

void printMaze() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int findPath(int r, int c) {
    if (r == er && c == ec) {
        return 1;
    }
    if (maze[r][c] != ' ') {
        return 0;
    }
    maze[r][c] = '.';
    if (findPath(r-1, c) || findPath(r, c+1)
        || findPath(r+1, c) || findPath(r, c-1)) {
        return 1;
    }
    maze[r][c] = ' ';
    return 0;
}

int main() {
    printf("MAZE ROUTE FINDER\n");
    printf("-----------------\n");
    printf("Enter starting row: ");
    scanf("%d", &sr);
    printf("Enter starting col: ");
    scanf("%d", &sc);
    printf("Enter ending row: ");
    scanf("%d", &er);
    printf("Enter ending col: ");
    scanf("%d", &ec);
    if (findPath(sr, sc)) {
        maze[sr][sc] = 'S';
        maze[er][ec] = 'E';
        printf("The path to the end is:\n");
        printMaze();
    } else {
        printf("No path to the end could be found.\n");
    }
    return 0;
}