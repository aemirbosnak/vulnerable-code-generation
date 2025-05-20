//Falcon-180B DATASET v1.0 Category: Sorting ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define max number of elements
#define MAX 100

// Define a structure for each element
typedef struct {
    int value;
    int index;
} Element;

// Function to swap two elements
void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

// Function to compare two elements
int compare(Element *a, Element *b) {
    if (a->value < b->value)
        return 1;
    else if (a->value > b->value)
        return -1;
    else
        return 0;
}

// Function to perform counting sort
void countingSort(Element *arr, int n) {
    Element *temp = (Element *)malloc(n * sizeof(Element));
    int *count = (int *)malloc(MAX * sizeof(int));
    int max = arr[0].value;

    // Initialize count array with 0s
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Count the number of occurrences of each element
    for (int i = 0; i < n; i++)
        count[arr[i].value]++;

    // Calculate the cumulative sum of counts
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Place each element in its sorted position
    for (int i = n - 1; i >= 0; i--) {
        temp[count[arr[i].value] - 1] = arr[i];
        count[arr[i].value]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i].value = temp[i].value;
        arr[i].index = temp[i].index;
    }

    // Free memory
    free(count);
    free(temp);
}

int main() {
    Element arr[MAX];
    int n;

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Read each element
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
    }

    // Sort the array using counting sort
    countingSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i].value);

    return 0;
}