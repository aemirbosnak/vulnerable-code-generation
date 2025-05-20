//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_BOOKS 100

typedef struct {
    char title[50];
    char author[50];
    char genre[50];
    char description[100];
} Book;

Book books[MAX_BOOKS];
int numBooks = 0;

void addBook() {
    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);
    printf("Enter book author: ");
    scanf("%s", books[numBooks].author);
    printf("Enter book genre: ");
    scanf("%s", books[numBooks].genre);
    printf("Enter book description: ");
    scanf("%s", books[numBooks].description);
    numBooks++;
}

void displayBooks() {
    printf("Book Title\tAuthor\tGenre\tDescription\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%s\t%s\t%s\t%s\n", books[i].title, books[i].author, books[i].genre, books[i].description);
    }
}

void searchBook(char* searchTerm) {
    printf("Searching for \"%s\"...\n", searchTerm);
    for (int i = 0; i < numBooks; i++) {
        if (strstr(books[i].title, searchTerm)!= NULL ||
            strstr(books[i].author, searchTerm)!= NULL ||
            strstr(books[i].genre, searchTerm)!= NULL ||
            strstr(books[i].description, searchTerm)!= NULL) {
            printf("%s by %s (%s)\n%s\n", books[i].title, books[i].author, books[i].genre, books[i].description);
        }
    }
}

int main() {
    int choice;
    char input[MAX_LINE_LENGTH];

    printf("Welcome to the Ebook Reader!\n");
    while (1) {
        printf("\n");
        printf("1. Add a book\n");
        printf("2. Display all books\n");
        printf("3. Search for a book\n");
        printf("4. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            printf("Enter search term: ");
            fgets(input, MAX_LINE_LENGTH, stdin);
            searchBook(input);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}