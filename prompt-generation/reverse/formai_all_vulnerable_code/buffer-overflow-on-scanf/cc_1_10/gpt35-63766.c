//FormAI DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

/**
 * This function inserts a node at the beginning of the linked list
 * @param head pointer to the head of the linked list
 * @param value the value to be inserted
 * @return pointer to the new head of the linked list
 **/
Node* insert_front(Node* head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    return head;
}

/**
 * This function inserts a node at the end of the linked list
 * @param head pointer to the head of the linked list
 * @param value the value to be inserted
 * @return pointer to the head of the linked list
 **/
Node* insert_end(Node* head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        Node* current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    return head;
}

/**
 * This function deletes a node from the linked list
 * @param head pointer to the head of the linked list
 * @param value the value to be deleted
 * @return pointer to the head of the linked list
 **/
Node* delete(Node* head, int value) {
    Node* current_node = head;
    Node* previous_node = NULL;
    while (current_node != NULL && current_node->data != value) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        printf("%d is not present in the linked list\n", value);
        return head;
    }
    if (previous_node == NULL) {
        head = current_node->next;
    } else {
        previous_node->next = current_node->next;
    }
    free(current_node);
    return head;
}

/**
 * This function checks whether a value is present in the linked list
 * @param head pointer to the head of the linked list
 * @param value the value to be searched
 * @return true if the value is present, else false
 **/
bool search(Node* head, int value) {
    Node* current_node = head;
    while (current_node != NULL && current_node->data != value) {
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        return false;
    }
    return true;
}

/**
 * This function displays all the nodes in the linked list
 * @param head pointer to the head of the linked list
 **/
void display(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        Node* current_node = head;
        while (current_node != NULL) {
            printf("%d ", current_node->data);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    int choice, data, value;
    while (true) {
        printf("Enter your choice:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                head = insert_front(head, data);
                printf("Node with value %d inserted at front\n", data);
                break;
            case 2:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                head = insert_end(head, data);
                printf("Node with value %d inserted at end\n", data);
                break;
            case 3:
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                head = delete(head, value);
                printf("Node with value %d deleted\n", value);
                break;
            case 4:
                printf("Enter the value to be searched: ");
                scanf("%d", &value);
                if (search(head, value)) {
                    printf("%d is present in the linked list\n", value);
                } else {
                    printf("%d is not present in the linked list\n", value);
                }
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}