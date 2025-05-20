//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: protected
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

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full, can't add more books.\n");
        return;
    }

    Book new_book;
    printf("Enter book title: ");
    getchar();  // Clear the newline buffer
    fgets(new_book.title, TITLE_LENGTH, stdin);
    strtok(new_book.title, "\n");  // Remove newline character

    printf("Enter author name: ");
    fgets(new_book.author, AUTHOR_LENGTH, stdin);
    strtok(new_book.author, "\n");  // Remove newline character

    printf("Enter year of publication: ");
    scanf("%d", &new_book.year);

    library[book_count++] = new_book;
    printf("Book added successfully!\n");
}

void display_books() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }
    
    printf("\nBooks in Library:\n");
    for (int i = 0; i < book_count; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Year: %d\n", library[i].year);
        printf("====================\n");
    }
}

void search_book() {
    char search_term[TITLE_LENGTH];
    printf("Enter the title or author to search: ");
    getchar();  // Clear the newline buffer
    fgets(search_term, TITLE_LENGTH, stdin);
    strtok(search_term, "\n");  // Remove newline character

    printf("\nSearch results:\n");
    for (int i = 0; i < book_count; i++) {
        if (strstr(library[i].title, search_term) != NULL || strstr(library[i].author, search_term) != NULL) {
            printf("Book %d:\n", i + 1);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Year: %d\n", library[i].year);
            printf("====================\n");
        }
    }
}

void menu() {
    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}