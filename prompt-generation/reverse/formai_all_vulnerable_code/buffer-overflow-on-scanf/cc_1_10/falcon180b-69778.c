//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_PARAGRAPH_LENGTH 5000

typedef struct {
    char *text;
    int length;
} Paragraph;

Paragraph *read_paragraph(FILE *file) {
    char ch;
    Paragraph *paragraph = malloc(sizeof(Paragraph));
    paragraph->text = malloc(MAX_PARAGRAPH_LENGTH * sizeof(char));
    paragraph->length = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n' || ch == '\r') {
            break;
        }

        if (paragraph->length >= MAX_PARAGRAPH_LENGTH - 1) {
            break;
        }

        paragraph->text[paragraph->length] = ch;
        paragraph->length++;
    }

    paragraph->text[paragraph->length] = '\0';

    return paragraph;
}

void print_paragraph(Paragraph *paragraph) {
    printf("%s\n", paragraph->text);
}

void free_paragraph(Paragraph *paragraph) {
    free(paragraph->text);
    free(paragraph);
}

int main() {
    FILE *file;
    char filename[100];
    Paragraph *paragraph;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while ((paragraph = read_paragraph(file))!= NULL) {
        print_paragraph(paragraph);
        free_paragraph(paragraph);
    }

    fclose(file);

    return 0;
}