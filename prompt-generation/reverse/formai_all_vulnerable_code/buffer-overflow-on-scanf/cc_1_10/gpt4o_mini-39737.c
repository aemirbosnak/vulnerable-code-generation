//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two strings (used for sorting)
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Function to print the array of strings
void printArray(char *arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}

// Function to sort and print an array of strings
void sortAndPrintStrings() {
    char *arr[] = {
        "Banana", 
        "Apple", 
        "Cherry", 
        "Mango", 
        "Orange", 
        "Peach", 
        "Grape", 
        "Pineapple", 
        "Kiwi", 
        "Strawberry"
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    printArray(arr, n);

    // Sorting the array using qsort and the compare function
    qsort(arr, n, sizeof(char *), compare);

    printf("\nAfter sorting:\n");
    printArray(arr, n);
}

// Function to get input from the user to dynamically create an array of strings
void userInputStrings() {
    int n;
    printf("Enter the number of fruits you want to sort: ");
    scanf("%d", &n);
    
    // Allocating memory for the array of strings
    char **arr = (char **)malloc(n * sizeof(char *));
    if (arr == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        return;
    }

    // Getting user input for each string
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(50 * sizeof(char)); // Allocate memory for each string
        if (arr[i] == NULL) {
            fprintf(stderr, "Error allocating memory for string\n");
            return;
        }
        printf("Enter fruit %d: ", i + 1);
        scanf("%s", arr[i]); // Getting input
    }

    printf("\nBefore sorting:\n");
    printArray(arr, n);

    // Sorting the array using qsort and the compare function
    qsort(arr, n, sizeof(char *), compare);

    printf("\nAfter sorting:\n");
    printArray(arr, n);
    
    // Freeing allocated memory
    for (int i = 0; i < n; i++) {
        free(arr[i]); // Freeing each string
    }
    free(arr); // Freeing the array of strings
}

int main() {
    int choice;
    printf("Sorting Program\n");
    printf("1. Predefined fruit list\n");
    printf("2. Input your own list\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sortAndPrintStrings();
            break;
        case 2:
            userInputStrings();
            break;
        default:
            printf("Invalid option.\n");
            break;
    }

    return 0;
}