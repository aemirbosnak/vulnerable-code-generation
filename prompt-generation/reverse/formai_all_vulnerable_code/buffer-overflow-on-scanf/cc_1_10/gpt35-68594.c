//FormAI DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGES 100
#define MAX_PAGE_SIZE 10000

typedef struct Page {
    char content[MAX_PAGE_SIZE];
} Page;

typedef struct Ebook {
    char title[100];
    char author[50];
    Page pages[MAX_PAGES];
    int current_page;
    int num_pages;
} Ebook;

void display_current_page(Ebook *book) {
    printf("%s - %s\n\n", book->title, book->author);
    printf("Page %d of %d\n\n", book->current_page + 1, book->num_pages);
    printf("%s\n\n", book->pages[book->current_page].content);
}

void go_to_next_page(Ebook *book) {
    book->current_page++;
    if (book->current_page >= book->num_pages) {
        book->current_page = book->num_pages - 1;
    }
}

void go_to_prev_page(Ebook *book) {
    book->current_page--;
    if (book->current_page < 0) {
        book->current_page = 0;
    }
}

int main() {
    FILE *file;
    Ebook book;
    char filename[100];
    char buffer[MAX_PAGE_SIZE];
    int i;

    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    i = 0;
    while (fgets(buffer, MAX_PAGE_SIZE, file) != NULL) {
        if (i == 0) {
            sscanf(buffer, "%s by %s", book.title, book.author);
        } else {
            strcpy(book.pages[i - 1].content, buffer);
        }
        i++;
    }
    book.num_pages = i - 1;
    book.current_page = 0;

    while (1) {
        display_current_page(&book);
        printf("Press n to go to the next page, or p to go to the previous page. Press q to quit.\n");
        char c = getchar();
        while ((getchar()) != '\n'); // Clear input buffer
        if (c == 'n') {
            go_to_next_page(&book);
        } else if (c == 'p') {
            go_to_prev_page(&book);
        } else if (c == 'q') {
            break;
        }
    }

    fclose(file);
    return 0;
}