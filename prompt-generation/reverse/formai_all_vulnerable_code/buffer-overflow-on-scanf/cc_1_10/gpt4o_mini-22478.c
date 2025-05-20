//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
    int pages;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

// Function declarations
void addBook(Library *library);
void displayBooks(const Library *library);
void searchBook(const Library *library);
void deleteBook(Library *library);
void saveLibrary(const Library *library, const char *filename);
void loadLibrary(Library *library, const char *filename);

int main() {
    Library library = { .count = 0 };
    int choice;

    // Load existing library from file
    loadLibrary(&library, "library.dat");

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Save & Exit\n");
        printf("Please select an option (1-5): ");
        scanf("%d", &choice);
        getchar();  // Clear the newline character from buffer

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
                deleteBook(&library);
                break;
            case 5:
                saveLibrary(&library, "library.dat");
                printf("Exiting and saving changes...\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addBook(Library *library) {
    if (library->count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book newBook;

    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;  // Remove newline

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;  // Remove newline

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);
    printf("Enter number of pages: ");
    scanf("%d", &newBook.pages);
    getchar();  // Clear the newline character from buffer

    library->books[library->count] = newBook;
    library->count++;
    printf("Book added successfully!\n");
}

void displayBooks(const Library *library) {
    if (library->count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", library->books[i].title);
        printf("Author: %s\n", library->books[i].author);
        printf("Year: %d\n", library->books[i].year);
        printf("Pages: %d\n\n", library->books[i].pages);
    }
}

void searchBook(const Library *library) {
    char title[TITLE_LENGTH];

    printf("Enter the title of the book to search for: ");
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0;  // Remove newline

    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", library->books[i].title);
            printf("Author: %s\n", library->books[i].author);
            printf("Year: %d\n", library->books[i].year);
            printf("Pages: %d\n", library->books[i].pages);
            return;
        }
    }
    printf("Book not found.\n");
}

void deleteBook(Library *library) {
    char title[TITLE_LENGTH];

    printf("Enter the title of the book to delete: ");
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0;  // Remove newline

    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            // Shift books to remove the deleted book
            for (int j = i; j < library->count - 1; j++) {
                library->books[j] = library->books[j + 1];
            }
            library->count--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void saveLibrary(const Library *library, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    fwrite(library, sizeof(Library), 1, file);
    fclose(file);
}

void loadLibrary(Library *library, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("No existing library file found. Starting new library.\n");
        library->count = 0;
        return;
    }
    fread(library, sizeof(Library), 1, file);
    fclose(file);
}