//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char title[100];
    char author[50];
    char content[10000];
    int pages;
} Book;

typedef struct {
    Book book;
    int current_page;
} Reader;

void turn_page(Reader* reader) {
    if (reader->current_page < reader->book.pages - 1) {
        reader->current_page++;
    }
}

int main() {
    srand(time(NULL));

    Book my_book = {"The Time Machine", "H.G. Wells", "", 225};
    Reader reader = {my_book, 0};

    puts("Welcome to the CEbook reader!");
    puts("Solving this riddle will allow you to read a book...");
    puts("What has keys but can't open locks?");

    char answer[10];
    scanf("%s", answer);

    if (strcmp(answer, "piano") != 0) {
        puts("Sorry, that's not correct. Try again.");
        main();
    }

    while (reader.current_page < reader.book.pages) {
        int page_size = rand() % 50 + 50;
        char page[page_size];

        sprintf(page, "%s %d\n%s\n", "Once upon a time...", reader.current_page + 1, reader.book.content + reader.current_page * 50);

        printf("%s\n", page);
        turn_page(&reader);
    }

    puts("Congratulations! You have finished reading the book.");

    return 0;
}