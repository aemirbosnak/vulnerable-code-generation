//Falcon-180B DATASET v1.0 Category: Sorting ; Style: futuristic
#include <stdio.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(Element* arr, int n) {
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].data < arr[min_idx].data) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

int main() {
    Element arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    selection_sort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d (%d)\n", arr[i].data, arr[i].index);
    }

    return 0;
}