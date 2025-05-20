//FormAI DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>

struct ebook {
    char title[50];
    char author[50];
    int pages;
};

typedef struct ebook Ebook;

void display(Ebook book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Number of Pages: %d\n", book.pages);
}

void display_all(Ebook books[], int num_books) {
    for (int i = 0; i < num_books; i++) {
        display(books[i]);
        printf("\n");
    }
}

void search(Ebook books[], int num_books, char term[]) {
    for (int i = 0; i < num_books; i++) {
        if (strstr(books[i].title, term) != NULL || strstr(books[i].author, term) != NULL) {
            display(books[i]);
            printf("\n");
        }
    }
}

int main() {
    int num_books;
    printf("How many ebooks do you have?\n");
    scanf("%d", &num_books);
    Ebook *books = (Ebook*)malloc(num_books * sizeof(Ebook));

    for (int i = 0; i < num_books; i++) {
        printf("Ebook #%d:\n", i + 1);
        printf("Enter title: ");
        scanf("%s", books[i].title);
        printf("Enter author: ");
        scanf("%s", books[i].author);
        printf("Enter number of pages: ");
        scanf("%d", &books[i].pages);
        printf("\n");
    }

    printf("Your ebooks:\n");
    display_all(books, num_books);

    char term[50];
    printf("Enter a search term: ");
    scanf("%s", term);
    printf("Results for \"%s\":\n", term);
    search(books, num_books, term);

    free(books);
    return 0;
}