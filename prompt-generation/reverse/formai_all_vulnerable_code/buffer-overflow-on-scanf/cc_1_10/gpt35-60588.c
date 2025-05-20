//FormAI DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LEN 20
#define MAX_AUTHOR_LEN 20

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    double price;
    int publication_year;
} Book;

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Price: $%.2f\n", book->price);
    printf("Publication Year: %d\n", book->publication_year);
}

void ebook_reader(Book *books, int num_books) {
    int i, choice;

    printf("Welcome to the Ebook Reader.\n");
    printf("Please choose a book to read:\n");

    for (i = 0; i < num_books; i++) {
        printf("%d. %s by %s\n", i + 1, books[i].title, books[i].author);
    }

    printf("Enter the number of your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_books) {
        printf("Invalid choice. Aborting...\n");
        exit(1);
    }

    printf("You have chosen %s by %s.\n", books[choice - 1].title, books[choice - 1].author);
}

int main() {
    Book ebooks[MAX_BOOKS];
    int num_ebooks = 0;

    strcpy(ebooks[num_ebooks].title, "The C Programming Language");
    strcpy(ebooks[num_ebooks].author, "Brian Kernighan and Dennis Ritchie");
    ebooks[num_ebooks].price = 19.99;
    ebooks[num_ebooks].publication_year = 1988;
    num_ebooks++;

    strcpy(ebooks[num_ebooks].title, "The Art of Computer Programming");
    strcpy(ebooks[num_ebooks].author, "Donald Knuth");
    ebooks[num_ebooks].price = 24.99;
    ebooks[num_ebooks].publication_year = 1968;
    num_ebooks++;

    strcpy(ebooks[num_ebooks].title, "Operating System Concepts");
    strcpy(ebooks[num_ebooks].author, "Abraham Silberschatz, Peter Baer Galvin, and Greg Gagne");
    ebooks[num_ebooks].price = 29.99;
    ebooks[num_ebooks].publication_year = 1986;
    num_ebooks++;

    ebook_reader(ebooks, num_ebooks);

    return 0;
}