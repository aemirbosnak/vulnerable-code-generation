//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char key[11];
    int value;
} Record;

void swap(Record *a, Record *b) {
    Record temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Record arr[], int low, int high) {
    int pivot = arr[high].value;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].value < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Record arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(Record arr[], char *x, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (strcmp(arr[mid].key, x) == 0)
            return mid;

        if (strcmp(arr[mid].key, x) < 0)
            return binarySearch(arr, x, mid + 1, high);

        return binarySearch(arr, x, low, mid - 1);
    }

    return -1;
}

int main() {
    Record data[MAX];
    int n, i, found = 0;
    char key[11];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d records:\n", n);

    for (i = 0; i < n; i++) {
        printf("Record %d: ", i + 1);
        scanf("%s%d", data[i].key, &data[i].value);
    }

    printf("\nEnter the key to search: ");
    scanf("%s", key);

    quickSort(data, 0, n - 1);

    found = binarySearch(data, key, 0, n - 1);

    (found != -1) ? printf("\nKey %s found at location %d\n", key, found + 1) :
                   printf("\nKey %s not present in the array\n", key);

    return 0;
}