//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define INITIAL_CAPACITY 2

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int pages;
} Book;

typedef struct {
    Book *books;
    size_t size;
    size_t capacity;
} Library;

Library *create_library() {
    Library *lib = (Library *)malloc(sizeof(Library));
    lib->size = 0;
    lib->capacity = INITIAL_CAPACITY;
    lib->books = (Book *)malloc(lib->capacity * sizeof(Book));
    return lib;
}

void resize_library(Library *lib) {
    lib->capacity *= 2;
    lib->books = (Book *)realloc(lib->books, lib->capacity * sizeof(Book));
}

void add_book(Library *lib, const char *title, int pages) {
    if (lib->size == lib->capacity) {
        resize_library(lib);
    }
    strncpy(lib->books[lib->size].title, title, MAX_TITLE_LENGTH);
    lib->books[lib->size].pages = pages;
    lib->size++;
}

void view_books(Library *lib) {
    printf("Library contains %zu books:\n", lib->size);
    for (size_t i = 0; i < lib->size; i++) {
        printf("Book %zu: '%s', Pages: %d\n", i + 1, lib->books[i].title, lib->books[i].pages);
    }
}

void free_library(Library *lib) {
    free(lib->books);
    free(lib);
}

int main() {
    Library *myLibrary = create_library();
    int numBooks;
    char title[MAX_TITLE_LENGTH];
    int pages;

    printf("How many books would you like to add? ");
    scanf("%d", &numBooks);
    
    for (int i = 0; i < numBooks; i++) {
        printf("Enter title for book %d: ", i + 1);
        scanf(" %[^\n]", title); // Read string with spaces
        printf("Enter number of pages for book %d: ", i + 1);
        scanf("%d", &pages);
        add_book(myLibrary, title, pages);
    }

    view_books(myLibrary);
    
    // Free the library memory
    free_library(myLibrary);

    return 0;
}