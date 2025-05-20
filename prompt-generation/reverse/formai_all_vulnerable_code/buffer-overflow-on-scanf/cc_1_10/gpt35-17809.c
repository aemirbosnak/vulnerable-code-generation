//FormAI DATASET v1.0 Category: Memory management ; Style: real-life
/*
* This program is an example of dynamic memory allocation in C.
* It simulates a library system where books can be added and removed from a library.
* The program uses a linked list data structure to keep track of books.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to hold book information
typedef struct book {
    char title[50];
    char author[50];
    int pages;
    struct book *next;
} Book;

// A function to add a book to the library
void add_book(Book **library) {
    char title[50], author[50];
    int pages;

    printf("Enter book title: ");
    scanf("%s", title);

    printf("Enter book author: ");
    scanf("%s", author);

    printf("Enter book pages: ");
    scanf("%d", &pages);

    Book *new_book = (Book*) malloc(sizeof(Book));
    strcpy(new_book->title, title);
    strcpy(new_book->author, author);
    new_book->pages = pages;
    new_book->next = *library;

    *library = new_book;

    printf("%s by %s with %d pages added to the library.\n", title, author, pages);
}

// A function to remove a book from the library
void remove_book(Book **library) {
    char title[50];
    Book *current_book = *library;
    Book *previous_book = NULL;

    printf("Enter the title of the book to be removed: ");
    scanf("%s", title);

    while (current_book != NULL) {
        if (strcmp(current_book->title, title) == 0) {
            if (previous_book == NULL) {
                *library = current_book->next;
            } else {
                previous_book->next = current_book->next;
            }
            printf("%s by %s with %d pages removed from the library.\n", current_book->title, current_book->author, current_book->pages);
            free(current_book);
            return;
        }
        previous_book = current_book;
        current_book = current_book->next;
    }

    printf("Book %s not found in the library.\n", title);
}

// A function to print all the books in the library
void print_library(Book *library) {
    printf("Books in library:\n");

    while (library != NULL) {
        printf("%s by %s with %d pages\n", library->title, library->author, library->pages);
        library = library->next;
    }
}

// The main function
int main() {
    Book *library = NULL;
    int choice = 0;

    do {
        printf("Menu\n");
        printf("1. Add book\n");
        printf("2. Remove book\n");
        printf("3. Print library\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book(&library);
                break;
            case 2:
                remove_book(&library);
                break;
            case 3:
                print_library(library);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\n");

    } while (choice != 4);

    return 0;
}