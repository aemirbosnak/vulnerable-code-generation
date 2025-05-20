//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 100

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void replace_char(char *str, char old_char, char new_char) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == old_char) {
            str[i] = new_char;
        }
    }
}

void palindrome_check(char *str) {
    int len = strlen(str);
    int is_palindrome = 1;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }
    printf("The string \"%s\" is %s palindrome.\n", str, is_palindrome ? "a" : "not a");
}

void concatenate_strings(char *str1, const char *str2) {
    strcat(str1, str2);
}

void split_string(const char *str, char delimiter) {
    char *temp_str = strdup(str);
    char *token = strtok(temp_str, &delimiter);
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, &delimiter);
    }
    free(temp_str);
}

int main() {
    char str1[MAX_STR_LEN];
    char str2[MAX_STR_LEN];
    
    // User input
    printf("Enter the first string: ");
    fgets(str1, MAX_STR_LEN, stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, MAX_STR_LEN, stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    // Display original strings
    printf("\nOriginal String 1: %s\n", str1);
    printf("Original String 2: %s\n", str2);

    // Manipulations
    to_uppercase(str1);
    printf("Uppercase String 1: %s\n", str1);

    to_lowercase(str2);
    printf("Lowercase String 2: %s\n", str2);

    char str3[MAX_STR_LEN];
    strcpy(str3, str1);
    reverse_string(str3);
    printf("Reversed String 1: %s\n", str3);

    char old_char, new_char;
    printf("Enter a character to replace in String 1: ");
    scanf(" %c", &old_char);
    printf("Enter a new character to replace with: ");
    scanf(" %c", &new_char);
    replace_char(str1, old_char, new_char);
    printf("Modified String 1: %s\n", str1);

    palindrome_check(str1);

    // Concatenation
    char concatenated[MAX_STR_LEN * 2];
    strcpy(concatenated, str1);
    concatenate_strings(concatenated, str2);
    printf("Concatenated String: %s\n", concatenated);

    // Split String
    printf("Enter a delimiter to split String 1: ");
    char delimiter;
    scanf(" %c", &delimiter);
    printf("Splitting String 1 by '%c':\n", delimiter);
    split_string(str1, delimiter);

    // Final message
    printf("String manipulation complete!\n");

    return 0;
}