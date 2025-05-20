//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int size;
    int num;
    int sum = 0;
    double avg;
    double min, max;
    int count = 0;
    int i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    avg = (double) sum / size;

    printf("The sum of the array is: %d\n", sum);
    printf("The average of the array is: %.2f\n", avg);

    min = arr[0];
    max = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("The minimum value in the array is: %d\n", min);
    printf("The maximum value in the array is: %d\n", max);

    count = 0;
    printf("Enter a number to count its occurrence in the array: ");
    scanf("%d", &num);

    for (i = 0; i < size; i++) {
        if (arr[i] == num) {
            count++;
        }
    }

    printf("The number %d occurs %d times in the array.\n", num, count);

    return 0;
}