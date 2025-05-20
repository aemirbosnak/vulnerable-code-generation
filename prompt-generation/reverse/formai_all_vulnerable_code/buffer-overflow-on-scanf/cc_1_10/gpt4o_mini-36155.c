//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct Book {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

typedef struct Node {
    Book book;
    struct Node* left;
    struct Node* right;
} Node;

// Function prototypes
Node* createNode(Book book);
Node* insert(Node* root, Book book);
Node* search(Node* root, const char* title);
void inOrder(Node* root);
void freeTree(Node* root);
void getBookInfo(Book* book);

int main() {
    Node* root = NULL;
    
    printf("Welcome to the Book Database Indexing System!\n");
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Book\n");
        printf("2. Search Book by Title\n");
        printf("3. Display All Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1: {
                Book book;
                getBookInfo(&book);
                root = insert(root, book);
                printf("Book inserted!\n");
                break;
            }
            case 2: {
                char title[MAX_TITLE_LENGTH];
                printf("Enter the title of the book to search: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                
                Node* foundNode = search(root, title);
                if (foundNode != NULL) {
                    printf("Book Found: ID: %d, Title: %s, Author: %s\n", 
                           foundNode->book.id, foundNode->book.title, foundNode->book.author);
                } else {
                    printf("Book not found!\n");
                }
                break;
            }
            case 3: {
                printf("Displaying all books:\n");
                inOrder(root);
                break;
            }
            case 4: {
                printf("Exiting the system. Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid choice! Please try again.\n");
                break;
            }
        }
    } while (choice != 4);
    
    freeTree(root);
    return 0;
}

void getBookInfo(Book* book) {
    printf("Enter Book ID: ");
    scanf("%d", &book->id);
    getchar(); // Consume newline
    printf("Enter Book Title: ");
    fgets(book->title, MAX_TITLE_LENGTH, stdin);
    book->title[strcspn(book->title, "\n")] = 0; // Remove newline
    printf("Enter Author Name: ");
    fgets(book->author, MAX_AUTHOR_LENGTH, stdin);
    book->author[strcspn(book->author, "\n")] = 0; // Remove newline
}

Node* createNode(Book book) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->book = book;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, Book book) {
    if (root == NULL) {
        return createNode(book);
    }
    if (strcmp(book.title, root->book.title) < 0) {
        root->left = insert(root->left, book);
    } else if (strcmp(book.title, root->book.title) > 0) {
        root->right = insert(root->right, book);
    }
    return root;
}

Node* search(Node* root, const char* title) {
    if (root == NULL || strcmp(root->book.title, title) == 0) {
        return root;
    }
    if (strcmp(title, root->book.title) < 0) {
        return search(root->left, title);
    }
    return search(root->right, title);
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("ID: %d, Title: %s, Author: %s\n", 
               root->book.id, root->book.title, root->book.author);
        inOrder(root->right);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}