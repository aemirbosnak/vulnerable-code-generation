//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: irregular
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

// Function Prototypes
void addBook();
void searchBook();
void displayBooks();
void flushInputBuffer();

int main() {
    int choice;
    do {
        printf("==== Library Management System ====\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Display All Books\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        flushInputBuffer(); // Clear the buffer

        switch (choice) {
            case 1: 
                addBook();
                break;
            case 2: 
                searchBook();
                break;
            case 3: 
                displayBooks();
                break;
            case 4: 
                printf("Exiting... Goodbye!\n");
                break;
            default: 
                printf("Invalid option. Try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return;
    }

    printf("Enter the book title: ");
    fgets(library[bookCount].title, TITLE_LEN, stdin);
    library[bookCount].title[strcspn(library[bookCount].title, "\n")] = 0; // Remove newline character

    printf("Enter the author's name: ");
    fgets(library[bookCount].author, AUTHOR_LEN, stdin);
    library[bookCount].author[strcspn(library[bookCount].author, "\n")] = 0; // Remove newline character

    printf("Enter the publication year: ");
    scanf("%d", &library[bookCount].year);
    flushInputBuffer(); // Clear the buffer

    printf("Book added successfully!\n");
    bookCount++;
}

void searchBook() {
    char searchTitle[TITLE_LEN];
    printf("Enter the title to search for: ");
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    for (int i = 0; i < bookCount; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("Book found: %s by %s (%d)\n", library[i].title, library[i].author, library[i].year);
            return;
        }
    }
    printf("Book not found in the library.\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("=== All Available Books ===\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, library[i].title, library[i].author, library[i].year);
    }
}

void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}