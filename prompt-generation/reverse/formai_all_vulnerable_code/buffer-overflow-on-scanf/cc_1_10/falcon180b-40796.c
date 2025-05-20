//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init(int *p, int n) {
    for (int i = 0; i < n; i++) {
        *p++ = rand() % 2;
    }
}

void print(int *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", *p++);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void selection_sort(int *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (*(p + j) < *(p + min_idx)) {
                min_idx = j;
            }
        }
        if (min_idx!= i) {
            swap(p + i, p + min_idx);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *p = (int *) malloc(n * sizeof(int));
    if (p == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    init(p, n);
    printf("Before sorting:\n");
    print(p, n);
    selection_sort(p, n);
    printf("After sorting:\n");
    print(p, n);
    free(p);
    return 0;
}