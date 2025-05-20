//FormAI DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ebook {
    char title[50];
    char author[50];
    int num_pages;
    char format[10];
};

int main() {
    int num_books;
    printf("Welcome to the Ebook Reader!\n");

    printf("How many books are in your library?\n");
    scanf("%d", &num_books);

    struct ebook library[num_books];

    for (int i = 0; i < num_books; i++) {
        printf("Please enter the title of book %d:\n", i+1);
        scanf("%s", library[i].title);

        printf("Please enter the author of book %d:\n", i+1);
        scanf("%s", library[i].author);

        printf("Please enter the number of pages in book %d:\n", i+1);
        scanf("%d", &library[i].num_pages);

        printf("Please enter the format of book %d (PDF, EPUB, MOBI):\n", i+1);
        scanf("%s", library[i].format);
    }

    char search_title[50];
    printf("What book would you like to read?\n");
    scanf("%s", search_title);

    int found_book = 0;

    for (int i = 0; i < num_books; i++) {
        if (strcmp(search_title, library[i].title) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Number of pages: %d\n", library[i].num_pages);
            printf("Format: %s\n", library[i].format);
            found_book = 1;
            break;
        }
    }

    if (!found_book) {
        printf("Sorry, that book is not in your library.\n");
    }

    return 0;
}