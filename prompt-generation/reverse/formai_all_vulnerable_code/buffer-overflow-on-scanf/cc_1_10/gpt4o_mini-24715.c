//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: real-life
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

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void initialize_library(Library* library) {
    library->count = 0;
}

int add_book(Library* library, const char* title, const char* author, int year) {
    if (library->count >= MAX_BOOKS) {
        return 0; // Library is full
    }
    strncpy(library->books[library->count].title, title, TITLE_LENGTH);
    strncpy(library->books[library->count].author, author, AUTHOR_LENGTH);
    library->books[library->count].year = year;
    library->count++;
    return 1; // Book added successfully
}

void display_books(const Library* library) {
    printf("\nList of Books in the Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Book %d:\n", i + 1);
        printf("  Title: %s\n", library->books[i].title);
        printf("  Author: %s\n", library->books[i].author);
        printf("  Year: %d\n", library->books[i].year);
        printf("---------------------------\n");
    }
}

void search_book(const Library* library, const char* title) {
    int found = 0;
    printf("\nSearching for book titled '%s':\n", title);
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->books[i].title, title) == 0) {
            printf("Book Found:\n");
            printf("  Title: %s\n", library->books[i].title);
            printf("  Author: %s\n", library->books[i].author);
            printf("  Year: %d\n", library->books[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No book found with the title '%s'.\n", title);
    }
}

void menu() {
    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book by Title\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Library library;
    initialize_library(&library);

    int choice;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar(); // consume newline character from input buffer
        
        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline

                printf("Enter author name: ");
                fgets(author, AUTHOR_LENGTH, stdin);
                author[strcspn(author, "\n")] = 0; // Remove newline

                printf("Enter publication year: ");
                scanf("%d", &year);
                getchar(); // consume newline character
                
                if (add_book(&library, title, author, year)) {
                    printf("Book added successfully!\n");
                } else {
                    printf("Library is full! Cannot add more books.\n");
                }
                break;

            case 2:
                display_books(&library);
                break;

            case 3:
                printf("Enter the title of the book to search: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                search_book(&library, title);
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}