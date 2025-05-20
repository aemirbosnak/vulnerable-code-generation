//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define MAX_BOOK_NAME 50
#define MAX_AUTHOR_NAME 30
#define MAX_PAGES 1000

// Structure to store book information
typedef struct {
    char name[MAX_BOOK_NAME];
    char author[MAX_AUTHOR_NAME];
    int pages;
} book_info_t;

// Function to read a book from a file
book_info_t read_book(char *file_name) {
    book_info_t book;
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        return book;
    }
    fscanf(file, "%s %s %d", book.name, book.author, &book.pages);
    fclose(file);
    return book;
}

// Function to display book information
void display_book(book_info_t book) {
    printf("Book Name: %s\n", book.name);
    printf("Author Name: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
}

// Function to jump to a specific page
void jump_to_page(book_info_t book, int page) {
    if (page < 1 || page > book.pages) {
        printf("Invalid page number\n");
        return;
    }
    printf("Jumping to page %d...\n", page);
}

// Function to display the next page
void display_next_page(book_info_t book) {
    if (book.pages <= 1) {
        printf("No more pages\n");
        return;
    }
    printf("Page %d\n", book.pages - 1);
    book.pages--;
}

// Function to display the previous page
void display_prev_page(book_info_t book) {
    if (book.pages <= 1) {
        printf("No more pages\n");
        return;
    }
    printf("Page %d\n", book.pages + 1);
    book.pages++;
}

int main() {
    book_info_t book;
    char file_name[50];

    // Ask user for book file name
    printf("Enter the file name of the book: ");
    scanf("%s", file_name);

    // Read the book from the file
    book = read_book(file_name);

    // Display the book information
    display_book(book);

    // Ask user for page number
    int page = 1;
    printf("Enter the page number to jump to (1-%d): ", book.pages);
    scanf("%d", &page);

    // Jump to the specified page
    jump_to_page(book, page);

    // Display the next page
    while (book.pages > 1) {
        display_next_page(book);
    }

    return 0;
}