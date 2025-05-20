//FormAI DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 25
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

// Creates a new book
Book createBook(char* title, char* author, int year) {
    Book book;

    strncpy(book.title, title, MAX_TITLE_LENGTH);
    strncpy(book.author, author, MAX_AUTHOR_LENGTH);
    book.year = year;

    return book;
}

// Displays information about a book
void displayBook(Book book) {
    printf("\nTitle: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year: %d\n", book.year);
}

// Displays all books in the library
void displayLibrary(Book library[], int num_books) {
    printf("\n---LIBRARY---\n");
    for (int i=0; i<num_books; i++) {
        displayBook(library[i]);
    }
}

// Searches for a book in the library by title
void searchByTitle(Book library[], int num_books) {
    char search_title[MAX_TITLE_LENGTH];
    printf("\nEnter the title of the book you want to search for: ");
    fgets(search_title, MAX_TITLE_LENGTH, stdin);
    search_title[strcspn(search_title, "\n")] = '\0';

    int found = 0;
    for (int i=0; i<num_books; i++) {
        if (strcmp(library[i].title, search_title) == 0) {
            displayBook(library[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("\nBook not found.\n");
    }
}

int main() {
    Book library[MAX_BOOKS];
    int num_books = 0;
    int choice;

    while (1) {
        printf("\n1. Add a book to the library.\n");
        printf("2. Display all books in the library.\n");
        printf("3. Search for a book by title.\n");
        printf("4. Exit.\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1: { // add a book
                if (num_books >= MAX_BOOKS) {
                    printf("\nLibrary is full.\n");
                    break;
                }

                char title[MAX_TITLE_LENGTH], author[MAX_AUTHOR_LENGTH];
                int year;

                printf("\nEnter the title of the book: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0';

                printf("Enter the author of the book: ");
                fgets(author, MAX_AUTHOR_LENGTH, stdin);
                author[strcspn(author, "\n")] = '\0';

                printf("Enter the year the book was published: ");
                scanf("%d", &year);
                fflush(stdin);

                Book new_book = createBook(title, author, year);
                library[num_books++] = new_book;

                printf("\nBook added to the library.\n");
                break;
            }
            case 2: // display all books
                displayLibrary(library, num_books);
                break;
            case 3: // search for a book by title
                searchByTitle(library, num_books);
                break;
            case 4: // exit
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}