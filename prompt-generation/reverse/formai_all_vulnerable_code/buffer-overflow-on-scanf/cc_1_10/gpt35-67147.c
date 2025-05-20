//FormAI DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_TITLE 100
#define MAX_AUTHOR 50

struct Book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int year;
    char filename[100];
};

int numBooks = 0;   // number of books in library
struct Book library[MAX_BOOKS]; // array to hold books

void printMenu();
void addBook();
void viewBook();
void deleteBook();

int main()
{
    int choice;
    do {
        printMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBook(); break;
            case 3: deleteBook(); break;
            case 4: printf("Exiting program..."); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
    return 0;
}

void printMenu()
{
    printf("\nWelcome to the Ebook Library!\n");
    printf("1. Add a Book\n");
    printf("2. View a Book\n");
    printf("3. Delete a Book\n");
    printf("4. Quit\n");
}

void addBook()
{
    struct Book newBook;
    printf("Enter book title: ");
    scanf("%s", newBook.title);
    printf("Enter book author: ");
    scanf("%s", newBook.author);
    printf("Enter year published: ");
    scanf("%d", &newBook.year);
    printf("Enter filename (.pdf): ");
    scanf("%s", newBook.filename);
    if (numBooks == MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }
    library[numBooks++] = newBook;
    printf("Book added to library.\n");
}

void viewBook()
{
    int i;
    char title[MAX_TITLE];
    printf("Enter book title to view: ");
    scanf("%s", title);
    for (i = 0; i < numBooks; i++) {
        if (strcmp(title, library[i].title) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Year: %d\n", library[i].year);
            printf("Filename: %s\n", library[i].filename);
            printf("Opening ebook...\n");
            // code to open ebook with default program goes here
            return;
        }
    }
    printf("Book not found in library.\n");
}

void deleteBook()
{
    int i, j;
    char title[MAX_TITLE];
    printf("Enter book title to delete: ");
    scanf("%s", title);
    for (i = 0; i < numBooks; i++) {
        if (strcmp(title, library[i].title) == 0) {
            for (j = i; j < numBooks - 1; j++) {
                library[j] = library[j+1];
            }
            numBooks--;
            printf("Book deleted from library.\n");
            return;
        }
    }
    printf("Book not found in library.\n");
}