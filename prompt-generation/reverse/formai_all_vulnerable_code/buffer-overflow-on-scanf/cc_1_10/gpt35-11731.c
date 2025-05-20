//FormAI DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insert(int data) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void delete(int data) {
    Node* temp = head, *prev = NULL;

    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Data not found in the linked list.\n");
        return;
    } 
    prev->next = temp->next;
    free(temp);
}

void display() {
    Node* temp = head;
    printf("\nThe current linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    printf("Welcome to the C Linked List Program!\n\n");
    int choice, num;

    while (1) {
        printf("\nWhat operation would you like to perform?\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the number to be inserted: ");
                scanf("%d", &num);
                insert(num);
                printf("The number %d was successfully inserted!\n", num);
                break;
            case 2:
                printf("\nEnter the number to be deleted: ");
                scanf("%d", &num);
                delete(num);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nThank you for using the C Linked List Program!");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose again.\n");
                break;
        }
    }
    return 0;
}