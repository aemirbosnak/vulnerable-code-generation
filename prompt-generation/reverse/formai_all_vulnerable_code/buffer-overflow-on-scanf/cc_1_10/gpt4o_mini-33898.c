//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 50

typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int is_available;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    
    Book new_book;
    new_book.id = book_count + 1;
    printf("Enter book title: ");
    getchar(); // consume newline
    fgets(new_book.title, TITLE_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; // remove newline

    printf("Enter author name: ");
    fgets(new_book.author, AUTHOR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0; // remove newline
   
    new_book.is_available = 1; // Initially available
    library[book_count] = new_book;
    book_count++;
    printf("Added book: %s by %s (ID: %d)\n", new_book.title, new_book.author, new_book.id);
}

void listBooks() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\nLibrary Books:\n");
    for (int i = 0; i < book_count; i++) {
        printf("ID: %d | Title: %s | Author: %s | %s\n", library[i].id, 
               library[i].title, library[i].author, 
               library[i].is_available ? "Available" : "Checked Out");
    }
}

void checkOutBook() {
    int id;
    printf("Enter book ID to check out: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > book_count) {
        printf("Invalid ID! Please try again.\n");
        return;
    }

    if (library[id - 1].is_available) {
        library[id - 1].is_available = 0; // Mark as checked out
        printf("You've checked out: %s by %s\n", library[id - 1].title, library[id - 1].author);
    } else {
        printf("Sorry, this book is already checked out.\n");
    }
}

void returnBook() {
    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > book_count) {
        printf("Invalid ID! Please try again.\n");
        return;
    }

    if (!library[id - 1].is_available) {
        library[id - 1].is_available = 1; // Mark as available
        printf("You've returned: %s by %s\n", library[id - 1].title, library[id - 1].author);
    } else {
        printf("This book was not checked out.\n");
    }
}

void menu() {
    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Check Out Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                checkOutBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                printf("Exiting system. Have a nice day!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}