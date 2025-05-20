//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct HashNode {
    int key;
    int index;
} HashNode;

int hashFunction(int key) {
    int hash = 0;
    for (int i = 0; i < 4; i++) {
        hash += key * (i + 1);
    }
    return hash % MAX_SIZE;
}

void createHashTable(HashNode table[MAX_SIZE], int array[], int size) {
    for (int i = 0; i < size; i++) {
        int index = hashFunction(array[i]);
        table[index].key = array[i];
        table[index].index = i;
    }
}

int crazySearch(HashNode table[MAX_SIZE], int target) {
    int left = 0, right = MAX_SIZE - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int index = table[mid].index;
        if (table[mid].key == target) {
            return index;
        }
        if (target < table[mid].key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int array[MAX_SIZE];
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    HashNode table[MAX_SIZE];
    createHashTable(table, array, size);

    printf("Enter the target element: ");
    scanf("%d", &target);

    int index = crazySearch(table, target);
    if (index != -1) {
        printf("Found the element at index %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}