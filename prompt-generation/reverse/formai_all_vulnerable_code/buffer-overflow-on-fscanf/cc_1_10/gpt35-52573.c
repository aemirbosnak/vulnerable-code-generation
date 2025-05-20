//FormAI DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_BOOKS 100

struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    char* content;
};

struct Library {
    struct Book books[MAX_BOOKS];
    int num_books;
};

void read_book(struct Book* book, FILE* file) {
    fgets(book->title, MAX_TITLE_LENGTH, file);
    fgets(book->author, MAX_AUTHOR_LENGTH, file);
    fscanf(file, "%d", &book->pages);
    // allocate memory for the content and read it from the file
    book->content = (char*)malloc(sizeof(char) * book->pages);
    fscanf(file, "%s", book->content);
}

void print_book(struct Book* book) {
    printf("Title: %s", book->title);
    printf("Author: %s", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Content: %s\n", book->content);
}

void print_library(struct Library* library) {
    for (int i = 0; i < library->num_books; i++) {
        printf("Book %d:\n", i+1);
        print_book(&library->books[i]);
    }
}

int main() {
    struct Library library;
    library.num_books = 0;

    char filename[] = "library.txt";
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (!feof(file)) {
        struct Book book;
        read_book(&book, file);
        library.books[library.num_books++] = book;
    }

    fclose(file);

    print_library(&library);

    return 0;
}