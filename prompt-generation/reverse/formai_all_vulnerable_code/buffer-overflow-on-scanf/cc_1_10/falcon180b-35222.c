//Falcon-180B DATASET v1.0 Category: Memory management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void add(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory Error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void display() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Add Element\n2. Display Elements\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter Element to be added: ");
            scanf("%d", &data);
            add(data);
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}