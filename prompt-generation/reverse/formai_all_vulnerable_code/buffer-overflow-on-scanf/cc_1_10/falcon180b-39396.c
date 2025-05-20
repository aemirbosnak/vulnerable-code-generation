//Falcon-180B DATASET v1.0 Category: Educational ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node *next;
};

void push(struct node **head_ref, int new_data);
int pop(struct node **head_ref);
int peek(struct node *head);
void printList(struct node *node);

int main() {
    struct node *head = NULL;
    int choice, data;

    do {
        printf("1. Push\n2. Pop\n3. Peek\n4. Print List\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(&head, data);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                data = peek(head);
                if (data == -1)
                    printf("Stack is empty\n");
                else
                    printf("Top element is %d\n", data);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}

void push(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Stack overflow\n");
        exit(0);
    }

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int pop(struct node **head_ref) {
    char res;
    struct node *top = *head_ref;

    if (top == NULL) {
        printf("Stack underflow\n");
        exit(0);
    }

    res = top->data;
    free(top);
    top = top->next;
    (*head_ref) = top;

    return res;
}

int peek(struct node *head) {
    if (head == NULL)
        return -1;
    else
        return head->data;
}

void printList(struct node *node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}