//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 30

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    
    Book newBook;
    printf("Enter book title: ");
    getchar(); // To consume the newline character left by previous input
    fgets(newBook.title, TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);

    library[bookCount++] = newBook;
    printf("Book added successfully!\n");
}

void viewBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    
    printf("\nLibrary Collection:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book %d:\n", i + 1);
        printf("\tTitle: %s\n", library[i].title);
        printf("\tAuthor: %s\n", library[i].author);
        printf("\tYear: %d\n\n", library[i].year);
    }
}

void searchBook() {
    char searchTitle[TITLE_LEN];
    printf("Enter the title of the book to search: ");
    getchar(); // Consume newline
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("Found Book:\n");
            printf("\tTitle: %s\n", library[i].title);
            printf("\tAuthor: %s\n", library[i].author);
            printf("\tYear: %d\n", library[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No book found with the title '%s'.\n", searchTitle);
    }
}

void deleteBook() {
    char deleteTitle[TITLE_LEN];
    printf("Enter the title of the book to delete: ");
    getchar(); // Consume newline
    fgets(deleteTitle, TITLE_LEN, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline character
    
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcasecmp(library[i].title, deleteTitle) == 0) {
            found = 1;
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1]; // Shift books left
            }
            bookCount--;
            printf("Book '%s' deleted successfully!\n", deleteTitle);
            break;
        }
    }
    if (!found) {
        printf("No book found with the title '%s'.\n", deleteTitle);
    }
}

void showMenu() {
    printf("\n=== Simple Book Database ===\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Search Book\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
    printf("============================\n");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}