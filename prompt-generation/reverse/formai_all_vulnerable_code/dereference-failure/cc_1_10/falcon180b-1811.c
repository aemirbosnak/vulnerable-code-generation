//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_TEXT_LENGTH 100000

typedef struct {
    char *text;
    int length;
} Text;

void print_text(Text *text, int indent) {
    int i = 0;
    while (i < text->length) {
        if (i + indent >= MAX_LINE_LENGTH) {
            printf("\n");
            for (int j = 0; j < indent; j++) {
                printf(" ");
            }
        }
        if (text->text[i] == '\n') {
            printf("\n");
            for (int j = 0; j < indent; j++) {
                printf(" ");
            }
        } else {
            printf("%c", text->text[i]);
        }
        i++;
    }
}

void generate_ascii_art(Text *text, int indent) {
    int i = 0;
    while (i < text->length) {
        if (text->text[i] == '\n') {
            printf("\n");
            for (int j = 0; j < indent; j++) {
                printf(" ");
            }
        } else if (isalpha(text->text[i])) {
            printf("%c", toupper(text->text[i]));
        } else {
            printf(" ");
        }
        i++;
    }
}

int main() {
    Text text;
    text.text = (char *)malloc(MAX_TEXT_LENGTH * sizeof(char));
    text.length = 0;

    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", text.text + text.length)!= EOF) {
        text.length += strlen(text.text + text.length);
    }

    fclose(file);

    printf("Input text:\n");
    print_text(&text, 0);

    printf("\nASCII art:\n");
    generate_ascii_art(&text, 0);

    free(text.text);

    return 0;
}