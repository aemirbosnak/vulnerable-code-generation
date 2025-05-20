//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Declare variables and arrays
    int n, i, j, k, sum, product, factorial;
    int arr1[100], arr2[100], arr3[100];

    // Get input from user
    printf("Enter the number of elements in the arrays: ");
    scanf("%d", &n);

    printf("Enter the elements of the first array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of the second array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    // Perform arithmetic operations on arrays
    for (i = 0; i < n; i++) {
        arr3[i] = arr1[i] + arr2[i];
    }

    // Find the sum of all elements in arr3
    sum = 0;
    for (i = 0; i < n; i++) {
        sum += arr3[i];
    }

    // Find the product of all elements in arr3
    product = 1;
    for (i = 0; i < n; i++) {
        product *= arr3[i];
    }

    // Calculate the factorial of the sum of all elements in arr3
    factorial = 1;
    j = sum;
    while (j > 0) {
        factorial *= j;
        j--;
    }

    // Print the results
    printf("The sum of all elements in arr3 is: %d\n", sum);
    printf("The product of all elements in arr3 is: %d\n", product);
    printf("The factorial of the sum of all elements in arr3 is: %d\n", factorial);

    return 0;
}