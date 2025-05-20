//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PAGES 100
#define MAX_TEXT_SIZE 1024

typedef struct {
    char *title;
    char *author;
    char *text;
    int page_count;
} Book;

Book books[5];
int current_book = 0;

void init_books() {
    books[0].title = "The Great Gatsby";
    books[0].author = "F. Scott Fitzgerald";
    books[0].text = "Once upon a time, in the town of West Egg, there lived a man named Gatsby...";
    books[0].page_count = 200;

    books[1].title = "To Kill a Mockingbird";
    books[1].author = "Harper Lee";
    books[1].text = "In the deep south, a young girl named Scout Finch learns about prejudice and injustice...";
    books[1].page_count = 300;

    books[2].title = "Pride and Prejudice";
    books[2].author = "Jane Austen";
    books[2].text = "In the English countryside, a young woman named Elizabeth Bennet navigates love and societal expectations...";
    books[2].page_count = 250;

    books[3].title = "The Catcher in the Rye";
    books[3].author = "J.D. Salinger";
    books[3].text = "In post-war New York City, a young man named Holden Caulfield struggles with the phoniness of adulthood...";
    books[3].page_count = 200;

    books[4].title = "The Hitchhiker's Guide to the Galaxy";
    books[4].author = "Douglas Adams";
    books[4].text = "In a galaxy far, far away, an unwitting human named Arthur Dent embarks on a journey through space...";
    books[4].page_count = 350;
}

void read_book(int book_num) {
    char line[MAX_TEXT_SIZE];
    int page = 0;

    printf("Currently reading: %s (%d of %d pages)\n", books[book_num].title, page, books[book_num].page_count);

    while (page < books[book_num].page_count) {
        gets(line);
        printf("%s\n", line);
        page++;
    }
}

int main() {
    init_books();

    while (1) {
        printf("Choose a book (1-4): ");
        int book_num = getchar() - '1';

        read_book(book_num);
    }

    return 0;
}