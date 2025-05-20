//FormAI DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 50
#define MAX_AUTHOR 30
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int year;
    int pages;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook()
{
    if (bookCount < MAX_BOOKS) {
        printf("\nEnter book title: ");
        scanf(" %[^\n]s", library[bookCount].title);
        printf("Enter author name: ");
        scanf(" %[^\n]s", library[bookCount].author);
        printf("Enter year of publication: ");
        scanf("%d", &library[bookCount].year);
        printf("Enter number of pages: ");
        scanf("%d", &library[bookCount].pages);
        bookCount++;
        printf("\nBook added to library!\n");
    } else {
        printf("\nSorry, the library is full.\n");
    }
}

void viewLibrary()
{
    if (bookCount == 0) {
        printf("\nThe library is empty.\n");
    } else {
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        for (int i = 0; i < bookCount; i++) {
            printf("\nTitle: %s\nAuthor: %s\nYear: %d\nPages: %d\n", library[i].title, library[i].author, library[i].year, library[i].pages);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        }
    }
}

int searchByTitle()
{
    char title[MAX_TITLE];
    int found = 0;

    printf("\nEnter book title: ");
    scanf(" %[^\n]s", title);

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(title, library[i].title) == 0) {
            found++;
            printf("\nTitle: %s\nAuthor: %s\nYear: %d\nPages: %d\n", library[i].title, library[i].author, library[i].year, library[i].pages);
        }
    }

    if (!found) {
        printf("\nBook not found.\n");
    }

    return found;
}

void deleteByTitle()
{
    char title[MAX_TITLE];
    int found = 0;

    printf("\nEnter book title: ");
    scanf(" %[^\n]s", title);

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(title, library[i].title) == 0) {
            found++;
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            printf("\nBook deleted from library.\n");
        }
    }

    if (!found) {
        printf("\nBook not found.\n");
    }
}

void medievalIntro()
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n* * * * * * * WELCOME TO THE MEDIEVAL LIBRARY * * * * * * *\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("The year is 1456 and you have stumbled upon the mystical medieval library.");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

int main()
{
    int choice;

    medievalIntro();

    do {
        printf("\n\nWhat would you like to do?");
        printf("\n1. Add a book to the library.");
        printf("\n2. View all books in the library.");
        printf("\n3. Search for a book by title.");
        printf("\n4. Delete a book from the library.");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewLibrary(); break;
            case 3: searchByTitle(); break;
            case 4: deleteByTitle(); break;
            case 5: printf("\nFarewell adventurer.\n"); break;

            default: printf("\nSorry, I didn't understand that.\n"); break;
        }
    } while (choice != 5);

    return 0;
}