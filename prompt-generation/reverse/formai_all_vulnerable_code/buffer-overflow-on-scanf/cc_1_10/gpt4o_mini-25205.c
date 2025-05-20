//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 200

void to_uppercase(char *str);
void reverse_string(char *str);
void find_substring(char *str, const char *substring);
void remove_whitespace(char *str);
void replace_character(char *str, char oldChar, char newChar);
void print_instructions();

int main() {
    char original[MAX_LENGTH];
    char action;
    char substring[MAX_LENGTH];
    char oldChar, newChar;

    print_instructions();

    printf("Enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(original, MAX_LENGTH, stdin);
    // Remove newline character if present
    original[strcspn(original, "\n")] = 0;

    do {
        printf("\nChoose an action:\n");
        printf("a. Convert to uppercase\n");
        printf("b. Reverse the string\n");
        printf("c. Find a substring\n");
        printf("d. Remove whitespace\n");
        printf("e. Replace a character\n");
        printf("f. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &action);
        getchar(); // To consume newline left in buffer

        switch (action) {
            case 'a':
                to_uppercase(original);
                printf("Uppercase: %s\n", original);
                break;
            case 'b':
                reverse_string(original);
                printf("Reversed: %s\n", original);
                break;
            case 'c':
                printf("Enter the substring to find: ");
                fgets(substring, MAX_LENGTH, stdin);
                substring[strcspn(substring, "\n")] = 0;
                find_substring(original, substring);
                break;
            case 'd':
                remove_whitespace(original);
                printf("Without whitespace: %s\n", original);
                break;
            case 'e':
                printf("Enter character to be replaced: ");
                oldChar = getchar();
                getchar(); // To consume newline
                printf("Enter new character: ");
                newChar = getchar();
                getchar(); // To consume newline
                replace_character(original, oldChar, newChar);
                printf("After replacement: %s\n", original);
                break;
            case 'f':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (action != 'f');

    return 0;
}

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void reverse_string(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void find_substring(char *str, const char *substring) {
    char *pos = strstr(str, substring);
    if (pos) {
        printf("Substring found at position: %ld\n", pos - str);
    } else {
        printf("Substring not found.\n");
    }
}

void remove_whitespace(char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (!isspace((unsigned char)str[i])) {
            str[count++] = str[i]; // Remove whitespace
        }
    }
    str[count] = '\0'; // Null terminate the string
}

void replace_character(char *str, char oldChar, char newChar) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

void print_instructions() {
    printf("Welcome to the String Manipulation Program!\n");
    printf("This program allows you to perform various actions on strings.\n");
    printf("You can convert to uppercase, reverse the string, find a substring,\n");
    printf("remove whitespaces, or replace characters in the string.\n");
    printf("Please make your selection from the menu provided.\n");
}