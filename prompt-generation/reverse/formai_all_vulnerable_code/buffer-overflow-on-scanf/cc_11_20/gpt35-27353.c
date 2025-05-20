//FormAI DATASET v1.0 Category: Ebook reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_CHARS 2000

struct Book {
    char title[MAX_CHARS];
    char author[MAX_CHARS];
    int pages;
    char content[MAX_CHARS];
};

int main() {

    struct Book library[MAX_BOOKS];
    int num_books = 0;
    int current_book = -1;

    printf("Welcome to the Ebook Reader! Please choose an option:\n\n");

    while (1) {

        printf("1. Add a book\n");
        printf("2. Select a book\n");
        printf("3. Read the current book\n");
        printf("4. Quit\n\n");

        int choice = -1;
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a book

                if (num_books < MAX_BOOKS) {

                    current_book = num_books;
                    num_books++;

                    printf("\nPlease enter the book's title: ");
                    scanf("%s", library[current_book].title);

                    printf("\nPlease enter the book's author: ");
                    scanf("%s", library[current_book].author);

                    printf("\nPlease enter the number of pages in the book: ");
                    scanf("%d", &library[current_book].pages);

                    printf("\nPlease enter the book's content: ");
                    scanf("%s", library[current_book].content);

                    printf("\nBook added successfully!\n\n");
                } else {
                    printf("\nError: you have reached the maximum number of books!\n\n");
                }
                break;

            case 2: // Select a book

                if (num_books > 0) {

                    printf("\nPlease choose a book:\n");
                    for (int i = 0; i < num_books; i++) {
                        printf("%d. %s by %s\n", i, library[i].title, library[i].author);
                    }

                    int book_choice = -1;
                    printf("\nPlease enter your choice: ");
                    scanf("%d", &book_choice);

                    if (book_choice >= 0 && book_choice < num_books) {
                        current_book = book_choice;
                        printf("\nYou selected %s by %s\n\n", library[current_book].title, library[current_book].author);
                    } else {
                        printf("\nError: invalid book choice!\n\n");
                    }
                } else {
                    printf("\nError: no books found!\n\n");
                }
                break;

            case 3: // Read the current book

                if (current_book >= 0 && current_book < num_books) {
                    printf("\nReading %s by %s...\n\n", library[current_book].title, library[current_book].author);
                    printf("%s\n", library[current_book].content);
                } else {
                    printf("\nError: no book selected!\n\n");
                }
                break;

            case 4: // Quit

                printf("\nThank you for using the Ebook Reader!\n");
                exit(0);

            default: // Error

                printf("\nError: invalid choice!\n\n");
                break;
        }
    }

    return 0;
}