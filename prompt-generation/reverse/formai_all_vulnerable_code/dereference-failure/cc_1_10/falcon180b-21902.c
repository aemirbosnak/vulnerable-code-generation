//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse a string
void reverseString(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i]!= str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[1000];

    // Prompt user for input
    printf("Enter a string: ");
    scanf("%s", input);

    // Remove whitespace from input
    char* output = strtok(input, " ");
    while (output!= NULL) {
        printf("%s ", output);
        output = strtok(NULL, " ");
    }

    // Reverse the string
    printf("\nReversed string: ");
    reverseString(input);
    printf("%s\n", input);

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}