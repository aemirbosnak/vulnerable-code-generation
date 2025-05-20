//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_WORDS 1000

typedef struct {
    char title[50];
    char author[50];
    char content[MAX_WORDS][50];
    int num_words;
} Book;

void read_book(Book* book) {
    FILE* fp = fopen("book.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(fp, "%s %s", book->title, book->author);
    int i = 0;
    while (fscanf(fp, "%s", book->content[i])!= EOF) {
        i++;
        if (i >= MAX_WORDS) {
            printf("Error: too many words in book.\n");
            exit(1);
        }
    }
    book->num_words = i;

    fclose(fp);
}

void print_book(Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of words: %d\n", book->num_words);

    for (int i = 0; i < book->num_words; i++) {
        printf("%s ", book->content[i]);
    }
    printf("\n");
}

int main() {
    Book books[MAX_BOOKS];
    int num_books = 0;

    while (num_books < MAX_BOOKS) {
        printf("Enter book title: ");
        scanf("%s", books[num_books].title);

        printf("Enter book author: ");
        scanf("%s", books[num_books].author);

        read_book(&books[num_books]);
        num_books++;
    }

    int choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Print all books\n");
        printf("2. Print a specific book\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            for (int i = 0; i < num_books; i++) {
                print_book(&books[i]);
            }
            break;
        case 2:
            printf("Enter book number: ");
            scanf("%d", &choice);
            if (choice >= 0 && choice < num_books) {
                print_book(&books[choice]);
            } else {
                printf("Invalid book number.\n");
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}