//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000

int main() {
    int num, i, j;
    srand(time(NULL));
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 1 || num > MAX_NUM) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_NUM);
        return 1;
    }

    int *arr = (int *)malloc(num * sizeof(int));

    for (i = 0; i < num; i++) {
        arr[i] = rand() % 100;
    }

    printf("Original array:\n");
    for (i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }

    int sum = 0;
    for (i = 0; i < num; i++) {
        sum += arr[i];
    }

    double avg = (double)sum / num;
    printf("\nAverage: %.2f\n", avg);

    int max = arr[0];
    int min = arr[0];

    for (i = 1; i < num; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    free(arr);
    return 0;
}