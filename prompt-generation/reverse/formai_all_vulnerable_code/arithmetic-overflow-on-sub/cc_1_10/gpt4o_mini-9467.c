//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void add_book(const char* title, const char* content) {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    strncpy(library[book_count].title, title, MAX_TITLE_LENGTH);
    strncpy(library[book_count].content, content, MAX_CONTENT_LENGTH);
    book_count++;
}

void view_books() {
    printf("\nAvailable Books:\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
    }
}

void read_book(int index) {
    if (index < 0 || index >= book_count) {
        printf("Invalid index! Please choose a correct book number.\n");
        return;
    }
    printf("\nReading \"%s\":\n", library[index].title);
    printf("%s\n", library[index].content);
}

void display_menu() {
    printf("\n--- E-Book Reader Menu ---\n");
    printf("1. Add a new book\n");
    printf("2. View available books\n");
    printf("3. Read a book\n");
    printf("4. Exit\n");
    printf("-------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar();  // Consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the book title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0;  // Remove newline character

                printf("Enter the book content: ");
                fgets(content, MAX_CONTENT_LENGTH, stdin);
                content[strcspn(content, "\n")] = 0;  // Remove newline character

                add_book(title, content);
                printf("Book added successfully!\n");
                break;

            case 2:
                view_books();
                break;

            case 3:
                view_books();
                printf("Enter the book number to read: ");
                int book_number;
                scanf("%d", &book_number);
                read_book(book_number - 1);  // Convert to zero-based index
                break;

            case 4:
                printf("Exiting the application. Bye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}