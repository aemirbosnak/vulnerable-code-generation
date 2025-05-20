//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to search a string in a given array of strings
int searchString(char *str, char *arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcasecmp(str, arr[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char str[100];
    char *arr[10];
    int size = 10;
    int i, j;
    
    // Prompt user for input
    printf("Enter a string to search: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character from input
    str[strcspn(str, "\n")] = '\0';
    
    // Prompt user for array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    
    // Prompt user for array elements
    printf("Enter %d elements: ", size);
    for (i = 0; i < size; i++) {
        fgets(arr[i], sizeof(arr[i]), stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0';
    }
    
    // Search for input string in array
    int index = searchString(str, arr, size);
    
    // Print result
    if (index!= -1) {
        printf("String found at index %d.\n", index);
    } else {
        printf("String not found in array.\n");
    }
    
    return 0;
}