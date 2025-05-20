//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 256
#define MAX_CONTENT_LENGTH 2048

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

void displayMenu() {
    printf("\n=== Ebook Reader ===\n");
    printf("1. Add Book\n");
    printf("2. View Book\n");
    printf("3. List All Books\n");
    printf("4. Exit\n");
    printf("====================\n");
}

void addBook(Book *library, int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    fgets(library[*bookCount].title, MAX_TITLE_LENGTH, stdin);
    library[*bookCount].title[strcspn(library[*bookCount].title, "\n")] = 0; // Remove newline

    printf("Enter book content (max %d characters): ", MAX_CONTENT_LENGTH - 1);
    fgets(library[*bookCount].content, MAX_CONTENT_LENGTH, stdin);
    library[*bookCount].content[strcspn(library[*bookCount].content, "\n")] = 0; // Remove newline

    (*bookCount)++;
    printf("Book added successfully!\n");
}

void viewBook(Book *library, int bookCount) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter book title to view: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("\n--- %s ---\n", library[i].title);
            printf("%s\n", library[i].content);
            printf("------------------\n");
            return;
        }
    }
    printf("Book not found!\n");
}

void listBooks(Book *library, int bookCount) {
    printf("\n=== List of Books ===\n");
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
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
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                viewBook(library, bookCount);
                break;
            case 3:
                listBooks(library, bookCount);
                break;
            case 4:
                printf("Exiting the Ebook Reader. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}