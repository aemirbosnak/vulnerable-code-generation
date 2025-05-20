//FormAI DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct page {
    int number;
    char content[1000];
    struct page *next;
};

struct book {
    char title[50];
    char author[50];
    int pages_count;
    struct page *pages;
};

int main() {
    struct book my_book;
    printf("Enter book title: ");
    scanf("%s", my_book.title);
    printf("Enter book author: ");
    scanf("%s", my_book.author);
    printf("Enter number of pages: ");
    scanf("%d", &my_book.pages_count);

    // Allocate memory for all pages
    my_book.pages = (struct page *) malloc(sizeof(struct page) * my_book.pages_count);

    // Populate contents for all pages
    for (int i = 0; i < my_book.pages_count; i++) {
        my_book.pages[i].number = i+1;
        printf("Enter content for page %d: ", i+1);
        getchar();
        fgets(my_book.pages[i].content, 1000, stdin);
        my_book.pages[i].next = (i == my_book.pages_count-1) ? NULL : &my_book.pages[i+1];
    }

    // Print all contents of book
    printf("Book Title: %s\n", my_book.title);
    printf("Book Author: %s\n", my_book.author);
    printf("Number of Pages: %d\n\n", my_book.pages_count);
    printf("Contents:\n\n");

    struct page *current_page = &my_book.pages[0];

    while (current_page != NULL) {
        printf("Page %d:\n", current_page->number);
        printf("%s\n", current_page->content);
        current_page = current_page->next;
    }

    // Free allocated memory
    free(my_book.pages);

    return 0;
}