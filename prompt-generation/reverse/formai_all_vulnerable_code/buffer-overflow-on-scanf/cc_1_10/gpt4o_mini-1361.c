//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full, cannot add more books!\n");
        return;
    }
    
    Book newBook;
    newBook.id = bookCount + 1;  // Simple incremental id assignment

    printf("Enter the title of the book: ");
    getchar(); // to consume the newline character left by previous input
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character

    printf("Enter the author of the book: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    library[bookCount] = newBook;
    bookCount++;

    printf("Book added successfully! ID: %d\n", newBook.id);
}

void viewBooks() {
    if (bookCount == 0) {
        printf("No books found in the library.\n");
        return;
    }
    
    printf("\n--- List of Books in the Library ---\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
    }
    printf("--------------------------------------\n");
}

void searchBook() {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // to consume the newline character left by previous input
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, searchTitle) != NULL) {
            printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found with the title containing: %s\n", searchTitle);
    }
    printf("-----------------------\n");
}

void displayMenu() {
    printf("\n--- Welcome to the Book Library Database ---\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Search Book\n");
    printf("4. Exit\n");
    printf("---------------------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("Exiting the program. Happy reading!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}