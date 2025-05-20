//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NAMES 50

struct Name {
    char name[20];
    int age;
};

typedef struct Name Name;

bool isSorted(Name arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(arr[i].name, arr[i + 1].name) > 0) {
            return false;
        }
    }
    return true;
}

void merge(Name arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Name L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (strcmp(L[i].name, R[j].name) <= 0) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(Name arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    srand(time(NULL));

    Name names[MAX_NAMES];

    printf("Montagues and Capulets, come forth and be sorted!\n");

    int n = 0;

    while (n < MAX_NAMES / 2 && scanf("%s", names[n].name) != EOF) {
        names[n++].age = rand() % 101;
    }

    mergeSort(names, 0, n - 1);

    printf("\nLove's Labours Sorted:\n");

    for (int i = 0; i < n; i++) {
        printf("%s, %d years old\n", names[i].name, names[i].age);
    }

    return 0;
}