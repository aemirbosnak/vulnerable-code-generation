//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(x, y) do { tmp = (x); (x) = (y); (y) = tmp; } while (0)

typedef struct { int key; char name[20]; } record;

int compare(const void *a, const void *b) {
    const record *aa = a, *bb = b;
    if (aa->key < bb->key) return -1;
    if (aa->key > bb->key) return 1;
    return strcmp(aa->name, bb->name);
}

void merge(record arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    record L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    for (k = l; k <= r; k++) {
        if (i < n1 && (j >= n2 || L[i].key <= R[j].key)) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
    }
}

void mergeSort(record arr[], int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    int n, i;
    record arr[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d%s", &arr[i].key, arr[i].name);
    }

    mergeSort(arr, 0, n - 1);

    for (i = 0; i < n; i++) {
        printf("%d %s\n", arr[i].key, arr[i].name);
    }

    return 0;
}