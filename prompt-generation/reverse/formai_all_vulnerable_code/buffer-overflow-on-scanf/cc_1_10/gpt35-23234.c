//FormAI DATASET v1.0 Category: Ebook reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 1000
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

typedef struct book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    char path[200];
} book;

book library[MAX_BOOKS];
int num_books;

void display_menu() {
    printf("**** Ebook Reader ****\n");
    printf("1. Add book\n");
    printf("2. View library\n");
    printf("3. Open book\n");
    printf("4. Exit program\n");
}

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    book new_book;
    printf("Enter book title: ");
    scanf("%s", new_book.title);
    printf("Enter book author: ");
    scanf("%s", new_book.author);
    printf("Enter number of pages: ");
    scanf("%d", &new_book.pages);
    printf("Enter file path: ");
    scanf("%s", new_book.path);

    library[num_books] = new_book;
    num_books++;
    printf("Book added successfully!\n");
}

void view_library() {
    printf("**** Library ****\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s (%d pages)\n", i+1, library[i].title, library[i].author, library[i].pages);
    }
}

void open_book() {
    int book_choice;
    printf("Enter book number: ");
    scanf("%d", &book_choice);

    if (book_choice < 1 || book_choice > num_books) {
        printf("Invalid book number!\n");
        return;
    }

    printf("Opening book %s...\n", library[book_choice-1].title);
    // Code for opening ebook file goes here
}

int main() {
    int choice;
    num_books = 0;

    while (1) {
        display_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                view_library();
                break;
            case 3:
                open_book();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}