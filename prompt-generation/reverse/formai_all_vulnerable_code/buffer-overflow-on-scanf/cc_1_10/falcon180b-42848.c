//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME 100
#define MAX_BOOK_AUTHOR 100
#define MAX_BOOK_PAGES 1000

typedef struct {
    char name[MAX_BOOK_NAME];
    char author[MAX_BOOK_AUTHOR];
    int pages;
} Book;

int numBooks = 0;
Book books[MAX_BOOKS];

void addBook() {
    if (numBooks >= MAX_BOOKS) {
        printf("Sorry, you have reached the maximum number of books.\n");
        return;
    }
    printf("Enter the name of the book: ");
    scanf("%s", books[numBooks].name);
    printf("Enter the author of the book: ");
    scanf("%s", books[numBooks].author);
    printf("Enter the number of pages: ");
    scanf("%d", &books[numBooks].pages);
    numBooks++;
    printf("Book added successfully!\n");
}

void removeBook() {
    if (numBooks == 0) {
        printf("Sorry, there are no books to remove.\n");
        return;
    }
    printf("Enter the name of the book you want to remove: ");
    char bookName[MAX_BOOK_NAME];
    scanf("%s", bookName);
    int i;
    for (i = 0; i < numBooks; i++) {
        if (strcmp(books[i].name, bookName) == 0) {
            numBooks--;
            printf("Book removed successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void displayBooks() {
    if (numBooks == 0) {
        printf("Sorry, there are no books to display.\n");
        return;
    }
    printf("Name\tAuthor\tPages\n");
    int i;
    for (i = 0; i < numBooks; i++) {
        printf("%s\t%s\t%d\n", books[i].name, books[i].author, books[i].pages);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add book\n2. Remove book\n3. Display books\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            removeBook();
            break;
        case 3:
            displayBooks();
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}