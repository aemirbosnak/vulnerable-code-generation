//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Palindrome checker function with string input
int is_palindrome(char *str) {
    int start = 0, end = strlen(str) - 1;

    // Loop until start and end pointers meet
    while (start < end) {
        // If characters are not same, return false
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }

        // Move start pointer to right and end pointer to left
        start++;
        end--;
    }

    // If loop completed, string is a palindrome
    return 1;
}

// Palindrome checker function with character array input
int is_palindrome_array(char arr[], int size) {
    int start = 0, end = size - 1;

    // Loop until start and end pointers meet
    while (start < end) {
        // If characters are not same, return false
        if (tolower(arr[start]) != tolower(arr[end])) {
            return 0;
        }

        // Move start pointer to right and end pointer to left
        start++;
        end--;
    }

    // If loop completed, character array is a palindrome
    return 1;
}

// Function to print palindrome message
void print_palindrome_message(char *str) {
    if (is_palindrome(str)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
}

// Function to print palindrome message with character array input
void print_palindrome_message_array(char arr[], int size) {
    if (is_palindrome_array(arr, size)) {
        printf("The character array is a palindrome!\n");
    } else {
        printf("The character array is not a palindrome.\n");
    }
}

// Main function to test palindrome checker functions
int main() {
    char str[100];
    int size;

    printf("Enter a string: ");
    scanf("%s", str);

    // Calculate length of string using strlen() function
    size = strlen(str);

    // Test palindrome checker function with string input
    print_palindrome_message(str);

    printf("\n");

    // Initialize character array with given string
    char arr[size];
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        arr[i] = str[i];
    }

    // Test palindrome checker function with character array input
    print_palindrome_message_array(arr, size);

    return 0;
}