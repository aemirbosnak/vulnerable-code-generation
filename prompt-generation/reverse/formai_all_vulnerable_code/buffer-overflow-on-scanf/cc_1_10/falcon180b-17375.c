//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to remove all whitespace characters from a string
void removeWhiteSpace(char* str) {
    int i = 0;
    int j = 0;
    while (str[i]!= '\0') {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char temp;
    for (int i = 0; i < length/2; i++) {
        temp = str[i];
        str[i] = str[length-1-i];
        str[length-1-i] = temp;
    }
}

// Function to convert a string to uppercase
void toUpperCase(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length/2; i++) {
        if (str[i]!= str[length-1-i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input);

    // Remove all whitespace characters
    removeWhiteSpace(input);

    // Reverse the string
    reverseString(input);

    // Convert the string to uppercase
    toUpperCase(input);

    // Convert the string to lowercase
    toLowerCase(input);

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}