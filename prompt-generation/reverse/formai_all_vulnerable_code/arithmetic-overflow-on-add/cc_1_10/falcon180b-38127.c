//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define TRUE 1
#define FALSE 0

int search(char *arr, int size, char *key) {
    int left = 0;
    int right = size - 1;
    int mid = (left + right) / 2;
    int cmp = 0;

    while (left <= right) {
        cmp = strcmp(arr + mid * sizeof(char), key);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }

    return -1;
}

int main() {
    char arr[MAX_SIZE];
    int size = 0;
    char key[MAX_SIZE];
    int result = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%s", arr + i * sizeof(char));
    }

    printf("Enter the key to search for:\n");
    scanf("%s", key);

    result = search(arr, size, key);

    if (result == -1) {
        printf("Key not found in the array.\n");
    } else {
        printf("Key found at index %d.\n", result);
    }

    return 0;
}