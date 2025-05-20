//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100

typedef struct {
    int id;
    char title[TITLE_LENGTH];
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void initializeLibrary(Library *library) {
    library->count = 0;
}

void addBook(Library *library, const char *title) {
    if (library->count < MAX_BOOKS) {
        library->books[library->count].id = library->count + 1;
        strncpy(library->books[library->count].title, title, TITLE_LENGTH);
        library->count++;
        printf("Book '%s' added to the library with ID %d.\n", title, library->books[library->count - 1].id);
    } else {
        printf("Library is full! Cannot add more books.\n");
    }
}

void displayBooks(const Library *library) {
    if (library->count == 0) {
        printf("No books in the library yet. Peaceful silence...\n");
        return;
    }
    printf("\nCurrent Books in the Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("ID: %d, Title: %s\n", library->books[i].id, library->books[i].title);
    }
}

void searchBook(const Library *library, const char *title) {
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            printf("Found Book: ID: %d, Title: %s\n", library->books[i].id, library->books[i].title);
            return;
        }
    }
    printf("Book titled '%s' not found in the library. A tranquil moment of waiting...\n", title);
}

int main() {
    Library library;
    char title[TITLE_LENGTH];
    int choice;
    
    initializeLibrary(&library);
    
    while (1) {
        printf("\n---- Welcome to Peaceful Library Indexing System ----\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove trailing newline
                addBook(&library, title);
                break;
            case 2:
                displayBooks(&library);
                break;
            case 3:
                printf("Enter book title to search: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove trailing newline
                searchBook(&library, title);
                break;
            case 4:
                printf("Exiting peacefully...\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    }
    return 0;
}