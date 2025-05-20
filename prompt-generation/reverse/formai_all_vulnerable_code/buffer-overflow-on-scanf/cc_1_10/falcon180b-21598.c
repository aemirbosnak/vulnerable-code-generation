//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// Function to compare two strings
int compare(char *str1, char *str2) {
    int i = 0;
    while (str1[i] == str2[i]) {
        i++;
    }
    return (str1[i] - str2[i]);
}

// Function to perform a binary search on a sorted array
int binarySearch(char *arr[], int size, char *key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = compare(arr[mid], key);

        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    char **arr = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        arr[i] = (char *)malloc(100 * sizeof(char));
        printf("Enter element %d: ", i + 1);
        scanf("%s", arr[i]);
    }

    char *key;
    printf("Enter the key to search for: ");
    scanf("%s", key);

    int index = binarySearch(arr, size, key);

    if (index == -1) {
        printf("Key not found\n");
    } else {
        printf("Key found at index %d\n", index);
    }

    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}