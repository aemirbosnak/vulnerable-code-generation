//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);

    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    return head;
}

void searchBook(Book* head) {
    char searchTitle[50];
    printf("Enter book title: ");
    scanf("%s", searchTitle);

    Book* temp = head;
    while (temp) {
        if (strcmp(searchTitle, temp->title) == 0) {
            printf("Book title: %s\n", temp->title);
            printf("Book author: %s\n", temp->author);
            printf("Book quantity: %d\n", temp->quantity);
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book not found.\n");
    }
}

void updateBook(Book* head) {
    char updateTitle[50];
    printf("Enter book title: ");
    scanf("%s", updateTitle);

    Book* temp = head;
    while (temp) {
        if (strcmp(updateTitle, temp->title) == 0) {
            printf("Enter new book title: ");
            scanf("%s", temp->title);
            printf("Enter new book author: ");
            scanf("%s", temp->author);
            printf("Enter new book quantity: ");
            scanf("%d", &temp->quantity);
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book not found.\n");
    }
}

void deleteBook(Book* head) {
    char deleteTitle[50];
    printf("Enter book title: ");
    scanf("%s", deleteTitle);

    Book* temp = head;
    Book* prev = NULL;
    while (temp) {
        if (strcmp(deleteTitle, temp->title) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book not found.\n");
    }
}

int main() {
    Book* head = NULL;

    while (1) {
        printf("1. Insert Book\n");
        printf("2. Search Book\n");
        printf("3. Update Book\n");
        printf("4. Delete Book\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertBook(head);
                break;
            case 2:
                searchBook(head);
                break;
            case 3:
                updateBook(head);
                break;
            case 4:
                deleteBook(head);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Press any key to continue... ");
        getchar();
    }

    return 0;
}