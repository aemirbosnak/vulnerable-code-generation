//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
    char title[100];
    char author[100];
    int year;
    struct Book* left;
    struct Book* right;
} Book;

// Function to create a new book node
Book* createBook(char *title, char *author, int year) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->year = year;
    newBook->left = NULL;
    newBook->right = NULL;
    return newBook;
}

// Function to insert a book into the BST
Book* insertBook(Book* root, Book* newBook) {
    if (root == NULL) {
        return newBook;
    }
    if (strcmp(newBook->title, root->title) < 0) {
        root->left = insertBook(root->left, newBook);
    } else {
        root->right = insertBook(root->right, newBook);
    }
    return root;
}

// Function to search for a book by title
Book* searchBook(Book* root, const char* title) {
    if (root == NULL || strcmp(root->title, title) == 0) {
        return root;
    }
    if (strcmp(title, root->title) < 0) {
        return searchBook(root->left, title);
    }
    return searchBook(root->right, title);
}

// Function to print books in sorted order (inorder traversal)
void printBooksInOrder(Book* root) {
    if (root != NULL) {
        printBooksInOrder(root->left);
        printf("Title: %s, Author: %s, Year: %d\n", root->title, root->author, root->year);
        printBooksInOrder(root->right);
    }
}

// Function to free the memory allocated for the BST
void freeBooks(Book* root) {
    if (root != NULL) {
        freeBooks(root->left);
        freeBooks(root->right);
        free(root);
    }
}

// Main function to demonstrate the library system
int main() {
    Book* library = NULL;
    int choice;
    char title[100], author[100];
    int year;

    do {
        printf("\nLibrary Menu:\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. List All Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline character

                printf("Enter author: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = '\0'; // Remove newline character

                printf("Enter year of publication: ");
                scanf("%d", &year);

                library = insertBook(library, createBook(title, author, year));
                printf("Book added successfully.\n");
                break;

            case 2:
                printf("Enter book title to search: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline character

                Book* foundBook = searchBook(library, title);
                if (foundBook != NULL) {
                    printf("Book found: Title: %s, Author: %s, Year: %d\n", foundBook->title, foundBook->author, foundBook->year);
                } else {
                    printf("Book not found.\n");
                }
                break;

            case 3:
                printf("\nList of all books:\n");
                printBooksInOrder(library);
                break;

            case 4:
                printf("Exiting the library system.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    freeBooks(library);
    return 0;
}