//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

void displayMenu() {
    printf("=== E-Book Reader ===\n");
    printf("1. Add a new book\n");
    printf("2. View all books\n");
    printf("3. Read a book\n");
    printf("4. Search for a book\n");
    printf("5. Exit\n");
    printf("=====================\n");
}

void addBook(Book *library, int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter the title of the book: ");
    fgets(library[*bookCount].title, MAX_TITLE_LENGTH, stdin);
    library[*bookCount].title[strcspn(library[*bookCount].title, "\n")] = 0; // Remove newline

    printf("Enter the content of the book: ");
    fgets(library[*bookCount].content, MAX_CONTENT_LENGTH, stdin);
    library[*bookCount].content[strcspn(library[*bookCount].content, "\n")] = 0; // Remove newline

    (*bookCount)++;
    printf("Book '%s' added successfully!\n", library[*bookCount - 1].title);
}

void viewBooks(Book *library, int bookCount) {
    if (bookCount == 0) {
        printf("No books in the library yet.\n");
        return;
    }
    printf("Books in the library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
    }
}

void readBook(Book *library, int bookCount) {
    if (bookCount == 0) {
        printf("No books available to read.\n");
        return;
    }

    int choice;
    printf("Select a book to read (1-%d): ", bookCount);
    scanf("%d", &choice);
    getchar(); // Clear newline from input buffer

    if (choice < 1 || choice > bookCount) {
        printf("Invalid selection!\n");
        return;
    }

    printf("Reading '%s':\n", library[choice - 1].title);
    printf("%s\n", library[choice - 1].content);
}

void searchBook(Book *library, int bookCount) {
    if (bookCount == 0) {
        printf("No books available for search.\n");
        return;
    }

    char searchTerm[MAX_TITLE_LENGTH];
    printf("Enter search term: ");
    fgets(searchTerm, MAX_TITLE_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline

    printf("Search results for '%s':\n", searchTerm);
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, searchTerm) != NULL) {
            printf("Found: %s\n", library[i].title);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found for the search term.\n");
    }
}

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                viewBooks(library, bookCount);
                break;
            case 3:
                readBook(library, bookCount);
                break;
            case 4:
                searchBook(library, bookCount);
                break;
            case 5:
                printf("Exiting the e-book reader. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}