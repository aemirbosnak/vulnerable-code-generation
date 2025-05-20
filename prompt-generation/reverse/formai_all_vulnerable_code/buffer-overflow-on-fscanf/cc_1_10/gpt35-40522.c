//FormAI DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 30
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;
} Book;

void read_books(int *num_books, Book *books);
void print_books(int num_books, Book *books);
void select_book(int num_books, Book *books);

int main() {
    int num_books = 0;
    Book books[MAX_BOOKS];

    read_books(&num_books, books);
    print_books(num_books, books);

    select_book(num_books, books);

    return 0;
}

void read_books(int *num_books, Book *books) {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;

    // Read books from file or user input
    FILE *fp = fopen("books.txt", "r");
    if (fp == NULL) {
        printf("Enter the number of books: ");
        scanf("%d", num_books);

        for (int i = 0; i < *num_books; i++) {
            printf("Enter the title of book %d: ", i+1);
            scanf("%s", title);
            printf("Enter the author of book %d: ", i+1);
            scanf("%s", author);
            printf("Enter the number of pages of book %d: ",i+1);
            scanf("%d", &pages);

            // Add book to array
            strcpy(books[i].title, title);
            strcpy(books[i].author, author);
            books[i].pages = pages;
        }
    } else {
        // Read books from file
        while (fscanf(fp, "%s %s %d", title, author, &pages) != EOF && *num_books < MAX_BOOKS) {
            // Add book to array
            strcpy(books[*num_books].title, title);
            strcpy(books[*num_books].author, author);
            books[*num_books].pages = pages;
            (*num_books)++;
        }
        fclose(fp);
    }
}

void print_books(int num_books, Book *books) {
    printf("\nList of books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s (%d pages)\n", i+1, books[i].title, books[i].author, books[i].pages);
    }
}

void select_book(int num_books, Book *books) {
    int choice;
    printf("\nEnter the number of the book you want to read: ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= num_books) {
        // Open book file and display contents
        char filename[MAX_TITLE_LEN + MAX_AUTHOR_LEN + 10];
        sprintf(filename, "%s - %s.txt", books[choice-1].title, books[choice-1].author);

        FILE *fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error opening file.\n");
        } else {
            // Read and display file contents
            int c;
            while ((c = getc(fp)) != EOF) {
              putchar(c);
            }
            fclose(fp);
        }
    } else {
        printf("Invalid book choice.\n");
    }
}