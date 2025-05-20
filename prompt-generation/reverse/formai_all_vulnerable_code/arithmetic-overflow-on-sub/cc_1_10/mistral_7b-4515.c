//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 50

typedef struct Error {
    char message[100];
} Error;

Error create_error(char* message) {
    Error err;
    strcpy(err.message, message);
    return err;
}

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_array(int arr[], int size) {
    int i;
    printf("Array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int arr[MAX_SIZE], n, i;
    Error err;

    printf("Fortune teller: Today is a good day for sorting.\n");

    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        err = create_error("Array size is too large.");
        printf("%s\n", err.message);
        return 1;
    }

    printf("Filling array with random numbers:\n");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubble_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}