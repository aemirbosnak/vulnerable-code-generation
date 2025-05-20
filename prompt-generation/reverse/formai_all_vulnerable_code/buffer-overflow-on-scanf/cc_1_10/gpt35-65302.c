//FormAI DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Ebook {
    char title[100];
    char author[100];
    int year_published;
} Ebook;

Ebook ebook_library[MAX_BOOKS];
int num_books = 0;

// Function to add a new ebook to the library
void add_ebook() {
    Ebook new_book;
    printf("Enter the title of the ebook: ");
    fgets(new_book.title, 100, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0;  // Remove newline character

    printf("Enter the author of the ebook: ");
    fgets(new_book.author, 100, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;  // Remove newline character

    printf("Enter the year the ebook was published: ");
    scanf("%d", &new_book.year_published);
    getchar();  // Consume newline character

    ebook_library[num_books++] = new_book;
    printf("Ebook added to library successfully!\n");
}

// Function to display the details of all ebooks in the library
void display_ebooks() {
    printf("----- EBOOK LIBRARY -----\n");
    for (int i = 0; i < num_books; i++) {
        printf("Title: %s\n", ebook_library[i].title);
        printf("Author: %s\n", ebook_library[i].author);
        printf("Year Published: %d\n\n", ebook_library[i].year_published);
    }
}

int main() {
    char choice;

    printf("Welcome to the Ebook Reader Example Program!\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("a - Add a new ebook to the library\n");
        printf("d - Display all ebooks in the library\n");
        printf("q - Quit\n");

        printf("Enter your choice: ");
        scanf("%c", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 'a':
                add_ebook();
                break;
            case 'd':
                display_ebooks();
                break;
            case 'q':
                printf("Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}