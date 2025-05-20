//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: random
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    char name[20];
    int weight;
} Food;

void merge(Food arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Food L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].weight <= R[j].weight) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Food arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    Food food[MAX];
    int i;

    printf("Welcome to the Mysterious Kitchen!\n");
    printf("Let's sort out some ingredients for our recipe.\n");

    for (i = 0; i < MAX; i++) {
        printf("\nEnter name of ingredient %d: ", i + 1);
        scanf("%s", food[i].name);
        printf("Enter weight of ingredient %s: ", food[i].name);
        scanf("%d", &food[i].weight);
    }

    mergeSort(food, 0, MAX - 1);

    printf("\nSorted list of ingredients:\n");
    for (i = 0; i < MAX; i++) {
        printf("\nName: %s, Weight: %d", food[i].name, food[i].weight);
    }

    return 0;
}