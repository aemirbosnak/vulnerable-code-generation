//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

// Function Prototypes
void to_uppercase(char *str);
void to_lowercase(char *str);
void reverse_string(char *str);
void remove_whitespace(char *str);
void display_menu();
void execute_option(int option);

int main() {
    char input[MAX_LEN];
    int option;
    
    printf("Enter a string (max %d characters): ", MAX_LEN - 1);
    fgets(input, MAX_LEN, stdin);
    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    while (1) {
        display_menu();
        printf("Choose an option (0 to quit): ");
        scanf("%d", &option);
        
        if (option == 0) {
            printf("Exiting program.\n");
            break;
        }
        
        execute_option(option);
    }

    return 0;
}

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
    printf("Uppercase: %s\n", str);
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    printf("Lowercase: %s\n", str);
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    printf("Reversed: %s\n", str);
}

void remove_whitespace(char *str) {
    char *dest = str;
    for (int i = 0; str[i]; i++) {
        if (!isspace(str[i])) {
            *dest++ = str[i];
        }
    }
    *dest = '\0'; // Null-terminate the new string
    printf("No Whitespace: %s\n", str);
}

void display_menu() {
    printf("\nString Manipulation Options:\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Convert to Lowercase\n");
    printf("3. Reverse String\n");
    printf("4. Remove Whitespace\n");
    printf("Enter your choice: ");
}

void execute_option(int option) {
    static char input[MAX_LEN] = {0}; // Static to retain input across function calls
    printf("Current String: %s\n", input);
    printf("Enter the string to manipulate: ");
    scanf(" %[^\n]", input);  // Read until newline

    switch (option) {
        case 1:
            to_uppercase(input);
            break;
        case 2:
            to_lowercase(input);
            break;
        case 3:
            reverse_string(input);
            break;
        case 4:
            remove_whitespace(input);
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }
}