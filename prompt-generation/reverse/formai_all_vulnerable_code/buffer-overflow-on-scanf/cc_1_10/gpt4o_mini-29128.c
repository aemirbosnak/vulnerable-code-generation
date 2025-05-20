//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void addBook(Library *library);
void displayBooks(const Library *library);
void searchBook(const Library *library);
void clearInputBuffer();

int main() {
    Library library;
    library.count = 0;
    int choice;

    do {
        printf("\n****** Library Management System ******\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // clear the newline after the number

        switch (choice) {
            case 1:
                addBook(&library);
                break;
            case 2:
                displayBooks(&library);
                break;
            case 3:
                searchBook(&library);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

void addBook(Library *library) {
    if (library->count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter the title of the book: ");
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // remove trailing newline

    printf("Enter the author of the book: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // remove trailing newline

    printf("Enter the year of publication: ");
    scanf("%d", &newBook.year);
    clearInputBuffer(); // clear the newline after the number

    library->books[library->count] = newBook;
    library->count++;
    printf("Book added successfully!\n");
}

void displayBooks(const Library *library) {
    if (library->count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\nList of Books in the Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Book %d: %s by %s (%d)\n", 
                i + 1, 
                library->books[i].title, 
                library->books[i].author, 
                library->books[i].year);
    }
}

void searchBook(const Library *library) {
    if (library->count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove trailing newline

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->books[i].title, searchTitle) == 0) {
            printf("Book found: %s by %s (%d)\n", 
                    library->books[i].title, 
                    library->books[i].author, 
                    library->books[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found in the library.\n");
    }
}

void clearInputBuffer() {
    while (getchar() != '\n'); // remove the leftover characters from input buffer
}