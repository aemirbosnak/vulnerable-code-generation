//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// function prototypes
void init_array(int arr[], int size);
void print_array(int arr[], int size);
int sum_array(int arr[], int size);
int count_even_numbers(int arr[], int size);

int main() {
    int arr[MAX];
    int size;

    // seed the random number generator with the current time
    srand(time(NULL));

    // prompt the user for the array size
    printf("Enter the array size (up to %d): ", MAX);
    scanf("%d", &size);

    // initialize the array with random numbers
    init_array(arr, size);

    // print the initial array
    printf("\nInitial array:\n");
    print_array(arr, size);

    // sum all the elements in the array
    int sum = sum_array(arr, size);
    printf("\nThe sum of all elements in the array is: %d\n", sum);

    // count the number of even numbers in the array
    int count = count_even_numbers(arr, size);
    printf("\nThere are %d even numbers in the array.\n", count);

    return 0;
}

void init_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // generate a random number between 0 and 99
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sum_array(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int count_even_numbers(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) { // check if the number is even
            count++;
        }
    }
    return count;
}