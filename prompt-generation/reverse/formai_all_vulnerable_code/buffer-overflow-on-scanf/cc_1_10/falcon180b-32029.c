//Falcon-180B DATASET v1.0 Category: Educational ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MIN_VALUE 1
#define MAX_VALUE 100

int main() {
    int array[MAX_SIZE];
    int size;
    int sum = 0;
    int average;
    int min_value = MAX_VALUE;
    int max_value = MIN_VALUE;
    int count = 0;

    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    srand(time(NULL));

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        sum += array[i];

        if (array[i] < min_value) {
            min_value = array[i];
        }

        if (array[i] > max_value) {
            max_value = array[i];
        }
    }

    average = sum / size;

    printf("The sum of the array elements is: %d\n", sum);
    printf("The average of the array elements is: %.2f\n", (float)average);
    printf("The minimum value in the array is: %d\n", min_value);
    printf("The maximum value in the array is: %d\n", max_value);

    return 0;
}