//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int isAvailable;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void addBook();
void displayBooks();
void searchBook();
void deleteBook();
void displayMenu();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline character
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                printf("Exiting the program. Bye Bye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Library Management System ---\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
    printf("---------------------------------\n");
}

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Can't add more books.\n");
        return;
    }
    printf("Enter book title: ");
    fgets(library[book_count].title, TITLE_LEN, stdin);
    library[book_count].title[strcspn(library[book_count].title, "\n")] = '\0'; // remove newline
    printf("Enter author name: ");
    fgets(library[book_count].author, AUTHOR_LEN, stdin);
    library[book_count].author[strcspn(library[book_count].author, "\n")] = '\0'; // remove newline
    library[book_count].isAvailable = 1; // indicates the book is available
    book_count++;
    printf("Book added successfully!\n");
}

void displayBooks() {
    if (book_count == 0) {
        printf("No books in the library yet!\n");
        return;
    }
    printf("\n--- List of Books ---\n");
    for (int i = 0; i < book_count; i++) {
        printf("Book %d: Title: '%s', Author: '%s', Available: %s\n",
                i + 1,
                library[i].title,
                library[i].author,
                library[i].isAvailable ? "Yes" : "No");
    }
}

void searchBook() {
    char title[TITLE_LEN];
    printf("Enter the title of the book you want to search: ");
    fgets(title, TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = '\0'; // remove newline
    int found = 0;

    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(library[i].title, title) == 0) {
            printf("Book found! Title: '%s', Author: '%s', Available: %s\n",
                    library[i].title,
                    library[i].author,
                    library[i].isAvailable ? "Yes" : "No");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found!\n");
    }
}

void deleteBook() {
    char title[TITLE_LEN];
    printf("Enter the title of the book you want to delete: ");
    fgets(title, TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = '\0'; // remove newline
    int found = 0;

    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(library[i].title, title) == 0) {
            found = 1;
            for (int j = i; j < book_count - 1; j++) {
                library[j] = library[j + 1]; // shift books to fill the gap
            }
            book_count--;
            printf("Book '%s' deleted successfully!\n", title);
            break;
        }
    }
    if (!found) {
        printf("Book not found, can't delete!\n");
    }
}