//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *data;
    int size;
    int capacity;
} PointArray;

void PointArray_init(PointArray *array) {
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

void PointArray_free(PointArray *array) {
    if (array->data!= NULL) {
        free(array->data);
    }
}

void PointArray_resize(PointArray *array, int new_capacity) {
    if (array->capacity == 0) {
        array->capacity = 1;
    } else {
        array->capacity *= 2;
    }

    Point *new_data = realloc(array->data, array->capacity * sizeof(Point));

    if (new_data == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    array->data = new_data;
}

void PointArray_push(PointArray *array, int x, int y) {
    if (array->size == array->capacity) {
        PointArray_resize(array, array->capacity * 2);
    }

    array->data[array->size].x = x;
    array->data[array->size].y = y;

    array->size++;
}

void PointArray_print(PointArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("(%d, %d)\n", array->data[i].x, array->data[i].y);
    }
}

int main() {
    PointArray points;
    PointArray_init(&points);

    int x, y;
    while (scanf("%d %d", &x, &y)!= EOF) {
        PointArray_push(&points, x, y);
    }

    PointArray_print(&points);

    PointArray_free(&points);

    return 0;
}