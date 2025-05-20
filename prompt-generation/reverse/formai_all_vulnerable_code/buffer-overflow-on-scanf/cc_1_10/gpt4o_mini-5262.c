//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void print_welcome_message() {
    printf("==============================================\n");
    printf("       Welcome to the Palindrome Checker       \n");
    printf("==============================================\n");
}

void convert_to_lowercase(char *input_str) {
    for (int i = 0; input_str[i]; i++) {
        input_str[i] = tolower(input_str[i]);
    }
}

void strip_non_alpha(char *input_str) {
    char temp[MAX_LENGTH];
    int j = 0;

    for (int i = 0; input_str[i]; i++) {
        if (isalpha(input_str[i])) {
            temp[j++] = input_str[i];
        }
    }
    temp[j] = '\0'; // Null terminate the new string
    strcpy(input_str, temp);
}

int is_palindrome(const char *input_str) {
    int len = strlen(input_str);
    for (int i = 0; i < len / 2; i++) {
        if (input_str[i] != input_str[len - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // It is a palindrome
}

void check_palindrome() {
    char input_str[MAX_LENGTH];

    printf("Please enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(input_str, MAX_LENGTH, stdin);

    // Remove newline character if present
    input_str[strcspn(input_str, "\n")] = 0;

    convert_to_lowercase(input_str);
    strip_non_alpha(input_str);
    
    if (is_palindrome(input_str)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }
}

int main() {
    print_welcome_message();

    char continue_checking;
    do {
        check_palindrome();
        printf("Do you want to check another string? (y/n): ");
        scanf(" %c", &continue_checking);
        getchar(); // Clear newline from buffer after scanf
    } while (continue_checking == 'y' || continue_checking == 'Y');

    printf("Thank you for using the Palindrome Checker!\n");
    return 0;
}