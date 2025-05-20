//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// define the maximum number of elements in the array
#define MAX_ELEMENTS 100

// define the structure for each element in the array
typedef struct {
    int data;
    int index;
} Element;

// define the function to print the array
void printArray(Element arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Index %d: %d\n", arr[i].index, arr[i].data);
    }
}

// define the function to search for an element in the array
int search(Element arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i].data == target) {
            return arr[i].index;
        }
    }
    return -1;
}

// define the main function
int main() {
    // initialize the array
    Element arr[MAX_ELEMENTS];
    int n = 0;

    // prompt the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // prompt the user for each element in the array
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    // prompt the user for the target value
    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    // search for the target value in the array
    int result = search(arr, n, target);

    // print the result
    if (result == -1) {
        printf("The target value was not found in the array.\n");
    } else {
        printf("The target value was found at index %d.\n", result);
    }

    return 0;
}