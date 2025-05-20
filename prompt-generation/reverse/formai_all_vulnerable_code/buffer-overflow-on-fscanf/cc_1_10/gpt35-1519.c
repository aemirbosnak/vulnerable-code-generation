//FormAI DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1000
#define MAX_PAGES 5000

struct book {
    char title[100];
    char author[100];
    int pages;
    char content[MAX_PAGES];
} books[MAX_BOOKS];

int num_books = 0;

void read_book(struct book* b, char* filename);
void add_book(char* title, char* author, char* filename);
void list_books();
void read_page(char* title, int page_num);

int main() {
    printf("Welcome to the Ebook Reader!\n");
    printf("Please choose an option:\n");
    printf("1. Add a book to the library\n");
    printf("2. List current books in library\n");
    printf("3. Read a book\n");
    printf("4. Quit\n");

    int option;
    scanf("%d", &option);

    while (option != 4) {
        switch (option) {
            case 1: {
                char title[100];
                char author[100];
                char filename[100];

                printf("Enter the book title: ");
                scanf("%s", title);
                printf("Enter the author name: ");
                scanf("%s", author);
                printf("Enter the filename: ");
                scanf("%s", filename);

                add_book(title, author, filename);
                break;
            }
            case 2:
                list_books();
                break;
            case 3: {
                char title[100];
                int page_num;

                printf("Enter the book title: ");
                scanf("%s", title);
                printf("Enter the page number: ");
                scanf("%d", &page_num);

                read_page(title, page_num);
                break;
            }
            default:
                printf("Invalid option. Please enter a number between 1 and 4.\n");
        }

        printf("Please choose an option:\n");
        printf("1. Add a book to the library\n");
        printf("2. List current books in library\n");
        printf("3. Read a book\n");
        printf("4. Quit\n");

        scanf("%d", &option);
    }

    printf("Thank you for using the Ebook Reader!\n");

    return 0;
}

void read_book(struct book* b, char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read metadata
    fscanf(fp, "Title: %[^\n]\n", b->title);
    fscanf(fp, "Author: %[^\n]\n", b->author);
    fscanf(fp, "Pages: %d\n", &b->pages);

    // Read content
    b->content[0] = '\0';
    char line[MAX_PAGES];
    while (fgets(line, sizeof(line), fp)) {
        strcat(b->content, line);
    }

    fclose(fp);
}

void add_book(char* title, char* author, char* filename) {
    if (num_books >= MAX_BOOKS) {
        printf("Maximum number of books reached. Please delete some books to make room.\n");
        return;
    }

    struct book* b = &books[num_books];
    strcpy(b->title, title);
    strcpy(b->author, author);
    read_book(b, filename);

    printf("Book added successfully!\n");

    num_books++;
}

void list_books() {
    printf("Current library:\n");
    for (int i = 0; i < num_books; i++) {
        struct book* b = &books[i];
        printf("%d. %s by %s (%d pages)\n", i+1, b->title, b->author, b->pages);
    }

    printf("\n");
}

void read_page(char* title, int page_num) {
    struct book* b = NULL;
    for (int i = 0; i < num_books; i++) {
        if (strcmp(title, books[i].title) == 0) {
            b = &books[i];
            break;
        }
    }

    if (b == NULL) {
        printf("Book not found.\n");
        return;
    }

    if (page_num < 1 || page_num > b->pages) {
        printf("Invalid page number. Please enter a number between 1 and %d.\n", b->pages);
        return;
    }

    printf("%s by %s\n", b->title, b->author);
    printf("Page %d of %d\n", page_num, b->pages);
    int start = (page_num - 1) * 1000;
    int end = (page_num * 1000) - 1;
    for (int i = start; i <= end && i < strlen(b->content); i++) {
        printf("%c", b->content[i]);
    }

    printf("\n");
}