//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PAGES 100
#define MAX_BOOK_SIZE 10000

typedef struct {
    char title[50];
    char author[50];
    char chapter[50];
    char page[5];
} book_t;

book_t books[10];
int current_book = 0;
int current_page = 0;

void add_book(book_t *book) {
    int i;
    for (i = 0; i < 10; i++) {
        if (books[i].title[0] == '\0') {
            strcpy(books[i].title, book->title);
            strcpy(books[i].author, book->author);
            strcpy(books[i].chapter, book->chapter);
            books[i].page[0] = '\0';
            current_book = i;
            break;
        }
    }
}

void next_page() {
    current_page++;
    if (current_page >= books[current_book].page[0]) {
        current_page = 0;
    }
}

void prev_page() {
    current_page--;
    if (current_page < 0) {
        current_page = books[current_book].page[0] - 1;
    }
}

void display_book() {
    printf("Book: %s, by %s\n", books[current_book].title, books[current_book].author);
    printf("Chapter: %s\n", books[current_book].chapter);
    printf("Page: %d\n", current_page);
}

int main() {
    char input[50];
    int choice;

    while (1) {
        display_book();
        printf("Choose a book (1-9): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book(&books[0]);
                break;
            case 2:
                add_book(&books[1]);
                break;
            case 3:
                add_book(&books[2]);
                break;
            case 4:
                next_page();
                break;
            case 5:
                prev_page();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}