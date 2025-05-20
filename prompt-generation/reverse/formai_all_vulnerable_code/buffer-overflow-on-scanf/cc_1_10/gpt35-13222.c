//FormAI DATASET v1.0 Category: Linked list operations ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void insertFront(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Wow! Your data %d has been added to the front of the linked list!\n", data);
}

void insertEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        printf("Amazing! Your data %d has been added to the end of the linked list!\n", data);
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    printf("Fantastic! Your data %d has been added to the end of the linked list!\n", data);
}

void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("Woohoo! Node with data %d has been deleted from the linked list!\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
 
    if (temp == NULL) {
        printf("Oh no! Node with data %d not found in the linked list.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Wowza! Node with data %d has been deleted from the linked list!\n", key);
}

void display(Node* head_ref) {
    printf("Your current linked list is: ");
    while (head_ref != NULL) {
        printf("%d ", head_ref->data);
        head_ref = head_ref->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice = 0, data = 0;

    do {
        printf("\nSelect an operation:\n1. Insert at front\n2. Insert at end\n3. Delete a node\n4. Display linked list\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to insert at front: ");
            scanf("%d", &data);
            insertFront(&head, data);
            break;
        case 2:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insertEnd(&head, data);
            break;
        case 3:
            printf("Enter data of node to delete: ");
            scanf("%d", &data);
            deleteNode(&head, data);
            break;
        case 4:
            display(head);
            break;
        case 5:
            printf("Thank you for using this program!\n");
            break;
        default:
            printf("Invalid choice. Please try again!\n");
        }
    } while (choice != 5);

    return 0;
}