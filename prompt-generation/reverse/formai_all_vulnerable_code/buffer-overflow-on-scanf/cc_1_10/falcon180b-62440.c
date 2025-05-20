//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} Pair;

void swap(Pair *a, Pair *b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    Pair *pairA = (Pair *)a;
    Pair *pairB = (Pair *)b;

    return strcmp(pairA->key, pairB->key);
}

void quickSort(Pair arr[], int left, int right) {
    int i = left, j = right;
    Pair pivot = arr[(left + right) / 2];
    Pair temp;

    while (i <= j) {
        while (strcmp(arr[i].key, pivot.key) < 0)
            i++;
        while (strcmp(arr[j].key, pivot.key) > 0)
            j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

void buildIndex(Pair arr[], int n) {
    qsort(arr, n, sizeof(Pair), compare);
}

int search(Pair arr[], char *key, int n) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (strcmp(arr[mid].key, key) == 0)
            return arr[mid].value;

        if (strcmp(arr[mid].key, key) < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    Pair arr[] = {{"John", 22}, {"Jane", 25}, {"Doe", 30}, {"Alice", 18}, {"Bob", 28}};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildIndex(arr, n);

    char key[MAX_SIZE];
    printf("Enter a name to search for: ");
    scanf("%s", key);

    int result = search(arr, key, n);

    if (result == -1)
        printf("Name not found.\n");
    else
        printf("Age of %s is %d.\n", key, result);

    return 0;
}