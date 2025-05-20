//Falcon-180B DATASET v1.0 Category: Data mining ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VAL 100

int main() {
    int arr[MAX_SIZE];
    int i, j, min, max, avg, sum = 0;
    int minindex, maxindex;
    double avgval;
    srand(time(NULL));

    printf("Enter the number of elements in the array: ");
    scanf("%d", &i);

    for (j = 0; j < i; j++) {
        arr[j] = rand() % MAX_VAL;
        sum += arr[j];
    }

    printf("The array is: ");
    for (j = 0; j < i; j++) {
        printf("%d ", arr[j]);
    }

    printf("\nThe sum of the array is: %d", sum);

    min = max = arr[0];
    minindex = maxindex = 0;

    for (j = 1; j < i; j++) {
        if (arr[j] < min) {
            min = arr[j];
            minindex = j;
        }
        if (arr[j] > max) {
            max = arr[j];
            maxindex = j;
        }
    }

    printf("\nThe minimum value in the array is: %d at index %d", min, minindex);
    printf("\nThe maximum value in the array is: %d at index %d", max, maxindex);

    avgval = (double) sum / i;
    printf("\nThe average value of the array is: %.2f", avgval);

    return 0;
}