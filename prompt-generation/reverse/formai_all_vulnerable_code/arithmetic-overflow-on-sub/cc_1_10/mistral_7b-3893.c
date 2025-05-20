//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    int key;
    char name[20];
} Data;

bool compare(const void *a, const void *b) {
    Data *x = (Data *)a;
    Data *y = (Data *)b;
    if (x->key < y->key) {
        return true;
    }
    if (x->key > y->key) {
        return false;
    }
    return strcmp(x->name, y->name) < 0;
}

void swap(Data *a, Data *b) {
    Data temp = *a;
    *a = *b;
    *b = temp;
}

int c_search(Data arr[], int left, int right, int key) {
    int mid1, mid2, mid3;

    while (left <= right) {
        mid1 = left + (right - left) / 3;
        mid2 = right - (right - left) / 3;

        if (arr[mid1].key == key) {
            return mid1;
        }

        if (arr[mid1].key < key) {
            if (arr[mid2].key >= key) {
                swap(&arr[mid1], &arr[mid2]);
                left = mid1 + 1;
            } else {
                right = mid2 - 1;
            }
        } else {
            if (arr[mid1].key > key) {
                if (arr[mid2].key <= key) {
                    swap(&arr[mid1], &arr[mid2]);
                    left = mid1 - 1;
                } else {
                    right = mid1 - 1;
                }
            } else {
                if (arr[mid1].key == arr[mid2].key) {
                    if (strcmp(arr[mid1].name, arr[right].name) < 0) {
                        swap(&arr[mid1], &arr[right]);
                    }
                    swap(&arr[mid1], &arr[mid2]);
                    swap(&arr[mid2], &arr[right]);
                    right--;
                } else {
                    swap(&arr[mid1], &arr[mid2]);
                    mid1 = mid1 + (right - mid2);
                    right = mid1 - 1;
                }
            }
        }
    }

    return -1;
}

int main() {
    Data arr[MAX_SIZE];
    int n, i, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d%s", &arr[i].key, arr[i].name);
    }

    qsort(arr, n, sizeof(Data), compare);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int index = c_search(arr, 0, n - 1, key);

    if (index == -1) {
        printf("Key %d not found!\n", key);
    } else {
        printf("Key %d found at index %d and name %s!\n", key, index, arr[index].name);
    }

    return 0;
}