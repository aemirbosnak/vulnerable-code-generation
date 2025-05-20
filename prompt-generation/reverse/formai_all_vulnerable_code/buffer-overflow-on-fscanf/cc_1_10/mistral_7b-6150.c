//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    char* content;
    int pages;
} Book;

void print_book(Book b) {
    printf("\n%s by %s\n", b.title, b.author);
    printf("Pages: %d\n", b.pages);
    int i;
    for (i = 0; i < b.pages; i++) {
        printf("%s\n", *(b.content + i * 80));
    }
}

void load_book(Book* b, char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    fscanf(fp, "%s %s %d", b->title, b->author, &b->pages);
    b->content = (char*) malloc(b->pages * 80 * sizeof(char));

    for (int i = 0; i < b->pages; i++) {
        fgets((b->content + i * 80), 81, fp);
    }

    fclose(fp);
}

int main() {
    Book my_book;
    char filename[100];

    printf("\nEnter book filename: ");
    scanf("%s", filename);

    load_book(&my_book, filename);
    print_book(my_book);

    free(my_book.content);
    return 0;
}