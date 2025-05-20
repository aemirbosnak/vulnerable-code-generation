//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_BOOKS 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char author[MAX_NAME_LENGTH];
} Book;

typedef struct {
    Book *books;
    int count;
    int capacity;
} Library;

// Function prototypes
Library* createLibrary(int capacity);
void deleteLibrary(Library* library);
void addBook(Library* library, const char* name, const char* author);
void removeBook(Library* library, int id);
void listBooks(const Library* library);
Book* findBookById(const Library* library, int id);

int main() {
    Library *library = createLibrary(MAX_BOOKS);
    
    int choice;
    char name[MAX_NAME_LENGTH];
    char author[MAX_NAME_LENGTH];
    int id;

    do {
        printf("\nLibrary Menu:\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. List Books\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter book name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline

                printf("Enter author name: ");
                fgets(author, MAX_NAME_LENGTH, stdin);
                author[strcspn(author, "\n")] = '\0'; // Remove newline

                addBook(library, name, author);
                break;

            case 2:
                printf("Enter book ID to remove: ");
                scanf("%d", &id);
                removeBook(library, id);
                break;

            case 3:
                listBooks(library);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    deleteLibrary(library);
    return 0;
}

Library* createLibrary(int capacity) {
    Library *library = (Library*) malloc(sizeof(Library));
    if (!library) {
        fprintf(stderr, "Failed to allocate memory for library.\n");
        exit(EXIT_FAILURE);
    }

    library->books = (Book*) malloc(capacity * sizeof(Book));
    if (!library->books) {
        fprintf(stderr, "Failed to allocate memory for books.\n");
        free(library);
        exit(EXIT_FAILURE);
    }

    library->count = 0;
    library->capacity = capacity;
    return library;
}

void deleteLibrary(Library* library) {
    if (library) {
        free(library->books);
        free(library);
    }
}

void addBook(Library* library, const char* name, const char* author) {
    if (library->count < library->capacity) {
        Book *newBook = &library->books[library->count++];
        newBook->id = library->count; // Assigning ID as the count
        strncpy(newBook->name, name, MAX_NAME_LENGTH);
        strncpy(newBook->author, author, MAX_NAME_LENGTH);
        printf("Book added: ID=%d, Name=%s, Author=%s\n", newBook->id, newBook->name, newBook->author);
    } else {
        printf("Library is full! Cannot add more books.\n");
    }
}

void removeBook(Library* library, int id) {
    if (id <= 0 || id > library->count) {
        printf("Invalid book ID.\n");
        return;
    }

    for (int i = id - 1; i < library->count - 1; i++) {
        library->books[i] = library->books[i + 1];
    }
    library->count--;
    printf("Book with ID=%d has been removed.\n", id);
}

void listBooks(const Library* library) {
    if (library->count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("List of Books:\n");
    for (int i = 0; i < library->count; i++) {
        printf("ID: %d, Name: %s, Author: %s\n", library->books[i].id, library->books[i].name, library->books[i].author);
    }
}