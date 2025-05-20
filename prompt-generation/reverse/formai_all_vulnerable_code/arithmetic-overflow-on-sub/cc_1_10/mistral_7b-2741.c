//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int key;
    char name[20];
} Element;

void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Element arr[], int low, int high) {
    int pivot = arr[high].key;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].key <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void knuthZaratoiniSearch(Element arr[], int low, int high, int x) {
    int k;

    if (high <= low)
        return;

    k = partition(arr, low, high);

    if (arr[k].key == x) {
        printf("\nElement found at index %d", k);
        return;
    }

    if (x < arr[k].key)
        knuthZaratoiniSearch(arr, low, k - 1, x);
    else
        knuthZaratoiniSearch(arr, k + 1, high, x);
}

int main() {
    int n, i, searchKey;
    Element *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (Element *)malloc(n * sizeof(Element));

    for (i = 0; i < n; i++) {
        printf("\nEnter the key and name for element %d: ", i + 1);
        scanf("%d %s", &arr[i].key, arr[i].name);
    }

    printf("\nEnter the key to search: ");
    scanf("%d", &searchKey);

    knuthZaratoiniSearch(arr, 0, n - 1, searchKey);

    if (n > 0)
        free(arr);

    return 0;
}