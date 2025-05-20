//FormAI DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
};

struct Book library[MAX_BOOKS];
int num_books = 0;

// Display the main menu
void display_menu() {
    printf("C Ebook Reader Main Menu\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Quit\n");
}

// Add a book to the library
void add_book() {
    if (num_books == MAX_BOOKS) {
        printf("Error: library is full\n");
        return;
    }

    printf("Enter the title of the book: ");
    fgets(library[num_books].title, MAX_TITLE_LENGTH, stdin);
    library[num_books].title[strcspn(library[num_books].title, "\n")] = 0;  // remove newline character

    printf("Enter the author of the book: ");
    fgets(library[num_books].author, MAX_AUTHOR_LENGTH, stdin);
    library[num_books].author[strcspn(library[num_books].author, "\n")] = 0;  // remove newline character
    
    printf("Enter the number of pages in the book: ");
    scanf("%d", &library[num_books].pages);
    getchar();  // consume newline character

    num_books++;
}

// Display all books in the library
void display_books() {
    if (num_books == 0) {
        printf("Library is empty\n");
        return;
    }

    printf("Library Contents\n");
    for (int i = 0; i < num_books; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Pages: %d\n", library[i].pages);
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline character

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}