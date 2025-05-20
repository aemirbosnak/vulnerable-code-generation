//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 30

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter title of the book: ");
    fgets(library[*count].title, TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove newline

    printf("Enter author of the book: ");
    fgets(library[*count].author, AUTHOR_LENGTH, stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = 0; // Remove newline

    printf("Enter year of publication: ");
    scanf("%d", &library[*count].year);
    getchar(); // Clear newline from input buffer

    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(const Book *library, int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nLibrary Collection:\n");
    printf("%-30s %-25s %-6s\n", "Title", "Author", "Year");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-30s %-25s %-6d\n", library[i].title, library[i].author, library[i].year);
    }
}

void searchBook(const Book *library, int count) {
    char query[TITLE_LENGTH];
    printf("Enter title or author to search: ");
    fgets(query, TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = 0; // Remove newline

    int found = 0;
    printf("\nSearch Results:\n");
    printf("%-30s %-25s %-6s\n", "Title", "Author", "Year");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, query) != NULL || strstr(library[i].author, query) != NULL) {
            printf("%-30s %-25s %-6d\n", library[i].title, library[i].author, library[i].year);
            found++;
        }
    }

    if (found == 0) {
        printf("No books found matching the search criteria.\n");
    }
}

void removeBook(Book *library, int *count) {
    char titleToRemove[TITLE_LENGTH];
    printf("Enter title of the book to remove: ");
    fgets(titleToRemove, TITLE_LENGTH, stdin);
    titleToRemove[strcspn(titleToRemove, "\n")] = 0; // Remove newline

    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].title, titleToRemove) == 0) {
            // Shift books down to fill the gap
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1];
            }
            (*count)--;
            printf("Book removed successfully!\n");
            return;
        }
    }

    printf("Book not found!\n");
}

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Remove Book\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                removeBook(library, &bookCount);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}