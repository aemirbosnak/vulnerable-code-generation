//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define MAX_CONTENTS_LEN 1000

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char contents[MAX_CONTENTS_LEN];
} Book;

int num_books = 0;
Book books[MAX_BOOKS];

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("Error: Maximum number of books reached.\n");
        return;
    }

    printf("Enter title: ");
    scanf("%s", books[num_books].title);

    printf("Enter author: ");
    scanf("%s", books[num_books].author);

    printf("Enter contents:\n");
    char line[MAX_CONTENTS_LEN];
    while (fgets(line, MAX_CONTENTS_LEN, stdin)!= NULL) {
        strcat(books[num_books].contents, line);
    }
    strcat(books[num_books].contents, "\n");

    num_books++;
}

void read_book(int index) {
    if (index >= num_books || index < 0) {
        printf("Error: Invalid book index.\n");
        return;
    }

    printf("Title: %s\n", books[index].title);
    printf("Author: %s\n", books[index].author);
    printf("Contents:\n%s", books[index].contents);
}

int main() {
    int choice, index;

    while (1) {
        printf("Ebook Reader\n");
        printf("1. Add book\n");
        printf("2. Read book\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_book();
            break;
        case 2:
            printf("Enter book index: ");
            scanf("%d", &index);
            read_book(index);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}