//FormAI DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

void displayMenu() {
    printf("\nEbook Reader\n");
    printf("------------\n");
    printf("1. Add book\n");
    printf("2. View all books\n");
    printf("3. Search book\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addBook(Book *books, int *numOfBooks) {
    if (*numOfBooks >= MAX_BOOKS) {
        printf("\nCannot add more books. Maximum limit reached.\n");
        return;
    }

    printf("\nEnter book details:\n");

    printf("Title: ");
    fgets(books[*numOfBooks].title, MAX_TITLE_LENGTH, stdin);
    books[*numOfBooks].title[strcspn(books[*numOfBooks].title, "\n")] = '\0';  // removes trailing '\n' from input

    printf("Author: ");
    fgets(books[*numOfBooks].author, MAX_AUTHOR_LENGTH, stdin);
    books[*numOfBooks].author[strcspn(books[*numOfBooks].author, "\n")] = '\0';

    printf("Year: ");
    scanf("%d", &books[*numOfBooks].year);
    getchar();  // removes trailing newline character from input buffer

    (*numOfBooks)++;  // incrementing numOfBooks after successfully adding a book

    printf("\nBook added successfully.\n");
}

void viewAllBooks(Book *books, int numOfBooks) {
    if (numOfBooks == 0) {
        printf("\nNo books found.\n");
        return;
    }

    printf("\nAll books:\n");

    for (int i = 0; i < numOfBooks; i++) {
        printf("\nBook %d\n", i+1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Year: %d\n", books[i].year);
    }
}

void searchBook(Book *books, int numOfBooks) {
    if (numOfBooks == 0) {
        printf("\nNo books found.\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("\nEnter title of the book to search: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0';

    for (int i = 0; i < numOfBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("\nBook found:\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n", books[i].year);
            return;
        }
    }

    printf("\nBook not found.\n");
}

int main() {
    Book books[MAX_BOOKS];
    int numOfBooks = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // removes trailing newline character from input buffer

        switch(choice) {
            case 1:
                addBook(books, &numOfBooks);
                break;
            case 2:
                viewAllBooks(books, numOfBooks);
                break;
            case 3:
                searchBook(books, numOfBooks);
                break;
            case 4:
                printf("\nExiting the program.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}