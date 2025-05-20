//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 256
#define MAX_CONTENT 2048

typedef struct {
    char title[MAX_TITLE];
    char content[MAX_CONTENT];
} Book;

void clear_buffer() {
    while (getchar() != '\n');
}

void add_book(Book *library, int *book_count) {
    if (*book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter the title of the book: ");
    fgets(library[*book_count].title, MAX_TITLE, stdin);
    library[*book_count].title[strcspn(library[*book_count].title, "\n")] = 0; // Remove newline

    printf("Enter the content of the book: ");
    fgets(library[*book_count].content, MAX_CONTENT, stdin);
    library[*book_count].content[strcspn(library[*book_count].content, "\n")] = 0; // Remove newline

    (*book_count)++;
    printf("Book '%s' added successfully!\n", library[*book_count - 1].title);
}

void display_books(Book *library, int book_count) {
    printf("\n=== Your Library ===\n");
    for (int i = 0; i < book_count; i++) {
        printf("[%d] %s\n", i + 1, library[i].title);
    }
    printf("====================\n");
}

void read_book(Book *library, int book_index) {
    printf("\nReading book: %s\n", library[book_index].title);
    printf("Content:\n%s\n", library[book_index].content);
}

void delete_book(Book *library, int *book_count, int book_index) {
    for (int i = book_index; i < *book_count - 1; i++) {
        library[i] = library[i + 1];
    }
    (*book_count)--;
    printf("Book deleted successfully!\n");
}

int main() {
    Book library[MAX_BOOKS];
    int book_count = 0;
    int choice;

    do {
        printf("\n=== E-Book Reader ===\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Read Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                add_book(library, &book_count);
                break;
            case 2:
                display_books(library, book_count);
                break;
            case 3:
                if (book_count == 0) {
                    printf("No books available to read.\n");
                } else {
                    int read_choice;
                    printf("Enter the book number to read: ");
                    scanf("%d", &read_choice);
                    clear_buffer();
                    if (read_choice > 0 && read_choice <= book_count) {
                        read_book(library, read_choice - 1);
                    } else {
                        printf("Invalid book number!\n");
                    }
                }
                break;
            case 4:
                if (book_count == 0) {
                    printf("No books available to delete.\n");
                } else {
                    int delete_choice;
                    printf("Enter the book number to delete: ");
                    scanf("%d", &delete_choice);
                    clear_buffer();
                    if (delete_choice > 0 && delete_choice <= book_count) {
                        delete_book(library, &book_count, delete_choice - 1);
                    } else {
                        printf("Invalid book number!\n");
                    }
                }
                break;
            case 5:
                printf("Exiting the E-Book Reader. Happy reading!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}