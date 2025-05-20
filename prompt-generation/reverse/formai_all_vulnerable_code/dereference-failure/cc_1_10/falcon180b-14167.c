//Falcon-180B DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    char name[MAX_SIZE];
} item;

void swap(item* a, item* b) {
    item temp = *a;
    *a = *b;
    *b = temp;
}

int compare_name(const void* a, const void* b) {
    return strcmp(*(item**)a, *(item**)b);
}

int compare_data(const void* a, const void* b) {
    return (*(item**)a)->data - (*(item**)b)->data;
}

int main() {
    int n;
    scanf("%d", &n);

    item* arr = (item*)malloc(n * sizeof(item));

    for (int i = 0; i < n; i++) {
        scanf("%s %d", arr[i].name, &arr[i].data);
    }

    int choice;
    printf("Sort by:\n1. Name\n2. Data\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            qsort(arr, n, sizeof(item), compare_name);
            break;
        case 2:
            qsort(arr, n, sizeof(item), compare_data);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", arr[i].name, arr[i].data);
    }

    return 0;
}