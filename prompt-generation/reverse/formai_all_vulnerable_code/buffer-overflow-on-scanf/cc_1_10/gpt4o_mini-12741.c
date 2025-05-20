//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 256
#define MAX_CONTENT_LENGTH 1024

typedef struct Book {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

void displayMenu() {
    printf("=== E-Book Reader ===\n");
    printf("1. Add a Book\n");
    printf("2. View a Book\n");
    printf("3. List All Books\n");
    printf("4. Search for a Book\n");
    printf("5. Exit\n");
    printf("======================\n");
}

void addBook(Book books[], int *currentBookCount) {
    if (*currentBookCount >= MAX_BOOKS) {
        printf("Book limit reached. Cannot add more books.\n");
        return;
    }

    printf("Enter the title of the book: ");
    fgets(books[*currentBookCount].title, MAX_TITLE_LENGTH, stdin);
    books[*currentBookCount].title[strcspn(books[*currentBookCount].title, "\n")] = 0;

    printf("Enter the content of the book: ");
    fgets(books[*currentBookCount].content, MAX_CONTENT_LENGTH, stdin);
    books[*currentBookCount].content[strcspn(books[*currentBookCount].content, "\n")] = 0;

    (*currentBookCount)++;
    printf("Book added successfully!\n\n");
}

void viewBook(Book books[], int index) {
    printf("Title: %s\n", books[index].title);
    printf("Content:\n%s\n", books[index].content);
}

void listAllBooks(Book books[], int currentBookCount) {
    printf("List of Books:\n");
    for (int i = 0; i < currentBookCount; i++) {
        printf("%d. %s\n", i + 1, books[i].title);
    }
    printf("\n");
}

void searchBook(Book books[], int currentBookCount) {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    for (int i = 0; i < currentBookCount; i++) {
        if (strstr(books[i].title, searchTitle)) {
            printf("Found Book:\n");
            viewBook(books, i);
            return;
        }
    }

    printf("No book found with the title '%s'.\n\n", searchTitle);
}

int main() {
    Book books[MAX_BOOKS];
    int currentBookCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                addBook(books, &currentBookCount);
                break;
            case 2:
                if (currentBookCount == 0) {
                    printf("No books available.\n");
                } else {
                    printf("Enter the number of the book to view: ");
                    int bookNumber;
                    scanf("%d", &bookNumber);
                    getchar(); // Consume newline
                    if (bookNumber > 0 && bookNumber <= currentBookCount) {
                        viewBook(books, bookNumber - 1);
                    } else {
                        printf("Invalid book number.\n");
                    }
                }
                break;
            case 3:
                listAllBooks(books, currentBookCount);
                break;
            case 4:
                searchBook(books, currentBookCount);
                break;
            case 5:
                printf("Exiting the E-Book Reader. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}