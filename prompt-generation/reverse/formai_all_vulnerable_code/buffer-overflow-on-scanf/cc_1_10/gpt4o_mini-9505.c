//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void display_menu() {
    printf("\n*** Welcome to Your Library Database! ***\n");
    printf("1. Add a Book\n");
    printf("2. View All Books\n");
    printf("3. Delete a Book\n");
    printf("4. Exit\n");
    printf("Please select an option (1-4): ");
}

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    getchar();  // To consume newline left by previous input
    fgets(library[book_count].title, TITLE_LENGTH, stdin);
    library[book_count].title[strcspn(library[book_count].title, "\n")] = '\0'; // Remove newline

    printf("Enter author name: ");
    fgets(library[book_count].author, AUTHOR_LENGTH, stdin);
    library[book_count].author[strcspn(library[book_count].author, "\n")] = '\0'; // Remove newline

    printf("Enter publication year: ");
    scanf("%d", &library[book_count].year);

    book_count++;
    printf("Book added successfully!\n");
}

void view_books() {
    if (book_count == 0) {
        printf("No books found in the library.\n");
        return;
    }

    printf("\n*** List of Books in Library ***\n");
    for (int i = 0; i < book_count; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Year: %d\n\n", library[i].year);
    }
}

void delete_book() {
    if (book_count == 0) {
        printf("No books to delete.\n");
        return;
    }

    int index;
    printf("Enter the number of the book you want to delete (1-%d): ", book_count);
    scanf("%d", &index);

    if (index < 1 || index > book_count) {
        printf("Invalid book number!\n");
    } else {
        for (int i = index - 1; i < book_count - 1; i++) {
            library[i] = library[i + 1]; // Shift books to the left
        }
        book_count--;
        printf("Book deleted successfully!\n");
    }
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                view_books();
                break;
            case 3:
                delete_book();
                break;
            case 4:
                printf("Exiting the library database. See you next time!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}