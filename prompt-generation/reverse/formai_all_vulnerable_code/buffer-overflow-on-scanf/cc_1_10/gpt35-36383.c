//FormAI DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} node;

node* head = NULL;

void insert(int num, int pos) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = num;

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    int i;
    node* temp = head;

    for (i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid Position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void delete(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 0) {
        node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    int i;
    node* temp = head;

    for (i = 0; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Invalid Position\n");
        return;
    }

    node* del = temp->next;
    temp->next = del->next;
    free(del);
}

void print() {
    node* temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, num, pos;

    while (1) {
        printf("1. Insert\n2. Delete\n3. Print\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the number you want to insert: ");
                scanf("%d", &num);
                printf("Enter the position where you want to insert: ");
                scanf("%d", &pos);
                insert(num, pos);
                break;
            case 2:
                printf("Enter the position you want to delete: ");
                scanf("%d", &pos);
                delete(pos);
                break;
            case 3:
                print();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("\n");
    }

    return 0;
}