//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Watson's memory map
typedef struct _map {
    int width;
    int height;
    char **data;
} map;

// Sherlock's pathfinding algorithm
int find_path(map *m, int x1, int y1, int x2, int y2) {
    // Allocate memory for the visited array
    int **visited = malloc(sizeof(int *) * m->height);
    for (int i = 0; i < m->height; i++) {
        visited[i] = malloc(sizeof(int) * m->width);
    }

    // Initialize the visited array to 0
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            visited[i][j] = 0;
        }
    }

    // Create a queue to store the cells to be visited
    typedef struct _queue {
        int x;
        int y;
    } queue;

    queue *q = malloc(sizeof(queue));
    q->x = x1;
    q->y = y1;

    // While the queue is not empty
    while (q->x != -1 && q->y != -1) {
        // Pop the first cell from the queue
        int x = q->x;
        int y = q->y;
        q++;

        // Mark the cell as visited
        visited[y][x] = 1;

        // Check if the cell is the destination
        if (x == x2 && y == y2) {
            // Free the memory for the visited array
            for (int i = 0; i < m->height; i++) {
                free(visited[i]);
            }
            free(visited);

            // Free the memory for the queue
            free(q);

            // Return the number of steps taken
            return visited[y][x];
        }

        // Add the adjacent cells to the queue
        if (x > 0 && m->data[y][x - 1] != 'X' && visited[y][x - 1] == 0) {
            q->x = x - 1;
            q->y = y;
        }
        if (y > 0 && m->data[y - 1][x] != 'X' && visited[y - 1][x] == 0) {
            q->x = x;
            q->y = y - 1;
        }
        if (x < m->width - 1 && m->data[y][x + 1] != 'X' && visited[y][x + 1] == 0) {
            q->x = x + 1;
            q->y = y;
        }
        if (y < m->height - 1 && m->data[y + 1][x] != 'X' && visited[y + 1][x] == 0) {
            q->x = x;
            q->y = y + 1;
        }
    }

    // Free the memory for the visited array
    for (int i = 0; i < m->height; i++) {
        free(visited[i]);
    }
    free(visited);

    // Free the memory for the queue
    free(q);

    // Return -1 if the destination was not found
    return -1;
}

int main() {
    // Create the map
    map m;
    m.width = 8;
    m.height = 8;
    m.data = malloc(sizeof(char *) * m.height);
    for (int i = 0; i < m.height; i++) {
        m.data[i] = malloc(sizeof(char) * m.width);
    }

    // Initialize the map
    strcpy(m.data[0], "########");
    strcpy(m.data[1], "#......#");
    strcpy(m.data[2], "#..####.#");
    strcpy(m.data[3], "#......#");
    strcpy(m.data[4], "########");
    strcpy(m.data[5], "#......#");
    strcpy(m.data[6], "#......#");
    strcpy(m.data[7], "########");

    // Find the path from (1, 1) to (6, 6)
    int steps = find_path(&m, 1, 1, 6, 6);

    // Print the number of steps
    printf("The number of steps taken is %d\n", steps);

    // Free the memory for the map
    for (int i = 0; i < m.height; i++) {
        free(m.data[i]);
    }
    free(m.data);

    return 0;
}