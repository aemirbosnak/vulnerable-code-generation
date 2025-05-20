//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000

int main() {
    int size;
    int *arr;
    int sum = 0;
    int product = 1;
    double avg;
    double std_dev;
    int count = 0;
    int i;
    int j;
    int k;

    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int*)malloc(size * sizeof(int));

    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    printf("\nThe array is:\n");

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nThe sum of the array is: %d", sum);

    for (i = 0; i < size; i++) {
        sum += arr[i];
    }

    printf("\n\nThe product of the array is: %d", product);

    for (i = 0; i < size; i++) {
        product *= arr[i];
    }

    printf("\n\nThe average of the array is: %.2f", (double)sum / size);

    avg = (double)sum / size;

    for (i = 0; i < size; i++) {
        avg -= arr[i];
        avg *= avg;
        std_dev += avg;
    }

    std_dev = sqrt(std_dev / size);

    printf("\n\nThe standard deviation of the array is: %.2f", std_dev);

    free(arr);

    return 0;
}