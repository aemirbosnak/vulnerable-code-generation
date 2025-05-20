//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a structure to store book information
    typedef struct Book
    {
        char title[20];
        char author[20];
        int pages;
    } Book;

    // Create an array of books
    Book books[100];

    // Initialize the books array
    for (int i = 0; i < 100; i++)
    {
        books[i].title[0] = '\0';
        books[i].author[0] = '\0';
        books[i].pages = 0;
    }

    // Get the number of books from the user
    int numBooks;
    printf("Enter the number of books you want to store: ");
    scanf("%d", &numBooks);

    // Store the book information
    for (int i = 0; i < numBooks; i++)
    {
        printf("Enter the title of book %d: ", i + 1);
        scanf("%s", books[i].title);

        printf("Enter the author of book %d: ", i + 1);
        scanf("%s", books[i].author);

        printf("Enter the number of pages in book %d: ", i + 1);
        scanf("%d", &books[i].pages);
    }

    // Print the book information
    printf("Here is your book information:\n");
    for (int i = 0; i < numBooks; i++)
    {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n", books[i].pages);
        printf("\n");
    }

    return 0;
}