//Falcon-180B DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Function to remove all white spaces from a string
void remove_spaces(char* str) {
    int len = strlen(str);
    char* dest = str;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            *dest++ = str[i];
        }
    }
    *dest = '\0';
}

// Function to reverse a string
void reverse_string(char* str) {
    int len = strlen(str);
    char* dest = str + len - 1;
    char* src = str;
    while (src < dest) {
        *dest-- = *src++;
    }
}

// Function to check if a string is a palindrome
bool is_palindrome(char* str) {
    remove_spaces(str);
    reverse_string(str);
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i]!= str[len-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char input[1000];
    printf("Enter a string: ");
    fgets(input, 1000, stdin);
    if (is_palindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}