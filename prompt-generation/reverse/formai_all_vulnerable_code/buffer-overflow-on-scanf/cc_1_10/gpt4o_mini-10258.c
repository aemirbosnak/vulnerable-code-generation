//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_MAX 50
#define AUTHOR_MAX 50

typedef struct {
    int id;
    char title[TITLE_MAX];
    char author[AUTHOR_MAX];
} Book;

void addBook(Book *library, int *count);
void searchBook(Book *library, int count);
void deleteBook(Book *library, int *count);
void displayBooks(Book *library, int count);
void clearBuffer(void);

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nLibrary Database Menu:\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Delete Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); 

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                searchBook(library, count);
                break;
            case 3:
                deleteBook(library, &count);
                break;
            case 4:
                displayBooks(library, count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    
    Book newBook;
    newBook.id = *count + 1; // Auto-increment ID
    printf("Enter title: ");
    fgets(newBook.title, TITLE_MAX, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline
    printf("Enter author: ");
    fgets(newBook.author, AUTHOR_MAX, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline

    library[*count] = newBook;
    (*count)++;
    printf("Book added successfully! ID: %d\n", newBook.id);
}

void searchBook(Book *library, int count) {
    int id;
    printf("Enter book ID to search: ");
    scanf("%d", &id);
    clearBuffer();

    if (id <= 0 || id > count) {
        printf("Book not found!\n");
        return;
    }

    Book foundBook = library[id - 1];
    printf("Book found:\n");
    printf("ID: %d\nTitle: %s\nAuthor: %s\n", foundBook.id, foundBook.title, foundBook.author);
}

void deleteBook(Book *library, int *count) {
    int id;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);
    clearBuffer();

    if (id <= 0 || id > *count) {
        printf("Book not found!\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        library[i] = library[i + 1]; // Shift left
    }
    (*count)--;
    printf("Book deleted successfully!\n");
}

void displayBooks(Book *library, int count) {
    if (count == 0) {
        printf("No books in the library!\n");
        return;
    }

    printf("\nList of Books in Library:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
    }
}

void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}