//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0

typedef struct _room {
    char name[50];
    int occupied;
    int north;
    int east;
    int south;
    int west;
} Room;

void create_maze(Room *maze, int rows, int cols) {
    int x, y, dx, dy;

    for (x = 0; x < rows; x++) {
        for (y = 0; y < cols; y++) {
            maze[x * cols + y].occupied = FALSE;
            maze[x * cols + y].north = -1;
            maze[x * cols + y].east = -1;
            maze[x * cols + y].south = -1;
            maze[x * cols + y].west = -1;
        }
    }

    x = 0;
    y = 0;
    dx = 0;
    dy = 1;

    maze[x * cols + y].occupied = TRUE;

    while (!((x == rows - 1) && (y == cols - 1))) {
        switch (maze[x * cols + y].occupied) {
            case TRUE:
                if (maze[x * cols + y + dy].occupied == FALSE) {
                    maze[x * cols + y + dy].north = x * cols + y;
                    maze[x * cols + y].east = x * cols + y + dy;
                    x = x * cols + y + dy;
                    dx = dy;
                    dy = -dy;
                } else {
                    maze[x * cols + y + dx].west = x * cols + y;
                    maze[x * cols + y].south = x * cols + y + dx;
                    x = x * cols + y + dx;
                    dx = -dx;
                    dy = -dy;
                }
                break;
            case FALSE:
                x = x + dx;
                y = y + dy;
                break;
        }
    }
}

void print_maze(Room *maze, int rows, int cols) {
    int x, y;

    for (x = 0; x < rows; x++) {
        for (y = 0; y < cols; y++) {
            if (maze[x * cols + y].north != -1)
                printf(" N ");
            else
                printf("   ");

            if (maze[x * cols + y].east != -1)
                printf(" E ");
            else
                printf("   ");

            if (maze[x * cols + y].south != -1)
                printf(" S ");
            else
                printf("   ");

            if (maze[x * cols + y].west != -1)
                printf(" W ");
            else
                printf("   ");

            printf("%s\n", maze[x * cols + y].name);
        }
    }
}

int main(void) {
    int rows, cols, i;
    Room *maze;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    maze = (Room *)calloc(rows * cols, sizeof(Room));

    if (!maze) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    create_maze(maze, rows, cols);
    print_maze(maze, rows, cols);

    for (i = 0; i < rows * cols; i++) {
        free(maze[i].name);
    }
    free(maze);

    return EXIT_SUCCESS;
}