//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate the factorial of a given number
long long int factorial(int n) {
    long long int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the number of permutations of a given set of elements
long long int permutations(int n, int r) {
    return factorial(n) / factorial(n-r);
}

// Function to generate a random permutation of a given set of elements
void generate_permutation(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to print a given array of elements
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, r;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number of elements to be selected: ");
    scanf("%d", &r);

    // Calculate the number of permutations
    long long int num_permutations = permutations(n, r);

    // Generate a random permutation
    generate_permutation(arr, n);

    // Print the original array
    printf("Original array: ");
    print_array(arr, n);

    // Print the selected elements
    int selected_arr[r];
    for (int i = 0; i < r; i++) {
        selected_arr[i] = arr[i];
    }
    printf("Selected elements: ");
    print_array(selected_arr, r);

    // Print the number of permutations
    printf("Number of permutations: %lld\n", num_permutations);

    return 0;
}