//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct book
{
    char title[50];
    char author[50];
    int quantity;
    float price;
    struct book* next;
};

struct book* insertBook(struct book* head)
{
    struct book* newBook = (struct book*)malloc(sizeof(struct book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);
    printf("Enter book price: ");
    scanf("%f", &newBook->price);

    newBook->next = head;
    head = newBook;

    return head;
}

struct book* searchBook(struct book* head, char* title)
{
    struct book* currentBook = head;

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

void updateBookQuantity(struct book* head, char* title, int newQuantity)
{
    struct book* currentBook = searchBook(head, title);

    if (currentBook)
    {
        currentBook->quantity = newQuantity;
    }
}

void deleteBook(struct book* head, char* title)
{
    struct book* currentBook = searchBook(head, title);

    if (currentBook)
    {
        struct book* previousBook = NULL;

        while (currentBook->next)
        {
            previousBook = currentBook;
            currentBook = currentBook->next;
        }

        if (previousBook)
        {
            previousBook->next = currentBook->next;
        }
        else
        {
            head = currentBook->next;
        }

        free(currentBook);
    }
}

int main()
{
    struct book* head = NULL;

    head = insertBook(head);
    insertBook(head);
    insertBook(head);

    searchBook(head, "Book 1") -> quantity = 10;

    deleteBook(head, "Book 2");

    return 0;
}