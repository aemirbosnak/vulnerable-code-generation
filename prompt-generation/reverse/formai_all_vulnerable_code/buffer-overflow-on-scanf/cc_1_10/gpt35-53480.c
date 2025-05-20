//FormAI DATASET v1.0 Category: Ebook reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_TITLE_LENGTH];
    int num_pages;
    int year_published;
} Book;

Book books[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books == MAX_BOOKS) {
        printf("Sorry, the library is full.\n");
        return;
    }

    Book book;

    printf("Enter the title of the book: ");
    fgets(book.title, MAX_TITLE_LENGTH, stdin);
    book.title[strcspn(book.title, "\n")] = 0;

    printf("Enter the name of the author: ");
    fgets(book.author, MAX_TITLE_LENGTH, stdin);
    book.author[strcspn(book.author, "\n")] = 0;

    printf("Enter the number of pages in the book: ");
    scanf("%d", &book.num_pages);
    getchar();

    printf("Enter the year the book was published: ");
    scanf("%d", &book.year_published);
    getchar();

    books[num_books] = book;
    num_books++;

    printf("Book added successfully!\n");
}

void list_books() {
    if (num_books == 0) {
        printf("The library is empty.\n");
        return;
    }

    printf("List of books:\n");

    for (int i = 0; i < num_books; i++) {
        printf("Book %d:\n", i+1);
        printf("   Title: %s\n", books[i].title);
        printf("   Author: %s\n", books[i].author);
        printf("   Number of pages: %d\n", books[i].num_pages);
        printf("   Year published: %d\n", books[i].year_published);
    }
}

void search_book() {
    if (num_books == 0) {
        printf("The library is empty.\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];

    printf("Enter the title of the book to search for: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0;

    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book found:\n");
            printf("   Title: %s\n", books[i].title);
            printf("   Author: %s\n", books[i].author);
            printf("   Number of pages: %d\n", books[i].num_pages);
            printf("   Year published: %d\n", books[i].year_published);
            return;
        }
    }

    printf("Book not found.\n");
}

int main() {
    int choice;

    do {
        printf("Please choose an option:\n");
        printf("  1. Add a book\n");
        printf("  2. List all books\n");
        printf("  3. Search for a book\n");
        printf("  4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}