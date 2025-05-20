//Falcon-180B DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Recursive function to generate permutations
void permute(int arr[], int l, int r) {
    int i;

    // One by one move boundary of the subarray
    // from l to r
    for (i = l; i <= r; i++) {

        // Last i elements are already in place
        if (i == r)
            printf("%d ", arr[i]);
        else
            printf("%d ", arr[i]);

        // Recursive call for the next element
        permute(arr, i + 1, r);
    }
}

// Driver program to test above functions
int main() {
    int arr[MAX], n, i;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Read the elements of the array
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Print the original array
    printf("Original array: ");
    printArray(arr, n);

    // Generate permutations of the array
    printf("Permutations of the array: ");
    permute(arr, 0, n - 1);

    return 0;
}

/*
Sample Input/Output:

Enter the size of the array: 4
Enter the elements of the array: 1 2 3 4
Original array: 1 2 3 4
Permutations of the array: 
1 2 3 4 
1 2 4 3 
1 3 2 4 
1 3 4 2 
1 4 2 3 
1 4 3 2 
2 1 3 4 
2 1 4 3 
2 3 1 4 
2 3 4 1 
2 4 1 3 
2 4 3 1 
3 1 2 4 
3 1 4 2 
3 2 1 4 
3 2 4 1 
3 4 1 2 
3 4 2 1 
4 1 2 3 
4 1 3 2 
4 2 1 3 
4 2 3 1 
4 3 1 2 
4 3 2 1 
*/