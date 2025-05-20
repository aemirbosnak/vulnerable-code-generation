//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_LENGTH 50
#define MAX_BOOK_AUTHOR_LENGTH 50
#define MAX_BOOK_CONTENT_LENGTH 1000000

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    char content[MAX_BOOK_CONTENT_LENGTH];
} Book;

int num_books = 0;
Book books[MAX_BOOKS];

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("Error: Maximum number of books reached.\n");
        return;
    }

    printf("Enter book name: ");
    scanf("%s", books[num_books].name);

    printf("Enter book author: ");
    scanf("%s", books[num_books].author);

    printf("Enter book content:\n");
    char content[MAX_BOOK_CONTENT_LENGTH];
    fgets(content, MAX_BOOK_CONTENT_LENGTH, stdin);
    strcpy(books[num_books].content, content);

    num_books++;
    printf("Book added successfully.\n");
}

void list_books() {
    printf("List of books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s\n", i+1, books[i].name, books[i].author);
    }
}

void read_book() {
    if (num_books == 0) {
        printf("Error: No books available.\n");
        return;
    }

    int book_index;
    printf("Enter book index: ");
    scanf("%d", &book_index);

    if (book_index < 1 || book_index > num_books) {
        printf("Error: Invalid book index.\n");
        return;
    }

    printf("Book content:\n%s\n", books[book_index-1].content);
}

int main() {
    int choice;
    do {
        printf("Ebook Reader Menu:\n");
        printf("1. Add book\n");
        printf("2. List books\n");
        printf("3. Read book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 3:
                read_book();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}