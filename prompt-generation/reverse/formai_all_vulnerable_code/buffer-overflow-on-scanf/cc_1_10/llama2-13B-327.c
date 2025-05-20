//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOOK_COUNT 10
#define CHAPTER_COUNT 5
#define PAGE_COUNT 20

typedef struct {
    char title[50];
    char author[50];
    int pages;
} book_t;

book_t books[BOOK_COUNT] = {
    {"The Great Gatsby", "F. Scott Fitzgerald", 240},
    {"To Kill a Mockingbird", "Harper Lee", 320},
    {"The Catcher in the Rye", "J.D. Salinger", 220},
    {"The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 350},
    {"The Hunger Games", "Suzanne Collins", 380},
};

int main() {
    srand(time(NULL));

    // Generate a random book to read
    int book_index = rand() % BOOK_COUNT;
    book_t *current_book = &books[book_index];

    // Generate a random chapter to read
    int chapter_index = rand() % CHAPTER_COUNT;
    int page_index = rand() % PAGE_COUNT;

    // Print the title and author of the current book
    printf("Currently reading: %s by %s\n", current_book->title, current_book->author);

    // Print a random page from the current chapter
    for (int i = 0; i < page_index; i++) {
        int page_num = rand() % current_book->pages;
        printf("%d\n", page_num);
    }

    // Print the current page number
    printf("Page %d of %d\n", page_index, current_book->pages);

    // Ask the user if they want to continue reading
    printf("Do you want to continue reading? (y/n): ");
    char response;
    scanf("%c", &response);

    // If the user wants to continue reading, generate another random page
    if (response == 'y' || response == 'Y') {
        chapter_index = rand() % CHAPTER_COUNT;
        page_index = rand() % PAGE_COUNT;
        printf("Page %d of %d\n", page_index, current_book->pages);
    } else {
        printf("Thank you for reading! Would you like to read another book? (y/n): ");
    }

    return 0;
}