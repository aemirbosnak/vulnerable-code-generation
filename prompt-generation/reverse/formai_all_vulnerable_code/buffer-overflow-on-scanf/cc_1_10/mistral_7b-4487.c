//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define KEY_SIZE 20

typedef struct {
    int index;
    char key[KEY_SIZE];
} Record;

void linear_search(Record arr[], char target[], int *index) {
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(arr[i].key, target) == 0) {
            *index = i;
            return;
        }
    }

    *index = -1;
}

void binary_search(Record arr[], char target[], int *index) {
    int low = 0, high = SIZE - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (strcmp(arr[mid].key, target) == 0) {
            *index = mid;
            return;
        } else if (strcmp(arr[mid].key, target) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    *index = -1;
}

int main() {
    Record records[SIZE];
    char target[KEY_SIZE];
    int index;

    printf("Enter %d records:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Record %d: ", i + 1);
        scanf("%s", records[i].key);
    }

    printf("\nEnter target key: ");
    scanf("%s", target);

    binary_search(records, target, &index);

    if (index >= 0)
        printf("\nKey '%s' found at index %d.\n", target, index);
    else
        printf("\nKey '%s' not found.\n", target);

    linear_search(records, target, &index);

    if (index >= 0)
        printf("\nKey '%s' found at index %d (linear search).\n", target, index);
    else
        printf("\nKey '%s' not found (linear search).\n", target);

    return 0;
}