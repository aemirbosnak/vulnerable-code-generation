//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_SHAPE_SIZE 100

typedef struct shape_t {
    int x;
    int y;
    int width;
    int height;
} shape_t;

void init_shape(shape_t* s) {
    s->x = 0;
    s->y = 0;
    s->width = 0;
    s->height = 0;
}

void add_point(shape_t* s, int x, int y) {
    if (s->width == 0) {
        s->x = x;
        s->y = y;
        s->width = 1;
        s->height = 1;
    } else if (x < s->x + s->width) {
        s->width++;
        s->x = x;
    } else if (x == s->x + s->width && y < s->y + s->height) {
        s->height++;
        s->y = y;
    }
}

int main() {
    shape_t shape;
    init_shape(&shape);
    int log_size = 0;
    char log[MAX_LOG_SIZE];

    while (fgets(log, MAX_LOG_SIZE, stdin)!= NULL) {
        log_size++;
        if (log_size % 10000 == 0) {
            printf("Log size: %d\n", log_size);
        }
        char* token = strtok(log, " ");
        while (token!= NULL) {
            if (strncmp(token, "add", 3) == 0) {
                int x, y;
                sscanf(token + 3, "%d %d", &x, &y);
                add_point(&shape, x, y);
            }
            token = strtok(NULL, " ");
        }
    }

    printf("Shape:\n");
    for (int y = 0; y < shape.height; y++) {
        for (int x = 0; x < shape.width; x++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}