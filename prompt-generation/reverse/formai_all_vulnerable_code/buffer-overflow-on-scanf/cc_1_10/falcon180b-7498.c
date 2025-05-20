//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} KeyValuePair;

int compare(const void *a, const void *b) {
    KeyValuePair kvpA = *(KeyValuePair*)a;
    KeyValuePair kvpB = *(KeyValuePair*)b;

    int result = strcmp(kvpA.key, kvpB.key);

    if (result == 0) {
        result = kvpA.value - kvpB.value;
    }

    return result;
}

void swap(KeyValuePair *a, KeyValuePair *b) {
    KeyValuePair temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(KeyValuePair arr[], int n) {
    for (int i = 1; i < n; i++) {
        KeyValuePair key = arr[i];
        int j = i - 1;

        while (j >= 0 && compare(&arr[j], &key) > 0) {
            swap(&arr[j + 1], &arr[j]);
            j--;
        }

        arr[j + 1] = key;
    }
}

int binarySearch(KeyValuePair arr[], int size, char *key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int result = compare(&arr[mid], key);

        if (result == 0) {
            return mid;
        } else if (result < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    KeyValuePair arr[MAX_SIZE];

    for (int i = 0; i < n; i++) {
        char key[100];
        scanf("%s", key);
        int value;
        scanf("%d", &value);

        arr[i].key = strdup(key);
        arr[i].value = value;
    }

    insertionSort(arr, n);

    char searchKey[100];
    scanf("%s", searchKey);

    int index = binarySearch(arr, n, searchKey);

    if (index == -1) {
        printf("Key not found.\n");
    } else {
        printf("Value: %d\n", arr[index].value);
    }

    for (int i = 0; i < n; i++) {
        free(arr[i].key);
    }

    return 0;
}