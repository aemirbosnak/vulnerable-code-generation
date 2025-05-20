//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int key;
    char name[50];
} Record;

void swap(Record arr[], int i, int j) {
    Record temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int binarySearch(Record arr[], int l, int r, int key) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m].key == key)
            return m;

        if (arr[m].key < key)
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

int linearSearch(Record arr[], int n, int key) {
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i].key == key)
            return i;
    }

    return -1;
}

void merge(Record arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Record L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i].key <= R[j].key) {
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

void mergeSort(Record arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    Record arr[MAX];
    int n, i, key, choice;

    printf("Enter number of records: ");
    scanf("%d", &n);

    printf("Enter records:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %s", &arr[i].key, arr[i].name);
    }

    do {
        printf("\nChoose search algorithm:\n");
        printf("1. Binary Search\n");
        printf("2. Linear Search\n");
        printf("3. Merge Sort & Binary Search\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int index = binarySearch(arr, 0, n - 1, key);
                if (index == -1)
                    printf("Key not found!\n");
                else
                    printf("Key found at index %d\n", index);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int index2 = linearSearch(arr, n, key);
                if (index2 == -1)
                    printf("Key not found!\n");
                else
                    printf("Key found at index %d\n", index2);
                break;
            case 3:
                mergeSort(arr, 0, n - 1);
                printf("Enter key to search: ");
                scanf("%d", &key);
                int index3 = binarySearch(arr, 0, n - 1, key);
                if (index3 == -1)
                    printf("Key not found!\n");
                else
                    printf("Key found at index %d\n", index3);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}