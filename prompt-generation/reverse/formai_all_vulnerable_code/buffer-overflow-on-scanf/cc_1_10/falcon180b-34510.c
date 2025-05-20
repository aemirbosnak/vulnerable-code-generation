//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOK_TITLE_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 100
#define MAX_BOOK_GENRE_LENGTH 50
#define MAX_BOOK_PAGES 1000
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_BOOK_TITLE_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    char genre[MAX_BOOK_GENRE_LENGTH];
    int pages;
} Book;

Book books[MAX_BOOKS];
int numBooks;

void addBook() {
    if (numBooks >= MAX_BOOKS) {
        printf("Error: Maximum number of books reached.\n");
        return;
    }

    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);
    printf("Enter book author: ");
    scanf("%s", books[numBooks].author);
    printf("Enter book genre: ");
    scanf("%s", books[numBooks].genre);
    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);

    numBooks++;
    printf("Book added successfully.\n");
}

void displayBooks() {
    printf("Book Title\tAuthor\tGenre\tPages\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%s\t%s\t%s\t%d\n", books[i].title, books[i].author, books[i].genre, books[i].pages);
    }
}

void searchBook() {
    char searchTitle[MAX_BOOK_TITLE_LENGTH];

    printf("Enter book title to search: ");
    scanf("%s", searchTitle);

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Genre: %s\n", books[i].genre);
            printf("Pages: %d\n", books[i].pages);
        }
    }
}

int main() {
    printf("Welcome to the Ebook Reader!\n");
    printf("Enter 1 to add a book.\n");
    printf("Enter 2 to display all books.\n");
    printf("Enter 3 to search for a book.\n");

    int choice;
    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\nPress any key to continue...");
        getchar();
    }

    return 0;
}