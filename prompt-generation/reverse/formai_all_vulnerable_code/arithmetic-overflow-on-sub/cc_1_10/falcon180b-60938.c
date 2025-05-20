//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int search(char *arr[], int n, char *key);

int main() {
    char *arr[MAX_SIZE];
    int n = 0;
    char key[MAX_SIZE];

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    printf("Enter the search key: ");
    scanf("%s", key);

    int result = search(arr, n, key);

    if (result == -1) {
        printf("Key not found\n");
    } else {
        printf("Key found at index %d\n", result);
    }

    return 0;
}

int search(char *arr[], int n, char *key) {
    int *indexes = malloc(n * sizeof(int));
    int i = 0;

    for (i = 0; i < n; i++) {
        indexes[i] = i;
    }

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        int cmp = strcmp(arr[indexes[mid]], key);

        if (cmp == 0) {
            return indexes[mid];
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    free(indexes);
    return -1;
}