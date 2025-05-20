//FormAI DATASET v1.0 Category: Ebook reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char title[MAX_NAME_LENGTH];
    char author[MAX_NAME_LENGTH];
    double price;
    int pages;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int num_books;
} Library;

void add_book(Library *lib) {
    if (lib->num_books == MAX_BOOKS) {
        printf("The library is full.\n");
        return;
    }
    Book book;
    printf("Enter the title of the book: ");
    scanf("%s", book.title);
    printf("Enter the author's name: ");
    scanf("%s", book.author);
    printf("Enter the price of the book: ");
    scanf("%lf", &book.price);
    printf("Enter the number of pages: ");
    scanf("%d", &book.pages);
    lib->books[lib->num_books] = book;
    lib->num_books++;
    printf("Book added successfully!\n");
}

void print_books(Library *lib) {
    printf("Title\t\tAuthor\t\tPrice\tPages\n");
    for (int i = 0; i < lib->num_books; i++) {
        printf("%s\t\t%s\t\t%.2lf\t%d\n", lib->books[i].title, lib->books[i].author, lib->books[i].price, lib->books[i].pages);
    }
}

int main() {
    Library lib = {0};
    int choice = 0;
    do {
        printf("\n1. Add a book\n2. Print all books\n3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book(&lib);
                break;
            case 2:
                print_books(&lib);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
    return 0;
}