//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_WORDS 1000
#define MAX_LINES 1000

typedef struct {
    char title[50];
    char author[50];
    int num_pages;
    char content[MAX_WORDS][MAX_LINES];
} Book;

int num_books = 0;
Book books[MAX_BOOKS];

void add_book() {
    printf("Enter book title: ");
    scanf("%s", books[num_books].title);

    printf("Enter author name: ");
    scanf("%s", books[num_books].author);

    printf("Enter number of pages: ");
    scanf("%d", &books[num_books].num_pages);

    int i, j, k;
    for(i=0; i<books[num_books].num_pages; i++) {
        printf("Enter content for page %d:\n", i+1);
        fgets(books[num_books].content[i], MAX_LINES, stdin);
    }

    num_books++;
}

void display_books() {
    printf("\nList of books:\n");
    for(int i=0; i<num_books; i++) {
        printf("%d. %s by %s\n", i+1, books[i].title, books[i].author);
    }
}

void read_book(int book_num) {
    printf("\nReading book %s by %s...\n\n", books[book_num-1].title, books[book_num-1].author);
    for(int i=0; i<books[book_num-1].num_pages; i++) {
        printf("%s", books[book_num-1].content[i]);
    }
}

int main() {
    int choice, book_num;

    do {
        printf("\nWelcome to the Ebook Reader!\n");
        printf("1. Add a book\n2. Display list of books\n3. Read a book\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                printf("Enter book number: ");
                scanf("%d", &book_num);
                read_book(book_num);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 4);

    return 0;
}