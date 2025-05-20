//FormAI DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

struct index {
    int key;
    int pointer;
};

int compare(const void *a, const void *b) {
    const struct index *ia = (const struct index *) a;
    const struct index *ib = (const struct index *) b;
    return (ia->key - ib->key);
}

int search(struct index *arr, int numElems, int value) {
    int low = 0;
    int high = numElems - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid].key == value) {
            return arr[mid].pointer;
        } else if (arr[mid].key < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int num;
    printf("Enter number of indexes: ");
    scanf("%d", &num);
    struct index *arr;
    arr = (struct index *) malloc(num * sizeof(struct index));
    printf("Enter %d indexes (key, pointer): \n", num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i].key);
        scanf("%d", &arr[i].pointer);
    }
    qsort(arr, num, sizeof(struct index), compare);
    int value;
    printf("Enter a key to search: ");
    scanf("%d", &value);
    int result = search(arr, num, value);
    if (result == -1) {
        printf("Key not found\n");
    } else {
        printf("Key found at pointer %d\n", result);
    }
    free(arr);
    return 0;
}