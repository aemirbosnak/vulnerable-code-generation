//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_BOOK_NAME_LEN 100
#define MAX_BOOK_AUTHOR_LEN 100
#define MAX_BOOK_GENRE_LEN 50
#define MAX_BOOK_PUBLISHER_LEN 100
#define MAX_BOOK_DESCRIPTION_LEN 500

typedef struct {
    char book_name[MAX_BOOK_NAME_LEN];
    char book_author[MAX_BOOK_AUTHOR_LEN];
    char book_genre[MAX_BOOK_GENRE_LEN];
    char book_publisher[MAX_BOOK_PUBLISHER_LEN];
    char book_description[MAX_BOOK_DESCRIPTION_LEN];
} book_t;

int main() {
    int num_books;
    book_t books[MAX_BOOKS];
    FILE *fp;
    char filename[100];
    int i, j;

    printf("Enter the number of books: ");
    scanf("%d", &num_books);

    for (i = 0; i < num_books; i++) {
        printf("Enter the name of book %d: ", i + 1);
        scanf("%s", books[i].book_name);
        printf("Enter the author of book %d: ", i + 1);
        scanf("%s", books[i].book_author);
        printf("Enter the genre of book %d: ", i + 1);
        scanf("%s", books[i].book_genre);
        printf("Enter the publisher of book %d: ", i + 1);
        scanf("%s", books[i].book_publisher);
        printf("Enter the description of book %d: ", i + 1);
        scanf("%[^\n]", books[i].book_description);
    }

    printf("Enter the filename to save the data: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    for (i = 0; i < num_books; i++) {
        fprintf(fp, "Book %d:\n", i + 1);
        fprintf(fp, "Name: %s\n", books[i].book_name);
        fprintf(fp, "Author: %s\n", books[i].book_author);
        fprintf(fp, "Genre: %s\n", books[i].book_genre);
        fprintf(fp, "Publisher: %s\n", books[i].book_publisher);
        fprintf(fp, "Description: %s\n\n", books[i].book_description);
    }

    fclose(fp);

    printf("Data saved to file %s\n", filename);

    return 0;
}