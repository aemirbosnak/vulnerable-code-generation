//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

Book database[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Database is full! Cannot add more books.\n");
        return;
    }
    Book new_book;
    printf("Enter title: ");
    fgets(new_book.title, TITLE_LENGTH, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; // Removing the newline

    printf("Enter author: ");
    fgets(new_book.author, AUTHOR_LENGTH, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;

    printf("Enter year of publication: ");
    scanf("%d", &new_book.year);
    getchar(); // Consume the leftover newline

    database[book_count++] = new_book;
    printf("Book added successfully!\n");
}

void display_books() {
    if (book_count == 0) {
        printf("No books in the database.\n");
        return;
    }
    printf("\nList of Books in Database:\n");
    for (int i = 0; i < book_count; i++) {
        printf("Book %d: '%s' by %s (%d)\n", i + 1, database[i].title, database[i].author, database[i].year);
    }
}

void search_book() {
    char search_title[TITLE_LENGTH];
    printf("Enter title of book to search: ");
    fgets(search_title, TITLE_LENGTH, stdin);
    search_title[strcspn(search_title, "\n")] = 0;

    for (int i = 0; i < book_count; i++) {
        if (strcmp(database[i].title, search_title) == 0) {
            printf("Found Book: '%s' by %s (%d)\n", database[i].title, database[i].author, database[i].year);
            return;
        }
    }
    printf("Book not found!\n");
}

void delete_book() {
    char delete_title[TITLE_LENGTH];
    printf("Enter title of book to delete: ");
    fgets(delete_title, TITLE_LENGTH, stdin);
    delete_title[strcspn(delete_title, "\n")] = 0;

    for (int i = 0; i < book_count; i++) {
        if (strcmp(database[i].title, delete_title) == 0) {
            for (int j = i; j < book_count - 1; j++) {
                database[j] = database[j + 1];
            }
            book_count--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

void display_menu() {
    printf("\n--- Book Database Menu ---\n");
    printf("1. Add Book\n");
    printf("2. Display All Books\n");
    printf("3. Search Book\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
    printf("--------------------------\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                delete_book();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}