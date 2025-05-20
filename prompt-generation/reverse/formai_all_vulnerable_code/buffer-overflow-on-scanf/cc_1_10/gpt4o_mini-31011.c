//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 256
#define MAX_CONTENT 2048

typedef struct {
    char title[MAX_TITLE_LEN];
    char content[MAX_CONTENT];
} Book;

void display_menu() {
    printf("\n*** E-Book Reader ***\n");
    printf("1. Load Book\n");
    printf("2. Read Book\n");
    printf("3. List Loaded Books\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

void load_book(Book *book) {
    printf("Enter book title: ");
    fgets(book->title, MAX_TITLE_LEN, stdin);
    book->title[strcspn(book->title, "\n")] = '\0'; // Remove newline

    printf("Enter book content (end with 'END'):\n");
    char buffer[MAX_CONTENT];
    size_t content_len = 0;

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strncmp(buffer, "END", 3) == 0)
            break;
        if (content_len + strlen(buffer) < MAX_CONTENT) {
            strcat(book->content, buffer);
            content_len += strlen(buffer);
        } else {
            printf("Content exceeds maximum limit!\n");
            break;
        }
    }
    printf("Book '%s' loaded successfully!\n", book->title);
}

void read_book(const Book *book) {
    if (strlen(book->content) == 0) {
        printf("No book loaded yet!\n");
        return;
    }
    printf("\n** Reading '%s' **\n", book->title);
    printf("%s\n", book->content);
    printf("** End of '%s' **\n", book->title);
}

int main() {
    Book books[MAX_BOOKS];
    int total_books = 0;
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // absorb newline character

        switch (choice) {
            case 1:
                if (total_books < MAX_BOOKS) {
                    load_book(&books[total_books]);
                    total_books++;
                } else {
                    printf("Maximum number of books loaded.\n");
                }
                break;
            case 2:
                for (int i = 0; i < total_books; i++) {
                    printf("%d. %s\n", i + 1, books[i].title);
                }
                printf("Select a book to read (1-%d): ", total_books);
                int read_choice;
                scanf("%d", &read_choice);
                getchar(); // absorb newline character
                if (read_choice > 0 && read_choice <= total_books) {
                    read_book(&books[read_choice - 1]);
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            case 3:
                printf("\nLoaded Books:\n");
                for (int i = 0; i < total_books; i++) {
                    printf("%d. %s\n", i + 1, books[i].title);
                }
                break;
            case 4:
                printf("Exiting the E-Book Reader. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}