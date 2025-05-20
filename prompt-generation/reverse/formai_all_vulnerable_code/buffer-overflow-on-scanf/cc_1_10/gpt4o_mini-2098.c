//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_ELEMENTS 100

typedef struct {
    char name[MAX_STR_LEN];
    int age;
} Person;

void swap(Person* a, Person* b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Person arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].age > arr[j + 1].age) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(Person arr[], int n) {
    int i, j, minIdx;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].age < arr[minIdx].age) {
                minIdx = j;
            }
        }
        swap(&arr[minIdx], &arr[i]);
    }
}

void insertionSort(Person arr[], int n) {
    int i, j;
    Person key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].age > key.age) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(Person arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Age: %d\n", arr[i].name, arr[i].age);
    }
}

void fillArray(Person arr[], int* n) {
    printf("Enter the number of people (max %d): ", MAX_ELEMENTS);
    scanf("%d", n);
    
    for (int i = 0; i < *n; i++) {
        printf("Enter name of person %d: ", i + 1);
        scanf("%s", arr[i].name);
        printf("Enter age of person %d: ", i + 1);
        scanf("%d", &arr[i].age);
    }
}

int main() {
    Person persons[MAX_ELEMENTS];
    int n, choice;

    fillArray(persons, &n);

    printf("Choose a sorting method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(persons, n);
            printf("\nArray sorted using Bubble Sort:\n");
            break;
        case 2:
            selectionSort(persons, n);
            printf("\nArray sorted using Selection Sort:\n");
            break;
        case 3:
            insertionSort(persons, n);
            printf("\nArray sorted using Insertion Sort:\n");
            break;
        default:
            printf("Invalid choice!\n");
            return 1; // Exit if invalid choice
    }

    printArray(persons, n);

    return 0;
}