//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_SIZE 100
#define AUTHOR_SIZE 100

typedef struct {
    int id;
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
    int year;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void initializeLibrary(Library* lib) {
    lib->count = 0;
}

void addBook(Library* lib) {
    if (lib->count >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return;
    }
    Book newBook;
    newBook.id = lib->count + 1;
    
    printf("Enter book title: ");
    getchar(); // consume newline
    fgets(newBook.title, TITLE_SIZE, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // remove newline

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_SIZE, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // remove newline

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);

    lib->books[lib->count] = newBook;
    lib->count++;
    printf("Book added successfully.\n");
}

void listBooks(const Library* lib) {
    if (lib->count == 0) {
        printf("No books in library.\n");
        return;
    }
    printf("Books in Library:\n");
    printf("ID\tTitle\t\tAuthor\t\tYear\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < lib->count; i++) {
        printf("%d\t%s\t%s\t%d\n", lib->books[i].id, lib->books[i].title, lib->books[i].author, lib->books[i].year);
    }
}

void findBook(const Library* lib) {
    if (lib->count == 0) {
        printf("No books to search.\n");
        return;
    }

    int search_id;
    printf("Enter book ID to search: ");
    scanf("%d", &search_id);

    if (search_id < 1 || search_id > lib->count) {
        printf("Book not found.\n");
        return;
    }
    
    Book foundBook = lib->books[search_id - 1];
    printf("Book found:\n");
    printf("ID: %d\n", foundBook.id);
    printf("Title: %s\n", foundBook.title);
    printf("Author: %s\n", foundBook.author);
    printf("Year: %d\n", foundBook.year);
}

void deleteBook(Library* lib) {
    if (lib->count == 0) {
        printf("No books to delete.\n");
        return;
    }

    int delete_id;
    printf("Enter book ID to delete: ");
    scanf("%d", &delete_id);

    if (delete_id < 1 || delete_id > lib->count) {
        printf("Invalid ID. Book not found.\n");
        return;
    }

    for (int i = delete_id - 1; i < lib->count - 1; i++) {
        lib->books[i] = lib->books[i + 1];
    }
    
    lib->count--;
    printf("Book deleted successfully.\n");
}

void showMenu() {
    printf("\nLibrary Menu:\n");
    printf("1. Add Book\n");
    printf("2. List Books\n");
    printf("3. Find Book\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Library myLibrary;
    initializeLibrary(&myLibrary);
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook(&myLibrary);
                break;
            case 2:
                listBooks(&myLibrary);
                break;
            case 3:
                findBook(&myLibrary);
                break;
            case 4:
                deleteBook(&myLibrary);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}