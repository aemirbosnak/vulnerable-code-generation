//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char data[MAX_SIZE];
    int length;
    struct node *next;
};

void push(struct node **head, char data[]) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->data, data);
    new_node->length = strlen(data);
    new_node->next = *head;
    *head = new_node;
}

void display(struct node *head) {
    while (head!= NULL) {
        printf("Data: %s, Length: %d\n", head->data, head->length);
        head = head->next;
    }
}

void pop(struct node **head) {
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main() {
    struct node *head = NULL;
    char data[MAX_SIZE];
    int choice, i;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%s", data);
                push(&head, data);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}