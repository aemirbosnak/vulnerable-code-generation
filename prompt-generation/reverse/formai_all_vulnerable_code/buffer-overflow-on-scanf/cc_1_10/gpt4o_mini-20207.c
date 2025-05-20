//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int id;
} Book;

Book *database[MAX_BOOKS];
int current_size = 0;

void add_book() {
    if (current_size >= MAX_BOOKS) {
        printf("Database is full, cannot add more books.\n");
        return;
    }

    Book *new_book = (Book *)malloc(sizeof(Book));
    if (new_book == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &(new_book->id));
    getchar();  // Clear the newline character from the buffer

    printf("Enter book title: ");
    fgets(new_book->title, MAX_TITLE_LENGTH, stdin);
    new_book->title[strcspn(new_book->title, "\n")] = 0;  // Remove newline

    printf("Enter book author: ");
    fgets(new_book->author, MAX_AUTHOR_LENGTH, stdin);
    new_book->author[strcspn(new_book->author, "\n")] = 0;  // Remove newline

    database[current_size] = new_book;
    current_size++;

    printf("Book added successfully!\n");
}

void view_books() {
    if (current_size == 0) {
        printf("No books in the database.\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < current_size; i++) {
        printf("ID: %d | Title: %s | Author: %s\n", database[i]->id, database[i]->title, database[i]->author);
    }
}

void search_book() {
    if (current_size == 0) {
        printf("No books in the database.\n");
        return;
    }

    int search_id;
    printf("Enter book ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < current_size; i++) {
        if (database[i]->id == search_id) {
            printf("Book found: ID: %d | Title: %s | Author: %s\n", database[i]->id, database[i]->title, database[i]->author);
            return;
        }
    }
    
    printf("Book with ID %d not found.\n", search_id);
}

void delete_book() {
    if (current_size == 0) {
        printf("No books in the database to delete.\n");
        return;
    }

    int id_to_delete;
    printf("Enter book ID to delete: ");
    scanf("%d", &id_to_delete);

    for (int i = 0; i < current_size; i++) {
        if (database[i]->id == id_to_delete) {
            free(database[i]);
            for (int j = i; j < current_size - 1; j++) {
                database[j] = database[j + 1];
            }
            current_size--;
            printf("Book with ID %d deleted successfully.\n", id_to_delete);
            return;
        }
    }

    printf("Book with ID %d not found.\n", id_to_delete);
}

void free_memory() {
    for (int i = 0; i < current_size; i++) {
        free(database[i]);
    }
}

int main() {
    while (1) {
        printf("\nBook Database Menu:\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        
        int choice;
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
                delete_book();
                break;
            case 5:
                free_memory();
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}