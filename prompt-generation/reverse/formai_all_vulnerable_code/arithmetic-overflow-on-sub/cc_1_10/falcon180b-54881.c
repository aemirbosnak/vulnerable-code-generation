//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} pair;

void swap(pair* a, pair* b) {
    pair temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(pair arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l].data > arr[largest].data)
        largest = l;

    if(r < n && arr[r].data > arr[largest].data)
        largest = r;

    if(largest!= i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(pair arr[], int n) {
    int i;

    for(i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(i = n-1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int i, n, search_key;
    pair arr[MAX_SIZE];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    heapSort(arr, n);

    printf("Enter the search key: ");
    scanf("%d", &search_key);

    int index = -1;
    pair* p = (pair*)malloc(sizeof(pair));
    p->data = search_key;
    p->index = index;

    int j = n-1;
    while(j >= 0) {
        if(arr[j].data == search_key) {
            index = arr[j].index;
            break;
        }
        j--;
    }

    if(index == -1)
        printf("Element not found!\n");
    else
        printf("Element found at index %d.\n", index);

    return 0;
}