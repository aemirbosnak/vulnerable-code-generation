//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000
#define MIN_VALUE -1000
#define MAX_VALUE 1000

int main(int argc, char *argv[]) {
    int i, j, n, m, count = 0;
    double sum = 0, avg, std_dev = 0;
    double arr[MAX_SIZE];
    double mean, variance;
    clock_t start, end;

    srand(time(NULL));

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    printf("\nOriginal Array:\n");
    for (i = 0; i < n; i++) {
        printf("%lf ", arr[i]);
    }
    printf("\n");

    start = clock();
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    end = clock();
    avg = sum / n;
    printf("\nAverage: %.2lf\n", avg);

    start = clock();
    for (i = 0; i < n; i++) {
        sum += pow(arr[i] - avg, 2);
    }
    end = clock();
    variance = sum / n;
    std_dev = sqrt(variance);
    printf("Standard Deviation: %.2lf\n", std_dev);

    return 0;
}