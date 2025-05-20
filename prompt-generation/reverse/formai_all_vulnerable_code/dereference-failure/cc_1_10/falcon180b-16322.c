//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_LENGTH 100
#define MAX_CHAPTER_LENGTH 1000

typedef struct {
    char title[MAX_BOOK_NAME_LENGTH];
    int num_chapters;
    char *chapters[MAX_BOOKS];
} Book;

void add_chapter(Book *book, char *chapter) {
    int i;
    for (i = 0; i < book->num_chapters; i++) {
        if (strcmp(book->chapters[i], chapter) == 0) {
            return;
        }
    }
    book->chapters[book->num_chapters++] = strdup(chapter);
}

int main() {
    Book book;
    char input[MAX_BOOK_NAME_LENGTH];
    char chapter[MAX_CHAPTER_LENGTH];
    int i;

    printf("Enter the name of the book: ");
    scanf("%s", input);
    strcpy(book.title, input);

    printf("Enter the number of chapters: ");
    scanf("%d", &book.num_chapters);

    for (i = 0; i < book.num_chapters; i++) {
        printf("Enter the name of chapter %d: ", i+1);
        scanf("%s", chapter);
        add_chapter(&book, chapter);
    }

    printf("The book %s has %d chapters:\n", book.title, book.num_chapters);
    for (i = 0; i < book.num_chapters; i++) {
        printf("Chapter %d: %s\n", i+1, book.chapters[i]);
    }

    return 0;
}