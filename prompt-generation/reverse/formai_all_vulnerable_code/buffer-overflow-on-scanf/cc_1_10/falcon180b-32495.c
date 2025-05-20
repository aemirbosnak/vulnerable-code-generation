//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 50
#define MAX_VALUE 1000000

typedef struct {
    int x, y, value;
} Point;

void generateFibonacci(int maxValue, int *fibonacci) {
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i <= maxValue; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

void generateRandomPoints(int numPoints, Point *points, int maxValue) {
    srand(time(NULL));
    for (int i = 0; i < numPoints; i++) {
        points[i].x = rand() % WIDTH;
        points[i].y = rand() % HEIGHT;
        points[i].value = rand() % maxValue;
    }
}

void sortPoints(Point *points, int numPoints) {
    for (int i = 0; i < numPoints - 1; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            if (points[i].value > points[j].value) {
                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }
}

void drawPoint(int x, int y, int value) {
    printf("\033[H\033[2J");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (x == j && y == i) {
                printf("\033[1;31m*\033[0m");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\033[2A");
}

int main() {
    int maxValue, numPoints;
    Point *points;

    printf("Enter the maximum value: ");
    scanf("%d", &maxValue);

    printf("Enter the number of points: ");
    scanf("%d", &numPoints);

    points = (Point *)malloc(numPoints * sizeof(Point));

    generateFibonacci(maxValue, NULL);
    generateRandomPoints(numPoints, points, maxValue);
    sortPoints(points, numPoints);

    printf("Press any key to visualize the Fibonacci sequence...\n");
    getchar();

    for (int i = 0; i < numPoints; i++) {
        drawPoint(points[i].x, points[i].y, points[i].value);
        usleep(100000);
    }

    free(points);

    return 0;
}