//Falcon-180B DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char data;
    struct node *next;
};

struct node *head = NULL;

void push(char data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Stack overflow!\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

char pop() {
    char data;
    if (head == NULL) {
        printf("Stack underflow!\n");
        exit(0);
    }
    data = head->data;
    struct node *temp = head;
    head = head->next;
    free(temp);
    return data;
}

int is_empty() {
    return head == NULL;
}

int is_full() {
    return head == NULL;
}

void print_stack() {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    char ch;

    do {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print stack\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be pushed:\n");
                scanf("%c", &ch);
                push(ch);
                break;
            case 2:
                data = pop();
                printf("The popped element is %c\n", data);
                break;
            case 3:
                print_stack();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}