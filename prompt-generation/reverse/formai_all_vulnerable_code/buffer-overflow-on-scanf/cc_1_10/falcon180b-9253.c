//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_CONTENT_LENGTH 100000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

int numBooks = 0;
Book books[MAX_BOOKS];

void addBook() {
    if (numBooks >= MAX_BOOKS) {
        printf("Cannot add more books. Maximum limit reached.\n");
        return;
    }

    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);

    printf("Enter author name: ");
    scanf("%s", books[numBooks].author);

    printf("Enter book content: ");
    fgets(books[numBooks].content, MAX_CONTENT_LENGTH, stdin);

    numBooks++;
}

void listBooks() {
    printf("\nList of books:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s\n", i+1, books[i].title, books[i].author);
    }
}

void readBook(int index) {
    if (index < 0 || index >= numBooks) {
        printf("Invalid book index.\n");
        return;
    }

    printf("\n%s by %s\n\n%s", books[index].title, books[index].author, books[index].content);
}

int main() {
    int choice;

    do {
        printf("\nE-book reader\n");
        printf("1. Add book\n2. List books\n3. Read book\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                printf("Enter book index: ");
                scanf("%d", &choice);
                readBook(choice-1);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}