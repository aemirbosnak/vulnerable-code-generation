//FormAI DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the Memory Magic program!\n");
    printf("In this program, we will allocate and deallocate memory dynamically.\n\n");

    // Allocate memory for a string
    char *str = (char *)malloc(15 * sizeof(char));

    if (str == NULL) {
        printf("Memory allocation failed. Exiting program...");
        exit(0);
    } else {
        printf("Memory allocation successful!\nEnter a string (up to 15 characters): ");
        scanf("%s", str);
        printf("You entered: %s\n\n", str);
    }

    // Allocate memory for an array
    int size, *arr, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    arr = (int *)calloc(size, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed. Exiting program...");
        exit(0);
    } else {
        printf("Memory allocation successful!\nEnter %d numbers:\n", size);
        for (i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
        printf("You entered:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    // Reallocate memory for the string
    printf("Enter a new string (up to 15 characters): ");
    scanf("%s", str);
    str = (char *)realloc(str, 20 * sizeof(char));

    if (str == NULL) {
        printf("Memory reallocation failed. Exiting program...");
        exit(0);
    } else {
        printf("Memory reallocation successful!\nYou entered: %s\n", str);
    }

    // Free memory
    free(str);
    free(arr);

    printf("Memory has been freed. Exiting program...");

    return 0;
}