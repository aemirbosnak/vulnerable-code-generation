//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int size;
    int *arr;
    int sum = 0;
    int count = 0;
    int max = 0;
    int min = 0;
    int avg = 0;
    int i;
    int j;
    int k;
    int temp;
    int choice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int *) malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    printf("Enter the elements of the array:\n");

    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter your choice:\n");
    printf("1. Find the sum of elements\n");
    printf("2. Find the average of elements\n");
    printf("3. Find the maximum element\n");
    printf("4. Find the minimum element\n");
    printf("5. Sort the array in ascending order\n");
    printf("6. Sort the array in descending order\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (i = 0; i < size; i++) {
                sum += arr[i];
            }
            printf("The sum of elements is: %d\n", sum);
            break;
        case 2:
            for (i = 0; i < size; i++) {
                avg += arr[i];
            }
            avg /= size;
            printf("The average of elements is: %d\n", avg);
            break;
        case 3:
            max = arr[0];
            for (i = 1; i < size; i++) {
                if (arr[i] > max) {
                    max = arr[i];
                }
            }
            printf("The maximum element is: %d\n", max);
            break;
        case 4:
            min = arr[0];
            for (i = 1; i < size; i++) {
                if (arr[i] < min) {
                    min = arr[i];
                }
            }
            printf("The minimum element is: %d\n", min);
            break;
        case 5:
            for (i = 0; i < size - 1; i++) {
                for (j = i + 1; j < size; j++) {
                    if (arr[i] > arr[j]) {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("The array in ascending order is:\n");
            for (i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 6:
            for (i = 0; i < size - 1; i++) {
                for (j = i + 1; j < size; j++) {
                    if (arr[i] < arr[j]) {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("The array in descending order is:\n");
            for (i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        default:
            printf("Invalid choice\n");
    }

    free(arr);
    return 0;
}