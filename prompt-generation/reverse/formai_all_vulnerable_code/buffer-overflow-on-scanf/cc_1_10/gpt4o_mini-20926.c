//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

void addBook(Book* library, int* count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Can't add more books.\n");
        return;
    }
    
    printf("Enter book title: ");
    fgets(library[*count].title, MAX_TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = '\0'; // Remove newline

    printf("Enter book content: ");
    fgets(library[*count].content, MAX_CONTENT_LENGTH, stdin);
    library[*count].content[strcspn(library[*count].content, "\n")] = '\0'; // Remove newline

    (*count)++;
    printf("Book '%s' added successfully!\n", library[*count - 1].title);
}

void displayBooks(Book* library, int count) {
    if (count == 0) {
        printf("No books in the library yet.\n");
        return;
    }

    printf("\nBooks in Library:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
    }
}

void readBook(Book* library, int count) {
    int choice;
    printf("Select a book number to read (1 - %d): ", count);
    scanf("%d", &choice);
    getchar(); // Consume leftover newline

    if (choice < 1 || choice > count) {
        printf("Invalid choice, please try again.\n");
        return;
    }

    printf("\nReading '%s':\n", library[choice - 1].title);
    printf("%s\n", library[choice - 1].content);
}

void searchBook(Book* library, int count) {
    char query[MAX_TITLE_LENGTH];
    printf("Enter title to search: ");
    fgets(query, MAX_TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, query) != NULL) {
            printf("Found: %s\n", library[i].title);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found with the title containing '%s'.\n", query);
    }
}

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int option;

    while (1) {
        printf("\n=== Curious eBook Reader ===\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Read Book\n");
        printf("4. Search Book\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        getchar(); // Consume leftover newline

        switch (option) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                readBook(library, bookCount);
                break;
            case 4:
                searchBook(library, bookCount);
                break;
            case 5:
                printf("Exiting the curious reader. Happy reading!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}