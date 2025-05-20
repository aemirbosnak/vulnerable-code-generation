//FormAI DATASET v1.0 Category: Memory management ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
typedef struct node Node;

Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* insert_at_begin(Node *head, int data) {
    Node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

Node* insert_at_end(Node *head, int data) {
    Node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    }
    else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

Node* insert_at_pos(Node *head, int data, int pos) {
    Node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    }
    else {
        Node *temp = head;
        int i;
        for (i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position not found\n");
        }
        else {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    return head;
}

Node* delete_at_begin(Node *head) {
    if (head == NULL) {
        printf("Linked List is Empty\n");
    }
    else {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

Node* delete_at_end(Node *head) {
    if (head == NULL) {
        printf("Linked List is Empty\n");
    }
    else if (head->next == NULL) {
        Node *temp = head;
        head = NULL;
        free(temp);
    }
    else {
        Node *prev = NULL, *curr = head;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        free(curr);
    }
    return head;
}

Node* delete_at_pos(Node *head, int pos) {
    if (head == NULL) {
        printf("Linked List is Empty\n");
    }
    else if (pos == 1) {
        head = delete_at_begin(head);
    }
    else {
        Node *prev = NULL, *curr = head;
        int i;
        for (i = 1; i < pos && curr != NULL; i++) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) {
            printf("Position not found\n");
        }
        else {
            prev->next = curr->next;
            free(curr);
        }
    }
    return head;
}

int main() {
    Node *head = NULL;
    int choice, data, pos;
    while (1) {
        printf("****MENU****\n");
        printf("1. Insert at Begin.\n");
        printf("2. Insert at End.\n");
        printf("3. Insert at Position.\n");
        printf("4. Delete at Begin.\n");
        printf("5. Delete at End.\n");
        printf("6. Delete at Position.\n");
        printf("7. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            head = insert_at_begin(head, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            head = insert_at_end(head, data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            head = insert_at_pos(head, data, pos);
            break;
        case 4:
            head = delete_at_begin(head);
            break;
        case 5:
            head = delete_at_end(head);
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            head = delete_at_pos(head, pos);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}