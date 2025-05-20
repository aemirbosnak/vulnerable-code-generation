//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50

typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

// Function prototypes
void addBook(Library *library);
void searchBook(const Library *library);
void displayBooks(const Library *library);
void removeBook(Library *library);

int main() {
    Library library = { .count = 0 };
    int choice;

    do {
        printf("\nLibrary Database Management System\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Display All Books\n");
        printf("4. Remove Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addBook(&library);
                break;
            case 2:
                searchBook(&library);
                break;
            case 3:
                displayBooks(&library);
                break;
            case 4:
                removeBook(&library);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addBook(Library *library) {
    if (library->count >= MAX_BOOKS) {
        printf("Library is full! Unable to add more books.\n");
        return;
    }

    Book newBook;
    newBook.id = library->count + 1;

    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove trailing newline

    printf("Enter book author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;

    printf("Enter year of publication: ");
    scanf("%d", &newBook.year);
    getchar(); // Consume newline character

    library->books[library->count] = newBook;
    library->count++;

    printf("Book added successfully: %s by %s, %d (ID: %d)\n", 
           newBook.title, newBook.author, newBook.year, newBook.id);
}

void searchBook(const Library *library) {
    char searchTitle[TITLE_LENGTH];

    printf("Enter book title to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove trailing newline

    printf("Search results:\n");
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->books[i].title, searchTitle) != NULL) {
            printf("ID: %d, Title: %s, Author: %s, Year: %d\n",
                   library->books[i].id, library->books[i].title,
                   library->books[i].author, library->books[i].year);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No books found with the title '%s'.\n", searchTitle);
    }
}

void displayBooks(const Library *library) {
    if (library->count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("List of books in the library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("ID: %d, Title: %s, Author: %s, Year: %d\n",
               library->books[i].id, library->books[i].title,
               library->books[i].author, library->books[i].year);
    }
}

void removeBook(Library *library) {
    int id;

    printf("Enter the ID of the book to remove: ");
    scanf("%d", &id);
    getchar(); // Consume newline character

    if (id < 1 || id > library->count) {
        printf("Invalid ID! Please enter a valid book ID.\n");
        return;
    }

    for (int i = id - 1; i < library->count - 1; i++) {
        library->books[i] = library->books[i + 1];
    }
    library->count--;

    printf("Book with ID %d removed successfully!\n", id);
}