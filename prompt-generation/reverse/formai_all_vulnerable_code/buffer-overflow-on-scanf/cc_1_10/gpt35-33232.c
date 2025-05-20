//FormAI DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct book {
    char title[50];
    char author[50];
    int year;
    char file_name[50];
};

struct book_list {
    struct book *books;
    int num_books;
};

void read_data(struct book_list *library) {
    FILE *fp = fopen("bookdata.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    int num_books = 0;
    while (!feof(fp)) {
        char ch = fgetc(fp);
        if (ch == '\n') {
            num_books++;
        }
    }
    rewind(fp);
    library->num_books = num_books;
    library->books = calloc(num_books, sizeof(struct book));

    for (int i = 0; i < num_books; i++) {
        fscanf(fp, "%[^\n]\n", library->books[i].title);
        fscanf(fp, "%[^\n]\n", library->books[i].author);
        fscanf(fp, "%d\n", &library->books[i].year);
        fscanf(fp, "%[^\n]\n", library->books[i].file_name);
    }

    fclose(fp);
}

void print_library(struct book_list *library) {
    printf("Title\t\tAuthor\t\tYear\t\tFile Name\n");
    for (int i = 0; i < library->num_books; i++) {
        printf("%s\t%s\t%d\t%s\n", library->books[i].title, library->books[i].author, library->books[i].year,
               library->books[i].file_name);
    }
}

void display_book(struct book *book) {
    FILE *fp = fopen(book->file_name, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    printf("%s\n\n", book->title);

    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);
}

int main() {
    struct book_list library;

    read_data(&library);
    print_library(&library);

    int selection;
    do {
        printf("\nEnter the number of the book you want to read, or enter 0 to exit: ");
        scanf("%d", &selection);

        if (selection > 0 && selection <= library.num_books) {
            display_book(&library.books[selection - 1]);
        } else if (selection != 0) {
            printf("Invalid selection.\n");
        }
    } while (selection != 0);

    return 0;
}