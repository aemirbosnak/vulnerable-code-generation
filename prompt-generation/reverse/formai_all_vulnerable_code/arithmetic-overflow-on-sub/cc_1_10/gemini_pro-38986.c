//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int page;
    int line;
    int column;
} Location;

typedef struct {
    Location start;
    Location end;
    char *text;
} Paragraph;

typedef struct {
    int num_paragraphs;
    Paragraph *paragraphs;
} Chapter;

typedef struct {
    int num_chapters;
    Chapter *chapters;
} Book;

Book *read_book(FILE *fp) {
    Book *book = malloc(sizeof(Book));
    book->num_chapters = 0;
    book->chapters = NULL;

    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            book->num_chapters++;
            book->chapters = realloc(book->chapters, book->num_chapters * sizeof(Chapter));
            Chapter *chapter = &book->chapters[book->num_chapters - 1];
            chapter->num_paragraphs = 0;
            chapter->paragraphs = NULL;
        } else {
            Chapter *chapter = &book->chapters[book->num_chapters - 1];
            char *line = malloc(1024);
            int line_length = 0;
            while ((c = fgetc(fp)) != EOF && c != '\n') {
                line[line_length++] = c;
            }
            line[line_length] = '\0';

            Paragraph *paragraph = malloc(sizeof(Paragraph));
            paragraph->start.page = book->num_chapters;
            paragraph->start.line = chapter->num_paragraphs;
            paragraph->start.column = 0;
            paragraph->end.page = book->num_chapters;
            paragraph->end.line = chapter->num_paragraphs;
            paragraph->end.column = line_length;
            paragraph->text = strdup(line);

            chapter->num_paragraphs++;
            chapter->paragraphs = realloc(chapter->paragraphs, chapter->num_paragraphs * sizeof(Paragraph));
            chapter->paragraphs[chapter->num_paragraphs - 1] = *paragraph;
        }
    }

    return book;
}

void print_book(Book *book) {
    for (int i = 0; i < book->num_chapters; i++) {
        Chapter *chapter = &book->chapters[i];
        printf("Chapter %d\n", i + 1);
        for (int j = 0; j < chapter->num_paragraphs; j++) {
            Paragraph *paragraph = &chapter->paragraphs[j];
            printf("Paragraph %d\n", j + 1);
            printf("Text: %s\n", paragraph->text);
        }
    }
}

void free_book(Book *book) {
    for (int i = 0; i < book->num_chapters; i++) {
        Chapter *chapter = &book->chapters[i];
        for (int j = 0; j < chapter->num_paragraphs; j++) {
            Paragraph *paragraph = &chapter->paragraphs[j];
            free(paragraph->text);
        }
        free(chapter->paragraphs);
    }
    free(book->chapters);
    free(book);
}

int main() {
    FILE *fp = fopen("book.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return EXIT_FAILURE;
    }

    Book *book = read_book(fp);
    fclose(fp);

    print_book(book);

    free_book(book);

    return EXIT_SUCCESS;
}