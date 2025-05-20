//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: complete
/*
 * Unique C Searching algorithm example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

/* Structure for storing the element and its position in the array */
typedef struct {
    int element;
    int position;
} Element;

/* Function to sort the elements in the array */
void sortElements(int *arr, int n) {
    int i, j;
    Element temp;
    for (i = 1; i < n; i++) {
        j = i - 1;
        temp.element = arr[i];
        temp.position = i;
        while (j >= 0 && arr[j] > temp.element) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp.element;
    }
}

/* Function to search for an element in the array */
int searchElement(int *arr, int n, int element) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_ELEMENTS];
    int n;
    int element;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sortElements(arr, n);
    printf("Enter the element to be searched: ");
    scanf("%d", &element);
    int position = searchElement(arr, n, element);
    if (position != -1) {
        printf("Element found at position %d.\n", position);
    } else {
        printf("Element not found.\n");
    }
    return 0;
}