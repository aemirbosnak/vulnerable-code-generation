//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int published_year;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void initialize_library(Library *library) {
    library->count = 0;
}

void add_book(Library *library, const char *title, const char *author, int year) {
    if (library->count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    strncpy(library->books[library->count].title, title, TITLE_LENGTH);
    strncpy(library->books[library->count].author, author, AUTHOR_LENGTH);
    library->books[library->count].published_year = year;
    library->count++;
    printf("Book added: %s by %s (%d)\n", title, author, year);
}

void list_books(const Library *library) {
    if (library->count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\nListing all books in the library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. \"%s\" by %s (%d)\n", i + 1,
               library->books[i].title,
               library->books[i].author,
               library->books[i].published_year);
    }
}

void search_book(const Library *library, const char *search_term) {
    printf("\nSearching for books matching: \"%s\"\n", search_term);
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->books[i].title, search_term) || 
            strstr(library->books[i].author, search_term)) {
            printf("Found: \"%s\" by %s (%d)\n", 
                   library->books[i].title,
                   library->books[i].author,
                   library->books[i].published_year);
            found = 1;
        }
    }
    if (!found) {
        printf("No books matched the search term.\n");
    }
}

void delete_book(Library *library, int index) {
    if (index < 0 || index >= library->count) {
        printf("Invalid book index: %d. No book deleted.\n", index);
        return;
    }
    for (int i = index; i < library->count - 1; i++) {
        library->books[i] = library->books[i + 1];
    }
    library->count--;
    printf("Book at index %d deleted.\n", index);
}

int main() {
    Library library;
    initialize_library(&library);

    int choice;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
    char search_term[TITLE_LENGTH];

    while (1) {
        printf("\nLibrary Menu:\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline character
                printf("Enter author name: ");
                fgets(author, AUTHOR_LENGTH, stdin);
                author[strcspn(author, "\n")] = '\0'; // Remove newline character
                printf("Enter published year: ");
                scanf("%d", &year);
                add_book(&library, title, author, year);
                break;
            case 2:
                list_books(&library);
                break;
            case 3:
                printf("Enter search term: ");
                fgets(search_term, TITLE_LENGTH, stdin);
                search_term[strcspn(search_term, "\n")] = '\0'; // Remove newline character
                search_book(&library, search_term);
                break;
            case 4:
                printf("Enter book index to delete: ");
                int index;
                scanf("%d", &index);
                delete_book(&library, index - 1); // Adjust for 0-based index
                break;
            case 5:
                printf("Exiting the library program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}