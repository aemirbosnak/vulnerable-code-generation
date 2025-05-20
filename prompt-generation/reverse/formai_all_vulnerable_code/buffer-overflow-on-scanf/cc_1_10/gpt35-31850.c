//FormAI DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // allocate memory for two integers
    int* num1 = malloc(sizeof(int));
    int* num2 = malloc(sizeof(int));

    // check if memory allocation was successful
    if (num1 == NULL || num2 == NULL) {
        printf("Error allocating memory!");
        return 1;
    }

    // ask user to input integers
    printf("Enter first integer: ");
    scanf("%d", num1);
    printf("Enter second integer: ");
    scanf("%d", num2);

    // perform addition
    int sum = *num1 + *num2;
    printf("Sum of %d and %d is %d\n", *num1, *num2, sum);

    // free allocated memory
    free(num1);
    free(num2);

    // allocate memory for a string
    char* str = malloc(20 * sizeof(char));

    // check if memory allocation was successful
    if (str == NULL) {
        printf("Error allocating memory!");
        return 1;
    }

    // ask user to input a string
    printf("Enter a string (max 20 characters): ");
    scanf("%s", str);

    // reverse the string
    char* rev_str = malloc((strlen(str) + 1) * sizeof(char));
    int i, j;
    for (i = strlen(str) - 1, j = 0; i >= 0; i--, j++) {
        rev_str[j] = str[i];
    }
    rev_str[j] = '\0';

    // print the reversed string
    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", rev_str);

    // free allocated memory
    free(str);
    free(rev_str);

    return 0;
}