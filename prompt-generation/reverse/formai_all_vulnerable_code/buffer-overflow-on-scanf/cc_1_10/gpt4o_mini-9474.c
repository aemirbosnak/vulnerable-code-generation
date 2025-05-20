//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100
#define FILENAME "books.txt"

typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
} Book;

void initializeDatabase();
void addBook();
void displayBooks();
void searchBook();
int getNextId();

int main() {
    int choice;

    initializeDatabase();

    do {
        printf("\n=== Book Database Menu ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch(choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void initializeDatabase() {
    FILE *file = fopen(FILENAME, "a+");
    if (file == NULL) {
        perror("Failed to open database file");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void addBook() {
    Book book;
    book.id = getNextId();

    printf("Enter book title: ");
    fgets(book.title, TITLE_LEN, stdin);
    book.title[strcspn(book.title, "\n")] = 0; // Remove newline character

    printf("Enter book author: ");
    fgets(book.author, AUTHOR_LEN, stdin);
    book.author[strcspn(book.author, "\n")] = 0; // Remove newline character

    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Failed to open database file");
        return;
    }

    fprintf(file, "%d;%s;%s\n", book.id, book.title, book.author);
    fclose(file);
    printf("Book added successfully!\n");
}

void displayBooks() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Failed to open database file");
        return;
    }

    printf("\n=== Books in Database ===\n");
    char line[250];
    while (fgets(line, sizeof(line), file)) {
        Book book;
        sscanf(line, "%d;%99[^;];%99[^;]", &book.id, book.title, book.author);
        printf("ID: %d, Title: %s, Author: %s\n", book.id, book.title, book.author);
    }
    fclose(file);
}

void searchBook() {
    char searchTitle[TITLE_LEN];
    printf("Enter the title to search for: ");
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Failed to open database file");
        return;
    }

    printf("\n=== Search Results ===\n");
    char line[250];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        Book book;
        sscanf(line, "%d;%99[^;];%99[^;]", &book.id, book.title, book.author);
        if (strstr(book.title, searchTitle) != NULL) {
            printf("ID: %d, Title: %s, Author: %s\n", book.id, book.title, book.author);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found with the title containing '%s'.\n", searchTitle);
    }
    fclose(file);
}

int getNextId() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return 1; // Start IDs from 1 if file doesn't exist
    }

    char line[250];
    int maxId = 0;

    while (fgets(line, sizeof(line), file)) {
        Book book;
        sscanf(line, "%d;%99[^;];%99[^;]", &book.id, book.title, book.author);
        if (book.id > maxId) {
            maxId = book.id;
        }
    }

    fclose(file);
    return maxId + 1; // Return next available ID
}