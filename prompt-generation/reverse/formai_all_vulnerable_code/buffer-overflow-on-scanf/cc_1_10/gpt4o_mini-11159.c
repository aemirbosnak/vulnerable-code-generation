//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two integers for qsort
int compare_ints(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to compare two strings for qsort
int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// Function to display the array of integers
void display_ints(int arr[], int size) {
    printf("Integer Array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to display the array of strings
void display_strings(char *arr[], int size) {
    printf("String Array: ");
    for(int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

// Function to read integers from the user
void input_ints(int arr[], int size) {
    printf("Enter %d integers:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to read strings from the user
void input_strings(char *arr[], int size) {
    printf("Enter %d strings:\n", size);
    for(int i = 0; i < size; i++) {
        arr[i] = (char *)malloc(100 * sizeof(char)); // Dynamic allocation
        scanf("%s", arr[i]);
    }
}

// Main function to demonstrate sorting of integers and strings
int main() {
    int intSize, strSize;

    // Sorting integers
    printf("Enter the number of integers to sort: ");
    scanf("%d", &intSize);
    
    int *intArray = (int *)malloc(intSize * sizeof(int));
    input_ints(intArray, intSize);
    
    printf("Before Sorting:\n");
    display_ints(intArray, intSize);
    
    qsort(intArray, intSize, sizeof(int), compare_ints);
    
    printf("After Sorting:\n");
    display_ints(intArray, intSize);

    // Sorting strings
    printf("Enter the number of strings to sort: ");
    scanf("%d", &strSize);
    
    char **strArray = (char **)malloc(strSize * sizeof(char *));
    input_strings(strArray, strSize);
    
    printf("Before Sorting:\n");
    display_strings(strArray, strSize);
    
    qsort(strArray, strSize, sizeof(char *), compare_strings);
    
    printf("After Sorting:\n");
    display_strings(strArray, strSize);

    // Free allocated memory
    free(intArray);
    for(int i = 0; i < strSize; i++) {
        free(strArray[i]);
    }
    free(strArray);

    return 0;
}