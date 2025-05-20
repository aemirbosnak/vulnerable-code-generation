//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void input_string(char *str, int length);
void reverse_string(char *str);
void to_uppercase(char *str);
void to_lowercase(char *str);
void concatenate_strings(char *dest, const char *src);
void find_substring(const char *str, const char *substr);
void replace_substring(char *str, const char *old, const char *new);
void print_menu();

#define MAX_LENGTH 256
#define MAX_SUB_LENGTH 64

int main() {
    char str[MAX_LENGTH];
    char temp_str[MAX_LENGTH];
    char substr[MAX_SUB_LENGTH];
    char new_sub[MAX_SUB_LENGTH];
    int choice;

    printf("Enter a string (up to 255 characters): ");
    input_string(str, MAX_LENGTH);

    do {
        print_menu();
        printf("Choose an operation (1-7, 0 to exit): ");
        scanf("%d", &choice);
        getchar();  // To clear the newline character

        switch (choice) {
            case 1:
                printf("Original string: %s\n", str);
                break;
            case 2:
                strcpy(temp_str, str);
                reverse_string(temp_str);
                printf("Reversed string: %s\n", temp_str);
                break;
            case 3:
                strcpy(temp_str, str);
                to_uppercase(temp_str);
                printf("Uppercase string: %s\n", temp_str);
                break;
            case 4:
                strcpy(temp_str, str);
                to_lowercase(temp_str);
                printf("Lowercase string: %s\n", temp_str);
                break;
            case 5:
                printf("Enter string to concatenate: ");
                input_string(temp_str, MAX_LENGTH);
                concatenate_strings(str, temp_str);
                printf("Concatenated string: %s\n", str);
                break;
            case 6:
                printf("Enter substring to find: ");
                input_string(substr, MAX_SUB_LENGTH);
                find_substring(str, substr);
                break;
            case 7:
                printf("Enter substring to replace: ");
                input_string(substr, MAX_SUB_LENGTH);
                printf("Enter new substring: ");
                input_string(new_sub, MAX_SUB_LENGTH);
                replace_substring(str, substr, new_sub);
                printf("String after replacement: %s\n", str);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        printf("\n");
    } while (choice != 0);

    return 0;
}

void input_string(char *str, int length) {
    fgets(str, length, stdin);
    str[strcspn(str, "\n")] = 0;  // Remove newline character
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 'a' + 'A' : str[i];
    }
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] - 'A' + 'a' : str[i];
    }
}

void concatenate_strings(char *dest, const char *src) {
    strncat(dest, src, MAX_LENGTH - strlen(dest) - 1);
}

void find_substring(const char *str, const char *substr) {
    char *pos = strstr(str, substr);
    if (pos) {
        printf("Substring found at position: %ld\n", pos - str);
    } else {
        printf("Substring not found.\n");
    }
}

void replace_substring(char *str, const char *old, const char *new) {
    char *pos = strstr(str, old);
    if (pos) {
        char buffer[MAX_LENGTH];
        int old_len = strlen(old);
        int new_len = strlen(new);

        strncpy(buffer, str, pos - str);
        buffer[pos - str] = '\0';
        strcat(buffer, new);
        strcat(buffer, pos + old_len);
        strcpy(str, buffer);
    } else {
        printf("Substring to replace not found.\n");
    }
}

void print_menu() {
    printf("Menu:\n");
    printf("1. Display original string\n");
    printf("2. Reverse string\n");
    printf("3. Convert to uppercase\n");
    printf("4. Convert to lowercase\n");
    printf("5. Concatenate another string\n");
    printf("6. Find a substring\n");
    printf("7. Replace a substring\n");
    printf("0. Exit\n");
}