//Falcon-180B DATASET v1.0 Category: Sorting ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *array;
    int size;
} vector;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void print_vector(vector v) {
    int i;
    for (i = 0; i < v.size; i++) {
        printf("%d ", v.array[i]);
    }
    printf("\n");
}

void quick_sort(vector v, int low, int high) {
    int i = low, j = high;
    int pivot = v.array[(low + high) / 2];

    while (i <= j) {
        while (v.array[i] < pivot)
            i++;
        while (v.array[j] > pivot)
            j--;
        if (i <= j) {
            swap(&v.array[i], &v.array[j]);
            i++;
            j--;
        }
    }

    if (low < j)
        quick_sort(v, low, j);
    if (i < high)
        quick_sort(v, i, high);
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the size of the vector: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory error\n");
        return 1;
    }

    printf("Enter the elements of the vector:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    vector v;
    v.array = array;
    v.size = n;

    quick_sort(v, 0, n - 1);

    printf("Sorted vector:\n");
    print_vector(v);

    free(array);
    return 0;
}