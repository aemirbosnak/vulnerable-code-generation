//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];
    char result[MAX_SIZE];

    // Get first string from user
    printf("Enter first string: ");
    fgets(str1, MAX_SIZE, stdin);

    // Remove trailing newline character from first string
    int len1 = strlen(str1);
    if (str1[len1 - 1] == '\n') {
        str1[len1 - 1] = '\0';
        len1--;
    }

    // Get second string from user
    printf("Enter second string: ");
    fgets(str2, MAX_SIZE, stdin);

    // Remove trailing newline character from second string
    int len2 = strlen(str2);
    if (str2[len2 - 1] == '\n') {
        str2[len2 - 1] = '\0';
        len2--;
    }

    // Concatenate the two strings
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    // Copy the concatenated string to result
    strcpy(result, str1);

    // Reverse the concatenated string
    int i = 0, j = strlen(result) - 1;
    while (i < j) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
        i++;
        j--;
    }

    // Print the reversed string
    printf("Reversed string: %s\n", result);

    // Convert the concatenated string to uppercase
    for (int k = 0; k < strlen(result); k++) {
        result[k] = toupper(result[k]);
    }

    // Print the uppercase string
    printf("Uppercase string: %s\n", result);

    return 0;
}