//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main(int argc, char *argv[]) {
    int i, j, temp, max_index, count;
    int *arr;
    char choice;

    printf("Enter the number of elements: ");
    scanf("%d", &max_index);

    arr = (int *)malloc(max_index * sizeof(int));

    printf("Enter %d integers:\n", max_index);
    for (i = 0; i < max_index; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the choice of sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            for (i = 0; i < max_index - 1; ++i) {
                for (j = 0; j < max_index - i - 1; ++j) {
                    if (arr[j] > arr[j + 1]) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            printf("Sorted array using Bubble Sort:\n");
            for (i = 0; i < max_index; ++i) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;

        case '2':
            for (i = 0; i < max_index - 1; ++i) {
                max_index = i;
                for (j = i + 1; j < max_index; ++j) {
                    if (arr[j] > arr[max_index]) {
                        max_index = j;
                    }
                }
                temp = arr[i];
                arr[i] = arr[max_index];
                arr[max_index] = temp;
            }
            printf("Sorted array using Selection Sort:\n");
            for (i = 0; i < max_index; ++i) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;

        case '3':
            for (i = 1; i < max_index; ++i) {
                temp = arr[i];
                j = i - 1;
                while (j >= 0 && arr[j] > temp) {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = temp;
            }
            printf("Sorted array using Insertion Sort:\n");
            for (i = 0; i < max_index; ++i) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;

        default:
            printf("Invalid choice of sorting algorithm!\n");
    }

    free(arr);
    return 0;
}