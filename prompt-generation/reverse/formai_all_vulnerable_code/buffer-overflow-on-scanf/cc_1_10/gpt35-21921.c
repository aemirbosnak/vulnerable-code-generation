//FormAI DATASET v1.0 Category: Ebook reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    int pages;
    float price;
} Book;

typedef struct {
    int top;
    Book books[100];
} Stack;

void push(Stack *stack, Book book) {
    if (stack->top == 99) {
        printf("The stack is full! Cannot add any more books.\n");
        return;
    }
    stack->top++;
    stack->books[stack->top] = book;
    printf("Added book '%s' by %s.\n", book.title, book.author);
}

void pop(Stack *stack) {
    if (stack->top == -1) {
        printf("The stack is empty! Cannot remove any books.\n");
        return;
    }
    Book book = stack->books[stack->top];
    stack->top--;
    printf("Removed book '%s' by %s.\n", book.title, book.author);
}

void display(Stack *stack) {
    if (stack->top == -1) {
        printf("The stack is empty.\n");
        return;
    }
    printf("List of books in the stack:\n");
    for (int i = stack->top; i >= 0; i--) {
        Book book = stack->books[i];
        printf("%s by %s\n", book.title, book.author);
    }
}

int main() {
    Stack stack;
    stack.top = -1;
    int choice;
    do {
        printf("\nMenu:");
        printf("\n1. Add a book");
        printf("\n2. Remove a book");
        printf("\n3. Display all books");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Book book;
                printf("Enter book title: ");
                scanf("%s", book.title);
                printf("Enter book author: ");
                scanf("%s", book.author);
                printf("Enter number of pages: ");
                scanf("%d", &book.pages);
                printf("Enter price: ");
                scanf("%f", &book.price);
                push(&stack, book);
                break;
            }
            case 2: {
                pop(&stack);
                break;
            }
            case 3: {
                display(&stack);
                break;
            }
            case 4: {
                printf("Exiting program.\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    } while (choice != 4);
    return 0;
}