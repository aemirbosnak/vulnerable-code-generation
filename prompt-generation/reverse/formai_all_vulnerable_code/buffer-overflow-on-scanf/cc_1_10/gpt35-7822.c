//FormAI DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for buffer size and input string length
#define BUFFER_SIZE 100
#define INPUT_LENGTH 30

// Declare function prototypes
void change_case(char* str, char config);
void reverse_string(char* str);

int main() {
    char input[INPUT_LENGTH];  // Input string
    char config;  // Configuration for text processing
    char buffer[BUFFER_SIZE];  // Buffer for processed text
    printf("Enter a string to process: ");
    fgets(input, INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove newline character from input
    printf("Enter a configuration for text processing [C/c for Capitalize, L/l for Lowercase, R/r for Reverse]: ");
    scanf(" %c", &config);
    change_case(input, config);
    if (config == 'R' || config == 'r') {
        reverse_string(input);
    }
    // Copy processed string to buffer and print to console
    snprintf(buffer, BUFFER_SIZE, "Processed String: %s\n", input);
    printf("%s", buffer);
    return 0;
}

// Function to change the case of a string based on configuration (C/c for Capitalize, L/l for Lowercase)
void change_case(char* str, char config) {
    int i;
    int length = strlen(str);
    if (config == 'C' || config == 'c') {
        for (i = 0; i < length; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {  // If character is lowercase, convert to uppercase
                str[i] -= 32;
            }
        }
    } else if (config == 'L' || config == 'l') {
        for (i = 0; i < length; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {  // If character is uppercase, convert to lowercase
                str[i] += 32;
            }
        }
    }
}

// Function to reverse a string
void reverse_string(char* str) {
    int i, j;
    char temp;
    int length = strlen(str);
    for (i = 0, j = length - 1; i < j; i++, j--) {  // Swap characters from start to end and end to start until halfway point is reached
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}