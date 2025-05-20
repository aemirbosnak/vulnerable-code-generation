//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

struct person
{
    char name[100];
    char phone_number[20];
};

void add_person(struct person *book, char *name, char *phone_number)
{
    if (book == NULL)
    {
        printf("Error: Book not initialized!\n");
        return;
    }

    book->name[0] = '\0';
    strcpy(book->name, name);
    book->phone_number[0] = '\0';
    strcpy(book->phone_number, phone_number);
}

void print_book(struct person *book)
{
    if (book == NULL)
    {
        printf("Error: Book not initialized!\n");
        return;
    }

    printf("%s: %s\n", book->name, book->phone_number);
}

int main()
{
    struct person *book = NULL;

    printf("Enter name: ");
    char name[100];
    scanf("%s", name);

    printf("Enter phone number: ");
    char phone_number[20];
    scanf("%s", phone_number);

    add_person(book, name, phone_number);

    print_book(book);

    return 0;
}