//Falcon-180B DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top_ref, int new_data);
int pop(struct Node** top_ref);
int peek(struct Node* top);
void printList(struct Node* node);
int isEmpty(struct Node* top);

int main() {
    struct Node* top = NULL;
    int choice, element;

    srand(time(NULL));
    top = (struct Node*) malloc(sizeof(struct Node));
    top->data = rand() % 100;
    top->next = NULL;

    do {
        printf("\n\n1. Push\n2. Pop\n3. Peek\n4. Print List\n5. Check if Empty\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to be pushed: ");
                scanf("%d", &element);
                push(&top, element);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                printf("\nThe top element is %d\n", peek(top));
                break;
            case 4:
                printList(top);
                break;
            case 5:
                if (isEmpty(top))
                    printf("\nThe list is empty\n");
                else
                    printf("\nThe list is not empty\n");
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(struct Node** top_ref) {
    char res;
    struct Node* top = *top_ref;

    if (top == NULL) {
        printf("\nUnderflow\n");
        return -1;
    }
    else {
        res = top->data;
        free(top);
        *top_ref = top->next;
        return res;
    }
}

int peek(struct Node* top) {
    if (top == NULL)
        return -1;
    else
        return top->data;
}

void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int isEmpty(struct Node* top) {
    if (top == NULL)
        return 1;
    else
        return 0;
}