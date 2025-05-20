//LLAMA2-13B DATASET v1.0 Category: Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SHAPE_MAX 5
#define SHAPE_SQUARE 1
#define SHAPE_CIRCLE 2
#define SHAPE_TRIANGLE 3
#define SHAPE_RECTANGLE 4

typedef struct shape {
    int type;
    int x, y;
    int size;
} shape_t;

shape_t shapes[SHAPE_MAX] = {
    {SHAPE_SQUARE, 0, 50},
    {SHAPE_CIRCLE, 100, 50},
    {SHAPE_TRIANGLE, 200, 100},
    {SHAPE_RECTANGLE, 300, 200},
};

int main() {
    srand(time(NULL));

    for (int i = 0; i < SHAPE_MAX; i++) {
        shape_t *shape = &shapes[i];

        switch (shape->type) {
            case SHAPE_SQUARE:
                printf("Shape %d: Square at (%d, %d) with size %d\n", i, shape->x, shape->y, shape->size);
                break;
            case SHAPE_CIRCLE:
                printf("Shape %d: Circle at (%d, %d) with radius %d\n", i, shape->x, shape->y, shape->size / 2);
                break;
            case SHAPE_TRIANGLE:
                printf("Shape %d: Triangle at (%d, %d) with size %d\n", i, shape->x, shape->y, shape->size);
                break;
            case SHAPE_RECTANGLE:
                printf("Shape %d: Rectangle at (%d, %d) with size %dx%d\n", i, shape->x, shape->y, shape->size, shape->size);
                break;
        }
    }

    for (int i = 0; i < SHAPE_MAX; i++) {
        shape_t *shape = &shapes[i];

        switch (shape->type) {
            case SHAPE_SQUARE:
                shape->x = rand() % (400 - 100) + 100;
                shape->y = rand() % (300 - 100) + 100;
                shape->size = rand() % (100 - 50) + 50;
                break;
            case SHAPE_CIRCLE:
                shape->x = rand() % (400 - 150) + 150;
                shape->y = rand() % (300 - 150) + 150;
                shape->size = rand() % (150 - 50) + 50;
                break;
            case SHAPE_TRIANGLE:
                shape->x = rand() % (400 - 200) + 200;
                shape->y = rand() % (300 - 200) + 200;
                shape->size = rand() % (200 - 100) + 100;
                break;
            case SHAPE_RECTANGLE:
                shape->x = rand() % (400 - 300) + 300;
                shape->y = rand() % (300 - 300) + 300;
                shape->size = rand() % (300 - 200) + 200;
                break;
        }
    }

    for (int i = 0; i < SHAPE_MAX; i++) {
        shape_t *shape = &shapes[i];

        switch (shape->type) {
            case SHAPE_SQUARE:
                printf("Shape %d: Square at (%d, %d) with size %d\n", i, shape->x, shape->y, shape->size);
                break;
            case SHAPE_CIRCLE:
                printf("Shape %d: Circle at (%d, %d) with radius %d\n", i, shape->x, shape->y, shape->size / 2);
                break;
            case SHAPE_TRIANGLE:
                printf("Shape %d: Triangle at (%d, %d) with size %d\n", i, shape->x, shape->y, shape->size);
                break;
            case SHAPE_RECTANGLE:
                printf("Shape %d: Rectangle at (%d, %d) with size %dx%d\n", i, shape->x, shape->y, shape->size, shape->size);
                break;
        }
    }

    return 0;
}