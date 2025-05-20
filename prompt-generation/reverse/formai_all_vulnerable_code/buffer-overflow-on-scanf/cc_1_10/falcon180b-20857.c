//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

int numBooks = 0;
Book books[MAX_BOOKS];

void addBook() {
    printf("Enter title (max %d characters): ", MAX_TITLE_LENGTH);
    scanf("%s", books[numBooks].title);

    printf("Enter author (max %d characters): ", MAX_AUTHOR_LENGTH);
    scanf("%s", books[numBooks].author);

    printf("Enter content (max %d characters): ", MAX_CONTENT_LENGTH);
    scanf("%s", books[numBooks].content);

    numBooks++;
}

void listBooks() {
    printf("Number of books: %d\n", numBooks);
    for (int i = 0; i < numBooks; i++) {
        printf("Book %d:\n", i+1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Content: %s\n\n", books[i].content);
    }
}

void searchBook() {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter title to search: ");
    scanf("%s", searchTitle);

    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(searchTitle, books[i].title) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Content: %s\n", books[i].content);
            found = 1;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add book\n");
        printf("2. List books\n");
        printf("3. Search book\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}