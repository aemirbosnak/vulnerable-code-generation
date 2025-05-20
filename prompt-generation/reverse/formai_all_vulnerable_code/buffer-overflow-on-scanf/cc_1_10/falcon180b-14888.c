//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_SIZE 100
#define MAX_BOOK_AUTHOR_SIZE 50
#define MAX_BOOK_GENRE_SIZE 20

typedef struct {
    char book_name[MAX_BOOK_NAME_SIZE];
    char book_author[MAX_BOOK_AUTHOR_SIZE];
    char book_genre[MAX_BOOK_GENRE_SIZE];
    int book_pages;
    int book_published_year;
} Book;

Book books[MAX_BOOKS];

int add_book() {
    int i = 0;
    while (i < MAX_BOOKS && books[i].book_name[0]!= '\0') {
        i++;
    }
    if (i == MAX_BOOKS) {
        printf("Error: Maximum number of books reached.\n");
        return 1;
    }
    printf("Enter book name: ");
    scanf("%s", books[i].book_name);
    printf("Enter book author: ");
    scanf("%s", books[i].book_author);
    printf("Enter book genre: ");
    scanf("%s", books[i].book_genre);
    printf("Enter number of pages: ");
    scanf("%d", &books[i].book_pages);
    printf("Enter year published: ");
    scanf("%d", &books[i].book_published_year);
    books[i].book_name[0] = '\0';
    printf("Book added successfully.\n");
    return 0;
}

int display_all_books() {
    int i = 0;
    while (i < MAX_BOOKS) {
        if (books[i].book_name[0]!= '\0') {
            printf("Book name: %s\n", books[i].book_name);
            printf("Author: %s\n", books[i].book_author);
            printf("Genre: %s\n", books[i].book_genre);
            printf("Pages: %d\n", books[i].book_pages);
            printf("Year published: %d\n", books[i].book_published_year);
            printf("\n");
        }
        i++;
    }
    return 0;
}

int main() {
    int choice;
    do {
        printf("1. Add book\n");
        printf("2. Display all books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_book();
            break;
        case 2:
            display_all_books();
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);
    return 0;
}