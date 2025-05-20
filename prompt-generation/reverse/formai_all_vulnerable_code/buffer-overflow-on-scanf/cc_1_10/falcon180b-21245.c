//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000 // Maximum size of strings

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];
    int len1, len2;

    // Get input strings from user
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Get lengths of input strings
    len1 = strlen(str1);
    len2 = strlen(str2);

    // Concatenate strings
    char result[MAX_SIZE] = "";
    strcat(result, str1);
    strcat(result, str2);

    // Reverse the concatenated string
    char reversed[MAX_SIZE] = "";
    int i = strlen(result) - 1;
    while (i >= 0) {
        reversed[i] = result[i];
        i--;
    }

    // Convert to uppercase
    char uppercase[MAX_SIZE] = "";
    int j = 0;
    for (int i = 0; i < strlen(reversed); i++) {
        if (isalpha(reversed[i])) {
            uppercase[j++] = toupper(reversed[i]);
        } else {
            uppercase[j++] = reversed[i];
        }
    }

    // Print results
    printf("Concatenated string: %s\n", result);
    printf("Reversed string: %s\n", reversed);
    printf("Uppercase string: %s\n", uppercase);

    return 0;
}