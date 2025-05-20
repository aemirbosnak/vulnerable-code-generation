//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOOK_NAME_LENGTH 50
#define MAX_AUTHOR_NAME_LENGTH 30
#define MAX_PAGE_COUNT 1000

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_AUTHOR_NAME_LENGTH];
    int page_count;
} book_t;

book_t current_book;

void init_book(book_t *book) {
    strcpy(book->name, "Untitled");
    strcpy(book->author, "Anonymous");
    book->page_count = 0;
}

void add_page(book_t *book, int page_num) {
    if (book->page_count < MAX_PAGE_COUNT) {
        book->page_count++;
        printf("Page %d added to book %s by %s\n", page_num, book->name, book->author);
    } else {
        printf("Maximum page count reached. Unable to add more pages.\n");
    }
}

void display_book(book_t *book) {
    printf("Book: %s by %s\n", book->name, book->author);
    printf("Page Count: %d\n", book->page_count);
}

int main() {
    srand(time(NULL));

    book_t book;
    init_book(&book);

    int page_num;
    int choose;

    do {
        printf("Choose an option:\n");
        printf("1. Add a new page to the current book\n");
        printf("2. Display the current book details\n");
        printf("3. Quit\n");

        scanf("%d", &choose);

        switch (choose) {
            case 1:
                page_num = rand() % 100 + 1;
                add_page(&book, page_num);
                break;

            case 2:
                display_book(&book);
                break;

            case 3:
                printf("Exiting program...\n");
                return 0;
                break;

            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while (choose != 3);

    return 0;
}