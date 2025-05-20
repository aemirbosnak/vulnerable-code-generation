//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100
#define CONTENT_LENGTH 1000

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    char content[CONTENT_LENGTH];
} Book;

void addBook(Book *library, int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book newBook;

    printf("Enter the title of the book: ");
    fgets(newBook.title, TITLE_LENGTH, stdin);
    strtok(newBook.title, "\n");  // Remove newline character

    printf("Enter the author of the book: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    strtok(newBook.author, "\n");  // Remove newline character

    printf("Enter the content of the book: \n");
    fgets(newBook.content, CONTENT_LENGTH, stdin);
    strtok(newBook.content, "\n");  // Remove newline character

    library[*bookCount] = newBook;
    (*bookCount)++;
    printf("Book added successfully!\n");
}

void displayBooks(Book *library, int bookCount) {
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nCurrent books in the library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Content: %s\n\n", library[i].content);
    }
}

void searchBook(Book *library, int bookCount) {
    char searchTerm[TITLE_LENGTH];

    printf("Enter the title of the book to search: ");
    fgets(searchTerm, TITLE_LENGTH, stdin);
    strtok(searchTerm, "\n");  // Remove newline character

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcasecmp(library[i].title, searchTerm) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Content: %s\n\n", library[i].content);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

void deleteBook(Book *library, int *bookCount) {
    char title[TITLE_LENGTH];

    printf("Enter the title of the book to delete: ");
    fgets(title, TITLE_LENGTH, stdin);
    strtok(title, "\n");  // Remove newline character

    for (int i = 0; i < *bookCount; i++) {
        if (strcasecmp(library[i].title, title) == 0) {
            for (int j = i; j < (*bookCount) - 1; j++) {
                library[j] = library[j + 1];
            }
            (*bookCount)--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void displayMenu() {
    printf("E-Book Reader Menu:\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // Consume newline character left behind by scanf

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                deleteBook(library, &bookCount);
                break;
            case 5:
                printf("Exiting the E-Book Reader. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}