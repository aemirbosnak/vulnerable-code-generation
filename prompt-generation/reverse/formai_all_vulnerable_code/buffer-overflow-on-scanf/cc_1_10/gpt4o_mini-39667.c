//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    char author[100];
    int isbn;
    struct Book *left;
    struct Book *right;
} Book;

Book *createBook(int isbn, const char *title, const char *author) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    newBook->isbn = isbn;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->left = NULL;
    newBook->right = NULL;
    return newBook;
}

Book *insertBook(Book *root, int isbn, const char *title, const char *author) {
    if (root == NULL) {
        return createBook(isbn, title, author);
    }
    if (isbn < root->isbn) {
        root->left = insertBook(root->left, isbn, title, author);
    } else {
        root->right = insertBook(root->right, isbn, title, author);
    }
    return root;
}

Book *searchBook(Book *root, int isbn) {
    if (root == NULL || root->isbn == isbn) {
        return root;
    }
    if (isbn < root->isbn) {
        return searchBook(root->left, isbn);
    }
    return searchBook(root->right, isbn);
}

void inOrderDisplay(Book *root) {
    if (root != NULL) {
        inOrderDisplay(root->left);
        printf("ISBN: %d, Title: %s, Author: %s\n", root->isbn, root->title, root->author);
        inOrderDisplay(root->right);
    }
}

void freeBooks(Book *root) {
    if (root != NULL) {
        freeBooks(root->left);
        freeBooks(root->right);
        free(root);
    }
}

int main() {
    Book *library = NULL;
    int choice, isbn;
    char title[100], author[100];

    do {
        printf("Library Management System\n");
        printf("1. Add a Book\n");
        printf("2. Search for a Book\n");
        printf("3. Display All Books\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ISBN: ");
                scanf("%d", &isbn);
                printf("Enter Title: ");
                getchar(); // consume the newline character
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                printf("Enter Author: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0; // Remove newline character
                library = insertBook(library, isbn, title, author);
                printf("Book added successfully!\n\n");
                break;

            case 2:
                printf("Enter ISBN to search: ");
                scanf("%d", &isbn);
                Book *foundBook = searchBook(library, isbn);
                if (foundBook != NULL) {
                    printf("Book found: ISBN: %d, Title: %s, Author: %s\n\n",
                           foundBook->isbn, foundBook->title, foundBook->author);
                } else {
                    printf("Book not found.\n\n");
                }
                break;

            case 3:
                printf("All Books:\n");
                inOrderDisplay(library);
                printf("\n");
                break;

            case 4:
                freeBooks(library);
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 4);

    return 0;
}