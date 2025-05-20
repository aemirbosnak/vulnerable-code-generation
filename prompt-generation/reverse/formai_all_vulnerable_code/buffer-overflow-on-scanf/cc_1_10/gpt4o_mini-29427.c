//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHORS_LENGTH 100
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char authors[MAX_AUTHORS_LENGTH];
    char filename[MAX_TITLE_LENGTH];
} Book;

void addBook(Book *library, int *count);
void readBook(const char *filename);
void listBooks(Book *library, int count);
void clearInputBuffer();

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== E-Book Reader ===\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Read Book\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear buffer after input

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                listBooks(library, count);
                break;
            case 3: {
                char filename[MAX_TITLE_LENGTH];
                printf("Enter the filename of the book to read: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                readBook(filename);
                break;
            }
            case 4:
                printf("Exiting the E-Book Reader. Happy Reading!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return;
    }
    
    Book newBook;
    printf("Enter the title of the book: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline

    printf("Enter the authors of the book: ");
    fgets(newBook.authors, sizeof(newBook.authors), stdin);
    newBook.authors[strcspn(newBook.authors, "\n")] = 0; // Remove newline

    printf("Enter the filename where the book content is stored: ");
    fgets(newBook.filename, sizeof(newBook.filename), stdin);
    newBook.filename[strcspn(newBook.filename, "\n")] = 0; // Remove newline

    library[*count] = newBook;
    (*count)++;
    printf("Book '%s' by %s added to the library!\n", newBook.title, newBook.authors);
}

void listBooks(Book *library, int count) {
    if (count == 0) {
        printf("No books in the library yet.\n");
        return;
    }

    printf("\n=== List of Books ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. '%s' by %s\n", i + 1, library[i].title, library[i].authors);
    }
}

void readBook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return;
    }

    printf("\n=== Reading Book: %s ===\n", filename);
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    printf("\nEnd of the book.\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear the newline from the buffer
}