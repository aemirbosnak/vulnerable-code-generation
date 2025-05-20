//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000 // maximum length of a string

void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1); // allocate memory for the reversed string and null terminator
    char* start = str;
    char* end = str + length - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    strcpy(reversed, str); // copy the reversed string to the allocated memory
    printf("Reversed string: %s\n", reversed);
    free(reversed); // free the allocated memory
}

void upperCaseString(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
    printf("Upper case string: %s\n", str);
}

void lowerCaseString(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
    printf("Lower case string: %s\n", str);
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin); // read input from user
    input[strcspn(input, "\n")] = '\0'; // remove newline character from input

    printf("Original string: %s\n", input);
    reverseString(input);
    upperCaseString(input);
    lowerCaseString(input);

    return 0;
}