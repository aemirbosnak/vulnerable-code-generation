//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50

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
    
    printf("Enter book title: ");
    getchar(); // consume the newline character
    fgets(library[*count].title, TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = '\0'; // remove newline

    printf("Enter book author: ");
    fgets(library[*count].author, AUTHOR_LENGTH, stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = '\0'; // remove newline

    printf("Enter publication year: ");
    scanf("%d", &library[*count].year);
    
    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(Book *library, int count) {
    if (count == 0) {
        printf("There are no books in the library!\n");
        return;
    }
    
    printf("\nLibrary Books:\n");
    for (int i = 0; i < count; i++) {
        printf(" %d. %s by %s (%d)\n", i + 1, library[i].title, library[i].author, library[i].year);
    }
}

void searchBook(Book *library, int count) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar();
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // remove newline
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("Found: %s by %s (%d)\n", library[i].title, library[i].author, library[i].year);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found in the library!\n");
}

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    do {
        printf("\n=== Welcome to the Book Library ===\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Exit\n");
        printf("Please select an option (1-4): ");
        scanf("%d", &choice);
        
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
                printf("Exiting... Thanks for using the Book Library!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}