//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50
#define FILE_NAME "library.dat"

// Structure to hold book information
typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

// Function prototypes
void addBook(Book *library, int *count);
void displayBooks(Book *library, int count);
void searchBook(Book *library, int count);
void saveToFile(Book *library, int count);
void loadFromFile(Book *library, int *count);

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    loadFromFile(library, &bookCount);

    do {
        printf("\n*** Library Management System ***\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Save Books to File\n");
        printf("5. Load Books from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

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
                saveToFile(library, bookCount);
                break;
            case 5:
                loadFromFile(library, &bookCount);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to add a book to the library
void addBook(Book *library, int *count) {
    if (*count < MAX_BOOKS) {
        printf("Enter book title: ");
        fgets(library[*count].title, TITLE_LENGTH, stdin);
        library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove newline

        printf("Enter author name: ");
        fgets(library[*count].author, AUTHOR_LENGTH, stdin);
        library[*count].author[strcspn(library[*count].author, "\n")] = 0;

        printf("Enter publication year: ");
        scanf("%d", &library[*count].year);
        getchar(); // consume newline

        (*count)++;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full! Cannot add more books.\n");
    }
}

// Function to display all books in the library
void displayBooks(Book *library, int count) {
    if (count == 0) {
        printf("No books available in the library.\n");
    } else {
        printf("\n*** List of Books ***\n");
        for (int i = 0; i < count; i++) {
            printf("Title: %s, Author: %s, Year: %d\n",
                   library[i].title, library[i].author, library[i].year);
        }
    }
}

// Function to search for a book by title
void searchBook(Book *library, int count) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter book title to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("Found Book - Title: %s, Author: %s, Year: %d\n",
                   library[i].title, library[i].author, library[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found in the library.\n");
    }
}

// Function to save books to a file
void saveToFile(Book *library, int count) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file != NULL) {
        fwrite(library, sizeof(Book), count, file);
        fclose(file);
        printf("Books saved to file successfully!\n");
    } else {
        printf("Error saving to file.\n");
    }
}

// Function to load books from a file
void loadFromFile(Book *library, int *count) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file != NULL) {
        *count = fread(library, sizeof(Book), MAX_BOOKS, file);
        fclose(file);
        printf("Books loaded from file successfully!\n");
    } else {
        printf("No existing library data found. Starting fresh!\n");
    }
}