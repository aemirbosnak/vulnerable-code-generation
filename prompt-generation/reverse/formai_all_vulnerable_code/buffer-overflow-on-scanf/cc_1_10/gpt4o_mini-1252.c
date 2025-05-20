//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

void displayMenu();
void addBook(Book books[], int *bookCount);
void viewBooks(Book books[], int bookCount);
void readBook(Book books[], int bookIndex);
void clearBuffer();

int main() {
    Book books[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer(); // clear input buffer

        switch (choice) {
            case 1:
                addBook(books, &bookCount);
                break;
            case 2:
                viewBooks(books, bookCount);
                break;
            case 3:
                if (bookCount > 0) {
                    int bookIndex;
                    printf("Enter book number to read (1 - %d): ", bookCount);
                    scanf("%d", &bookIndex);
                    clearBuffer();
                    if (bookIndex > 0 && bookIndex <= bookCount) {
                        readBook(books, bookIndex - 1);
                    } else {
                        printf("Invalid book number!\n");
                    }
                } else {
                    printf("No books available to read.\n");
                }
                break;
            case 4:
                printf("Exiting the program. Have a nice day!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n--- Retro C Ebook Reader ---\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Read Book\n");
    printf("4. Exit\n");
}

void addBook(Book books[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Maximum book limit reached. Cannot add more books.\n");
        return;
    }
    
    printf("Enter book title: ");
    fgets(books[*bookCount].title, MAX_TITLE_LENGTH, stdin);
    books[*bookCount].title[strcspn(books[*bookCount].title, "\n")] = 0; // Remove newline character

    printf("Enter book content (max %d characters): ", MAX_CONTENT_LENGTH);
    fgets(books[*bookCount].content, MAX_CONTENT_LENGTH, stdin);
    books[*bookCount].content[strcspn(books[*bookCount].content, "\n")] = 0; // Remove newline character

    (*bookCount)++;
    printf("Book added successfully!\n");
}

void viewBooks(Book books[], int bookCount) {
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nAvailable Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s\n", i + 1, books[i].title);
    }
}

void readBook(Book books[], int bookIndex) {
    printf("\nReading '%s'\n", books[bookIndex].title);
    printf("-------------------------\n");
    printf("%s\n", books[bookIndex].content);
    printf("-------------------------\n");
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}