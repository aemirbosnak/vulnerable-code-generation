//Falcon-180B DATASET v1.0 Category: Error handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is even
int is_even(int num) {
    return num % 2 == 0;
}

// Function to calculate the sum of even numbers in an array
int sum_even(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (is_even(arr[i])) {
            sum += arr[i];
        }
    }
    return sum;
}

// Function to print an error message and exit the program
void error(char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

// Function to read an integer from standard input
int read_int() {
    int num;
    if (scanf("%d", &num)!= 1) {
        error("Invalid input");
    }
    return num;
}

// Main function
int main() {
    int size;
    printf("Enter the size of the array: ");
    size = read_int();
    if (size <= 0) {
        error("Invalid array size");
    }
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        arr[i] = read_int();
    }
    int sum = sum_even(arr, size);
    printf("The sum of even numbers in the array is: %d\n", sum);
    return 0;
}