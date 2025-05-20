//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define PI 3.14159265358979323846

typedef struct {
    int x, y;
} Point;

void print_point(Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}

Point add(Point a, Point b) {
    Point c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

Point multiply_matrix(Point matrix[3][3], Point vector) {
    Point result;
    for (int i = 0; i < 3; i++) {
        result.x += matrix[i][0].x * vector.x + matrix[i][0].y * vector.y;
        result.y += matrix[i][1].x * vector.x + matrix[i][1].y * vector.y;
    }
    return result;
}

void print_matrix(Point matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j].x);
        }
        printf("\t");
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j].y);
        }
        printf("\n");
    }
}

int main() {
    Point p1 = {5, 10};
    Point p2 = {1, 2};
    Point p3, p4;

    p3 = add(p1, p2);
    print_point(p3);

    Point matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Point vector = {1, 2};

    p4 = multiply_matrix(matrix, vector);
    print_point(p4);

    printf("\nMatrix:\n");
    print_matrix(matrix);

    return 0;
}