//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_BOOK_LENGTH 10000

typedef struct {
    char title[MAX_BOOK_LENGTH];
    char author[MAX_BOOK_LENGTH];
    char description[MAX_BOOK_LENGTH];
    char content[MAX_BOOK_LENGTH];
} Book;

int main() {
    Book book;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int line_number = 0;
    int word_count = 0;
    FILE *file;

    printf("Enter the name of the book: ");
    scanf("%s", book.title);

    printf("Enter the author of the book: ");
    scanf("%s", book.author);

    printf("Enter the description of the book: ");
    scanf("%s", book.description);

    file = fopen("book.txt", "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_number++;
        word_count = 0;
        char *word_start = line;

        while ((word_start = strtok(word_start, " "))!= NULL) {
            strcpy(word, word_start);
            word_count++;

            if (word_count == 1) {
                strcpy(book.content, word);
            } else {
                strcat(book.content, " ");
                strcat(book.content, word);
            }
        }

        strcat(book.content, "\n");
    }

    fclose(file);

    printf("Book Title: %s\n", book.title);
    printf("Book Author: %s\n", book.author);
    printf("Book Description: %s\n", book.description);
    printf("Book Content:\n%s", book.content);

    return 0;
}