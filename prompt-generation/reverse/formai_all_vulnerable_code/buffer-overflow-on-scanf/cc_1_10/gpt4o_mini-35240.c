//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 50

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
} Book;

Book* books[MAX_BOOKS];
int book_count = 0;

void add_book(const char* title, const char* author) {
    if (book_count >= MAX_BOOKS) {
        printf("Cannot add more books. Maximum limit reached!\n");
        return;
    }
    
    books[book_count] = (Book*) malloc(sizeof(Book));
    if (books[book_count] == NULL) {
        printf("Memory allocation failed! Could not add book.\n");
        return;
    }

    strncpy(books[book_count]->title, title, TITLE_LEN);
    strncpy(books[book_count]->author, author, AUTHOR_LEN);
    book_count++;
    printf("Book added: %s by %s\n", title, author);
}

void view_books() {
    if (book_count == 0) {
        printf("No books to display!\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d. %s by %s\n", i + 1, books[i]->title, books[i]->author);
    }
}

void delete_book(int index) {
    if (index < 0 || index >= book_count) {
        printf("Invalid book index!\n");
        return;
    }

    free(books[index]);
    for (int i = index; i < book_count - 1; i++) {
        books[i] = books[i + 1];
    }
    book_count--;
    printf("Book deleted successfully!\n");
}

void clean_up() {
    for (int i = 0; i < book_count; i++) {
        free(books[i]);
    }
    book_count = 0;
    printf("Cleaned up all allocated memory.\n");
}

int main() {
    int choice;
    char title[TITLE_LEN], author[AUTHOR_LEN];

    do {
        printf("\nBook Management System:\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline character
                printf("Enter book author: ");
                fgets(author, AUTHOR_LEN, stdin);
                author[strcspn(author, "\n")] = '\0'; // Remove newline character
                add_book(title, author);
                break;
            case 2:
                view_books();
                break;
            case 3:
                printf("Enter the index of the book to delete: ");
                int index;
                scanf("%d", &index);
                delete_book(index - 1); // Convert to zero-based index
                break;
            case 4:
                clean_up();
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}