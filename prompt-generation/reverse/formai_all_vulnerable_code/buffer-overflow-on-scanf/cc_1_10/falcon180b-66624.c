//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    char* original = str;
    char* end = str + length - 1;

    // Reverse the string
    while (original < end) {
        *reversed++ = *original++;
    }

    // Add null terminator
    *reversed = '\0';

    // Print the reversed string
    printf("Reversed string: %s\n", reversed);

    // Free memory
    free(reversed);
}

// Function to concatenate two strings
void concatenateStrings(char* str1, char* str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    char* concatenated = malloc(length1 + length2 + 1);

    // Concatenate the strings
    strcat(concatenated, str1);
    strcat(concatenated, str2);

    // Print the concatenated string
    printf("Concatenated string: %s\n", concatenated);

    // Free memory
    free(concatenated);
}

// Function to check if two strings are equal
int compareStrings(char* str1, char* str2) {
    return strcmp(str1, str2);
}

// Function to count the number of occurrences of a substring in a string
int countSubstringOccurrences(char* str, char* sub) {
    int count = 0;
    char* currentPos = str;

    // Loop through the string
    while ((currentPos = strstr(currentPos, sub))!= NULL) {
        // Increment the count
        count++;

        // Move the current position past the substring
        currentPos += strlen(sub);
    }

    // Return the count
    return count;
}

int main() {
    char input[100];

    // Prompt user for input
    printf("Enter a string: ");
    scanf("%s", input);

    reverseString(input);
    concatenateStrings(input, " of Camelot");
    int comparison = compareStrings(input, "Sir Lancelot");
    int occurrences = countSubstringOccurrences(input, "ot");

    // Print results
    printf("Comparison result: %d\n", comparison);
    printf("Occurrences of 'ot': %d\n", occurrences);

    return 0;
}