//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]) {
    char input_line[MAX_LINE_SIZE];
    int input_line_length;
    char *cleaned_line;
    int cleaned_line_length;
    int is_palindrome;
    int i;

    printf("Enter a line of text:\n");

    if (fgets(input_line, MAX_LINE_SIZE, stdin) == NULL) {
        printf("Error: Input line is too long.\n");
        return 1;
    }

    input_line_length = strlen(input_line);

    if (input_line_length == 0) {
        printf("Error: Input line is empty.\n");
        return 1;
    }

    // Clean up the input line
    cleaned_line = malloc(input_line_length + 1);
    cleaned_line_length = 0;
    for (i = 0; i < input_line_length; i++) {
        if (isalnum(input_line[i])) {
            cleaned_line[cleaned_line_length++] = tolower(input_line[i]);
        }
    }
    cleaned_line[cleaned_line_length] = '\0';

    // Check if the cleaned line is a palindrome
    is_palindrome = 1;
    for (i = 0; i < cleaned_line_length / 2; i++) {
        if (cleaned_line[i]!= cleaned_line[cleaned_line_length - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome) {
        printf("The input line is a palindrome.\n");
    } else {
        printf("The input line is not a palindrome.\n");
    }

    free(cleaned_line);
    return 0;
}