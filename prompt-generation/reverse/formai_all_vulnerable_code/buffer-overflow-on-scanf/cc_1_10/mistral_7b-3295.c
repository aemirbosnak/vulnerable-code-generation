//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

typedef struct {
    int data;
    char name[20];
} Element;

void bubbleSort(Element arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].data > arr[j + 1].data) {
                temp = arr[j].data;
                arr[j].data = arr[j + 1].data;
                arr[j + 1].data = temp;
                strcpy(arr[j].name, arr[j + 1].name);
                strcpy(arr[j + 1].name, arr[j].name);
            }
        }
    }
}

void printArray(Element arr[], int size) {
    int i;
    printf("Given array is \n");
    for (i = 0; i < size; i++) {
        printf("%d %s ", arr[i].data, arr[i].name);
    }
    printf("\n");
}

int main() {
    Element arr[MAX_SIZE];
    int n, i, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the data and name of each element:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %s", &arr[i].data, arr[i].name);
    }
    do {
        printArray(arr, n);
        bubbleSort(arr, n);
        printf("Do you want to sort again? Press 1 for YES and 0 for NO.\n");
        scanf("%d", &choice);
    } while (choice == 1);
    printf("Sorted array is \n");
    printArray(arr, n);
    return 0;
}