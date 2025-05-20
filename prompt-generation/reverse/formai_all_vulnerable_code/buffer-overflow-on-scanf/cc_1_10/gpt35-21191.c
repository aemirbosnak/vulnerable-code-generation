//FormAI DATASET v1.0 Category: Ebook reader ; Style: artistic
#include <stdio.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_PAGES 5000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
} Book;

void printBook(const Book *book) {
    printf("\"%s\" by %s (%d pages)\n", book->title, book->author, book->pages);
}

int main() {
    Book library[MAX_BOOKS] = {
        {"The C Programming Language", "Kernighan and Ritchie", 279},
        {"Programming Pearls", "Jon Bentley", 256},
        {"Head First Design Patterns", "Freeman and Robson", 694},
        {"Clean Code", "Robert Martin", 464},
        {"The Pragmatic Programmer", "Hunt and Thomas", 352}
    };

    int numBooks = 5;

    printf("Welcome to the Ebook reader!\n");
    printf("Here are the available books:\n");

    for (int i = 0; i < numBooks; i++) {
        printf("%d. ", i + 1);
        printBook(&library[i]);
    }

    printf("Enter the number of the book you would like to read: ");
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > numBooks) {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    Book *book = &library[choice - 1];

    printf("\n\nYou have chosen: ");
    printBook(book);

    printf("\n\nStarting to read \"%s\"...\n", book->title);

    char contents[MAX_PAGES];
    int pagesRead = 0;

    // Simulate reading the book page by page
    while (pagesRead < book->pages) {
        printf("You are reading page %d of %d.\n", pagesRead + 1, book->pages);
        printf("Press any key to turn the page or 'q' to quit...");

        char input;
        scanf(" %c", &input);

        if (input == 'q') {
            printf("\n\nQuitting...\n");
            return 0;
        }

        pagesRead++;
    }

    printf("\n\nCongratulations! You have finished reading \"%s\".\n", book->title);

    return 0;
}