//Falcon-180B DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char *text;
    int length;
} Text;

Text *create_text(char *text) {
    Text *new_text = malloc(sizeof(Text));
    new_text->text = strdup(text);
    new_text->length = strlen(text);
    return new_text;
}

void print_text(Text *text) {
    printf("%s\n", text->text);
}

void delete_text(Text *text) {
    free(text->text);
    free(text);
}

void count_words(Text *text) {
    int count = 0;
    char *token = strtok(text->text, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    printf("Number of words: %d\n", count);
}

void count_lines(Text *text) {
    int count = 0;
    char *line = strtok(text->text, "\n");
    while (line!= NULL) {
        count++;
        line = strtok(NULL, "\n");
    }
    printf("Number of lines: %d\n", count);
}

void count_chars(Text *text) {
    int count = 0;
    char *char_array = text->text;
    while (*char_array!= '\0') {
        count++;
        char_array++;
    }
    printf("Number of characters: %d\n", count);
}

int main() {
    char input_text[MAX_LINE_LENGTH];
    printf("Enter some text:\n");
    fgets(input_text, MAX_LINE_LENGTH, stdin);
    Text *text = create_text(input_text);
    printf("Original text:\n");
    print_text(text);
    count_words(text);
    count_lines(text);
    count_chars(text);
    delete_text(text);
    return 0;
}