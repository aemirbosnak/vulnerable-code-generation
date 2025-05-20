//FormAI DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_PAGES 500

struct Book {
    char title[50];
    char author[50];
    int num_pages;
    char *pages[MAX_PAGES];
};

struct Book *books[MAX_BOOKS];
int num_books = 0;

void load_book(struct Book *book, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'.\n", filename);
        exit(1);
    }
    char line[256];
    char *page = NULL;
    int page_count = 0;
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#') {
            sscanf(line, "# %[^\n]", book->title);
        } else if (line[0] == '$') {
            sscanf(line, "$ %[^\n]", book->author);
        } else if (line[0] == '@') {
            book->num_pages = atoi(line + 1);
            page_count = 0;
        } else {
            size_t len = strlen(line);
            if (page == NULL) {
                page = malloc(len);
            } else {
                page = realloc(page, page_count * MAX_PAGES + len);
            }
            strncpy(page + page_count * MAX_PAGES, line, len);
            page_count++;
        }
    }
    fclose(file);
    for (int i = 0; i < book->num_pages; i++) {
        book->pages[i] = page + i * MAX_PAGES;
    }
}

void add_book(const char *filename) {
    if (num_books == MAX_BOOKS) {
        fprintf(stderr, "Error: maximum number of books reached.\n");
        return;
    }
    struct Book *book = malloc(sizeof(struct Book));
    load_book(book, filename);
    books[num_books] = book;
    num_books++;
}

void view_book(struct Book *book) {
    printf("Title: %s\nAuthor: %s\n\n", book->title, book->author);
    int page_num = 0;
    while (page_num < book->num_pages) {
        printf("%s", book->pages[page_num]);
        page_num++;
        if (page_num < book->num_pages) {
            printf("---Press Enter to Continue---\n");
            getchar();
        }
    }
}

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [book1.txt] [book2.txt] ...\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        add_book(argv[i]);
    }
    while (1) {
        printf("Enter Book Number (1-%d)\n", num_books);
        for (int i = 0; i < num_books; i++) {
            printf("%d. %s\n", i+1, books[i]->title);
        }
        char input[10];
        fgets(input, sizeof(input), stdin);
        int book_num = atoi(input);
        if (book_num > 0 && book_num <= num_books) {
            view_book(books[book_num-1]);
        }
    }
    return 0;
}