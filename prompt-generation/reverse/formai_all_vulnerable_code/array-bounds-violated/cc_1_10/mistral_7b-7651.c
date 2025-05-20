//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define WIDTH 50
#define HEIGHT 10

typedef struct {
    int x;
    int y;
    char c;
} Point;

void print_pattern(Point points[], int num_points) {
    for (int i = 0; i < num_points; i++) {
        int x = points[i].x;
        int y = points[i].y;
        char c = points[i].c;

        for (int j = 0; j < WIDTH; j++) {
            if (j < x || j > x + 2 || (y == 0 && j == x))
                printf(" ");
            else
                printf("%c", c);
        }

        printf("\n");
    }
}

int main() {
    Point points[HEIGHT * 2];

    int i = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x > WIDTH / 2)
                points[i++] = (Point){x, y, '*'};
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x <= WIDTH / 2) {
                points[i++] = (Point){x, y, '.'};
            }
        }
    }

    print_pattern(points, i);

    return 0;
}