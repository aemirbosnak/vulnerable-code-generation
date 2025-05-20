//Code Llama-13B DATASET v1.0 Category: Text processing ; Style: sophisticated
// C Text processing example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to capitalize first letter of a string
char* capitalize_first_letter(char* str) {
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 32;
    }
    return str;
}

// Function to reverse a string
char* reverse_string(char* str) {
    int length = strlen(str);
    char* reversed = (char*)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }
    reversed[length] = '\0';
    return reversed;
}

// Function to remove spaces from a string
char* remove_spaces(char* str) {
    int length = strlen(str);
    char* no_spaces = (char*)malloc(length + 1);
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != ' ') {
            no_spaces[j++] = str[i];
        }
    }
    no_spaces[j] = '\0';
    return no_spaces;
}

// Function to remove duplicates from a string
char* remove_duplicates(char* str) {
    int length = strlen(str);
    char* no_duplicates = (char*)malloc(length + 1);
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != str[i + 1]) {
            no_duplicates[j++] = str[i];
        }
    }
    no_duplicates[j] = '\0';
    return no_duplicates;
}

// Function to replace all occurrences of a character in a string
char* replace_all_occurences(char* str, char find, char replace) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == find) {
            str[i] = replace;
        }
    }
    return str;
}

// Function to count the number of occurrences of a character in a string
int count_occurences(char* str, char find) {
    int length = strlen(str);
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == find) {
            count++;
        }
    }
    return count;
}

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Capitalize first letter
    char* capitalized = capitalize_first_letter(str);
    printf("Capitalized string: %s\n", capitalized);

    // Reverse string
    char* reversed = reverse_string(str);
    printf("Reversed string: %s\n", reversed);

    // Remove spaces
    char* no_spaces = remove_spaces(str);
    printf("No spaces string: %s\n", no_spaces);

    // Remove duplicates
    char* no_duplicates = remove_duplicates(str);
    printf("No duplicates string: %s\n", no_duplicates);

    // Replace all occurrences
    char* replaced = replace_all_occurences(str, 'a', 'b');
    printf("Replaced string: %s\n", replaced);

    // Count occurrences
    int count = count_occurences(str, 'a');
    printf("Number of occurrences: %d\n", count);

    // Check if palindrome
    int palindrome = is_palindrome(str);
    if (palindrome) {
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }

    return 0;
}