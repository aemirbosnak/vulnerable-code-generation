//FormAI DATASET v1.0 Category: Ebook reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

/*
 * eBook struct representing each page of the book
 */
typedef struct eBook {
    char* title;
    char* author;
    int pageNumber;
    char* content;
} eBook;

/*
 * Function to read eBook from file and return a pointer to the struct
 */
eBook* read_eBook(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Error: unable to open file at path %s\n", filepath);
        exit(EXIT_FAILURE);
    }

    eBook* book = (eBook*) malloc(sizeof(eBook));
    if (book == NULL) {
        printf("Error: unable to allocate memory for eBook\n");
        exit(EXIT_FAILURE);
    }

    // read book metadata
    fscanf(file, "%s %s %d\n", &(book->title), &(book->author), &(book->pageNumber));

    // allocate memory for book content
    book->content = (char*) malloc(book->pageNumber * sizeof(char));
    if (book->content == NULL) {
        printf("Error: unable to allocate memory for book content\n");
        exit(EXIT_FAILURE);
    }

    // read book content
    fread(book->content, sizeof(char), book->pageNumber, file);

    fclose(file);
    return book;
}

/*
 * Function to display contents of eBook
 */
void display_eBook(eBook* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of Pages: %d\n", book->pageNumber);
    printf("-------START OF BOOK-------\n");
    printf("%s", book->content);
    printf("\n-------END OF BOOK-------\n");
}

int main() {
    eBook* book = read_eBook("example_book.txt");
    display_eBook(book);
    free(book->content);
    free(book);

    return EXIT_SUCCESS;
}