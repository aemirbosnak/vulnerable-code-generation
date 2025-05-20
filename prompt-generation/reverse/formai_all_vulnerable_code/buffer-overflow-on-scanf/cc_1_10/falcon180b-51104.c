//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_PAGES 1000
#define MAX_WORDS 10000

typedef struct {
    char title[50];
    char author[50];
    int pages;
    char content[MAX_WORDS][100];
} Book;

void read_book(Book *book) {
    FILE *fp;
    char ch;
    int i = 0;
    int j = 0;
    fp = fopen("book.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            book->content[i][j] = '\0';
            i++;
            j = 0;
        } else {
            if (j >= 99) {
                printf("Error: Line too long\n");
                exit(1);
            }
            book->content[i][j++] = ch;
        }
    }
    book->content[i][j] = '\0';
    fclose(fp);
}

int main() {
    Book library[MAX_BOOKS];
    int num_books = 0;
    char filename[50];
    int choice;
    do {
        printf("Ebook Reader\n");
        printf("1. Read book\n");
        printf("2. Add book\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter book filename: ");
                scanf("%s", filename);
                read_book(&library[num_books]);
                printf("Book added to library\n");
                num_books++;
                break;
            case 2:
                printf("Enter book filename: ");
                scanf("%s", filename);
                if (num_books >= MAX_BOOKS) {
                    printf("Library is full\n");
                } else {
                    read_book(&library[num_books]);
                    printf("Book added to library\n");
                    num_books++;
                }
                break;
            case 3:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 3);
    return 0;
}