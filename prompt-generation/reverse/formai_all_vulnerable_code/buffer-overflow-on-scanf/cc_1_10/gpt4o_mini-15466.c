//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define ALPHABET_SIZE 26

void paranoid_message(const char* msg) {
    printf("Paranoia Level: Alert! %s\n", msg);
}

void display_array(int arr[], int size) {
    paranoid_message("Displaying the current state of the array.");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    paranoid_message("Swapping two elements!");
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int size) {
    paranoid_message("Beginning bubble sort. Stay vigilant!");
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            paranoid_message("Checking if elements need to be swapped.");
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                paranoid_message("Elements were swapped. Beware of hidden elements!");
            }
        }
        display_array(arr, size);
    }
}

int partition(int arr[], int low, int high) {
    paranoid_message("Partitioning the array. Watch your back...");
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        paranoid_message("Comparing elements against the pivot.");
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    paranoid_message("Completed partitioning!");
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    paranoid_message("Quick sort initiated. Stay alert, we proceed!");
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
    display_array(arr, high + 1);
}

void insertion_sort(int arr[], int size) {
    paranoid_message("Insertion sort is about to commence.");
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            paranoid_message("Shifting elements to create space...");
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        display_array(arr, size);
    }
}

int main() {
    paranoid_message("Welcome to the Sorting Program! Keep your senses sharp.");
    int arr[MAX_SIZE];
    int size;

    printf("Enter the number of elements you wish to sort (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size < 1 || size > MAX_SIZE) {
        paranoid_message("Input size is out of valid range. Exiting in paranoia...");
        exit(EXIT_FAILURE);
    }

    printf("Enter %d integers separated by spaces: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    paranoid_message("You've entered the numbers. Be cautious now!");

    display_array(arr, size);

    printf("\nChoose sorting method:\n1. Bubble Sort\n2. Quick Sort\n3. Insertion Sort\nYour choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            paranoid_message("You have chosen Bubble Sort. Brace yourself!");
            bubble_sort(arr, size);
            break;
        case 2:
            paranoid_message("You have chosen Quick Sort. Keep your eyes wide open!");
            quick_sort(arr, 0, size - 1);
            break;
        case 3:
            paranoid_message("You have chosen Insertion Sort. Prepare for insertion!");
            insertion_sort(arr, size);
            break;
        default:
            paranoid_message("Invalid choice! Conspiracy afoot. Exiting...");
            exit(EXIT_FAILURE);
    }

    printf("Sorted Array: ");
    display_array(arr, size);
    paranoid_message("Sorting completed! Feel the relief, momentarily.");
    
    return 0;
}