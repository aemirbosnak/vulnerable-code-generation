//Falcon-180B DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void delete_node(Node** head, int data) {
    Node* temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: Node not found\n");
        return;
    }
    Node* prev = temp->next;
    free(temp);
    prev->next = temp->next;
}

void print_list(Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    printf("List: ");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data;
    while (1) {
        printf("1. Add node\n2. Delete node\n3. Print list\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            add_node(&head, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            delete_node(&head, data);
            break;
        case 3:
            print_list(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Error: Invalid choice\n");
        }
    }
    return 0;
}