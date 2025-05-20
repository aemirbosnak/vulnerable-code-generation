//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_CATEGORY 100

struct book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char category[MAX_CATEGORY];
    int isbn;
    int page_count;
};

struct book books[MAX_BOOKS];

int book_count = 0;

void add_book(const char* title, const char* author, const char* category, int isbn, int page_count) {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full, cannot add any more books.\n");
        return;
    }

    struct book new_book = {
       .title = title,
       .author = author,
       .category = category,
       .isbn = isbn,
       .page_count = page_count,
    };

    books[book_count] = new_book;
    book_count++;
}

void remove_book(int index) {
    if (index < 0 || index >= book_count) {
        printf("Invalid index, cannot remove book.\n");
        return;
    }

    for (int i = index; i < book_count - 1; i++) {
        books[i] = books[i + 1];
    }

    book_count--;
}

void search_by_title(const char* title) {
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book found with title '%s'.\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Category: %s\n", books[i].category);
            printf("ISBN: %d\n", books[i].isbn);
            printf("Pages: %d\n", books[i].page_count);
            return;
        }
    }

    printf("Book not found.\n");
}

void search_by_author(const char* author) {
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].author, author) == 0) {
            printf("Book found with author '%s'.\n", books[i].author);
            printf("Title: %s\n", books[i].title);
            printf("Category: %s\n", books[i].category);
            printf("ISBN: %d\n", books[i].isbn);
            printf("Pages: %d\n", books[i].page_count);
            return;
        }
    }

    printf("Author not found.\n");
}

void search_by_category(const char* category) {
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].category, category) == 0) {
            printf("Book found with category '%s'.\n", books[i].category);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("ISBN: %d\n", books[i].isbn);
            printf("Pages: %d\n", books[i].page_count);
            return;
        }
    }

    printf("Category not found.\n");
}

int main() {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char category[MAX_CATEGORY];
    int isbn;
    int page_count;

    printf("Enter book details: \n");
    printf("Title: ");
    scanf("%s", title);
    printf("Author: ");
    scanf("%s", author);
    printf("Category: ");
    scanf("%s", category);
    printf("ISBN: ");
    scanf("%d", &isbn);
    printf("Pages: ");
    scanf("%d", &page_count);

    add_book(title, author, category, isbn, page_count);

    printf("\nSearch by title:\n");
    printf("Enter title: ");
    scanf("%s", title);
    search_by_title(title);

    printf("\nSearch by author:\n");
    printf("Enter author: ");
    scanf("%s", author);
    search_by_author(author);

    printf("\nSearch by category:\n");
    printf("Enter category: ");
    scanf("%s", category);
    search_by_category(category);

    printf("\nRemove book #1:\n");
    remove_book(0);

    printf("\nSearch by title (after removing book #1):\n");
    printf("Enter title: ");
    scanf("%s", title);
    search_by_title(title);

    return 0;
}