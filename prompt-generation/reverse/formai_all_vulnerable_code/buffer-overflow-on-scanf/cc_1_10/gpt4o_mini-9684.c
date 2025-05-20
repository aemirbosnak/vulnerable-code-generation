//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 50

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
} Book;

Book* library[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return;
    }
    
    library[book_count] = (Book*)malloc(sizeof(Book));
    if (library[book_count] == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    printf("Enter book title: ");
    getchar(); // To consume newline left in the buffer
    fgets(library[book_count]->title, TITLE_LEN, stdin);
    library[book_count]->title[strcspn(library[book_count]->title, "\n")] = 0; // Remove newline
    
    printf("Enter author name: ");
    fgets(library[book_count]->author, AUTHOR_LEN, stdin);
    library[book_count]->author[strcspn(library[book_count]->author, "\n")] = 0; // Remove newline

    printf("Enter publication year: ");
    scanf("%d", &library[book_count]->year);
    
    book_count++;
    printf("Book added successfully!\n");
}

void view_books() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }
    
    printf("\nList of Books in the Library:\n");
    for (int i = 0; i < book_count; i++) {
        printf("Book %d: %s by %s (%d)\n", i + 1, library[i]->title, library[i]->author, library[i]->year);
    }
}

void search_books() {
    char search_title[TITLE_LEN];
    printf("Enter title or author to search: ");
    getchar(); // To consume newline left in the buffer
    fgets(search_title, TITLE_LEN, stdin);
    search_title[strcspn(search_title, "\n")] = 0; // Remove newline

    printf("\nSearch Results:\n");
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strstr(library[i]->title, search_title) || strstr(library[i]->author, search_title)) {
            printf("Found: %s by %s (%d)\n", library[i]->title, library[i]->author, library[i]->year);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found matching the search criteria.\n");
    }
}

void free_memory() {
    for (int i = 0; i < book_count; i++) {
        free(library[i]);
    }
}

int main() {
    int choice;
    do {
        printf("\nLibrary Database Simulation\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Books\n");
        printf("4. Exit\n");
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
                search_books();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
    
    free_memory();
    return 0;
}