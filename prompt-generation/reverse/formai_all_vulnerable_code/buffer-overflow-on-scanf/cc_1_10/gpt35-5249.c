//FormAI DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constant values for maximum book title and author name length */
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

/* Define a struct for a Book */
struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
    double price;
};

/* Define a function to display a book's information */
void displayBook(struct Book book) {
    printf("\nTitle: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year: %d\n", book.year);
    printf("Price: $%.2f\n", book.price);
}

int main() {
    int numBooks;
    printf("Enter the number of Ebooks to read: ");
    scanf("%d", &numBooks);
    getchar(); // remove the newline character from the input buffer

    /* Allocate memory for an array of Books */
    struct Book *books = malloc(numBooks * sizeof(struct Book));

    /* Loop through the array of Books and read in the information from the user */
    for (int i = 0; i < numBooks; i++) {
        printf("\nEnter the information for Ebook #%d:\n", i+1);

        printf("Title: ");
        fgets(books[i].title, MAX_TITLE_LENGTH, stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0'; // remove the newline character from the input

        printf("Author: ");
        fgets(books[i].author, MAX_AUTHOR_LENGTH, stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0'; // remove the newline character from the input

        printf("Year: ");
        scanf("%d", &books[i].year);
        getchar(); // remove the newline character from the input buffer

        printf("Price: ");
        scanf("%lf", &books[i].price);
        getchar(); // remove the newline character from the input buffer
    }

    /* Display the information for each Book */
    printf("\n\nThe Ebooks in your library are:\n");
    for (int i = 0; i < numBooks; i++) {
        displayBook(books[i]);
    }

    /* Free the memory allocated for the array of Books */
    free(books);

    return 0;
}