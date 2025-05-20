//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void logOperation(const char *operation, const char *details) {
    FILE *logFile = fopen("sort_log.txt", "a");
    if (logFile == NULL) {
        perror("Error opening log file");
        return;
    }
    fprintf(logFile, "%s: %s\n", operation, details);
    fclose(logFile);
}

int compareInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compareString(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void sortIntegers(int *arr, int size) {
    qsort(arr, size, sizeof(int), compareInt);
    logOperation("Sort Integers", "Sorted an integer array.");
}

void sortStrings(char **arr, int size) {
    qsort(arr, size, sizeof(char *), compareString);
    logOperation("Sort Strings", "Sorted a string array.");
}

void printIntegers(int *arr, int size) {
    printf("Sorted integers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printStrings(char **arr, int size) {
    printf("Sorted strings: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    printf("Enter the number of integers to sort: ");
    scanf("%d", &n);
    
    int *intArray = malloc(n * sizeof(int));
    if (intArray == NULL) {
        perror("Failed to allocate memory for integer array");
        return EXIT_FAILURE;
    }
    
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &intArray[i]);
    }

    sortIntegers(intArray, n);
    printIntegers(intArray, n);
    
    // String sorting section
    int m;

    printf("Enter the number of strings to sort: ");
    scanf("%d", &m);

    char **strArray = malloc(m * sizeof(char *));
    if (strArray == NULL) {
        perror("Failed to allocate memory for string array");
        free(intArray);
        return EXIT_FAILURE;
    }
    
    printf("Enter %d strings (each string should not exceed 100 characters):\n", m);
    for (int i = 0; i < m; i++) {
        strArray[i] = malloc(100 * sizeof(char));
        if (strArray[i] == NULL) {
            perror("Failed to allocate memory for string");
            for (int j = 0; j < i; j++) {
                free(strArray[j]);
            }
            free(strArray);
            free(intArray);
            return EXIT_FAILURE;
        }
        scanf("%s", strArray[i]);
    }

    sortStrings(strArray, m);
    printStrings(strArray, m);
    
    // Free allocated memory
    free(intArray);
    for (int i = 0; i < m; i++) {
        free(strArray[i]);
    }
    free(strArray);

    return EXIT_SUCCESS;
}