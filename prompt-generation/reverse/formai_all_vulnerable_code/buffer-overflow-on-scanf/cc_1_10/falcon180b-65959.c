//Falcon-180B DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a string is a valid integer
int is_integer(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the sum of an array of integers
int sum_array(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to read an array of integers from standard input
int read_array(int arr[], int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i])!= 1) {
            printf("Invalid input.\n");
            exit(1);
        }
    }
    return 0;
}

// Function to write an integer to standard output
void write_integer(int num) {
    printf("%d\n", num);
}

// Main function
int main() {
    int arr[MAX_SIZE];
    int size;

    // Read the size of the array
    printf("Enter the size of the array (up to %d):\n", MAX_SIZE);
    if (scanf("%d", &size)!= 1 || size <= 0 || size > MAX_SIZE) {
        printf("Invalid size.\n");
        exit(1);
    }

    // Read the array from standard input
    if (read_array(arr, size)!= 0) {
        exit(1);
    }

    // Calculate the sum of the array
    int sum = sum_array(arr, size);

    // Write the sum to standard output
    write_integer(sum);

    return 0;
}