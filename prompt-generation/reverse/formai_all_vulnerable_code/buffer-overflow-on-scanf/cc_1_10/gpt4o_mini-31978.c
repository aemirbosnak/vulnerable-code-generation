//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    struct Book* next;
} Book;

Book* createBook(const char* title) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strncpy(newBook->title, title, sizeof(newBook->title) - 1);
    newBook->title[sizeof(newBook->title) - 1] = '\0'; // Ensure null-termination
    newBook->next = NULL;
    return newBook;
}

void addBook(Book** head, const char* title) {
    Book* newBook = createBook(title);
    if (newBook == NULL) return;

    newBook->next = *head;
    *head = newBook;
    printf("Book \"%s\" added to the library!\n", title);
}

void deleteBook(Book** head, const char* title) {
    Book* temp = *head, *prev = NULL;
    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Book \"%s\" not found in the library!\n", title);
        return;
    }
    if (prev == NULL) {
        *head = temp->next; // Remove the first book
    } else {
        prev->next = temp->next; // Bypass the deleted book
    }
    free(temp);
    printf("Book \"%s\" removed from the library!\n", title);
}

void searchBook(Book* head, const char* title) {
    Book* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            printf("Found the book: \"%s\"\n", title);
            return;
        }
        temp = temp->next;
    }
    printf("Book \"%s\" not found in the library!\n", title);
}

void displayBooks(Book* head) {
    if (head == NULL) {
        printf("The library is empty!\n");
        return;
    }
    printf("Books in the library:\n");
    while (head != NULL) {
        printf("- %s\n", head->title);
        head = head->next;
    }
}

void freeLibrary(Book* head) {
    Book* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Book* library = NULL;
    int choice;
    char title[100];

    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. Display Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume trailing newline

        switch (choice) {
            case 1:
                printf("Enter the title of the book: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                addBook(&library, title);
                break;
            case 2:
                printf("Enter the title of the book to delete: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                deleteBook(&library, title);
                break;
            case 3:
                printf("Enter the title of the book to search: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                searchBook(library, title);
                break;
            case 4:
                displayBooks(library);
                break;
            case 5:
                freeLibrary(library);
                printf("Exiting the library management system...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}