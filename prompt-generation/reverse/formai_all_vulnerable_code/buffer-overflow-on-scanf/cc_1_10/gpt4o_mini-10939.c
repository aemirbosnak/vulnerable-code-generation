//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[1000]; // Simple representation, can adjust size
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void addBook(Library *library);
void viewBooks(Library *library);
void readBook(Library *library);
void displayMenu(Library *library);
void freeLibrary(Library *library);
void clearInputBuffer();

int main() {
    Library library = { .count = 0 };
    displayMenu(&library);
    freeLibrary(&library); // Clean up any allocated memory
    return 0;
}

void displayMenu(Library *library) {
    int choice;
    do {
        printf("\n--- Ebook Reader Menu ---\n");
        printf("1. Add a Book\n");
        printf("2. View Books\n");
        printf("3. Read a Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the input buffer for the next input

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                viewBooks(library);
                break;
            case 3:
                readBook(library);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addBook(Library *library) {
    if (library->count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter the title of the book: ");
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline

    printf("Enter the content of the book: ");
    fgets(newBook.content, sizeof(newBook.content), stdin);
    newBook.content[strcspn(newBook.content, "\n")] = 0; // Remove newline

    library->books[library->count] = newBook;
    library->count++;
    printf("Book added successfully!\n");
}

void viewBooks(Library *library) {
    if (library->count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\nAvailable Books:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. %s\n", i + 1, library->books[i].title);
    }
}

void readBook(Library *library) {
    if (library->count == 0) {
        printf("No books available to read.\n");
        return;
    }

    int index;
    viewBooks(library);
    printf("Enter the book number you want to read: ");
    scanf("%d", &index);
    clearInputBuffer(); // Clear the input buffer for the next input

    if (index < 1 || index > library->count) {
        printf("Invalid book number.\n");
        return;
    }

    printf("\nReading Book: %s\n", library->books[index - 1].title);
    printf("Content:\n%s\n", library->books[index - 1].content);
}

void freeLibrary(Library *library) {
    // In this basic example, we don't have dynamically allocated memory
    // However, in more complex implementations, you would free memory here.
}