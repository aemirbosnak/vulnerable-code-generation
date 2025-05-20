//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int is_lended; // 0 for available, 1 for lended
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void load_books() {
    FILE *file = fopen("library.dat", "rb");
    if (file) {
        while (fread(&library[book_count], sizeof(Book), 1, file)) {
            book_count++;
        }
        fclose(file);
    }
}

void save_books() {
    FILE *file = fopen("library.dat", "wb");
    if (file) {
        fwrite(library, sizeof(Book), book_count, file);
        fclose(file);
    }
}

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    
    Book new_book;
    new_book.id = book_count + 1; // Simple ID assignment
    printf("Enter book title: ");
    getchar(); // Consume leftover newline
    fgets(new_book.title, MAX_TITLE_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; // Remove newline

    printf("Enter book author: ");
    fgets(new_book.author, MAX_AUTHOR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0; // Remove newline
    
    new_book.is_lended = 0; // Book is available
    library[book_count] = new_book;
    book_count++;

    printf("Book added: %s by %s\n", new_book.title, new_book.author);
    save_books();
}

void lend_book() {
    int id;
    printf("Enter book ID to lend: ");
    scanf("%d", &id);

    if (id <= 0 || id > book_count) {
        printf("Invalid book ID.\n");
        return;
    }

    if (library[id - 1].is_lended) {
        printf("Book is already lended: %s by %s\n", library[id - 1].title, library[id - 1].author);
        return;
    }

    library[id - 1].is_lended = 1;
    printf("Book lent: %s by %s\n", library[id - 1].title, library[id - 1].author);
    save_books();
}

void return_book() {
    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);

    if (id <= 0 || id > book_count) {
        printf("Invalid book ID.\n");
        return;
    }

    if (!library[id - 1].is_lended) {
        printf("Book is not lent: %s by %s\n", library[id - 1].title, library[id - 1].author);
        return;
    }

    library[id - 1].is_lended = 0;
    printf("Book returned: %s by %s\n", library[id - 1].title, library[id - 1].author);
    save_books();
}

void display_books() {
    printf("\nAvailable Books:\n");
    for (int i = 0; i < book_count; i++) {
        if (!library[i].is_lended) {
            printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
        }
    }
}

int main() {
    load_books();
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Lend Book\n");
        printf("3. Return Book\n");
        printf("4. Display Available Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                lend_book();
                break;
            case 3:
                return_book();
                break;
            case 4:
                display_books();
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}