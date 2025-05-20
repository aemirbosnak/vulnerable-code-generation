//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BORROWERS 20

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

typedef struct Borrower {
    char name[50];
    int books_borrowed;
    struct Borrower* next;
} Borrower;

Book* insertBook(Book* head) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);
    newBook->next = head;
    head = newBook;
    return head;
}

Borrower* insertBorrower(Borrower* head) {
    Borrower* newBorrower = (Borrower*)malloc(sizeof(Borrower));
    printf("Enter borrower name: ");
    scanf("%s", newBorrower->name);
    newBorrower->books_borrowed = 0;
    newBorrower->next = head;
    head = newBorrower;
    return head;
}

void borrowBook(Book* head, Borrower* headBorrower) {
    char bookTitle[50];
    printf("Enter book title: ");
    scanf("%s", bookTitle);

    Book* book = head;
    Borrower* borrower = headBorrower;

    while (book) {
        if (strcmp(book->title, bookTitle) == 0) {
            book->quantity--;
            borrower->books_borrowed++;
            printf("Book borrowed successfully!\n");
            return;
        }
        book = book->next;
    }

    printf("Book not found!\n");
}

void returnBook(Book* head, Borrower* headBorrower) {
    char bookTitle[50];
    printf("Enter book title: ");
    scanf("%s", bookTitle);

    Book* book = head;
    Borrower* borrower = headBorrower;

    while (book) {
        if (strcmp(book->title, bookTitle) == 0) {
            book->quantity++;
            borrower->books_borrowed--;
            printf("Book returned successfully!\n");
            return;
        }
        book = book->next;
    }

    printf("Book not found!\n");
}

int main() {
    Book* headBook = NULL;
    Borrower* headBorrower = NULL;

    // Insert book and borrower
    insertBook(headBook);
    insertBorrower(headBorrower);

    // Borrow book
    borrowBook(headBook, headBorrower);

    // Return book
    returnBook(headBook, headBorrower);

    return 0;
}