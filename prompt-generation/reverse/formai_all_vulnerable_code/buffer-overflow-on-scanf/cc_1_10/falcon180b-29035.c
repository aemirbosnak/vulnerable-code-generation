//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_PAGES_PER_BOOK 1000
#define MAX_WORDS_PER_PAGE 100
#define MAX_CHARS_PER_WORD 50
#define MAX_LINES_PER_PAGE 40

typedef struct {
    char title[MAX_CHARS_PER_WORD];
    int pages;
} Book;

typedef struct {
    char words[MAX_CHARS_PER_WORD];
    int chars;
} Page;

typedef struct {
    char lines[MAX_CHARS_PER_WORD];
    int length;
} Line;

int main() {
    Book books[MAX_BOOKS];
    Page pages[MAX_PAGES_PER_BOOK];
    Line lines[MAX_LINES_PER_PAGE];

    int numBooks = 0;
    int numPages = 0;
    int numLines = 0;

    char input[MAX_CHARS_PER_WORD];

    printf("Welcome to the Ebook Reader!\n");
    printf("Please enter the title of the book you would like to read:\n");
    scanf("%s", input);

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, input) == 0) {
            printf("You have already added this book.\n");
            return 0;
        }
    }

    strcpy(books[numBooks].title, input);
    numBooks++;

    printf("Please enter the number of pages in the book:\n");
    scanf("%d", &numPages);

    for (int i = 0; i < numPages; i++) {
        printf("Please enter the text for page %d:\n", i + 1);
        scanf("%s", pages[i].words);
    }

    for (int i = 0; i < numPages; i++) {
        numLines = 0;

        while (numLines < MAX_LINES_PER_PAGE && pages[i].words[numLines * MAX_CHARS_PER_WORD]!= '\0') {
            strncpy(lines[numLines].lines, pages[i].words + (numLines * MAX_CHARS_PER_WORD), MAX_CHARS_PER_WORD);
            numLines++;
        }

        printf("Page %d:\n", i + 1);

        for (int j = 0; j < numLines; j++) {
            printf("%s\n", lines[j].lines);
        }
    }

    return 0;
}