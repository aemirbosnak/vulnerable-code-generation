//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book
{
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* InsertBook(Book* head)
{
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);
    newBook->next = NULL;

    if (head == NULL)
    {
        head = newBook;
    }
    else
    {
        head->next = newBook;
    }

    return head;
}

Book* SearchBook(Book* head, char* title)
{
    Book* currentBook = head;

    while (currentBook)
    {
        if (strcmp(currentBook->title, title) == 0)
        {
            return currentBook;
        }
        currentBook = currentBook->next;
    }

    return NULL;
}

void UpdateBookQuantity(Book* book, int newQuantity)
{
    book->quantity = newQuantity;
}

void DeleteBook(Book* head, Book* bookToDelete)
{
    Book* previousBook = NULL;

    while (bookToDelete)
    {
        if (previousBook)
        {
            previousBook->next = bookToDelete->next;
        }
        else
        {
            head = bookToDelete->next;
        }

        free(bookToDelete);
        bookToDelete = previousBook->next;
    }
}

int main()
{
    Book* head = NULL;

    while (1)
    {
        printf("Enter command (add, search, update, delete): ");
        char command[50];
        scanf("%s", command);

        if (strcmp(command, "add") == 0)
        {
            head = InsertBook(head);
        }
        else if (strcmp(command, "search") == 0)
        {
            char title[50];
            printf("Enter book title: ");
            scanf("%s", title);
            Book* book = SearchBook(head, title);
            if (book)
            {
                printf("Book found:\n");
                printf("Title: %s\n", book->title);
                printf("Author: %s\n", book->author);
                printf("Quantity: %d\n", book->quantity);
            }
            else
            {
                printf("Book not found.\n");
            }
        }
        else if (strcmp(command, "update") == 0)
        {
            char title[50];
            printf("Enter book title: ");
            scanf("%s", title);
            Book* book = SearchBook(head, title);
            if (book)
            {
                int newQuantity;
                printf("Enter new book quantity: ");
                scanf("%d", &newQuantity);
                UpdateBookQuantity(book, newQuantity);
                printf("Book quantity updated.\n");
            }
            else
            {
                printf("Book not found.\n");
            }
        }
        else if (strcmp(command, "delete") == 0)
        {
            char title[50];
            printf("Enter book title: ");
            scanf("%s", title);
            Book* bookToDelete = SearchBook(head, title);
            if (bookToDelete)
            {
                DeleteBook(head, bookToDelete);
                printf("Book deleted.\n");
            }
            else
            {
                printf("Book not found.\n");
            }
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    return 0;
}