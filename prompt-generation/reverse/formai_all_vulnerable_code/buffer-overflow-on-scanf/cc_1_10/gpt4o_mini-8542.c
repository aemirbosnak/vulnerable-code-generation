//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to perform insertion sort
void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform selection sort
void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Function to print an array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to create a random array
void generate_random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // numbers between 0 and 99
    }
}

// Main function to orchestrate sorting
int main() {
    int choice, size;
    int arr[MAX_SIZE];

    printf("Welcome to the Mind-Bending Sorting Experience!\n");
    printf("How many numbers shall I conjure for your sorting task? (Max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if(size < 1 || size > MAX_SIZE) {
        printf("Please choose a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    generate_random_array(arr, size);
    printf("Here are your mystical numbers:\n");
    print_array(arr, size);

    printf("Which sorting spell would you like to cast?\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("Choose your weapon (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Casting Bubble Sort...\n");
            bubble_sort(arr, size);
            break;
        case 2:
            printf("Casting Insertion Sort...\n");
            insertion_sort(arr, size);
            break;
        case 3:
            printf("Casting Selection Sort...\n");
            selection_sort(arr, size);
            break;
        default:
            printf("Alas! That is not a valid choice.\n");
            return 2; // Exit due to invalid choice
    }

    printf("The sorted array is revealed:\n");
    print_array(arr, size);
    
    // Making the sorting experience more immersive
    printf("Shuffling the sorted elements for an unexpected encore!\n");
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }

    printf("Behold the enchanted shuffled array:\n");
    print_array(arr, size);

    printf("Thank you for embarking on this sorting journey. Until next time!\n");
    return 0;
}