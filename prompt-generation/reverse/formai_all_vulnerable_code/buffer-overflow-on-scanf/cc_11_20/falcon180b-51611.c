//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_BOOK_NAME_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 100

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    int pages;
} Book;

int main() {
    int numBooks = 0;
    Book *books = malloc(MAX_BOOKS * sizeof(Book));
    char input[100];

    printf("Welcome to the Ebook Reader!\n");

    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add a book\n");
        printf("2. Remove a book\n");
        printf("3. List all books\n");
        printf("4. Exit\n");

        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            if (numBooks >= MAX_BOOKS) {
                printf("Sorry, you cannot add more books.\n");
            } else {
                printf("Enter book name (max %d characters): ", MAX_BOOK_NAME_LENGTH);
                scanf("%s", books[numBooks].name);

                printf("Enter book author (max %d characters): ", MAX_BOOK_AUTHOR_LENGTH);
                scanf("%s", books[numBooks].author);

                printf("Enter number of pages: ");
                scanf("%d", &books[numBooks].pages);

                numBooks++;
            }
        } else if (strcmp(input, "2") == 0) {
            if (numBooks == 0) {
                printf("No books to remove.\n");
            } else {
                printf("Enter book number to remove (0-%d): ", numBooks - 1);
                int bookNum;
                scanf("%d", &bookNum);

                if (bookNum >= 0 && bookNum < numBooks) {
                    numBooks--;
                    for (int i = bookNum; i < numBooks; i++) {
                        books[i] = books[i+1];
                    }
                } else {
                    printf("Invalid book number.\n");
                }
            }
        } else if (strcmp(input, "3") == 0) {
            printf("List of books:\n");

            for (int i = 0; i < numBooks; i++) {
                printf("%s by %s (%d pages)\n", books[i].name, books[i].author, books[i].pages);
            }
        } else if (strcmp(input, "4") == 0) {
            printf("Exiting...\n");
            free(books);
            exit(0);
        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}