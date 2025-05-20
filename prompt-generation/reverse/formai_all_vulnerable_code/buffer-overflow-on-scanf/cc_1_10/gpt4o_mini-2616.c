//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    fgets(library[book_count].title, MAX_TITLE_LENGTH, stdin);
    library[book_count].title[strcspn(library[book_count].title, "\n")] = '\0'; // Remove newline

    printf("Enter book content (max %d characters): \n", MAX_CONTENT_LENGTH);
    fgets(library[book_count].content, MAX_CONTENT_LENGTH, stdin);
    library[book_count].content[strcspn(library[book_count].content, "\n")] = '\0'; // Remove newline

    book_count++;
    printf("Book added successfully!\n");
}

void display_books() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("Books in Library:\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
    }
}

void read_book() {
    int choice;
    printf("Enter the book number you want to read: ");
    scanf("%d", &choice);
    getchar(); // Consume the newline character left by scanf

    if (choice < 1 || choice > book_count) {
        printf("Invalid choice!\n");
        return;
    }

    printf("Reading %s:\n\n%s\n", library[choice - 1].title, library[choice - 1].content);
    printf("\nPress Enter to return to menu...");
    getchar(); // Wait for enter key
}

void menu() {
    int option;

    do {
        printf("\n~~~ E-Book Reader ~~~\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Read Book\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        getchar(); // Consume the newline character left by scanf

        switch (option) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                read_book();
                break;
            case 4:
                printf("Exiting the e-book reader. Happy reading!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (option != 4);
}

int main() {
    printf("Welcome to the Mind-Bending E-Book Reader!\n");
    menu();
    return 0;
}