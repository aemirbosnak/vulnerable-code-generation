//Code Llama-13B DATASET v1.0 Category: Text to ASCII art generator ; Style: realistic
// Text to ASCII Art Generator
// by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to print a line of ASCII art
void print_line(char *line) {
    int len = strlen(line);
    for (int i = 0; i < len; i++) {
        printf(" %c ", line[i]);
    }
    printf("\n");
}

// Function to print a box around a line of text
void print_box(char *text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (i == 0 || i == len - 1) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

// Main function
int main() {
    char text[MAX_LEN];
    printf("Enter text: ");
    scanf("%s", text);

    // Get the length of the text
    int len = strlen(text);

    // Print the text with a box around it
    print_box(text);

    // Print the text with ASCII art characters
    for (int i = 0; i < len; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            // Lowercase letters
            printf(" _______ \n");
            printf("/        \\ \n");
            printf("|        | \n");
            printf("|        | \n");
            printf("|  %c  | \n", c);
            printf("|        | \n");
            printf("|        | \n");
            printf("|_______| \n");
        } else if (c >= 'A' && c <= 'Z') {
            // Uppercase letters
            printf(" _______ \n");
            printf("/        \\ \n");
            printf("|        | \n");
            printf("|        | \n");
            printf("|  %c  | \n", c);
            printf("|        | \n");
            printf("|        | \n");
            printf("|_______| \n");
        } else {
            // Other characters
            printf(" _______ \n");
            printf("/        \\ \n");
            printf("|        | \n");
            printf("|        | \n");
            printf("|  %c  | \n", c);
            printf("|        | \n");
            printf("|        | \n");
            printf("|_______| \n");
        }
    }

    return 0;
}