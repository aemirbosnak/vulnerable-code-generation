//FormAI DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1000
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

struct book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
};

void add_book(struct book *b, int *count);

void view_books(struct book *b, int count);

void search_books(struct book *b, int count);

int main() {
    struct book books[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        printf("\n1. Add a book\n2. View all books\n3. Search books\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_book(&books[count], &count); break;
            case 2: view_books(books, count); break;
            case 3: search_books(books, count); break;
            case 4: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid choice. Please try again.\n"); break;
        }

    } while (choice != 4);

    return 0;
}

void add_book(struct book *b, int *count) {
    if (*count < MAX_BOOKS) {
        printf("\nEnter the book's title: ");
        getchar();
        fgets(b->title, MAX_TITLE_LENGTH, stdin);
        b->title[strcspn(b->title, "\n")] = '\0';

        printf("Enter the book's author: ");
        fgets(b->author, MAX_AUTHOR_LENGTH, stdin);
        b->author[strcspn(b->author, "\n")] = '\0';

        printf("Enter the number of pages: ");
        scanf("%d", &b->pages);

        (*count)++;
        printf("\nBook added successfully!\n");
    }
    else {
        printf("\nYou have reached the maximum number of books that can be stored.\n");
    }
}

void view_books(struct book *b, int count) {
    if (count == 0) {
        printf("\nNo books to display.\n");
    }
    else {
        printf("\n%-20s%-30s%-10s\n", "Title", "Author", "Pages");
        printf("-----------------------------------------------------------\n");
        for (int i = 0; i < count; i++) {
            printf("%-20s%-30s%-10d\n", b[i].title, b[i].author, b[i].pages);
        }
    }
}

void search_books(struct book *b, int count) {
    if (count == 0) {
        printf("\nNo books to search.\n");
    }
    else {
        getchar();
        char search_term[MAX_TITLE_LENGTH];
        printf("\nEnter a search term: ");
        fgets(search_term, MAX_TITLE_LENGTH, stdin);
        search_term[strcspn(search_term, "\n")] = '\0';

        for (int i = 0; i < count; i++) {
            if (strstr(b[i].title, search_term) != NULL) {
                printf("\n%-20s%-30s%-10s\n", "Title", "Author", "Pages");
                printf("-----------------------------------------------------------\n");
                printf("%-20s%-30s%-10d\n", b[i].title, b[i].author, b[i].pages);
            }
        }
    }
}