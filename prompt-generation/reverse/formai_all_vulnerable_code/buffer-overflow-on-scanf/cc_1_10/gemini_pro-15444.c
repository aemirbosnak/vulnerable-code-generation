//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtIndex(int data, int index) {
    if (index == 0) {
        insertAtBeginning(data);
    } else {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        struct Node *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else if (head->next == NULL) {
        head = NULL;
    } else {
        struct Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteAtIndex(int index) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else if (index == 0) {
        deleteAtBeginning();
    } else {
        struct Node *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        struct Node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

void printList() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    printf("Please enter the number of operations you want to perform:\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the operation you want to perform (1-7):\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at index\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at index\n");
        printf("7. Print list\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data you want to insert at the beginning:\n");
                int data;
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter the data you want to insert at the end:\n");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter the data you want to insert:\n");
                scanf("%d", &data);
                printf("Enter the index where you want to insert the data:\n");
                int index;
                scanf("%d", &index);
                insertAtIndex(data, index);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter the index where you want to delete the data:\n");
                scanf("%d", &index);
                deleteAtIndex(index);
                break;
            case 7:
                printList();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}