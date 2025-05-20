//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a book
typedef struct book
{
    char title[20];
    char author[20];
    int quantity;
} book;

// Define the book management function
void book_management(book *books, int num_books)
{
    // Display the list of books
    printf("List of books:\n");
    for (int i = 0; i < num_books; i++)
    {
        printf("%s by %s (Quantity: %d)\n", books[i].title, books[i].author, books[i].quantity);
    }

    // Add a new book
    printf("Enter the title of the new book: ");
    scanf("%s", books[num_books].title);

    printf("Enter the author's name: ");
    scanf("%s", books[num_books].author);

    printf("Enter the quantity: ");
    scanf("%d", &books[num_books].quantity);

    num_books++;
}

int main()
{
    // Create an array of books
    book books[10];

    // Initialize the number of books to 0
    int num_books = 0;

    // Book management loop
    while (1)
    {
        // Display the menu options
        printf("Options:\n");
        printf("1. Display list of books\n");
        printf("2. Add a new book\n");
        printf("3. Exit\n");

        // Get the user's choice
        int choice = 0;
        scanf("%d", &choice);

        // Execute the chosen option
        switch (choice)
        {
            case 1:
                book_management(books, num_books);
                break;
            case 2:
                book_management(books, num_books);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}