//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
typedef struct {
    int key;
    char name[20];
} Element;
void bubbleSort(Element arr[], int n) {
    int i, j, tempKey;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].key > arr[j + 1].key) {
                tempKey = arr[j].key;
                arr[j].key = arr[j + 1].key;
                arr[j + 1].key = tempKey;
                strcpy(arr[j].name, arr[j + 1].name);
                strcpy(arr[j + 1].name, arr[j].name);
            }
        }
    }
}
void printArray(Element arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("| %d | %s |\n", arr[i].key, arr[i].name);
    }
}
int main(int argc, char const *argv[]) {
    Element *arr;
    int size, i, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    arr = (Element *)malloc(size * sizeof(Element));
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d%s", &arr[i].key, arr[i].name);
    }
    printf("Sort by:\n1. Key\n2. Name\nEnter your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        bubbleSort(arr, size);
    } else {
        for (i = 0; i < size - 1; i++) {
            int j = i;
            char tempName[20];
            while (j < size && strcmp(arr[j].name, arr[j + 1].name) < 0) {
                strcpy(tempName, arr[j].name);
                strcpy(arr[j].name, arr[j + 1].name);
                strcpy(arr[j + 1].name, tempName);
                j++;
            }
        }
    }
    printf("Sorted array:\n");
    printArray(arr, size);
    free(arr);
    return 0;
}