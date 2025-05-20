//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to remove all whitespace characters from a string
void remove_whitespace(char* str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

// Function to reverse a string
void reverse_string(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (str[i]!= str[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    char input[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", input);

    // Remove whitespace characters
    remove_whitespace(input);

    // Reverse the string
    reverse_string(input);

    // Check if the string is a palindrome
    if (is_palindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}