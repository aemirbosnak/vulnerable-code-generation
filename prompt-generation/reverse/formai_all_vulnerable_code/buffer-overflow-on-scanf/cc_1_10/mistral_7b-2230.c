//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 100
#define MAX_PAGE 20
#define MAX_BOOKS 5

typedef struct {
    char title[50];
    char author[50];
    char content[MAX_LINE * MAX_PAGE];
    int page;
} Book;

void print_menu() {
    printf("\nCEbook Reader\n");
    printf("1. Load book\n");
    printf("2. Save book\n");
    printf("3. Read book\n");
    printf("4. Quit\n");
}

void load_book(Book *book, char *filename) {
    FILE *fp;
    char line[MAX_LINE];
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading file %s\n", filename);
        return;
    }

    fgets(book->title, sizeof(book->title), fp);
    fgets(book->author, sizeof(book->author), fp);

    while (fgets(line, sizeof(line), fp) && i < MAX_PAGE * MAX_LINE) {
        strcat(book->content, line);
        i++;
    }

    fclose(fp);
    book->page = i / MAX_LINE;
}

void save_book(Book *book, char *filename) {
    FILE *fp;
    int i;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error saving file %s\n", filename);
        return;
    }

    fprintf(fp, "%s\n%s\n", book->title, book->author);
    for (i = 0; i < book->page * MAX_LINE; i += MAX_LINE) {
        fprintf(fp, "%.*s\n", MAX_LINE, book->content + i);
    }

    fclose(fp);
}

void print_book(Book *book) {
    printf("\nTitle: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Page: %d\n", book->page);

    int i;
    for (i = 0; i < book->page * MAX_LINE; i += MAX_LINE) {
        printf("%.*s\n", MAX_LINE, book->content + i);
    }
}

int main() {
    Book books[MAX_BOOKS];
    char filename[50];
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book filename: ");
                scanf("%s", filename);
                load_book(&books[0], filename);
                break;
            case 2:
                printf("Enter book filename to save: ");
                scanf("%s", filename);
                save_book(&books[0], filename);
                break;
            case 3:
                print_book(&books[0]);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}