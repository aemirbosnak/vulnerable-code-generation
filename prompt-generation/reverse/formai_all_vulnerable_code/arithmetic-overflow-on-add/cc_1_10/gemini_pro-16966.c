//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point *points;
    int size;
} fibonacci_sequence;

fibonacci_sequence* create_fibonacci_sequence(int size) {
    fibonacci_sequence *sequence = malloc(sizeof(fibonacci_sequence));
    sequence->points = malloc(sizeof(point) * size);
    sequence->size = size;

    sequence->points[0].x = 0;
    sequence->points[0].y = 0;
    sequence->points[1].x = 1;
    sequence->points[1].y = 1;

    for (int i = 2; i < size; i++) {
        sequence->points[i].x = sequence->points[i - 1].x + sequence->points[i - 2].x;
        sequence->points[i].y = sequence->points[i - 1].y + sequence->points[i - 2].y;
    }

    return sequence;
}

void free_fibonacci_sequence(fibonacci_sequence *sequence) {
    free(sequence->points);
    free(sequence);
}

void print_fibonacci_sequence(fibonacci_sequence *sequence) {
    for (int i = 0; i < sequence->size; i++) {
        printf("(%d, %d)\n", sequence->points[i].x, sequence->points[i].y);
    }
}

void draw_fibonacci_sequence(fibonacci_sequence *sequence) {
    int max_x = 0;
    int max_y = 0;

    for (int i = 0; i < sequence->size; i++) {
        if (sequence->points[i].x > max_x) {
            max_x = sequence->points[i].x;
        }
        if (sequence->points[i].y > max_y) {
            max_y = sequence->points[i].y;
        }
    }

    char *grid = malloc(sizeof(char) * (max_x + 1) * (max_y + 1));
    memset(grid, ' ', sizeof(char) * (max_x + 1) * (max_y + 1));

    for (int i = 0; i < sequence->size; i++) {
        grid[sequence->points[i].y * (max_x + 1) + sequence->points[i].x] = '*';
    }

    for (int i = 0; i <= max_y; i++) {
        for (int j = 0; j <= max_x; j++) {
            printf("%c", grid[i * (max_x + 1) + j]);
        }
        printf("\n");
    }

    free(grid);
}

int main() {
    int size = 10;
    fibonacci_sequence *sequence = create_fibonacci_sequence(size);

    print_fibonacci_sequence(sequence);
    printf("\n");
    draw_fibonacci_sequence(sequence);

    free_fibonacci_sequence(sequence);

    return 0;
}