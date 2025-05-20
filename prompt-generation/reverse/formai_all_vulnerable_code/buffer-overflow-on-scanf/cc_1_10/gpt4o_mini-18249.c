//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100

typedef struct {
    int id;
    char title[TITLE_LENGTH];
} Book;

typedef struct {
    Book *books[MAX_BOOKS];
    int count;
} Library;

Library library;

void init_library() {
    library.count = 0;
}

int add_book(const char *title) {
    if (library.count >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return -1;
    }
    Book *new_book = malloc(sizeof(Book));
    new_book->id = library.count + 1;
    strncpy(new_book->title, title, TITLE_LENGTH);
    library.books[library.count++] = new_book;
    printf("Added book: %s with ID: %d\n", new_book->title, new_book->id);
    return new_book->id;
}

Book *find_book(const char *title) {
    for (int i = 0; i < library.count; i++) {
        if (strcmp(library.books[i]->title, title) == 0) {
            return library.books[i];
        }
    }
    return NULL;
}

void delete_book(int id) {
    for (int i = 0; i < library.count; i++) {
        if (library.books[i]->id == id) {
            printf("Deleting book: %s\n", library.books[i]->title);
            free(library.books[i]);
            library.books[i] = library.books[library.count - 1]; // Move last book to current position
            library.count--;
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

void display_books() {
    if (library.count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("Library Books:\n");
    for (int i = 0; i < library.count; i++) {
        printf("ID: %d, Title: %s\n", library.books[i]->id, library.books[i]->title);
    }
}

void free_library() {
    for (int i = 0; i < library.count; i++) {
        free(library.books[i]);
    }
    library.count = 0;
}

int main() {
    init_library();
    
    int option, id;
    char title[TITLE_LENGTH];

    while (1) {
        printf("\nLibrary Database Indexing System\n");
        printf("1. Add Book\n");
        printf("2. Find Book\n");
        printf("3. Delete Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar(); // Consume newline character

        switch (option) {
            case 1:
                printf("Enter book title: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                add_book(title);
                break;
            case 2:
                printf("Enter book title to find: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                Book *book = find_book(title);
                if (book) {
                    printf("Found book: ID: %d, Title: %s\n", book->id, book->title);
                } else {
                    printf("Book not found!\n");
                }
                break;
            case 3:
                printf("Enter book ID to delete: ");
                scanf("%d", &id);
                delete_book(id);
                break;
            case 4:
                display_books();
                break;
            case 5:
                free_library();
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}