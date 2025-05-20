//FormAI DATASET v1.0 Category: Linked list operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList() {
    struct Node* head = NULL;
    printf("Enter the number of elements you want in the Linked List: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the %d element: ", i + 1);
        int data;
        scanf("%d", &data);
        struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    return head;
}

void traverseList(struct Node* head) {
    struct Node* temp = head;
    printf("Elements in the Linked List are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node** head_ref) {
    printf("Enter the data to be inserted at the beginning: ");
    int data;
    scanf("%d", &data);
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("%d is inserted at the beginning.\n", data);
}

void insertAtEnd(struct Node** head_ref) {
    printf("Enter the data to be inserted at the end: ");
    int data;
    scanf("%d", &data);
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    struct Node* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        printf("%d is inserted.\n", data);
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    printf("%d is inserted.\n", data);
}

void insertAtPos(struct Node** head_ref) {
    printf("Enter the data to be inserted: ");
    int data;
    scanf("%d", &data);
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    printf("Enter the position to be inserted: ");
    int pos;
    scanf("%d", &pos);
    if (pos < 1) {
        printf("Invalid position.");
        return;
    }
    if (pos == 1) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        printf("%d is inserted at position %d.\n", data, pos);
        return;
    }
    struct Node* prev = NULL;
    struct Node* curr = *head_ref;
    for (int i = 1; i < pos; i++) {
        if (curr == NULL) {
            printf("Only %d elements are present.\n", i - 1);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    new_node->next = curr;
    prev->next = new_node;
    printf("%d is inserted at position %d.\n", data, pos);
}

void deleteAtBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Linked List is already empty.\n");
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = temp->next;
    printf("%d is deleted from the beginning.\n", temp->data);
    free(temp);
}

void deleteAtEnd(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Linked List is already empty.\n");
        return;
    }
    struct Node* temp = *head_ref;
    if (temp->next == NULL) {
        *head_ref = NULL;
        printf("%d is deleted.\n", temp->data);
        free(temp);
        return;
    }
    struct Node* last = *head_ref;
    struct Node* prev = NULL;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    printf("%d is deleted.\n", last->data);
    free(last);
}

void deleteAtPos(struct Node** head_ref) {
    printf("Enter the position to be deleted: ");
    int pos;
    scanf("%d", &pos);
    if (*head_ref == NULL) {
        printf("Linked List is already empty.\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* temp = *head_ref;
    if (pos == 1) {
        *head_ref = temp->next;
        printf("%d is deleted from position %d.\n", temp->data, pos);
        free(temp);
        return;
    }
    for (int i = 1; temp != NULL && i < pos; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Only %d elements are present.\n", i);
            return;
        }
        temp = temp->next;
    }
    struct Node* next = temp->next->next;
    printf("%d is deleted from position %d.\n", temp->next->data, pos);
    free(temp->next);
    temp->next = next;
}

int main() {

    printf("-------------------C Linked List Operations-------------------\n");

    struct Node* head = createList();
    traverseList(head);
    insertAtBeginning(&head);
    traverseList(head);
    insertAtEnd(&head);
    traverseList(head);
    insertAtPos(&head);
    traverseList(head);
    deleteAtBeginning(&head);
    traverseList(head);
    deleteAtEnd(&head);
    traverseList(head);
    deleteAtPos(&head);
    traverseList(head);

    printf("----------------------------End--------------------------------");

    return 0;
}