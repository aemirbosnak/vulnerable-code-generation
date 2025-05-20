//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_STRING_LENGTH 100

void displayArray(char arr[MAX_ELEMENTS][MAX_STRING_LENGTH], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}

int linearSearch(char arr[MAX_ELEMENTS][MAX_STRING_LENGTH], int size, const char *key) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], key) == 0) {
            return i; // found
        }
    }
    return -1; // not found
}

int binarySearch(char arr[MAX_ELEMENTS][MAX_STRING_LENGTH], int size, const char *key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(arr[mid], key);
        
        // Check if key is present at mid
        if (cmp == 0) {
            return mid;
        }
        // If key is greater, ignore left half
        else if (cmp < 0) {
            left = mid + 1;
        } 
        // If key is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    return -1; // not found
}

void inputStrings(char arr[MAX_ELEMENTS][MAX_STRING_LENGTH], int *size) {
    printf("Enter the number of strings (max %d): ", MAX_ELEMENTS);
    scanf("%d", size);
    getchar(); // consume newline

    if (*size > MAX_ELEMENTS) {
        printf("Size exceeds maximum elements. Truncating to %d.\n", MAX_ELEMENTS);
        *size = MAX_ELEMENTS;
    }

    for (int i = 0; i < *size; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(arr[i], MAX_STRING_LENGTH, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0'; // remove newline character
    }
}

void sortStrings(char arr[MAX_ELEMENTS][MAX_STRING_LENGTH], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                // swap
                char temp[MAX_STRING_LENGTH];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main() {
    char strings[MAX_ELEMENTS][MAX_STRING_LENGTH];
    int size;
    char key[MAX_STRING_LENGTH];
    
    inputStrings(strings, &size);
    printf("\nOriginal Strings:\n");
    displayArray(strings, size);
    
    sortStrings(strings, size);
    printf("\nSorted Strings:\n");
    displayArray(strings, size);
    
    printf("\nEnter string to search: ");
    fgets(key, MAX_STRING_LENGTH, stdin);
    key[strcspn(key, "\n")] = '\0'; // remove newline character
    
    // Linear Search
    int index = linearSearch(strings, size, key);
    if (index != -1) {
        printf("Linear Search: '%s' found at index %d\n", key, index);
    } else {
        printf("Linear Search: '%s' not found\n", key);
    }

    // Binary Search
    index = binarySearch(strings, size, key);
    if (index != -1) {
        printf("Binary Search: '%s' found at index %d\n", key, index);
    } else {
        printf("Binary Search: '%s' not found\n", key);
    }
    
    return 0;
}