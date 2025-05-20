//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverse(char* str) {
    int i = 0, j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i = 0, j = strlen(str) - 1;

    while (i < j) {
        if (tolower(str[i])!= tolower(str[j])) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

// Function to convert a string to uppercase
void strtoupper(char* str) {
    int i = 0;

    while (str[i]!= '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to convert a string to lowercase
void strtolower(char* str) {
    int i = 0;

    while (str[i]!= '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the input string
    reverse(str);
    printf("Reversed string: %s\n", str);

    // Check if the input string is a palindrome
    if (isPalindrome(str)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    // Convert the input string to uppercase
    strtoupper(str);
    printf("Uppercase string: %s\n", str);

    // Convert the input string to lowercase
    strtolower(str);
    printf("Lowercase string: %s\n", str);

    return 0;
}