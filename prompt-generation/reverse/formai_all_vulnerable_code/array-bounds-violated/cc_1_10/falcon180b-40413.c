//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to check if a string is palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a string to uppercase
void toUpper(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to convert a string to lowercase
void toLower(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to remove all whitespace characters from a string
void removeWhitespace(char* str) {
    int len = strlen(str);
    char temp[len];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

// Function to replace all occurrences of a character with another character
void replaceChar(char* str, char from, char to) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == from) {
            str[i] = to;
        }
    }
}

// Function to print a string with a specified delay between characters
void printDelayed(char* str, int delay) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        printf("%c", str[i]);
        fflush(stdout);
        usleep(delay * 1000);
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Remove whitespace characters
    removeWhitespace(str);

    // Reverse the string
    reverse(str);

    // Convert to uppercase
    toUpper(str);

    // Convert to lowercase
    toLower(str);

    // Check if palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Replace character
    replaceChar(str, 'a', 'x');
    printf("The string with 'a' replaced with 'x': %s\n", str);

    // Print with delay
    printDelayed(str, 50);

    return 0;
}