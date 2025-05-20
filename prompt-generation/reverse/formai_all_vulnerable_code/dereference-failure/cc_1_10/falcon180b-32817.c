//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char string1[MAX_SIZE];
    char string2[MAX_SIZE];
    char *result;

    // Prompt user for first string
    printf("Enter first string: ");
    fgets(string1, MAX_SIZE, stdin);

    // Prompt user for second string
    printf("Enter second string: ");
    fgets(string2, MAX_SIZE, stdin);

    // Concatenate strings
    result = malloc(strlen(string1) + strlen(string2) + 1);
    strcpy(result, string1);
    strcat(result, string2);

    // Print result
    printf("Concatenated string: %s\n", result);

    // Find length of concatenated string
    int length = strlen(result);
    printf("Length of concatenated string: %d\n", length);

    // Reverse the concatenated string
    char reversed[MAX_SIZE];
    int i = length - 1;
    while (i >= 0) {
        reversed[i] = result[length - 1 - i];
        i--;
    }
    reversed[length] = '\0';

    // Print reversed string
    printf("Reversed string: %s\n", reversed);

    // Check if reversed string is a palindrome
    int isPalindrome = 1;
    for (i = 0; i < length / 2; i++) {
        if (reversed[i]!= reversed[length - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome) {
        printf("Reversed string is a palindrome\n");
    } else {
        printf("Reversed string is not a palindrome\n");
    }

    // Free memory
    free(result);
    return 0;
}