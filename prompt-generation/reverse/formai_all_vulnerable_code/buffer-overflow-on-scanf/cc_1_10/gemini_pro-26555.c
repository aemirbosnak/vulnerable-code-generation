//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// A recursive function to print all the subsets of a given set
void printSubsets(int *arr, int n) {
    // Base case: if the set is empty, print the empty set
    if (n == 0) {
        printf("{}\n");
        return;
    }

    // Recursive case: for each element in the set, print the subset that includes the element and the subset that excludes the element
    for (int i = 0; i < n; i++) {
        // Create a new set that includes the element
        int *newArr = (int *)malloc((n - 1) * sizeof(int));
        for (int j = 0; j < i; j++) {
            newArr[j] = arr[j];
        }
        for (int j = i + 1; j < n; j++) {
            newArr[j - 1] = arr[j];
        }

        // Print the subset that includes the element
        printf("{");
        for (int j = 0; j < n - 1; j++) {
            printf("%d, ", newArr[j]);
        }
        printf("%d}\n", newArr[n - 2]);

        // Recursively print the subset that excludes the element
        printSubsets(newArr, n - 1);
    }
}

int main() {
    // Get the input set
    int n;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print all the subsets of the set
    printf("All the subsets of the set are:\n");
    printSubsets(arr, n);

    return 0;
}