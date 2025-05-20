//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

void swap(Point *a, Point *b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    const Point *p1 = a;
    const Point *p2 = b;
    if (p1->x < p2->x) {
        return -1;
    } else if (p1->x > p2->x) {
        return 1;
    } else {
        return 0;
    }
}

int partition(Point arr[], int low, int high) {
    Point pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (compare(&arr[j], &pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(Point arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void generatePoints(int n, Point arr[]) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i].x = rand() % 200 - 100;
        arr[i].y = rand() % 200 - 100;
    }
}

void printPoints(int n, Point arr[]) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", arr[i].x, arr[i].y);
    }
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point arr[n];
    generatePoints(n, arr);

    printf("Before sorting:\n");
    printPoints(n, arr);

    quicksort(arr, 0, n - 1);

    printf("After sorting:\n");
    printPoints(n, arr);

    return 0;
}