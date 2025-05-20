//FormAI DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 30

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;
    double price;
} Book;

Book books[MAX_BOOKS];
int num_books = 0;

void display_menu() {
    printf("E-Book Reader\n");
    printf("1. Add Book\n");
    printf("2. Display All Books\n");
    printf("3. Search Book\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("No more space for books.\n");
        return;
    }
    printf("Enter book title: ");
    fgets(books[num_books].title, MAX_TITLE_LEN, stdin);
    books[num_books].title[strcspn(books[num_books].title, "\n")] = '\0';
    printf("Enter book author: ");
    fgets(books[num_books].author, MAX_AUTHOR_LEN, stdin);
    books[num_books].author[strcspn(books[num_books].author, "\n")] = '\0';
    printf("Enter number of pages: ");
    scanf("%d", &books[num_books].pages);
    printf("Enter price: $");
    scanf("%lf", &books[num_books].price);
    num_books++;
}

void display_all_books() {
    if (num_books == 0) {
        printf("No books found.\n");
        return;
    }
    printf("Title\t\tAuthor\t\tPages\tPrice\n");
    for (int i = 0; i < num_books; i++) {
        printf("%s\t%s\t%d\t$%.2lf\n", books[i].title, books[i].author, books[i].pages, books[i].price);
    }
}

void search_book() {
    char title[MAX_TITLE_LEN];
    printf("Enter book title to search: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = '\0';
    for (int i = 0; i < num_books; i++) {
        if (strcmp(title, books[i].title) == 0) {
            printf("%s\t%s\t%d\t%.2lf\n", books[i].title, books[i].author, books[i].pages, books[i].price);
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_all_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}