//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_STRING_LENGTH 50

void searchInteger(int arr[], int size, int target) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == target) {
            printf("Integer %d found at index %d (Total comparisons made: %d)\n", target, i, comparisons);
            return;
        }
    }
    printf("Integer %d not found (Total comparisons made: %d)\n", target, comparisons);
}

void searchString(char arr[][MAX_STRING_LENGTH], int size, const char *target) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (strcmp(arr[i], target) == 0) {
            printf("String '%s' found at index %d (Total comparisons made: %d)\n", target, i, comparisons);
            return;
        }
    }
    printf("String '%s' not found (Total comparisons made: %d)\n", target, comparisons);
}

void safeInputString(char *str, int length) {
    fgets(str, length, stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character
}

int main() {
    int arraySize, option;
    int intArray[MAX_SIZE];
    char stringArray[MAX_SIZE][MAX_STRING_LENGTH];
    
    printf("Welcome to the Modified Linear Search Program!\n");
    
    // Integer Search
    printf("Enter the number of integers (max %d): ", MAX_SIZE);
    scanf("%d", &arraySize);
    if (arraySize > MAX_SIZE || arraySize < 1) {
        printf("Invalid array size.\n");
        return 1;
    }
    
    printf("Enter %d integers:\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &intArray[i]);
    }
    
    printf("Choose an integer to search: ");
    int targetInt;
    scanf("%d", &targetInt);
    searchInteger(intArray, arraySize, targetInt);

    // String Search
    printf("\nNow, let’s handle string search.\n");
    printf("Enter the number of strings (max %d): ", MAX_SIZE);
    scanf("%d", &arraySize);
    if (arraySize > MAX_SIZE || arraySize < 1) {
        printf("Invalid array size.\n");
        return 1;
    }
    getchar(); // Consume newline character after previous input
    
    printf("Enter %d strings:\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        safeInputString(stringArray[i], MAX_STRING_LENGTH);
    }
    
    printf("Choose a string to search: ");
    char targetString[MAX_STRING_LENGTH];
    safeInputString(targetString, MAX_STRING_LENGTH);
    searchString(stringArray, arraySize, targetString);
    
    printf("\nThank you for using the program!\n");
    return 0;
}