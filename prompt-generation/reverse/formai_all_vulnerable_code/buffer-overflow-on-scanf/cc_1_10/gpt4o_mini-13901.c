//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define NAME_LENGTH 50

// Define the structure for a Book
typedef struct Book {
    char title[TITLE_LENGTH];
    int id;
    struct Book* next;
} Book;

// Define the structure for a Stack (for checked out books)
typedef struct Stack {
    Book* top;
} Stack;

// Define the structure for a Queue (for waiting list)
typedef struct QueueNode {
    char name[NAME_LENGTH];
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Function prototypes
Book* createBook(int id, const char* title);
void addBook(Book** head, Book* newBook);
void displayBooks(Book* head);
void checkoutBook(Book** head, Stack* stack);
void returnBook(Stack* stack, Book** head);
void initializeQueue(Queue* queue);
void enqueue(Queue* queue, const char* name);
void dequeue(Queue* queue);
void displayQueue(Queue* queue);

int main() {
    Book* bookList = NULL;
    Stack* checkedOutBooks = (Stack*)malloc(sizeof(Stack));
    checkedOutBooks->top = NULL;
    Queue* waitingList = (Queue*)malloc(sizeof(Queue));
    initializeQueue(waitingList);
    
    int choice, id;
    char title[TITLE_LENGTH];
    
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Checkout Book\n");
        printf("4. Return Book\n");
        printf("5. Add to Waiting List\n");
        printf("6. Display Waiting List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter book title: ");
                scanf(" %[^\n]", title);
                addBook(&bookList, createBook(id, title));
                break;
            case 2:
                displayBooks(bookList);
                break;
            case 3:
                checkoutBook(&bookList, checkedOutBooks);
                break;
            case 4:
                returnBook(checkedOutBooks, &bookList);
                break;
            case 5:
                printf("Enter your name: ");
                scanf(" %[^\n]", title);
                enqueue(waitingList, title);
                break;
            case 6:
                displayQueue(waitingList);
                break;
            case 0:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);

    // Free dynamically allocated memory
    while (bookList != NULL) {
        Book* temp = bookList;
        bookList = bookList->next;
        free(temp);
    }
    free(checkedOutBooks);
    free(waitingList);
    
    return 0;
}

Book* createBook(int id, const char* title) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    newBook->id = id;
    strncpy(newBook->title, title, TITLE_LENGTH);
    newBook->next = NULL;
    return newBook;
}

void addBook(Book** head, Book* newBook) {
    if (*head == NULL) {
        *head = newBook;
    } else {
        Book* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
    printf("Book '%s' added successfully!\n", newBook->title);
}

void displayBooks(Book* head) {
    if (head == NULL) {
        printf("No books available.\n");
        return;
    }
    printf("Available books:\n");
    while (head != NULL) {
        printf("ID: %d, Title: %s\n", head->id, head->title);
        head = head->next;
    }
}

void checkoutBook(Book** head, Stack* stack) {
    if (*head == NULL) {
        printf("No books available to checkout.\n");
        return;
    }
    Book* temp = *head;
    *head = (*head)->next;

    temp->next = stack->top;
    stack->top = temp;
    printf("Book '%s' checked out successfully!\n", temp->title);
}

void returnBook(Stack* stack, Book** head) {
    if (stack->top == NULL) {
        printf("No books to return.\n");
        return;
    }
    Book* bookToReturn = stack->top;
    stack->top = stack->top->next;

    bookToReturn->next = *head;
    *head = bookToReturn;
    printf("Book '%s' returned successfully!\n", bookToReturn->title);
}

void initializeQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void enqueue(Queue* queue, const char* name) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    strncpy(newNode->name, name, NAME_LENGTH);
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%s has been added to the waiting list.\n", name);
}

void dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Waiting list is empty.\n");
        return;
    }
    QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
}

void displayQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Waiting list is empty.\n");
        return;
    }
    printf("People on waiting list:\n");
    QueueNode* temp = queue->front;
    while (temp != NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}