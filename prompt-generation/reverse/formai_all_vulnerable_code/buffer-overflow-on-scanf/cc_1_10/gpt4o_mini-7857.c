//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int is_available;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    
    Book new_book;
    new_book.id = book_count + 1;  // simple id assignment
    printf("Enter book title: ");
    getchar();  // to consume the newline left by previous input
    fgets(new_book.title, MAX_TITLE_LENGTH, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0'; // remove newline
    printf("Enter author: ");
    fgets(new_book.author, MAX_AUTHOR_LENGTH, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0'; // remove newline
    new_book.is_available = 1;  // 1 means available
    
    library[book_count] = new_book;
    book_count++;
    printf("Book added successfully!\n");
}

void view_books() {
    if (book_count == 0) {
        printf("No books available in the library.\n");
        return;
    }
    
    printf("\nList of Books:\n");
    printf("ID\tTitle\t\tAuthor\t\tAvailable\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d\t%s\t%s\t%d\n", library[i].id, library[i].title, library[i].author, library[i].is_available);
    }
}

void search_book() {
    char query[MAX_TITLE_LENGTH];
    printf("Enter book title to search: ");
    getchar();  // to consume the newline left by previous input
    fgets(query, MAX_TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = '\0'; // remove newline

    int found = 0;
    printf("\nSearch Results:\n");
    printf("ID\tTitle\t\tAuthor\t\tAvailable\n");
    printf("-----------------------------------------\n");
    
    for (int i = 0; i < book_count; i++) {
        if (strstr(library[i].title, query) != NULL) {
            printf("%d\t%s\t%s\t%d\n", library[i].id, library[i].title, library[i].author, library[i].is_available);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No matching books found.\n");
    }
}

void display_menu() {
    printf("\nLibrary Management System Menu:\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Search Book\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                view_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}