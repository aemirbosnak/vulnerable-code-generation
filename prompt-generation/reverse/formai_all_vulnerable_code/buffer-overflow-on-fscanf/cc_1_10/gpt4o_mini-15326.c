//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void initializeLibrary(Library *lib) {
    lib->count = 0;
}

void addBook(Library *lib) {
    if (lib->count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    
    Book newBook;
    printf("Enter book title: ");
    getchar(); // Clear the buffer
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline

    printf("Enter author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline
    
    printf("Enter publication year: ");
    scanf("%d", &newBook.year);
    
    lib->books[lib->count] = newBook;
    lib->count++;
    
    printf("Book added successfully!\n");
}

void listBooks(Library *lib) {
    if (lib->count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("Books in library:\n");
    for (int i = 0; i < lib->count; i++) {
        printf("Title: %s, Author: %s, Year: %d\n", 
                lib->books[i].title,
                lib->books[i].author,
                lib->books[i].year);
    }
}

void searchBook(Library *lib) {
    if (lib->count == 0) {
        printf("No books in the library to search.\n");
        return;
    }

    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // Clear the buffer
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    for (int i = 0; i < lib->count; i++) {
        if (strcasecmp(lib->books[i].title, searchTitle) == 0) {
            printf("Book found: Title: %s, Author: %s, Year: %d\n", 
                   lib->books[i].title, 
                   lib->books[i].author, 
                   lib->books[i].year);
            return;
        }
    }
    printf("Book not found in the library.\n");
}

void deleteBook(Library *lib) {
    if (lib->count == 0) {
        printf("No books in the library to delete.\n");
        return;
    }

    char deleteTitle[TITLE_LENGTH];
    printf("Enter the title of the book to delete: ");
    getchar(); // Clear the buffer
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline

    for (int i = 0; i < lib->count; i++) {
        if (strcasecmp(lib->books[i].title, deleteTitle) == 0) {
            for (int j = i; j < lib->count - 1; j++) {
                lib->books[j] = lib->books[j + 1];
            }
            lib->count--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found in the library.\n");
}

void saveLibrary(Library *lib) {
    FILE *file = fopen("library.txt", "w");
    if (!file) {
        printf("Error saving library to file.\n");
        return;
    }

    for (int i = 0; i < lib->count; i++) {
        fprintf(file, "%s\n%s\n%d\n", 
                lib->books[i].title, 
                lib->books[i].author, 
                lib->books[i].year);
    }
    fclose(file);
    printf("Library saved to library.txt successfully!\n");
}

void loadLibrary(Library *lib) {
    FILE *file = fopen("library.txt", "r");
    if (!file) {
        printf("No saved library found.\n");
        return;
    }

    while (fscanf(file, "%[^\n]\n%[^\n]\n%d\n", 
                  lib->books[lib->count].title, 
                  lib->books[lib->count].author, 
                  &lib->books[lib->count].year) == 3) {
        lib->count++;
    }
    fclose(file);
    printf("Library loaded successfully!\n");
}

int main() {
    Library myLibrary;
    initializeLibrary(&myLibrary);
    loadLibrary(&myLibrary);
    
    int choice;
    do {
        printf("\nLibrary Management System:\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Save Library\n");
        printf("6. Load Library\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addBook(&myLibrary); break;
            case 2: listBooks(&myLibrary); break;
            case 3: searchBook(&myLibrary); break;
            case 4: deleteBook(&myLibrary); break;
            case 5: saveLibrary(&myLibrary); break;
            case 6: loadLibrary(&myLibrary); break;
            case 0: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice! Please choose again.\n\n");
        }
    } while (choice != 0);
    
    return 0;
}