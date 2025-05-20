//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for storing information about books
typedef struct book {
    int id;
    char title[50];
    char author[50];
} Book;

int main() {
    // Define an array of books and initialize its size to 0
    Book books[100];
    int numBooks = 0;

    // Display menu options to the user
    while (1) {
        printf("\n----- BOOK DATABASE SIMULATION -----\n");
        printf("1. Add book\n");
        printf("2. Remove book\n");
        printf("3. Display all books\n");
        printf("4. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add a new book
            Book newBook;
            printf("\nEnter book ID: ");
            scanf("%d", &newBook.id);
            printf("Enter book title: ");
            scanf("%s", newBook.title);
            printf("Enter book author: ");
            scanf("%s", newBook.author);

            // Add the new book to the array of books
            books[numBooks] = newBook;
            numBooks++;
            printf("\nBook added successfully.\n");
        } else if (choice == 2) {
            // Remove a book
            int idToRemove;
            printf("\nEnter book ID to remove: ");
            scanf("%d", &idToRemove);

            // Search for the book by ID and remove it from the array of books
            int bookIndexToRemove = -1;
            for (int i = 0; i < numBooks; i++) {
                if (books[i].id == idToRemove) {
                    bookIndexToRemove = i;
                    break;
                }
            }

            if (bookIndexToRemove != -1) {
                for (int i = bookIndexToRemove + 1; i < numBooks; i++) {
                    books[i - 1] = books[i];
                }
                numBooks--;
                printf("\nBook removed successfully.\n");
            } else {
                printf("\nBook not found.\n");
            }
        } else if (choice == 3) {
            // Display all books
            if (numBooks == 0) {
                printf("\nNo books to display.\n");
            } else {
                printf("\nID\tTitle\t\tAuthor\n");
                for (int i = 0; i < numBooks; i++) {
                    printf("%d\t%s\t%s\n", books[i].id, books[i].title, books[i].author);
                }
            }
        } else if (choice == 4) {
            // Exit the program
            printf("\nGoodbye!\n");
            break;
        } else {
            printf("\nInvalid choice.\n");
        }
    }

    return 0;
}