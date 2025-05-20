//FormAI DATASET v1.0 Category: Database querying ; Style: imaginative
/* Welcome to the Virtual Library */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char listOfBooks[5][50] = {
    "The Catcher in the Rye",
    "To Kill a Mockingbird",
    "The Great Gatsby",
    "1984",
    "Animal Farm"
};
int numOfBooks = 5;

// function prototypes
bool searchForBook(char book[]);
void displayAllBooks();
void addNewBook(char book[]);
void removeBook(char book[]);
bool checkIfBookExists(char book[]);

// main function
int main()
{
    int choice;
    char book[50];

    printf("Welcome to the Virtual Library\n");
    printf("-------------------------------\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Display all books\n");
        printf("2. Search for a book\n");
        printf("3. Add a new book\n");
        printf("4. Remove a book\n");
        printf("5. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAllBooks();
                break;
            case 2:
                printf("\nEnter the name of the book you want to search: ");
                scanf(" %[^\n]s", book);
                if (searchForBook(book)) {
                    printf("Yes, we have that book\n");
                } else {
                    printf("Sorry, we do not have that book\n");
                }
                break;
            case 3:
                printf("\nEnter the name of the book you want to add: ");
                scanf(" %[^\n]s", book);
                addNewBook(book);
                printf("%s has been added to the library\n", book);
                break;
            case 4:
                printf("\nEnter the name of the book you want to remove: ");
                scanf(" %[^\n]s", book);
                removeBook(book);
                break;
            case 5:
                printf("\nThank you for using the Virtual Library!\n");
                break;
            default:
                printf("\nInvalid choice, please try again\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// function definitions

// display all the books in the library
void displayAllBooks()
{
    printf("\nList of all books in the library:\n");
    for (int i = 0; i < numOfBooks; i++) {
        printf("%d. %s\n", i+1, listOfBooks[i]);
    }
}

// search for a book in the library
bool searchForBook(char book[]) {
    for (int i = 0; i < numOfBooks; i++) {
        if (strcmp(listOfBooks[i], book) == 0) {
            return true;
        }
    }
    return false;
}

// add a new book to the library
void addNewBook(char book[]) {
    if (checkIfBookExists(book)) {
        printf("Sorry, this book already exists in the library\n");
        return;
    }
    // add the book to the end of the array
    strcpy(listOfBooks[numOfBooks], book);
    numOfBooks++;
}

// remove a book from the library
void removeBook(char book[]) {
    if (!checkIfBookExists(book)) {
        printf("Sorry, this book does not exist in the library\n");
        return;
    }
    // find the book and remove it by shifting all the books after it
    // one position to the left
    int i;
    for (i = 0; i < numOfBooks; i++) {
        if (strcmp(listOfBooks[i], book) == 0) {
            break;
        }
    }
    for (int j = i; j < numOfBooks-1; j++) {
        strcpy(listOfBooks[j], listOfBooks[j+1]);
    }
    numOfBooks--;
    printf("%s has been removed from the library\n", book);
}

// check if a book already exists in the library
bool checkIfBookExists(char book[]) {
    for (int i = 0; i < numOfBooks; i++) {
        if (strcmp(listOfBooks[i], book) == 0) {
            return true;
        }
    }
    return false;
}