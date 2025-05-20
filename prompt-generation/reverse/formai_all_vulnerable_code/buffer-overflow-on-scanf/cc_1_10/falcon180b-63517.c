//Falcon-180B DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int id;
} item;

void swap(item* a, item* b) {
    item temp;
    temp.data = a->data;
    temp.id = a->id;
    a->data = b->data;
    a->id = b->id;
    b->data = temp.data;
    b->id = temp.id;
}

int compare(const void* a, const void* b) {
    const item* itema = (const item*)a;
    const item* itemb = (const item*)b;
    if (itema->data > itemb->data) {
        return 1;
    } else if (itema->data < itemb->data) {
        return -1;
    }
    return 0;
}

void quicksort(item arr[], int left, int right) {
    int i = left, j = right;
    item pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i].data < pivot.data) {
            i++;
        }
        while (arr[j].data > pivot.data) {
            j--;
        }
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quicksort(arr, left, j);
    }
    if (i < right) {
        quicksort(arr, i, right);
    }
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of items to sort: ");
    scanf("%d", &n);
    item arr[n];
    printf("Enter the data and id of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].data, &arr[i].id);
    }
    quicksort(arr, 0, n - 1);
    printf("Sorted items:\n");
    for (int i = 0; i < n; i++) {
        printf("%d (%d)\n", arr[i].data, arr[i].id);
    }
    return 0;
}