//FormAI DATASET v1.0 Category: Ebook reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    int pages;
    double price;
};

typedef struct Book Book;

int main() {
    FILE *fp;
    Book book;
    char filename[50], option;
    int num_books = 0, i;

    printf("Enter the name of the file to open: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: cannot open file!\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    num_books = ftell(fp) / sizeof(Book);
    fseek(fp, 0, SEEK_SET);

    printf("There are %d books in the file.\n", num_books);
    printf("Do you want to view the list of books? (y/n): ");
    scanf(" %c", &option);

    if (option == 'y') {
        for (i = 0; i < num_books; i++) {
            fread(&book, sizeof(Book), 1, fp);
            printf("%d. Title: %s\n", i+1, book.title);
            printf("   Author: %s\n", book.author);
            printf("   Pages: %d\n", book.pages);
            printf("   Price: $%.2lf\n", book.price);
        }
    }

    fclose(fp);
    return 0;
}