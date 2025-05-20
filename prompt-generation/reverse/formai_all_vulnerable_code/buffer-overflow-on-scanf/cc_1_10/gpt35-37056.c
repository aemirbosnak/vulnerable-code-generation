//FormAI DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define the structure of each element in the array
typedef struct {
    int number;
    char *name;
} Element;

// Declare the functions for comparison and swapping of elements
int compare(Element a, Element b);
void swap(Element *a, Element *b);

// Implement the Bubble Sort algorithm for sorting the array
void bubbleSort(Element *arr, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (compare(arr[j], arr[j+1]) > 0) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Allocate memory for the array of elements
    Element *arr = (Element*) malloc(n * sizeof(Element));
    
    // Read input for each element in the array
    for (i = 0; i < n; i++) {
        printf("Enter number for element %d: ", i+1);
        scanf("%d", &arr[i].number);
        printf("Enter name for element %d: ", i+1);
        arr[i].name = (char*) malloc(50 * sizeof(char));
        scanf("%s", arr[i].name);
    }
    
    printf("Unsorted Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %s\n", arr[i].number, arr[i].name);
    }
    
    // Sort the array using the Bubble Sort algorithm
    bubbleSort(arr, n);
    
    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %s\n", arr[i].number, arr[i].name);
    }
    
    // Free the allocated memory for each element in the array
    for (i = 0; i < n; i++) {
        free(arr[i].name);
    }
    
    // Free the allocated memory for the array of elements
    free(arr);
    return 0;
}

// Implementation of the comparison function
int compare(Element a, Element b) {
    if (a.number < b.number) {
        return -1;
    } else if (a.number > b.number) {
        return 1;
    } else {
        return 0;
    }
}

// Implementation of the swapping function
void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}