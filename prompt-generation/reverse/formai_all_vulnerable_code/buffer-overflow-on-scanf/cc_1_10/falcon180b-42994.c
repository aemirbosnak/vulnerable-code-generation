//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define MAX_NUM 1000000
#define TRUE 1
#define FALSE 0

int arr[MAX];
int n;

void generateArray() {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_NUM;
    }
}

void printArray() {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int search(int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

void main() {
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    generateArray();
    printf("Sorted array: ");
    printArray();

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int index = search(key);

    if (index == -1) {
        printf("Key not found\n");
    } else {
        printf("Key found at index %d\n", index);
    }
}