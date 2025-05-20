//FormAI DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 50
#define MAX_AUTHOR 30

struct Book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int year;
    char publisher[MAX_AUTHOR];
    char isbn[20];
    float price;
};

struct Node {
    struct Book data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* BST;

BST insert(BST root, struct Book data) {
    if (root == NULL) {
        BST new_node = (BST) malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (strcasecmp(data.title, root->data.title) < 0)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

struct Node* search(BST root, char* title) {
    if (root == NULL)
        return NULL;
    else if (strcasecmp(title, root->data.title) == 0)
        return root;
    else if (strcasecmp(title, root->data.title) < 0)
        return search(root->left, title);
    else
        return search(root->right, title);
}

void display(struct Node* node) {
    if (node != NULL) {
        display(node->left);
        printf("Title: %s\nAuthor: %s\nYear: %d\nPublisher: %s\nISBN: %s\nPrice: $%.2f\n\n",
            node->data.title, node->data.author, node->data.year, node->data.publisher,
            node->data.isbn, node->data.price);
        display(node->right);
    }
}

int main() {
    BST root = NULL;
    int choice;
    struct Book new_book;
    struct Node* searched_book;

    printf("Electronic Book Reader\n\n");

    do {
        printf("Menu\n----\n");
        printf("1. Add a Book\n");
        printf("2. Search for a Book\n");
        printf("3. Display all Books\n");
        printf("4. Exit\n");
        printf("--------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nAdd a Book\n----------\n");
                printf("Title: ");
                fflush(stdin);
                fgets(new_book.title, MAX_TITLE, stdin);
                new_book.title[strcspn(new_book.title, "\n")] = '\0';
                printf("Author: ");
                fflush(stdin);
                fgets(new_book.author, MAX_AUTHOR, stdin);
                new_book.author[strcspn(new_book.author, "\n")] = '\0';
                printf("Year: ");
                scanf("%d", &new_book.year);
                printf("Publisher: ");
                fflush(stdin);
                fgets(new_book.publisher, MAX_AUTHOR, stdin);
                new_book.publisher[strcspn(new_book.publisher, "\n")] = '\0';
                printf("ISBN: ");
                fflush(stdin);
                fgets(new_book.isbn, 20, stdin);
                new_book.isbn[strcspn(new_book.isbn, "\n")] = '\0';
                printf("Price: ");
                scanf("%f", &new_book.price);

                root = insert(root, new_book);

                printf("\nBook Added Successfully!\n");
                break;

            case 2:
                printf("\nSearch for a Book\n------------------\n");
                printf("Enter the title of the book: ");
                fflush(stdin);
                fgets(new_book.title, MAX_TITLE, stdin);
                new_book.title[strcspn(new_book.title, "\n")] = '\0';

                searched_book = search(root, new_book.title);

                if (searched_book == NULL)
                    printf("Sorry, the book \"%s\" was not found.\n", new_book.title);
                else {
                    printf("Book Found!\n");
                    printf("Title: %s\nAuthor: %s\nYear: %d\nPublisher: %s\nISBN: %s\nPrice: $%.2f\n\n",
                        searched_book->data.title, searched_book->data.author, 
                        searched_book->data.year, searched_book->data.publisher,
                        searched_book->data.isbn, searched_book->data.price);
                }
                break;

            case 3:
                printf("\nBook List\n----------\n");
                display(root);
                break;

            case 4:
                printf("\nThank you for using the Electronic Book Reader.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        printf("\n");

    } while (choice != 4);

    return 0;
}