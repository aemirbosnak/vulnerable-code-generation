//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a book
typedef struct book {
    int id;
    char title[50];
    char author[50];
    double price;
} Book;

int main() {
    // Declare a variable for number of books
    int num_books;

    // Ask user for number of books
    printf("Enter the number of books: ");
    scanf("%d", &num_books);

    // Allocate memory dynamically for an array of books
    Book * books = (Book *)malloc(num_books * sizeof(Book));

    // Check if memory was allocated successfully
    if (books == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    // Loop through each book and ask user for book details
    for (int i = 0; i < num_books; i++) {
        printf("Enter details for book #%d:\n", i+1);
        printf("ID: ");
        scanf("%d", &(books+i)->id);
        printf("Title: ");
        scanf("%s", (books+i)->title);
        printf("Author: ");
        scanf("%s", (books+i)->author);
        printf("Price: ");
        scanf("%lf", &(books+i)->price);
    }

    // Print the list of books
    printf("\nList of books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d\t%s\t%s\t%.2f\n", (books+i)->id, (books+i)->title, (books+i)->author, (books+i)->price);
    }

    // Free the allocated memory
    free(books);

    return 0;
}