//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} KeyValuePair;

int main() {
    int numPairs, i;
    KeyValuePair *pairs;

    printf("Enter the number of key-value pairs: ");
    scanf("%d", &numPairs);

    pairs = (KeyValuePair *)malloc(numPairs * sizeof(KeyValuePair));

    printf("Enter the key-value pairs:\n");
    for (i = 0; i < numPairs; i++) {
        pairs[i].key = (char *)malloc(MAX_SIZE * sizeof(char));
        scanf(" %s", pairs[i].key);
        pairs[i].value = i;
    }

    printf("Enter the search key: ");
    char searchKey[MAX_SIZE];
    scanf(" %s", searchKey);

    int result = binarySearch(pairs, numPairs, searchKey);

    if (result == -1) {
        printf("Key not found!\n");
    } else {
        printf("Key found at index %d\n", result);
    }

    free(pairs);
    return 0;
}

int binarySearch(KeyValuePair *pairs, int numPairs, char *searchKey) {
    int left = 0, right = numPairs - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int cmp = strcmp(pairs[mid].key, searchKey);

        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}