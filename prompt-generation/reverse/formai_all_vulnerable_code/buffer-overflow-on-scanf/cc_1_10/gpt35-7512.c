//FormAI DATASET v1.0 Category: Ebook reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 50
#define MAX_PAGES 2000

struct ebook {
    char title[50];
    char author[30];
    int num_pages;
    char content[MAX_PAGES];
};

struct ebook library[MAX_BOOKS];
int num_books = 0;
int current_book = 0;
int current_page = 1;

void read_ebook(char *filename, struct ebook *book) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fscanf(fp, "%s", book->title);
    fscanf(fp, "%s", book->author);
    fscanf(fp, "%d", &book->num_pages);
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF && i < MAX_PAGES) {
        book->content[i++] = c;
    }
    fclose(fp);
}

void add_book(char *filename) {
    if (num_books >= MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }
    struct ebook book;
    read_ebook(filename, &book);
    library[num_books] = book;
    num_books++;
    printf("%s has been added to the library.\n", book.title);
}

void display_book(struct ebook book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Number of pages: %d\n", book.num_pages);
    int start = (current_page - 1) * 80;
    for (int i = start; i < start + 80; i++) {
        printf("%c", book.content[i]);
    }
    printf("\n");
    printf("Page %d of %d\n", current_page, book.num_pages);
}

void next_page() {
    if (current_page < library[current_book].num_pages) {
        current_page++;
    } else {
        printf("End of book reached.\n");
    }
}

void prev_page() {
    if (current_page > 1) {
        current_page--;
    } else {
        printf("Beginning of book reached.\n");
    }
}

void display_menu() {
    printf("1. Add a book\n");
    printf("2. Select a book\n");
    printf("3. Display current page\n");
    printf("4. Next page\n");
    printf("5. Previous page\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter filename: ");
                char filename[50];
                scanf("%s", filename);
                add_book(filename);
                break;
            case 2:
                printf("Enter book number: ");
                int book_num;
                scanf("%d", &book_num);
                if (book_num < 1 || book_num > num_books) {
                    printf("Invalid book number.\n");
                } else {
                    current_book = book_num - 1;
                    current_page = 1;
                }
                break;
            case 3:
                display_book(library[current_book]);
                break;
            case 4:
                next_page();
                break;
            case 5:
                prev_page();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}