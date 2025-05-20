//FormAI DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 30

struct Book {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int year;
    char filetype[4];
    int pages;
    char filepath[50];
};

struct EbookLibrary {
    int numBooks;
    struct Book books[MAX_BOOKS];
};

int main() {
    struct EbookLibrary library;
    library.numBooks = 0;

    // Reading in books from a file
    FILE* fp = fopen("books.txt", "r");
    if (fp != NULL) {
        char buffer[100];
        while (fgets(buffer, 100, fp) != NULL) {
            struct Book newBook;
            // Parsing book data from buffer
            sscanf(buffer, "%[^,],%[^,],%d,%[^,],%d,%s",
                newBook.title, newBook.author, &newBook.year,
                newBook.filetype, &newBook.pages, newBook.filepath);
            library.books[library.numBooks] = newBook;
            library.numBooks++;
        }
        fclose(fp);
    }

    // Displaying book information
    printf("Welcome to our Ebook Library! We have %d books available.\n\n", library.numBooks);
    for (int i = 0; i < library.numBooks; i++) {
        printf("%d. Title: %s\n", i+1, library.books[i].title);
        printf("   Author: %s\n", library.books[i].author);
        printf("   Year: %d\n", library.books[i].year);
        printf("   Filetype: %s\n", library.books[i].filetype);
        printf("   Pages: %d\n", library.books[i].pages);
        printf("   Filepath: %s\n\n", library.books[i].filepath);
    }

    // User selects book to read
    int bookChoice;
    printf("Please select a book to read (1-%d): ", library.numBooks);
    scanf("%d", &bookChoice);
    getchar();  // Consume newline character from scanf
    if (bookChoice < 1 || bookChoice > library.numBooks) {
        printf("Invalid choice.\n");
        exit(1);
    }
    struct Book chosenBook = library.books[bookChoice-1];

    // Opening file for reading
    fp = fopen(chosenBook.filepath, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Reading book content from file and displaying to user
    char contents[1000];
    fgets(contents, 1000, fp);
    printf("\n%s", contents);
    while (fgets(contents, 1000, fp) != NULL) {
        printf("%s", contents);
    }

    fclose(fp);
    return 0;
}