//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100
#define FILENAME "library.txt"

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

void addBook() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    
    Book book;
    printf("Enter book title: ");
    fgets(book.title, TITLE_LENGTH, stdin);
    book.title[strcspn(book.title, "\n")] = '\0'; // Remove newline character
    
    printf("Enter author name: ");
    fgets(book.author, AUTHOR_LENGTH, stdin);
    book.author[strcspn(book.author, "\n")] = '\0'; // Remove newline character
    
    printf("Enter publication year: ");
    scanf("%d", &book.year);
    getchar(); // To consume the newline left by scanf
    
    fprintf(file, "%s;%s;%d\n", book.title, book.author, book.year);
    fclose(file);
    printf("Book added successfully!\n\n");
}

void displayBooks() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    
    char line[255];
    printf("\nList of Books:\n");
    printf("--------------------------------------------------\n");
    while (fgets(line, sizeof(line), file)) {
        char title[TITLE_LENGTH];
        char author[AUTHOR_LENGTH];
        int year;

        sscanf(line, "%[^;];%[^;];%d\n", title, author, &year);
        printf("Title: %s\n", title);
        printf("Author: %s\n", author);
        printf("Year: %d\n", year);
        printf("--------------------------------------------------\n");
    }
    
    fclose(file);
}

void searchBook() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    
    char searchTitle[TITLE_LENGTH];
    printf("Enter title of the book to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // Remove newline character

    char line[255];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char title[TITLE_LENGTH];
        char author[AUTHOR_LENGTH];
        int year;

        sscanf(line, "%[^;];%[^;];%d\n", title, author, &year);
        if (strcmp(title, searchTitle) == 0) {
            printf("Book Found!\n");
            printf("Title: %s\n", title);
            printf("Author: %s\n", author);
            printf("Year: %d\n", year);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No book found with the title: %s\n", searchTitle);
    }

    fclose(file);
}

void displayMenu() {
    printf("Library Management System\n");
    printf("1. Add a Book\n");
    printf("2. Display All Books\n");
    printf("3. Search for a Book\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}