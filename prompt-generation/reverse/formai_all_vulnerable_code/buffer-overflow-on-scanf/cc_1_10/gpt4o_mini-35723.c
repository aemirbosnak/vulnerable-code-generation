//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

// Function to safely read a line of input
void safe_readline(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove newline character from the buffer
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    } else {
        // Handle error in reading
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }
}

// Function to concatenate two strings safely
char* safe_strcat(char *dest, const char *src, size_t buffer_size) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);

    if (dest_len + src_len + 1 > buffer_size) {
        fprintf(stderr, "Error: Concatenation would exceed buffer size.\n");
        exit(EXIT_FAILURE);
    }

    strcat(dest, src);
    return dest;
}

// Function to copy a string safely
char* safe_strcpy(char *dest, const char *src, size_t buffer_size) {
    size_t src_len = strlen(src);

    if (src_len + 1 > buffer_size) {
        fprintf(stderr, "Error: Copy would exceed buffer size.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(dest, src);
    return dest;
}

// Function to reverse a string
void reverse_string(char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to convert string to uppercase
void to_uppercase(char *str) {
    for (size_t i = 0; str[i]; i++) {
        str[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i];
    }
}

// Function to convert string to lowercase
void to_lowercase(char *str) {
    for (size_t i = 0; str[i]; i++) {
        str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
    }
}

// Function to print a menu of options
void print_menu() {
    printf("String Manipulation Menu:\n");
    printf("1: Concatenate Strings\n");
    printf("2: Copy String\n");
    printf("3: Reverse String\n");
    printf("4: Convert to Uppercase\n");
    printf("5: Convert to Lowercase\n");
    printf("6: Exit\n");
}

int main() {
    char str1[BUFFER_SIZE], str2[BUFFER_SIZE];
    int choice;
    
    printf("Enter the first string: ");
    safe_readline(str1, BUFFER_SIZE);

    do {
        print_menu();
        printf("Select an option: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            exit(EXIT_FAILURE);
        }
        
        getchar(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                printf("Enter the second string: ");
                safe_readline(str2, BUFFER_SIZE);
                safe_strcat(str1, str2, BUFFER_SIZE);
                printf("Concatenated String: %s\n", str1);
                break;
            case 2:
                printf("Enter the string to copy: ");
                safe_readline(str2, BUFFER_SIZE);
                safe_strcpy(str1, str2, BUFFER_SIZE);
                printf("Copied String: %s\n", str1);
                break;
            case 3:
                reverse_string(str1);
                printf("Reversed String: %s\n", str1);
                break;
            case 4:
                to_uppercase(str1);
                printf("Uppercase String: %s\n", str1);
                break;
            case 5:
                to_lowercase(str1);
                printf("Lowercase String: %s\n", str1);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}