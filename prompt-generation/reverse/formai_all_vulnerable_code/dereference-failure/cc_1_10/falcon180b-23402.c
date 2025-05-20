//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBERS 1000
#define MIN_VALUE -1000
#define MAX_VALUE 1000

int main() {
    int num_elements;
    int i, j;
    int *numbers;
    double mean, median, mode;
    double sum = 0;

    srand(time(NULL));
    num_elements = rand() % MAX_NUMBERS + 1;
    numbers = (int *)malloc(num_elements * sizeof(int));

    for (i = 0; i < num_elements; i++) {
        numbers[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        sum += numbers[i];
    }

    mean = sum / num_elements;
    printf("Mean: %.2f\n", mean);

    for (i = 0; i < num_elements; i++) {
        if (numbers[i] > mean) {
            numbers[i] = numbers[i] - mean;
        } else {
            numbers[i] = numbers[i] + mean;
        }
    }

    median = numbers[num_elements / 2];
    printf("Median: %d\n", median);

    mode = numbers[0];
    for (i = 1; i < num_elements; i++) {
        if (numbers[i] > mode) {
            mode = numbers[i];
        }
    }

    printf("Mode: %d\n", mode);

    free(numbers);
    return 0;
}