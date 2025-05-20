//FormAI DATASET v1.0 Category: Ebook reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_PAGES 2000

typedef struct {
    char title[50];
    char author[30];
    int pages;
    char* content;
} Book;

typedef struct {
    int num_books;
    Book books[MAX_BOOKS];
} Library;

void load_books(Library* library) {
    // Code to load books from a database or file
    // In this example, we will just load two books manually

    library->num_books = 2;

    Book book1 = {"A Tale of Two Cities", "Charles Dickens", 448, "It was the best of times, it was the worst of times..."};
    library->books[0] = book1;

    Book book2 = {"Pride and Prejudice", "Jane Austen", 432, "It is a truth universally acknowledged, that a single man in possession of a good fortune, must be in want of a wife."};
    library->books[1] = book2;
}

void display_books(Library* library) {
    printf("Available Books:\n");

    for(int i = 0; i < library->num_books; i++) {
        printf("%d. %s by %s\n", i+1, library->books[i].title, library->books[i].author);
    }
}

void display_book_details(Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
}

void view_book(Library* library) {
    int book_index;

    // Prompt user to select a book
    printf("Enter the number of the book you want to read: ");
    scanf("%d", &book_index);

    // Validate user input
    if(book_index < 1 || book_index > library->num_books) {
        printf("Invalid book selection\n");
        return;
    }

    Book* current_book = &library->books[book_index - 1];

    // Display the book details
    display_book_details(current_book);

    // Display the book content
    printf("\n%s\n", current_book->content);
}

int main() {
    Library library;

    load_books(&library);

    display_books(&library);

    view_book(&library);

    return 0;
}