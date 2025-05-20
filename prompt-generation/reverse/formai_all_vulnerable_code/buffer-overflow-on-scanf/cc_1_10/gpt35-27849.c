//FormAI DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_FILENAME_LENGTH 100

struct book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char filename[MAX_FILENAME_LENGTH];
};

int main() {
    struct book library[MAX_BOOKS];
    int num_books = 0;
    char input[MAX_TITLE_LENGTH];
    int choice = 0;

    printf("Welcome to the Ebook Reader!\n");
    printf("============================\n");

    while (choice != 3) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a book\n");
        printf("2. Display library\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (num_books == MAX_BOOKS) {
                printf("Sorry, library is full!\n");
            } else {
                struct book new_book;
                printf("Enter the title of the book: ");
                scanf("%s", new_book.title);
                printf("Enter the author of the book: ");
                scanf("%s", new_book.author);
                printf("Enter the filename of the ebook: ");
                scanf("%s", new_book.filename);

                library[num_books] = new_book;
                num_books++;
                printf("Book added to library!\n");
            }
        } else if (choice == 2) {
            if (num_books == 0) {
                printf("Sorry, library is empty!\n");
            } else {
                printf("Library contents:\n");
                for (int i = 0; i < num_books; i++) {
                    printf("%d. %s by %s (%s)\n", i+1, library[i].title, library[i].author, library[i].filename);
                }
            }
        } else if (choice == 3) {
            printf("Goodbye!\n");
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}