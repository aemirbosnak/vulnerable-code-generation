//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createLinkedList() {
    Node* head = NULL;
    Node* tail = NULL;
    int choice;

    do {
        printf("Enter 1 to add a node at the beginning\n");
        printf("Enter 2 to add a node at the end\n");
        printf("Enter 3 to display the linked list\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                head = (Node*)malloc(sizeof(Node));
                printf("Enter the data for the new node: ");
                scanf("%d", &head->data);
                head->next = NULL;
                if(tail == NULL) {
                    tail = head;
                }
                break;
            case 2:
                tail = (Node*)malloc(sizeof(Node));
                printf("Enter the data for the new node: ");
                scanf("%d", &tail->data);
                tail->next = NULL;
                if(head == NULL) {
                    head = tail;
                }
                break;
            case 3:
                if(head == NULL) {
                    printf("The linked list is empty.\n");
                } else {
                    printf("The linked list contains the following nodes:\n");
                    Node* curr = head;
                    while(curr!= NULL) {
                        printf("%d ", curr->data);
                        curr = curr->next;
                    }
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= 4);

    return head;
}

int main() {
    Node* linkedList = createLinkedList();

    return 0;
}