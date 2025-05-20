//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int id;
} Book;

Book bookDatabase[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Database is full! Cannot add more books.\n");
        return;
    }
    
    Book newBook;
    printf("Enter book title: ");
    scanf(" %[^\n]", newBook.title);
    printf("Enter author name: ");
    scanf(" %[^\n]", newBook.author);
    newBook.id = bookCount + 1; // Assigning an ID based on the current count

    bookDatabase[bookCount++] = newBook;
    printf("Book added with ID: %d\n", newBook.id);
}

void viewBooks() {
    if (bookCount == 0) {
        printf("No books in the database.\n");
        return;
    }
    
    printf("\nBooks in Database:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d, Title: \"%s\", Author: \"%s\"\n", bookDatabase[i].id, bookDatabase[i].title, bookDatabase[i].author);
    }
}

void deleteBook() {
    int id;
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > bookCount) {
        printf("Invalid ID! No book found with ID %d.\n", id);
        return;
    }

    for (int i = id - 1; i < bookCount - 1; i++) {
        bookDatabase[i] = bookDatabase[i + 1];
    }
    
    bookCount--;
    printf("Book with ID %d has been deleted.\n", id);
}

void searchBook() {
    char query[TITLE_LENGTH];
    printf("Enter title or author to search: ");
    scanf(" %[^\n]", query);
    
    int found = 0;
    printf("\nSearch Results:\n");
    for (int i = 0; i < bookCount; i++) {
        if (strstr(bookDatabase[i].title, query) != NULL || strstr(bookDatabase[i].author, query) != NULL) {
            printf("ID: %d, Title: \"%s\", Author: \"%s\"\n", bookDatabase[i].id, bookDatabase[i].title, bookDatabase[i].author);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No results found for \"%s\".\n", query);
    }
}

void displayMenu() {
    printf("\n*** Simple Book Database ***\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Delete Book\n");
    printf("4. Search Book\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                searchBook();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please select again.\n");
        }
    }
    
    return 0;
}