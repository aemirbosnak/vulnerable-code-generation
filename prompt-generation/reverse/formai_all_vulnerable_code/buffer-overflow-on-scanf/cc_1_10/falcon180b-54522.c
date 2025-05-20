//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    char *name;
    Point location;
} Room;

void generate_maze(int width, int height, Room rooms[26]) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            rooms[i * width + j].location.x = j;
            rooms[i * width + j].location.y = i;
        }
    }
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int count = 0;
            if (i > 0 && rooms[i * width + j].location.y == rooms[(i - 1) * width + j].location.y) {
                count++;
            }
            if (i < height - 1 && rooms[i * width + j].location.y == rooms[(i + 1) * width + j].location.y) {
                count++;
            }
            if (j > 0 && rooms[i * width + j].location.x == rooms[i * width + (j - 1)].location.x) {
                count++;
            }
            if (j < width - 1 && rooms[i * width + j].location.x == rooms[i * width + (j + 1)].location.x) {
                count++;
            }
            if (count == 1) {
                rooms[i * width + j].location.x += (rand() % 2) - 1;
                rooms[i * width + j].location.y += (rand() % 2) - 1;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int width, height;
    printf("Enter the width of the maze: ");
    scanf("%d", &width);
    printf("Enter the height of the maze: ");
    scanf("%d", &height);
    Room rooms[26];
    generate_maze(width, height, rooms);
    return 0;
}