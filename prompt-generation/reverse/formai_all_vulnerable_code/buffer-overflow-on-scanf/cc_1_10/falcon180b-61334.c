//Falcon-180B DATASET v1.0 Category: Educational ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to print a message and wait for user input
void wait_for_input(char* message) {
    printf("%s", message);
    char input;
    scanf("%c", &input);
}

// Function to get user input as a string
char* get_string_input(char* prompt) {
    char input[100];
    printf("%s: ", prompt);
    scanf("%[^\n]", input);
    input[strcspn(input, "\n")] = '\0';  // Remove newline character
    return strdup(input);
}

// Function to get user input as an integer
int get_integer_input(char* prompt) {
    int input;
    printf("%s: ", prompt);
    scanf("%d", &input);
    return input;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array using bubble sort
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    wait_for_input("Enter number of elements: ");
    n = get_integer_input("Number of elements: ");

    int arr[n];
    for (int i = 0; i < n; i++) {
        wait_for_input("Enter element ");
        arr[i] = get_integer_input("Element: ");
    }

    bubble_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}