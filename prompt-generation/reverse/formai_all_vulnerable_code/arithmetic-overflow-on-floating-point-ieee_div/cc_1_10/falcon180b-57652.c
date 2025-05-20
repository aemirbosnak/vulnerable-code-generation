//Falcon-180B DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000
#define MAX_ITERATIONS 100000

struct Point {
    double x;
    double y;
};

void generateRandomPoints(struct Point* points, int size) {
    for (int i = 0; i < size; i++) {
        points[i].x = rand() % MAX_SIZE;
        points[i].y = rand() % MAX_SIZE;
    }
}

void printPoints(struct Point* points, int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d,%d)\n", points[i].x, points[i].y);
    }
}

int isConvex(struct Point* points, int size) {
    int numConvex = 0;
    for (int i = 0; i < size - 2; i++) {
        double slope1 = (points[i+1].y - points[i].y) / (points[i+1].x - points[i].x);
        double slope2 = (points[i+2].y - points[i+1].y) / (points[i+2].x - points[i+1].x);
        if (slope1 >= slope2 && slope2 >= 0) {
            numConvex++;
        }
    }
    return numConvex == size - 2;
}

int main() {
    struct Point points[MAX_SIZE];
    int size = rand() % MAX_SIZE + 3;
    generateRandomPoints(points, size);
    printf("Random points:\n");
    printPoints(points, size);
    if (isConvex(points, size)) {
        printf("The points form a convex polygon.\n");
    } else {
        printf("The points do not form a convex polygon.\n");
    }
    return 0;
}