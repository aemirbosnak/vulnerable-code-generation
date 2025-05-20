//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 80
#define MAX_WORD_LENGTH 20

typedef struct {
    char *name;
    int page_count;
    char *pages[MAX_LINE_LENGTH];
} Book;

void read_book(FILE *fp, Book *book) {
    char line[MAX_LINE_LENGTH];
    int page_count = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        int line_length = strlen(line);
        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[--line_length] = '\0';
        }
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (strlen(word) > MAX_WORD_LENGTH) {
                printf("Error: Word '%s' is too long.\n", word);
                exit(1);
            }
            if (page_count >= MAX_LINE_LENGTH) {
                printf("Error: Page '%s' is too long.\n", book->pages[page_count - 1]);
                exit(1);
            }
            strcpy(book->pages[page_count], word);
            page_count++;
            word = strtok(NULL, ",.?!;:");
        }
    }
    book->page_count = page_count;
}

void print_book(Book *book) {
    printf("Book name: %s\n", book->name);
    printf("Page count: %d\n", book->page_count);
    for (int i = 0; i < book->page_count; i++) {
        printf("Page %d: %s\n", i + 1, book->pages[i]);
    }
}

int main() {
    Book book;
    char filename[MAX_LINE_LENGTH];
    printf("Enter book name: ");
    scanf("%s", book.name);
    printf("Enter book filename: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File '%s' not found.\n", filename);
        exit(1);
    }
    read_book(fp, &book);
    fclose(fp);
    print_book(&book);
    return 0;
}