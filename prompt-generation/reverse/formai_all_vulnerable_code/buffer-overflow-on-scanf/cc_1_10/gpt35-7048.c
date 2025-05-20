//FormAI DATASET v1.0 Category: Database simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
   char title[50];
   char author[50];
   int id;
   float price;
} Book;

void printMenu() {
    printf("1. Add book\n");
    printf("2. Search book by title\n");
    printf("3. Search book by author\n");
    printf("4. Delete book by id\n");
    printf("5. Display all books\n");
    printf("6. Exit\n");
}

void addBook(Book books[], int *numOfBooks) {
    if (*numOfBooks >= MAX_RECORDS) {
        printf("Database full. Can't add more books.\n");
        return;
    }

    Book newBook;

    printf("Enter book title: ");
    scanf("%s", newBook.title);
    printf("Enter book author: ");
    scanf("%s", newBook.author);
    printf("Enter book id: ");
    scanf("%d", &newBook.id);
    printf("Enter book price: ");
    scanf("%f", &newBook.price);

    books[*numOfBooks] = newBook;
    *numOfBooks += 1;
}

void searchByTitle(Book books[], int numOfBooks) {
    char searchTerm[50];
    printf("Enter a title to search for: ");
    scanf("%s", searchTerm);

    int found = 0;

    for (int i = 0; i < numOfBooks; i++) {
        if (strcmp(books[i].title, searchTerm) == 0) {
            printf("Book found! Title: %s, Author: %s, Id: %d, Price: %.2f\n", books[i].title, books[i].author, books[i].id, books[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void searchByAuthor(Book books[], int numOfBooks) {
    char searchTerm[50];
    printf("Enter an author to search for: ");
    scanf("%s", searchTerm);

    int found = 0;

    for (int i = 0; i < numOfBooks; i++) {
        if (strcmp(books[i].author, searchTerm) == 0) {
            printf("Book found! Title: %s, Author: %s, Id: %d, Price: %.2f\n", books[i].title, books[i].author, books[i].id, books[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void deleteById(Book books[], int *numOfBooks) {
    int idToDelete;
    printf("Enter the id of the book to delete: ");
    scanf("%d", &idToDelete);

    int found = 0;

    for (int i = 0; i < *numOfBooks; i++) {
        if (books[i].id == idToDelete) {
            found = 1;
            for (int j = i; j < (*numOfBooks) - 1; j++) {
                books[j] = books[j+1];
            }
            *numOfBooks -= 1;
            printf("Book deleted.\n");
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void displayAllBooks(Book books[], int numOfBooks) {
    for (int i = 0; i < numOfBooks; i++) {
        printf("Title: %s, Author: %s, Id: %d, Price: %.2f\n", books[i].title, books[i].author, books[i].id, books[i].price);
    }
}

int main() {
    Book books[MAX_RECORDS];
    int numOfBooks = 0;
    int choice = 0;

    printf("Welcome to the book database.\n");

    while (choice != 6) {
        printMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &numOfBooks);
                break;
            case 2:
                searchByTitle(books, numOfBooks);
                break;
            case 3:
                searchByAuthor(books, numOfBooks);
                break;
            case 4:
                deleteById(books, &numOfBooks);
                break;
            case 5:
                displayAllBooks(books, numOfBooks);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}