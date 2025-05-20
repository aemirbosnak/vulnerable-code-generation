//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

struct Book {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int id;
};

struct Library {
    struct Book books[MAX_BOOKS];
    int count;
};

void initializeLibrary(struct Library *library) {
    library->count = 0;
}

void addBook(struct Library *library) {
    if (library->count < MAX_BOOKS) {
        struct Book newBook;
        printf("Enter the title of the book: ");
        getchar(); // clear input buffer
        fgets(newBook.title, TITLE_LENGTH, stdin);
        strtok(newBook.title, "\n"); // remove newline
        printf("Enter the author's name: ");
        fgets(newBook.author, AUTHOR_LENGTH, stdin);
        strtok(newBook.author, "\n"); // remove newline
        newBook.id = library->count + 1; // simple ID assignment
        library->books[library->count++] = newBook;
        printf("A new treasure has been added: \"%s\" by %s!\n\n", newBook.title, newBook.author);
    } else {
        printf("Alas! The library is already filled with love stories.\n\n");
    }
}

void showBooks(struct Library *library) {
    if (library->count > 0) {
        printf("The library of love contains:\n");
        for (int i = 0; i < library->count; i++) {
            printf("[%d] \"%s\" by %s\n", library->books[i].id, library->books[i].title, library->books[i].author);
        }
    } else {
        printf("Oh dear! The shelves are empty, longing for stories.\n");
    }
    printf("\n");
}

void searchBook(struct Library *library) {
    char title[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // clear input buffer
    fgets(title, TITLE_LENGTH, stdin);
    strtok(title, "\n"); // remove newline

    for (int i = 0; i < library->count; i++) {
        if (strstr(library->books[i].title, title) != NULL) {
            printf("Found your beloved book: \"%s\" by %s\n", library->books[i].title, library->books[i].author);
            return;
        }
    }
    printf("Alas, no book contains that title in our enchanting collection.\n");
}

void deleteBook(struct Library *library) {
    int id;
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > library->count) {
        printf("Oh no, that book is not in our library of love.\n");
        return;
    }

    for (int i = id - 1; i < library->count - 1; i++) {
        library->books[i] = library->books[i + 1];
    }
    library->count--;
    printf("The bittersweet farewell of the book is complete.\n\n");
}

void menu() {
    printf("Welcome to the Library of Love\n");
    printf("1. Add a Book\n");
    printf("2. Show Books\n");
    printf("3. Search a Book\n");
    printf("4. Delete a Book\n");
    printf("5. Exit\n");
}

int main() {
    struct Library library;
    initializeLibrary(&library);

    int choice;
    do {
        menu();
        printf("Choose a romantic option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&library);
                break;
            case 2:
                showBooks(&library);
                break;
            case 3:
                searchBook(&library);
                break;
            case 4:
                deleteBook(&library);
                break;
            case 5:
                printf("Farewell, dear friend! Until we meet again in the realm of stories.\n");
                break;
            default:
                printf("Only dreams can take us to options that are not here!\n");
        }
    } while (choice != 5);

    return 0;
}