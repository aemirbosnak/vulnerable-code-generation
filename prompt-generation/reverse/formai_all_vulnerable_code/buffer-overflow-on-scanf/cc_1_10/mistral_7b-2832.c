//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct {
    int key;
    char name[20];
} Data;

void binarySearch(Data arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid].key == x) {
            printf("The Golden Apple is located at index %d.\n", mid);
            return;
        }

        if (arr[mid].key < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("The Golden Apple was not found.\n");
}

int main() {
    Data arr[MAX];
    int i, n;

    printf("Welcome, brave adventurer, to BinaryBob's Database!\n");
    printf("Let us begin the search for the legendary Golden Apple.\n");

    printf("Please enter the number of data entries: ");
    scanf("%d", &n);

    printf("Now, enter each data entry with its corresponding key and name:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %s", &arr[i].key, arr[i].name);
    }

    printf("The search shall now commence!\n");

    printf("Enter the key of the Golden Apple: ");
    int key;
    scanf("%d", &key);

    binarySearch(arr, 0, n - 1, key);

    return 0;
}