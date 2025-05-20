//Code Llama-13B DATASET v1.0 Category: Sorting ; Style: shape shifting
/*
* Sorting Example Program in a Shape Shifting Style
*/

#include <stdio.h>

#define MAX_SIZE 10

// Struct to store data
typedef struct {
    int data;
    int index;
} Data;

// Function to sort data
void sort(Data arr[], int n) {
    int i, j, temp;

    // Bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].data > arr[j + 1].data) {
                temp = arr[j].data;
                arr[j].data = arr[j + 1].data;
                arr[j + 1].data = temp;
            }
        }
    }
}

int main() {
    int i, n;
    Data arr[MAX_SIZE];

    // Input data
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    // Sort data
    sort(arr, n);

    // Print sorted data
    for (i = 0; i < n; i++) {
        printf("Sorted element %d: %d\n", i, arr[i].data);
    }

    return 0;
}