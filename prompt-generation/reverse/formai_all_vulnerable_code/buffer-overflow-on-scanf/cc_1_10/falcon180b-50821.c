//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    int price;
} Item;

typedef struct {
    int top;
    int capacity;
    Item items[MAX_SIZE];
} Stack;

void push(Stack* stack, Item item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full. Cannot push item.\n");
        return;
    }
    stack->items[++stack->top] = item;
}

Item pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty. Cannot pop item.\n");
        return (Item){0, "", 0, 0};
    }
    return stack->items[stack->top--];
}

void display(Stack* stack) {
    printf("Stack:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %d\n", stack->items[i].id, stack->items[i].name, stack->items[i].quantity, stack->items[i].price);
    }
}

int main() {
    Stack stack;
    stack.top = -1;
    stack.capacity = MAX_SIZE;

    int choice;
    while (1) {
        printf("1. Push item\n2. Pop item\n3. Display items\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            Item item;
            printf("Enter item ID: ");
            scanf("%d", &item.id);
            printf("Enter item name: ");
            scanf("%s", item.name);
            printf("Enter item quantity: ");
            scanf("%d", &item.quantity);
            printf("Enter item price: ");
            scanf("%d", &item.price);
            push(&stack, item);
            break;
        }
        case 2: {
            Item item = pop(&stack);
            if (item.id!= 0) {
                printf("Popped item: ID: %d, Name: %s, Quantity: %d, Price: %d\n", item.id, item.name, item.quantity, item.price);
            }
            break;
        }
        case 3: {
            display(&stack);
            break;
        }
        case 4: {
            exit(0);
        }
        default: {
            printf("Invalid choice. Please try again.\n");
        }
        }
    }

    return 0;
}