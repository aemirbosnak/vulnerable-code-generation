//Code Llama-13B DATASET v1.0 Category: Text processing ; Style: paranoid
/*
*  paranoid_text_processing.c
*
*  This program demonstrates how to perform text processing in a paranoid style.
*  The program takes a text input and converts it to uppercase, then checks if
*  the resulting text is a palindrome. If it is not, the program will abort.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000

int main(int argc, char *argv[]) {
    char input[MAX_LEN];
    char output[MAX_LEN];
    int i;

    // Read input from the command line
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }
    strncpy(input, argv[1], MAX_LEN);

    // Convert input to uppercase
    for (i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Check if input is a palindrome
    if (is_palindrome(input)) {
        printf("Input is a palindrome\n");
    } else {
        printf("Input is not a palindrome\n");
        return 1;
    }

    return 0;
}

int is_palindrome(char *text) {
    int i;
    int len = strlen(text);
    char *p = text;

    for (i = 0; i < len / 2; i++) {
        if (p[i] != p[len - i - 1]) {
            return 0;
        }
    }

    return 1;
}