//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_LINE_COUNT 1000

struct line_info {
    char* text;
    int length;
};

struct line_info lines[MAX_LINE_COUNT];
int line_count = 0;

void add_line(char* text) {
    if (line_count >= MAX_LINE_COUNT) {
        fprintf(stderr, "Error: Too many lines.\n");
        exit(1);
    }

    lines[line_count].text = strdup(text);
    lines[line_count].length = strlen(text);

    line_count++;
}

void print_lines() {
    for (int i = 0; i < line_count; i++) {
        printf("%s\n", lines[i].text);
    }
}

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char* input_text = NULL;
    size_t input_size = 0;

    while (1) {
        printf("Enter a line of text (or type 'done' to finish):\n");
        fgets(input_buffer, MAX_LINE_LENGTH, stdin);

        input_text = strtok(input_buffer, "\n");
        input_size = strlen(input_text);

        if (input_size == 0 || strcmp(input_text, "done") == 0) {
            break;
        }

        add_line(input_text);
    }

    print_lines();

    for (int i = 0; i < line_count; i++) {
        if (is_palindrome(lines[i].text)) {
            printf("Line %d is a palindrome.\n", i + 1);
        } else {
            printf("Line %d is not a palindrome.\n", i + 1);
        }
    }

    return 0;
}

int is_palindrome(char* text) {
    int length = strlen(text);
    int is_palindrome = 1;

    for (int i = 0; i < length / 2; i++) {
        if (text[i]!= text[length - 1 - i]) {
            is_palindrome = 0;
            break;
        }
    }

    return is_palindrome;
}