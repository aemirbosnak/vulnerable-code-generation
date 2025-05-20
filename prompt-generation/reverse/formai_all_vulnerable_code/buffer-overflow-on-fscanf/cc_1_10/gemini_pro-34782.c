//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
struct Book {
    char *title;
    char *author;
    int num_pages;
    char *content;
};

// Create a new book
struct Book *create_book(char *title, char *author, int num_pages, char *content) {
    struct Book *book = malloc(sizeof(struct Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->content = strdup(content);
    return book;
}

// Free the memory allocated for a book
void free_book(struct Book *book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

// Print the information about a book
void print_book(struct Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Content:\n%s\n", book->content);
}

// Read a book from a file
struct Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    char *title = NULL;
    size_t title_len = 0;
    getline(&title, &title_len, fp);

    char *author = NULL;
    size_t author_len = 0;
    getline(&author, &author_len, fp);

    int num_pages;
    fscanf(fp, "%d\n", &num_pages);

    char *content = NULL;
    size_t content_len = 0;
    while (!feof(fp)) {
        char *line = NULL;
        size_t line_len = 0;
        getline(&line, &line_len, fp);
        if (line_len > 0) {
            content = realloc(content, content_len + line_len);
            memcpy(content + content_len, line, line_len);
            content_len += line_len;
        }
    }

    fclose(fp);

    return create_book(title, author, num_pages, content);
}

// Write a book to a file
void write_book(struct Book *book, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    fprintf(fp, "%s\n", book->title);
    fprintf(fp, "%s\n", book->author);
    fprintf(fp, "%d\n", book->num_pages);
    fprintf(fp, "%s", book->content);

    fclose(fp);
}

// Create a new ebook reader
struct EbookReader {
    struct Book *book;
    int current_page;
};

// Create a new ebook reader
struct EbookReader *create_ebook_reader(struct Book *book) {
    struct EbookReader *reader = malloc(sizeof(struct EbookReader));
    reader->book = book;
    reader->current_page = 1;
    return reader;
}

// Free the memory allocated for an ebook reader
void free_ebook_reader(struct EbookReader *reader) {
    free_book(reader->book);
    free(reader);
}

// Turn to a specific page in the book
void turn_to_page(struct EbookReader *reader, int page_number) {
    if (page_number < 1 || page_number > reader->book->num_pages) {
        fprintf(stderr, "Error: Page number out of range\n");
        return;
    }

    reader->current_page = page_number;
}

// Read the current page of the book
char *read_current_page(struct EbookReader *reader) {
    int start = (reader->current_page - 1) * 80;
    int end = start + 80;
    if (end > strlen(reader->book->content)) {
        end = strlen(reader->book->content);
    }
    return strndup(reader->book->content + start, end - start);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ebook file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct Book *book = read_book(argv[1]);
    if (book == NULL) {
        fprintf(stderr, "Error reading book: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    struct EbookReader *reader = create_ebook_reader(book);

    // Print the first page of the book
    char *page = read_current_page(reader);
    printf("%s\n", page);
    free(page);

    // Turn to the next page
    turn_to_page(reader, 2);

    // Print the second page of the book
    page = read_current_page(reader);
    printf("%s\n", page);
    free(page);

    // Free the memory allocated for the book and the ebook reader
    free_ebook_reader(reader);
    free_book(book);

    return EXIT_SUCCESS;
}