//FormAI DATASET v1.0 Category: Ebook reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 1000

struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    char* content[MAX_PAGES];
};

int main() {
    struct Book books[MAX_BOOKS];
    int num_books = 0;
    int current_book = 0;
    char* current_page;

    // code to read books from file or database goes here

    // main program loop
    while (1) {
        // print the current page
        printf("%s\n", current_page);

        // get user input
        char input[10];
        printf("Enter 'n' for next page, 'p' for previous page, 'q' to quit\n");
        scanf("%s", input);

        // process user input
        if (strcmp(input, "n") == 0) {
            // go to the next page
            if (current_book < num_books) {
                current_page = books[current_book].content[0];
                current_book++;
            }
        } else if (strcmp(input, "p") == 0) {
            // go to the previous page
            if (current_book > 1) {
                current_book--;
                current_page = books[current_book - 1].content[0];
            }
        } else if (strcmp(input, "q") == 0) {
            // quit the program
            exit(0);
        }
    }

    return 0;
}