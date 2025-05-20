//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_BOOK_NAME_LENGTH 50
#define MAX_BOOK_AUTHOR_LENGTH 50

typedef struct {
    char book_name[MAX_BOOK_NAME_LENGTH];
    char book_author[MAX_BOOK_AUTHOR_LENGTH];
    char book_content[1000000];
} EBook;

int main() {
    EBook books[MAX_BOOKS];
    int num_books = 0;
    char filename[MAX_BOOK_NAME_LENGTH];

    printf("Enter the name of the eBook file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fscanf(fp, "Book Name: %s\nAuthor: %s\n", books[num_books].book_name, books[num_books].book_author)!= EOF) {
        char c;
        int i = 0;
        while ((c = fgetc(fp))!= '\n') {
            books[num_books].book_content[i++] = c;
        }
        books[num_books].book_content[i] = '\0';
        num_books++;
    }

    fclose(fp);

    printf("Number of eBooks: %d\n", num_books);

    for (int i = 0; i < num_books; i++) {
        printf("Book Name: %s\nAuthor: %s\n\n", books[i].book_name, books[i].book_author);
        printf("%s", books[i].book_content);
    }

    return 0;
}