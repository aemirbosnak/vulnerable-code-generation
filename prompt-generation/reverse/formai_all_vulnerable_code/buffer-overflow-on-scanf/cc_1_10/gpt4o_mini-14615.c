//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_CONTENT_LENGTH 1000
#define MAX_BOOKS 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void display_menu() {
    printf("\n=============================\n");
    printf("        E-Book Reader        \n");
    printf("=============================\n");
    printf("1. Add New Book\n");
    printf("2. View Books\n");
    printf("3. Read Book\n");
    printf("4. Exit\n");
    printf("=============================\n");
    printf("Choose an option: ");
}

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    Book new_book;
    printf("Enter the title of the book: ");
    getchar(); // To consume the newline from previous input
    fgets(new_book.title, MAX_TITLE_LENGTH, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; // Remove newline

    printf("Enter the author of the book: ");
    fgets(new_book.author, MAX_AUTHOR_LENGTH, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0; // Remove newline

    printf("Enter the content of the book (Max %d characters):\n", MAX_CONTENT_LENGTH);
    fgets(new_book.content, MAX_CONTENT_LENGTH, stdin);
    new_book.content[strcspn(new_book.content, "\n")] = 0; // Remove newline

    library[book_count++] = new_book;
    printf("Book '%s' by '%s' added to the library.\n", new_book.title, new_book.author);
}

void view_books() {
    printf("\nList of Books:\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d. %s by %s\n", i + 1, library[i].title, library[i].author);
    }
    if (book_count == 0) {
        printf("No books in the library.\n");
    }
}

void read_book() {
    int choice;
    view_books();
    if (book_count == 0) {
        return;
    }
    printf("Enter the book number to read: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > book_count) {
        printf("Invalid choice.\n");
        return;
    }

    printf("\nReading '%s' by '%s':\n", library[choice - 1].title, library[choice - 1].author);
    printf("%s\n", library[choice - 1].content);
}

int main() {
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_book();
                break;
            case 2:
                view_books();
                break;
            case 3:
                read_book();
                break;
            case 4:
                printf("Exiting E-Book Reader. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}