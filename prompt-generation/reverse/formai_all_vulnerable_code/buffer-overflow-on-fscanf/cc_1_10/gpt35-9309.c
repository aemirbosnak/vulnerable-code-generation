//FormAI DATASET v1.0 Category: Ebook reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of book title and author name
#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 20

// Define struct for book
typedef struct book {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pageCount;
    char* content;
} Book;

// Define function to read a book from file
Book read_book(char* filename) {
    FILE* fp = fopen(filename, "r");

    // Get book title and author
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    fscanf(fp, "%s %s", title, author);

    // Get page count
    int pageCount;
    fscanf(fp, "%d", &pageCount);

    // Allocate memory for book content
    char* content = (char*)malloc(sizeof(char) * pageCount);

    // Read book content from file
    for (int i = 0; i < pageCount; i++) {
        fscanf(fp, " %c", &content[i]);
    }

    // Create book object and return it
    Book book = {0};
    strcpy(book.title, title);
    strcpy(book.author, author);
    book.pageCount = pageCount;
    book.content = content;
    
    fclose(fp);
    return book;
}

// Define function to display book information
void display_book(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Page count: %d\n", book.pageCount);
}

// Define function to read a page from the book
void read_page(Book book, int page) {
    if (page >= 0 && page < book.pageCount) {
        printf("%c\n", book.content[page]);
    } else {
        printf("Invalid page number.\n");
    }
}

// Main program
int main() {
    printf("Welcome to the Surrealist Ebook Reader!\n\n");

    // Read a book from file
    Book book = read_book("surrealist_book.txt");

    // Display book information
    display_book(book);

    // Read pages from the book
    printf("Reading page 0:\n");
    read_page(book, 0);

    printf("Reading page 5:\n");
    read_page(book, 5);

    printf("Reading page 20:\n");
    read_page(book, 20);

    printf("Reading page 100:\n");
    read_page(book, 100);

    // Free memory
    free(book.content);

    printf("\nThank you for using the Surrealist Ebook Reader!\n");

    return 0;
}