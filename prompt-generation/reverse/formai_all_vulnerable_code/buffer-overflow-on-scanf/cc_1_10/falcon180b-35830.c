//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 100
#define MAX_BOOK_PAGES 1000

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    int pages;
} book;

void add_book(book* library, int num_books) {
    printf("Enter book name: ");
    scanf("%s", library[num_books].name);
    printf("Enter book author: ");
    scanf("%s", library[num_books].author);
    printf("Enter number of pages: ");
    scanf("%d", &library[num_books].pages);
}

void display_book(book book) {
    printf("Book name: %s\n", book.name);
    printf("Book author: %s\n", book.author);
    printf("Number of pages: %d\n", book.pages);
}

int main() {
    book library[MAX_BOOKS];
    int num_books = 0;

    printf("Welcome to the ebook reader!\n");
    printf("You can store up to %d books.\n", MAX_BOOKS);

    while(num_books < MAX_BOOKS) {
        printf("Enter 1 to add a book, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if(choice == 1) {
            add_book(library, num_books);
            num_books++;
        } else if(choice == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice, try again.\n");
        }
    }

    printf("\nList of books:\n");
    for(int i = 0; i < num_books; i++) {
        display_book(library[i]);
    }

    return 0;
}