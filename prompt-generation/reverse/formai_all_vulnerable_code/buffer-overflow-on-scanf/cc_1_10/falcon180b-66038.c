//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteList(Node** head) {
    Node* temp = *head;
    while (temp!= NULL) {
        *head = temp->next;
        free(temp);
        temp = *head;
    }
}

int searchList(Node* head, int data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    Node* head = NULL;
    int choice, data;

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &choice);

    printf("Enter the elements:\n");
    for (int i = 0; i < choice; i++) {
        scanf("%d", &data);
        addNode(&head, data);
    }

    printf("Original list:\n");
    printList(head);

    int searchData;
    printf("Enter the element to search for: ");
    scanf("%d", &searchData);

    if (searchList(head, searchData)) {
        printf("%d found in the list.\n", searchData);
    } else {
        printf("%d not found in the list.\n", searchData);
    }

    deleteList(&head);
    return 0;
}