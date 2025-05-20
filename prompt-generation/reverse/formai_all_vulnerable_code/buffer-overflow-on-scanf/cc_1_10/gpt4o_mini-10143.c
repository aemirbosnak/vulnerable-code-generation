//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
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
    printf("Enter the book title: ");
    getchar(); // clear the newline character
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // remove newline character

    printf("Enter the author's name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // remove newline character

    library[bookCount++] = newBook;
    printf("Book successfully added!\n");
}

void viewBooks() {
    if (bookCount == 0) {
        printf("The library is currently empty.\n");
        return;
    }
    
    printf("\nLibrary Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. \"%s\" by %s\n", i + 1, library[i].title, library[i].author);
    }
}

void searchBook() {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the book you want to search for: ");
    getchar(); // clear the newline character
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline character

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book found: \"%s\" by %s\n", library[i].title, library[i].author);
            return;
        }
    }
    printf("Sorry, no book found with the title \"%s\".\n", searchTitle);
}

void deleteBook() {
    char deleteTitle[TITLE_LENGTH];
    printf("Enter the title of the book you want to delete: ");
    getchar(); // clear the newline character
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // remove newline character

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, deleteTitle) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            printf("Book \"%s\" has been deleted from the library!\n", deleteTitle);
            return;
        }
    }
    printf("No book found with the title \"%s\" to delete.\n", deleteTitle);
}

void displayMenu() {
    printf("\nLibrary Database System\n");
    printf("1. Add a Book\n");
    printf("2. View All Books\n");
    printf("3. Search a Book\n");
    printf("4. Delete a Book\n");
    printf("5. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    int choice;

    do {
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
                deleteBook();
                break;
            case 5:
                printf("Exiting the program. Happy reading!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 5);

    return 0;
}