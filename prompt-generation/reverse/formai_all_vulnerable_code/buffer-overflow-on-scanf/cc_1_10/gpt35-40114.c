//FormAI DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int num_pages;
} book;

book library[MAX_BOOKS];
int num_books = 0;

void add_book() {
    book new_book;

    printf("Enter the title of the book: ");
    fgets(new_book.title, MAX_TITLE_LENGTH, stdin);

    printf("Enter the author of the book: ");
    fgets(new_book.author, MAX_AUTHOR_LENGTH, stdin);

    printf("Enter the number of pages in the book: ");
    scanf("%d", &new_book.num_pages);
    getchar(); // remove newline character from buffer

    if (num_books < MAX_BOOKS) {
        library[num_books] = new_book;
        num_books++;
        printf("Book added to library.\n");
    } else {
        printf("Error: Library is full!\n");
    }
}

void list_books() {
    printf("%-30s%-20s%-10s\n", "Title", "Author", "Pages");
    for (int i = 0; i < num_books; i++) {
        printf("%-30s%-20s%-10d\n", library[i].title, library[i].author, library[i].num_pages);
    }
}

int main() {
    int choice = 0;
    while (choice != 3) {
        printf("1. Add book to library\n");
        printf("2. List all books in library\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // remove newline character from buffer

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 3:
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}