//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE 100
#define MAX_BOOKS 10
#define MAX_CHAPTERS 20
#define MAX_WORDS 50

typedef struct {
    char title[50];
    char author[50];
    char** chapters;
    int numChapters;
} Book;

void loadBook(FILE* file, Book* book) {
    fscanf(file, "%s %s", book->title, book->author);
    book->numChapters = 0;

    book->chapters = (char**)malloc(MAX_CHAPTERS * sizeof(char*));

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, file) && book->numChapters < MAX_CHAPTERS) {
        int len = strlen(line);
        if (line[len - 1] == '\n') line[len - 1] = '\0';
        book->chapters[book->numChapters] = (char*)malloc(len + 1);
        strcpy(book->chapters[book->numChapters], line);
        book->numChapters++;
    }
}

void displayChapter(int bookNum, int chapterNum, Book books[]) {
    printf("\nBook: %s by %s\n", books[bookNum].title, books[bookNum].author);
    printf("\nChapter: %d\n", chapterNum + 1);
    printf("\n%s\n", books[bookNum].chapters[chapterNum]);
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    FILE* file = fopen("books.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open books.txt\n");
        return 1;
    }

    while (!feof(file) && numBooks < MAX_BOOKS) {
        Book book;
        loadBook(file, &book);
        books[numBooks] = book;
        numBooks++;
    }

    fclose(file);

    int bookNum, chapterNum;
    while (1) {
        printf("\nSelect a book (0 to quit): ");
        scanf("%d", &bookNum);

        if (bookNum == 0) break;

        if (bookNum < 0 || bookNum >= numBooks) {
            printf("Error: Invalid book number\n");
            continue;
        }

        printf("\nSelect a chapter (0 to quit): ");
        scanf("%d", &chapterNum);

        if (chapterNum < 0) {
            printf("Error: Invalid chapter number\n");
            continue;
        }

        displayChapter(bookNum, chapterNum, books);
    }

    for (int i = 0; i < numBooks; i++) {
        for (int j = 0; j < books[i].numChapters; j++) {
            free(books[i].chapters[j]);
        }
        free(books[i].chapters);
    }

    return 0;
}