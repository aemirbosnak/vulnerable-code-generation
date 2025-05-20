//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void addBook(Library *library) {
    if (library->count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter book title: ");
    getchar(); // Clear the new line character
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character

    printf("Enter author name: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    printf("Enter year of publication: ");
    scanf("%d", &newBook.year);

    library->books[library->count++] = newBook;
    printf("Book added successfully!\n");
}

void displayBooks(Library *library) {
    if (library->count == 0) {
        printf("No books in the library!\n");
        return;
    }

    printf("\nLibrary Catalog:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, library->books[i].title, library->books[i].author, library->books[i].year);
    }
}

void searchBook(Library *library) {
    char searchTerm[MAX_TITLE_LENGTH];
    printf("Enter the title or author to search: ");
    getchar(); // Clear the new line character
    fgets(searchTerm, MAX_TITLE_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline character

    int found = 0;
    
    printf("\nSearch Results:\n");
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->books[i].title, searchTerm) != NULL || strstr(library->books[i].author, searchTerm) != NULL) {
            printf("%d. %s by %s (%d)\n", i + 1, library->books[i].title, library->books[i].author, library->books[i].year);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No matching books found!\n");
    }
}

void displayMenu() {
    printf("\nWelcome to the Library Database!\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book\n");
    printf("4. Exit\n");
    printf("Please select an option: ");
}

int main() {
    Library library;
    library.count = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

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
                printf("Thank you for using the Library Database! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}