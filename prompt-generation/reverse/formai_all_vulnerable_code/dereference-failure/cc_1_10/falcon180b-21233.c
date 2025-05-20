//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000
#define PI 3.14159265358979323846

typedef struct {
    int id;
    double x, y;
} Point;

int compare(const void* a, const void* b) {
    Point* pointA = (Point*)a;
    Point* pointB = (Point*)b;

    if (pointA->x < pointB->x) {
        return -1;
    } else if (pointA->x > pointB->x) {
        return 1;
    } else {
        return 0;
    }
}

void quicksort(Point* arr, int left, int right) {
    int i = left, j = right;
    Point pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i].x < pivot.x) {
            i++;
        }
        while (arr[j].x > pivot.x) {
            j--;
        }
        if (i <= j) {
            Point temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) {
        quicksort(arr, left, j);
    }
    if (i < right) {
        quicksort(arr, i, right);
    }
}

int main() {
    int numPoints;
    Point* points;

    printf("Enter the number of points: ");
    scanf("%d", &numPoints);

    points = (Point*)malloc(numPoints * sizeof(Point));
    if (points == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    for (int i = 0; i < numPoints; i++) {
        printf("Enter the ID and coordinates of point %d:\n", i + 1);
        scanf("%d %lf %lf", &points[i].id, &points[i].x, &points[i].y);
    }

    quicksort(points, 0, numPoints - 1);

    printf("Sorted points:\n");
    for (int i = 0; i < numPoints; i++) {
        printf("ID %d: (%lf, %lf)\n", points[i].id, points[i].x, points[i].y);
    }

    free(points);
    return 0;
}