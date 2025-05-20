//FormAI DATASET v1.0 Category: Ebook reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_FILENAME_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int num_pages;
} Book;

int num_books = 0;
Book books[MAX_BOOKS];

void add_book() {
    if (num_books < MAX_BOOKS) {
        Book book;
        printf("Enter the title of the book: ");
        scanf("%s", book.title);
        printf("Enter the author of the book: ");
        scanf("%s", book.author);
        printf("Enter the number of pages in the book: ");
        scanf("%d", &book.num_pages);
        books[num_books++] = book;
        printf("Book added successfully!\n");
    } else {
        printf("Error: bookshelf is full.\n");
    }
}

void list_books() {
    printf("Title                      Author             Pages\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_books; i++) {
        printf("%-25s%-20s%-6d\n", books[i].title, books[i].author, books[i].num_pages);
    }
    printf("\n");
}

void read_book(char* title) {
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            char filename[MAX_FILENAME_LENGTH];
            snprintf(filename, MAX_FILENAME_LENGTH, "%s.txt", title);
            FILE* file = fopen(filename, "r");
            if (file) {
                char line[256];
                while (fgets(line, sizeof(line), file)) {
                    printf("%s", line);
                }
                fclose(file);
            } else {
                printf("Error: could not open file.\n");
            }
            return;
        }
    }
    printf("Error: book not found.\n");
}

int main() {
    int choice = 0;
    do {
        printf("1. Add book\n");
        printf("2. List books\n");
        printf("3. Read book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 3: {
                char title[MAX_TITLE_LENGTH];
                printf("Enter the title of the book you want to read: ");
                scanf("%s", title);
                read_book(title);
                break;
            }
            case 4:
                break;
            default:
                printf("Error: invalid choice.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}