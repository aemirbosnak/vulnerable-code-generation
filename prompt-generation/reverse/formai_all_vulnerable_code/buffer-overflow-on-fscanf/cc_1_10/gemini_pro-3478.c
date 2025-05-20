//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Represents a single page in the eBook
typedef struct page {
    char *text;
    int word_count;
    int line_count;
} page;

// Represents the entire eBook
typedef struct ebook {
    char *title;
    char *author;
    int num_pages;
    page *pages;
} ebook;

// Creates a new eBook object
ebook *new_ebook(char *title, char *author, int num_pages) {
    ebook *book = malloc(sizeof(ebook));
    book->title = title;
    book->author = author;
    book->num_pages = num_pages;
    book->pages = malloc(sizeof(page) * num_pages);
    return book;
}

// Frees the memory allocated for an eBook object
void free_ebook(ebook *book) {
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i].text);
    }
    free(book->pages);
    free(book->title);
    free(book->author);
    free(book);
}

// Loads an eBook from a text file
ebook *load_ebook(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the title and author
    char title[100];
    char author[100];
    fscanf(fp, "%s %s", title, author);

    // Read the number of pages
    int num_pages;
    fscanf(fp, "%d", &num_pages);

    // Create a new eBook object
    ebook *book = new_ebook(title, author, num_pages);

    // Read each page of the eBook
    for (int i = 0; i < num_pages; i++) {
        // Read the text of the page
        char text[10000];
        fscanf(fp, "%s", text);

        // Count the number of words and lines in the page
        int word_count = 0;
        int line_count = 0;
        for (int j = 0; j < strlen(text); j++) {
            if (text[j] == ' ') {
                word_count++;
            }
            if (text[j] == '\n') {
                line_count++;
            }
        }

        // Create a new page object
        page page = {text, word_count, line_count};

        // Add the page to the eBook
        book->pages[i] = page;
    }

    fclose(fp);
    return book;
}

// Prints the details of an eBook
void print_ebook(ebook *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d:\n", i + 1);
        printf("Text: %s\n", book->pages[i].text);
        printf("Word count: %d\n", book->pages[i].word_count);
        printf("Line count: %d\n", book->pages[i].line_count);
    }
}

int main() {
    // Load an eBook from a text file
    ebook *book = load_ebook("book.txt");

    // Print the details of the eBook
    print_ebook(book);

    // Free the memory allocated for the eBook
    free_ebook(book);

    return 0;
}