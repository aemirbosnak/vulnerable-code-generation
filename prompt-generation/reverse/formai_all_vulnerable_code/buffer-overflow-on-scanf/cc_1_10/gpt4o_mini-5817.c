//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
    int isAvailable; // 1 for available, 0 for checked out
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void initializeLibrary(Library *library) {
    library->count = 0;
}

void addBook(Library *library, const char *title, const char *author, int year) {
    if (library->count < MAX_BOOKS) {
        strcpy(library->books[library->count].title, title);
        strcpy(library->books[library->count].author, author);
        library->books[library->count].year = year;
        library->books[library->count].isAvailable = 1; // Initially available
        library->count++;
        printf("Added: '%s' by %s (%d)\n", title, author, year);
    } else {
        printf("Library is full, cannot add more books.\n");
    }
}

void listBooks(Library *library) {
    printf("\n--- Post-Apocalyptic Library ---\n");
    for (int i = 0; i < library->count; i++) {
        Book *b = &library->books[i];
        printf("%d: '%s' by %s (%d) [%s]\n", 
                i + 1, 
                b->title, 
                b->author, 
                b->year, 
                b->isAvailable ? "Available" : "Checked Out");
    }
    printf("---------------------------------\n");
}

void checkOutBook(Library *library, int index) {
    if (index < 0 || index >= library->count) {
        printf("Invalid book number.\n");
        return;
    }
    if (library->books[index].isAvailable) {
        library->books[index].isAvailable = 0; // Mark as checked out
        printf("Checked out: '%s'\n", library->books[index].title);
    } else {
        printf("'%s' is already checked out.\n", library->books[index].title);
    }
}

void returnBook(Library *library, int index) {
    if (index < 0 || index >= library->count) {
        printf("Invalid book number.\n");
        return;
    }
    if (!library->books[index].isAvailable) {
        library->books[index].isAvailable = 1; // Mark as available
        printf("Returned: '%s'\n", library->books[index].title);
    } else {
        printf("'%s' was not checked out.\n", library->books[index].title);
    }
}

void searchBook(Library *library, const char *keyword) {
    printf("\nSearching for: '%s'\n", keyword);
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->books[i].title, keyword) || 
            strstr(library->books[i].author, keyword)) {
            printf("Found: '%s' by %s (%d) [%s]\n", 
                    library->books[i].title,
                    library->books[i].author,
                    library->books[i].year,
                    library->books[i].isAvailable ? "Available" : "Checked Out");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found matching '%s'.\n", keyword);
    }
}

int main() {
    Library library;
    initializeLibrary(&library);

    char command[10];
    while (1) {
        printf("\nCommand (add/list/checkout/return/search/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char title[MAX_TITLE_LENGTH], author[MAX_AUTHOR_LENGTH];
            int year;
            printf("Enter title: ");
            getchar(); // Clear newline from input buffer
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // Remove newline
            printf("Enter author: ");
            fgets(author, sizeof(author), stdin);
            author[strcspn(author, "\n")] = 0; // Remove newline
            printf("Enter year: ");
            scanf("%d", &year);
            addBook(&library, title, author, year);
        } else if (strcmp(command, "list") == 0) {
            listBooks(&library);
        } else if (strcmp(command, "checkout") == 0) {
            int index;
            printf("Enter the book number to check out: ");
            scanf("%d", &index);
            checkOutBook(&library, index - 1);
        } else if (strcmp(command, "return") == 0) {
            int index;
            printf("Enter the book number to return: ");
            scanf("%d", &index);
            returnBook(&library, index - 1);
        } else if (strcmp(command, "search") == 0) {
            char keyword[MAX_TITLE_LENGTH];
            printf("Enter keyword to search: ");
            getchar(); // Clear newline from input buffer
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = 0; // Remove newline
            searchBook(&library, keyword);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the Library Management System. Survive well!\n");
            break;
        } else {
            printf("Unknown command. Survive when the library is scarce!\n");
        }
    }

    return 0;
}