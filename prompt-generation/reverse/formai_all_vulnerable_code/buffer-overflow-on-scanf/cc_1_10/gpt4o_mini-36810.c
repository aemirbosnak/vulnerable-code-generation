//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook();
void displayBooks();
void deleteBook();
void clearScreen();

int main() {
    int choice;

    while (1) {
        clearScreen();
        printf("*************************************\n");
        printf("       Welcome to Book Library       \n");
        printf("*************************************\n");
        printf("1. Add a Book\n");
        printf("2. Display Books\n");
        printf("3. Delete a Book\n");
        printf("4. Exit\n");
        printf("*************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                printf("Thank you for using the Book Library! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("Press Enter to continue...\n");
        getchar(); // Wait for user to press Enter
    }
    return 0;
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    fgets(library[bookCount].title, TITLE_LENGTH, stdin);
    library[bookCount].title[strcspn(library[bookCount].title, "\n")] = 0; // Remove newline

    printf("Enter author name: ");
    fgets(library[bookCount].author, AUTHOR_LENGTH, stdin);
    library[bookCount].author[strcspn(library[bookCount].author, "\n")] = 0; // Remove newline

    printf("Enter publication year: ");
    scanf("%d", &library[bookCount].year);
    getchar(); // Consume newline character

    bookCount++;
    printf("Book added successfully!\n");
}

void displayBooks() {
    clearScreen();
    printf("*************************************\n");
    printf("           List of Books            \n");
    printf("*************************************\n");

    if (bookCount == 0) {
        printf("No books in the library!\n");
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        printf("Book %d:\n", i + 1);
        printf("  Title: %s\n", library[i].title);
        printf("  Author: %s\n", library[i].author);
        printf("  Year: %d\n", library[i].year);
        printf("-------------------------------------\n");
    }
}

void deleteBook() {
    int idx;
    displayBooks();

    if (bookCount == 0) {
        return;
    }

    printf("Enter the book number to delete: ");
    scanf("%d", &idx);
    getchar(); // Consume newline character

    if (idx < 1 || idx > bookCount) {
        printf("Invalid book number! Please try again.\n");
        return;
    }

    // Shift books to the left to delete the selected book
    for (int i = idx - 1; i < bookCount - 1; i++) {
        library[i] = library[i + 1];
    }
    bookCount--;
    printf("Book deleted successfully!\n");
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}