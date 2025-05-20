//FormAI DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Book structure
typedef struct book {
    char title[100];
    char author[50];
    int year;
} Book;

// Function prototypes
void readBook(Book* book);
void displayBook(Book book);
void displayBooks(Book* books, int count);
void addBook(Book* books, int* count);
void searchBook(Book* books, int count);
void deleteBook(Book* books, int* count);

int main() {
    Book books[MAX_BOOKS];
    int count = 0, option;

    // Display menu
    do {
        printf("\nWelcome to the Library Book Management System!\n");
        printf("1. Display Books\n");
        printf("2. Add Book\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                displayBooks(books, count);
                break;

            case 2:
                addBook(books, &count);
                break;

            case 3:
                searchBook(books, count);
                break;

            case 4:
                deleteBook(books, &count);
                break;

            case 5:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid option. Please try again.\n");
        }

    } while(option != 5);

    return 0;
}

// Function to read book details from user input
void readBook(Book* book) {
    printf("\nEnter book title: ");
    fflush(stdin);
    gets(book->title);

    printf("Enter author name: ");
    gets(book->author);

    printf("Enter publication year: ");
    scanf("%d", &book->year);
}

// Function to display book details
void displayBook(Book book) {
    printf("\nTitle: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year of publication: %d\n", book.year);
}

// Function to display all books in array
void displayBooks(Book* books, int count) {
    if(count == 0) {
        printf("\nNo books in the library yet.\n");
        return;
    }

    printf("\nLibrary Book List:\n");
    for(int i = 0; i < count; i++) {
        displayBook(books[i]);
    }
}

// Function to add a new book to array
void addBook(Book* books, int* count) {
    if(*count == MAX_BOOKS) {
        printf("\nSorry, the library has reached maximum capacity.\n");
        return;
    }

    Book newBook;
    readBook(&newBook);

    books[*count] = newBook;
    (*count)++;

    printf("\nBook added successfully!\n");
}

// Function to search for a book by title
void searchBook(Book* books, int count) {
    char title[100];
    printf("\nEnter book title to search: ");
    fflush(stdin);
    gets(title);

    int found = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(title, books[i].title) == 0) {
            printf("\nBook found:\n");
            displayBook(books[i]);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nBook not found.\n");
    }
}

// Function to delete a book by title
void deleteBook(Book* books, int* count) {
    char title[100];
    printf("\nEnter book title to delete: ");
    fflush(stdin);
    gets(title);

    int found = 0;
    for(int i = 0; i < *count; i++) {
        if(strcmp(title, books[i].title) == 0) {
            // Shift all elements after deleted book to fill gap
            for(int j = i; j < *count - 1; j++) {
                books[j] = books[j + 1];
            }

            (*count)--;
            printf("\nBook deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nBook not found.\n");
    }
}