//Falcon-180B DATASET v1.0 Category: Recursive ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char reversed[length];
    char* temp = str;
    char* end = str + length - 1;

    // Reverse the string
    while (temp < end) {
        char c = *temp;
        *temp = *end;
        *end = c;
        temp++;
        end--;
    }

    // Copy the reversed string to the original string
    strcpy(str, reversed);
}

// Function to print a string in reverse order
void printReverse(char* str) {
    int length = strlen(str);
    char reversed[length];
    char* temp = str;
    char* end = str + length - 1;

    // Reverse the string
    while (temp < end) {
        char c = *temp;
        *temp = *end;
        *end = c;
        temp++;
        end--;
    }

    // Print the reversed string
    printf("%s\n", str);
}

// Recursive function to print a string in reverse order
void recursiveReverse(char* str, int start, int end) {
    if (start >= end) {
        return;
    }

    // Reverse the characters in the string
    char temp = *(str + start);
    *(str + start) = *(str + end);
    *(str + end) = temp;

    // Move to the next characters
    recursiveReverse(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    reverseString(str);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    // Print the reversed string in reverse order
    printReverse(str);

    // Recursively print the reversed string in reverse order
    recursiveReverse(str, 0, strlen(str) - 1);

    return 0;
}