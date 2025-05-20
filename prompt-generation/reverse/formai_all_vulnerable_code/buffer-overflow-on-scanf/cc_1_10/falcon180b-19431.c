//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define MAX_PAGES 1000

struct book {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;
};

void addBook(struct book *books, int numBooks, char *title, char *author, int pages) {
    if (numBooks >= MAX_BOOKS) {
        printf("Error: Too many books\n");
        return;
    }
    strcpy(books[numBooks].title, title);
    strcpy(books[numBooks].author, author);
    books[numBooks].pages = pages;
    numBooks++;
}

int main() {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;
    int numBooks = 0;
    struct book books[MAX_BOOKS];

    // Add some books
    addBook(books, numBooks, "The Great Gatsby", "F. Scott Fitzgerald", 180);
    addBook(books, numBooks, "To Kill a Mockingbird", "Harper Lee", 281);
    addBook(books, numBooks, "1984", "George Orwell", 328);

    printf("Number of books: %d\n", numBooks);
    for (int i = 0; i < numBooks; i++) {
        printf("Book %d:\n", i+1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n\n", books[i].pages);
    }

    // Search for a book by title
    printf("Enter a title to search for:\n");
    scanf("%s", title);
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Pages: %d\n", books[i].pages);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found\n");
    }

    return 0;
}