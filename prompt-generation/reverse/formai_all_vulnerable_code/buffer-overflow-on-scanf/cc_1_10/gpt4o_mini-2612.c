//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the Book
typedef struct Book {
    int id;
    char title[100];
    char author[50];
    struct Book* next;
} Book;

// Function prototypes
Book* createBook(int id, const char* title, const char* author);
void appendBook(Book** head_ref, int id, const char* title, const char* author);
void deleteBook(Book** head_ref, int id);
void displayBooks(Book* node);
void freeList(Book* head);

int main() {
    Book* head = NULL; // Initialize the head of the linked list
    int choice, id;
    char title[100];
    char author[50];

    // Main menu loop
    do {
        printf("\n--- Book Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Display Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                printf("Enter Book Title: ");
                getchar(); // To consume the newline character left by scanf
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline from title
                printf("Enter Book Author: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0; // Remove newline from author
                appendBook(&head, id, title, author);
                printf("Book added successfully!\n");
                break;
            case 2:
                printf("Enter Book ID to delete: ");
                scanf("%d", &id);
                deleteBook(&head, id);
                break;
            case 3:
                displayBooks(head);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 4);

    freeList(head); // Free memory before exiting
    return 0;
}

// Function to create a new book node
Book* createBook(int id, const char* title, const char* author) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = NULL;
    return newBook;
}

// Function to append a book to the linked list
void appendBook(Book** head_ref, int id, const char* title, const char* author) {
    Book* newBook = createBook(id, title, author);
    if (*head_ref == NULL) {
        *head_ref = newBook;
        return;
    }
    Book* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newBook;
}

// Function to delete a book by ID
void deleteBook(Book** head_ref, int id) {
    Book* temp = *head_ref;
    Book* prev = NULL;

    // If the book to be deleted is the first book
    if (temp != NULL && temp->id == id) {
        *head_ref = temp->next;
        free(temp);
        printf("Book with ID %d deleted successfully!\n", id);
        return;
    }

    // Traverse the linked list to find the book to be deleted
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    // If the book was not found
    if (temp == NULL) {
        printf("Book with ID %d not found.\n", id);
        return;
    }

    // Unlink the book from the linked list
    prev->next = temp->next;
    free(temp);
    printf("Book with ID %d deleted successfully!\n", id);
}

// Function to display all books in the list
void displayBooks(Book* node) {
    if (node == NULL) {
        printf("No books in the list.\n");
        return;
    }
    printf("\n--- List of Books ---\n");
    while (node != NULL) {
        printf("ID: %d, Title: %s, Author: %s\n", node->id, node->title, node->author);
        node = node->next;
    }
}

// Function to free linked list memory
void freeList(Book* head) {
    Book* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}