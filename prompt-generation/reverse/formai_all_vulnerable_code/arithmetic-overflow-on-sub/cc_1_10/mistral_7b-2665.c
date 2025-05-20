//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    int key;
    char data[100];
} Item;

void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(Item arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Key: %d, Data: %s\n", arr[i].key, arr[i].data);
    }
}

int binarySearch(Item arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid].key == key) {
            return mid;
        }

        if (arr[mid].key < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int linearSearch(Item arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i].key == key) {
            return i;
        }
    }

    return -1;
}

int cSearching(Item arr[], int size, char *pattern) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (strncmp(arr[mid].data, pattern, strlen(pattern)) == 0) {
            return mid;
        }

        if (strncmp(arr[mid].data, pattern, strlen(pattern)) < 0) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    Item arr[MAX_SIZE];
    int n, m, p;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter key and data (%d/%d): ", i + 1, i + 1);
        scanf("%d %s", &arr[i].key, arr[i].data);
    }

    printf("Enter the number of queries: ");
    scanf("%d", &m);

    char query[100];

    for (int i = 0; i < m; i++) {
        printf("Enter query %d (%s): ", i + 1, query);
        scanf("%s", query);

        int index = cSearching(arr, n, query);

        if (index == -1) {
            printf("Not found!\n");
        } else {
            printf("Found at index %d!\n", index);
        }
    }

    printArray(arr, n);

    return 0;
}