//Falcon-180B DATASET v1.0 Category: Sorting ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    char name[20];
} Person;

void swap(Person* a, Person* b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    const Person* personA = a;
    const Person* personB = b;

    if (personA->data > personB->data)
        return 1;
    else if (personA->data < personB->data)
        return -1;
    else
        return 0;
}

void quickSort(Person arr[], int left, int right) {
    int i = left, j = right;
    Person tmp;
    Person pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (compare(&arr[i], &pivot) < 0)
            i++;
        while (compare(&arr[j], &pivot) > 0)
            j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int main() {
    srand(time(NULL));

    Person arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        arr[i].data = rand() % 100;
        sprintf(arr[i].name, "Person %d", i + 1);
    }

    quickSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %d\n", arr[i].name, arr[i].data);
    }

    return 0;
}