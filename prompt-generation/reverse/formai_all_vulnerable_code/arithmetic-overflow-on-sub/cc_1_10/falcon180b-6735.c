//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to shuffle an array using the Fisher-Yates algorithm
void shuffle_array(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand_int(0, i);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Prompt the user for the size of the array
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Prompt the user for the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Shuffle the array
    shuffle_array(arr, n);

    // Print the shuffled array
    printf("Shuffled array:\n");
    print_array(arr, n);

    return 0;
}