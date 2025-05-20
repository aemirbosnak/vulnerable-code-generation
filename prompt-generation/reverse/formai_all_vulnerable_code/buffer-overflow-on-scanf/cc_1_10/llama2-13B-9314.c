//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the data to be sorted
struct data {
    int num;
    char name[20];
};

// Function to swap two elements
void swap(struct data *a, struct data *b) {
    struct data temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the data using bubble sort
void sort(struct data *arr, int n) {
    int i, j, flag = 1;

    // Loop until the flag is set to 0
    while (flag) {
        flag = 0;

        // Loop through the array
        for (i = 0; i < n - 1; i++) {
            // Loop through the next n-1 elements
            for (j = i + 1; j < n; j++) {
                // Check for a smaller element
                if (arr[i].num > arr[j].num) {
                    // Swap the elements
                    swap(&arr[i], &arr[j]);
                    flag = 1;
                }
            }
        }
    }
}

// Function to print the sorted array
void print(struct data *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d %s\n", arr[i].num, arr[i].name);
    }
}

// Main function
int main() {
    int n, i;
    struct data arr[10];

    // Ask the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Create the array with random elements
    for (i = 0; i < n; i++) {
        arr[i].num = rand() % 100;
        strcpy(arr[i].name, "Random name");
    }

    // Sort the array using bubble sort
    sort(arr, n);

    // Print the sorted array
    print(arr, n);

    return 0;
}