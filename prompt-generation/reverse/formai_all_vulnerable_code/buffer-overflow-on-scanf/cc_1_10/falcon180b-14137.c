//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int n;

// Function to insert an element in the array
void insert(int element) {
    if (n == MAX_SIZE) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }
    arr[n++] = element;
}

// Function to display the array
void display() {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to search for an element in the array
int search(int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1; // Element not found
}

int main() {
    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    display();

    int searchElement;
    printf("Enter the element you want to search for: ");
    scanf("%d", &searchElement);

    int index = search(searchElement);

    if (index == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }

    return 0;
}