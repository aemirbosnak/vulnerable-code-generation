//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    int pageCount;
    char content[MAX_LINE_LENGTH];
} Book;

int numBooks = 0;
Book books[MAX_BOOKS];

void addBook() {
    if (numBooks == MAX_BOOKS) {
        printf("Cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);

    printf("Enter author name: ");
    scanf("%s", books[numBooks].author);

    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pageCount);

    printf("Enter book content (press ENTER to finish):\n");

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        strcat(books[numBooks].content, line);
    }

    numBooks++;
    printf("Book added successfully.\n");
}

void readBook(int index) {
    if (index < 0 || index >= numBooks) {
        printf("Invalid book index.\n");
        return;
    }

    printf("Book title: %s\n", books[index].title);
    printf("Author: %s\n", books[index].author);
    printf("Number of pages: %d\n", books[index].pageCount);
    printf("Content:\n%s", books[index].content);
}

int main() {
    int choice;

    while (1) {
        printf("\nEbook Reader\n");
        printf("1. Add book\n");
        printf("2. Read book\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            printf("Enter book index: ");
            scanf("%d", &choice);
            readBook(choice - 1);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}