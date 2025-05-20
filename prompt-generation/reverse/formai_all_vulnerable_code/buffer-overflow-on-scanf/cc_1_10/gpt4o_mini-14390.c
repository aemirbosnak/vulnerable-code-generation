//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_BOOKS 50

typedef struct {
    char title[MAX_NAME_LENGTH];
    char author[MAX_NAME_LENGTH];
    int year;
    float rating;
} Book;

void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Cannot add more books, library is full!\n");
        return;
    }
    printf("Enter Book Title: ");
    fgets(library[*count].title, MAX_NAME_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove newline
    printf("Enter Author Name: ");
    fgets(library[*count].author, MAX_NAME_LENGTH, stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = 0; // Remove newline
    printf("Enter Year of Publication: ");
    scanf("%d", &library[*count].year);
    printf("Enter Rating (0-5): ");
    scanf("%f", &library[*count].rating);
    getchar(); // Clear the newline from the input buffer
    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(Book *library, int count) {
    if (count == 0) {
        printf("No books available in the library!\n");
        return;
    }
    printf("\n---Library Catalog---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Year: %d\n", library[i].year);
        printf("Rating: %.1f\n", library[i].rating);
        printf("-------------------------\n");
    }
}

void searchBookByTitle(Book *library, int count) {
    char searchTitle[MAX_NAME_LENGTH];
    printf("Enter title of the book to search: ");
    fgets(searchTitle, MAX_NAME_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, searchTitle) != NULL) {
            printf("Found: %s by %s, %d (Rating: %.1f)\n", library[i].title, library[i].author, library[i].year, library[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("No matching book found for title: %s\n", searchTitle);
    }
}

void deleteBook(Book *library, int *count) {
    if (*count == 0) {
        printf("No books available to delete!\n");
        return;
    }
    char titleToDelete[MAX_NAME_LENGTH];
    printf("Enter the title of the book to delete: ");
    fgets(titleToDelete, MAX_NAME_LENGTH, stdin);
    titleToDelete[strcspn(titleToDelete, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].title, titleToDelete) == 0) {
            // Shift books down
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1];
            }
            (*count)--;
            printf("Book '%s' deleted successfully!\n", titleToDelete);
            return;
        }
    }
    printf("No matching book found for title: %s\n", titleToDelete);
}

void displayMenu() {
    printf("\n---Library Management System---\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book by Title\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear the newline from the input buffer
        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                displayBooks(library, count);
                break;
            case 3:
                searchBookByTitle(library, count);
                break;
            case 4:
                deleteBook(library, &count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    return 0;
}