//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    int page_count;
};

struct EbookReader {
    struct Book* books;
    int num_books;
    int current_page;
};

void init_ebook_reader(struct EbookReader* reader) {
    reader->books = (struct Book*)malloc(sizeof(struct Book) * 100);
    reader->num_books = 0;
    reader->current_page = 0;
}

void add_book(struct EbookReader* reader, struct Book book) {
    if (reader->num_books >= 100) {
        printf("Ebook reader is full!\n");
        return;
    }

    reader->books[reader->num_books] = book;
    reader->num_books++;
}

void display_book_info(struct Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Page count: %d\n", book.page_count);
}

void display_ebook_reader_info(struct EbookReader reader) {
    printf("Books:\n");
    for (int i = 0; i < reader.num_books; i++) {
        display_book_info(reader.books[i]);
    }
    printf("Current page: %d\n", reader.current_page);
}

void next_page(struct EbookReader* reader) {
    if (reader->current_page < reader->books[reader->num_books - 1].page_count) {
        reader->current_page++;
    } else {
        printf("End of book!\n");
    }
}

void previous_page(struct EbookReader* reader) {
    if (reader->current_page > 0) {
        reader->current_page--;
    } else {
        printf("Start of book!\n");
    }
}

int main() {
    struct EbookReader reader;
    init_ebook_reader(&reader);

    struct Book book1 = {"The Great Gatsby", "F. Scott Fitzgerald", 200};
    struct Book book2 = {"To Kill a Mockingbird", "Harper Lee", 300};
    add_book(&reader, book1);
    add_book(&reader, book2);

    display_ebook_reader_info(reader);

    next_page(&reader);
    next_page(&reader);
    previous_page(&reader);

    return 0;
}