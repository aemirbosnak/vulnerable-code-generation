//Falcon-180B DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *text;
    int length;
} Text;

void initialize_text(Text *text) {
    text->text = malloc(MAX_LINE_LENGTH * sizeof(char));
    text->length = 0;
}

void append_char_to_text(Text *text, char c) {
    if (text->length >= MAX_LINE_LENGTH) {
        printf("Error: Text is too long.\n");
        exit(1);
    }
    text->text[text->length++] = c;
    text->text[text->length] = '\0';
}

void print_text(Text *text) {
    printf("%s", text->text);
}

int main() {
    Text input_text, output_text;
    char c;

    initialize_text(&input_text);
    initialize_text(&output_text);

    printf("Enter a romantic message: ");
    while ((c = getchar())!= '\n') {
        if (isalpha(c)) {
            if (isupper(c)) {
                append_char_to_text(&output_text, tolower(c));
            } else {
                append_char_to_text(&output_text, toupper(c));
            }
        } else {
            append_char_to_text(&output_text, c);
        }
    }

    printf("\nYour romantic message with alternating case:\n");
    print_text(&output_text);

    return 0;
}