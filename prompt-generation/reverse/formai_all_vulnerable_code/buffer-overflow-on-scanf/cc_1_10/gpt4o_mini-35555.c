//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Function declarations
void convert_to_uppercase(char *str);
void reverse_string(char *str);
void find_substring(char *str, char *sub);
void replace_substring(char *str, char *sub, char *replacement);
void print_menu();
void get_input(char *prompt, char *buffer, size_t size);

int main() {
    char str[MAX_STRING_LENGTH];
    char sub[MAX_STRING_LENGTH];
    char replacement[MAX_STRING_LENGTH];
    int choice;

    printf("Welcome to the C String Manipulation Program!\n");

    // Get initial string input
    get_input("Please enter a string: ", str, sizeof(str));

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character left in buffer

        switch (choice) {
            case 1:
                convert_to_uppercase(str);
                printf("String in uppercase: %s\n", str);
                break;
            case 2:
                reverse_string(str);
                printf("Reversed string: %s\n", str);
                break;
            case 3:
                get_input("Enter substring to find: ", sub, sizeof(sub));
                find_substring(str, sub);
                break;
            case 4:
                get_input("Enter substring to replace: ", sub, sizeof(sub));
                get_input("Enter replacement string: ", replacement, sizeof(replacement));
                replace_substring(str, sub, replacement);
                printf("Updated string: %s\n", str);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void convert_to_uppercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 'a' - 'A';
        }
    }
}

void reverse_string(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void find_substring(char *str, char *sub) {
    char *pos = strstr(str, sub);
    if (pos) {
        printf("Substring \"%s\" found at position %ld.\n", sub, pos - str);
    } else {
        printf("Substring \"%s\" not found in the string.\n", sub);
    }
}

void replace_substring(char *str, char *sub, char *replacement) {
    char buffer[MAX_STRING_LENGTH];
    char *pos;
    int index = 0;
    int sub_len = strlen(sub);
    int replacement_len = strlen(replacement);

    if ((pos = strstr(str, sub)) != NULL) {
        // Copy characters from original string to buffer
        while (str + index != pos) {
            buffer[index++] = str[index];
        }

        // Add replacement string into buffer
        for (int i = 0; i < replacement_len; i++) {
            buffer[index++] = replacement[i];
        }

        // Add remaining part of the original string
        strcpy(buffer + index, pos + sub_len);
        strcpy(str, buffer);
    }
}

void print_menu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Reverse String\n");
    printf("3. Find Substring\n");
    printf("4. Replace Substring\n");
    printf("5. Exit\n");
}

void get_input(char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}