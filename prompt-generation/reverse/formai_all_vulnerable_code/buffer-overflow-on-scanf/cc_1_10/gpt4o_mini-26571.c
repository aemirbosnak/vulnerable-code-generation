//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define MAX_BOOKS 100
#define TITLE_LEN 256
#define AUTHOR_LEN 256

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    char* content;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void loadBook(Library* library, int index, const char* title, const char* author, const char* filename) {
    strncpy(library->books[index].title, title, TITLE_LEN);
    strncpy(library->books[index].author, author, AUTHOR_LEN);
    library->books[index].content = NULL;

    FILE* file = fopen(filename, "r");
    if (file) {
        fseek(file, 0, SEEK_END);
        long length = ftell(file);
        fseek(file, 0, SEEK_SET);
        
        library->books[index].content = malloc(length + 1);
        fread(library->books[index].content, 1, length, file);
        library->books[index].content[length] = '\0'; // Null-terminate the string
        
        fclose(file);
    } else {
        fprintf(stderr, "Could not open file %s\n", filename);
    }
}

void addBookToLibrary(Library* library, const char* title, const char* author, const char* filename) {
    if (library->count < MAX_BOOKS) {
        loadBook(library, library->count, title, author, filename);
        library->count++;
    } else {
        fprintf(stderr, "Library is full.\n");
    }
}

void displayBook(const Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Content:\n%s\n", book->content);
}

void searchBookByTitle(Library* library, const char* title) {
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->books[i].title, title) == 0) {
            displayBook(&library->books[i]);
            return;
        }
    }
    printf("Book titled '%s' not found in the library.\n", title);
}

void cleanupLibrary(Library* library) {
    for (int i = 0; i < library->count; i++) {
        free(library->books[i].content);
    }
}

void displayMenu() {
    printf("E-Book Reader Menu:\n");
    printf("1. Add a new book\n");
    printf("2. Search for a book by title\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Library library = { .count = 0 };
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline

        if (choice == 1) {
            char title[TITLE_LEN], author[AUTHOR_LEN], filename[MAX_LEN];
            printf("Enter title: ");
            fgets(title, TITLE_LEN, stdin);
            title[strcspn(title, "\n")] = 0; // Remove newline
            
            printf("Enter author: ");
            fgets(author, AUTHOR_LEN, stdin);
            author[strcspn(author, "\n")] = 0; // Remove newline

            printf("Enter filename: ");
            fgets(filename, MAX_LEN, stdin);
            filename[strcspn(filename, "\n")] = 0; // Remove newline
            
            addBookToLibrary(&library, title, author, filename);
        } else if (choice == 2) {
            char title[TITLE_LEN];
            printf("Enter title to search: ");
            fgets(title, TITLE_LEN, stdin);
            title[strcspn(title, "\n")] = 0; // Remove newline
            
            searchBookByTitle(&library, title);
        } else if (choice == 3) {
            cleanupLibrary(&library);
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}