//FormAI DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* insert(Node *head, int data) {
    if (head == NULL) {
        head = (Node *) malloc(sizeof(Node));
        head->data = data;
        head->next = NULL;
    } 
    else {
        head->next = insert(head->next, data);
    }
    return head;
}

Node* delete(Node *head, int data){
    if(head == NULL){     
        return head; 
    }
    if(head->data == data){ 
        Node *temp = head->next; 
        free(head); 
        return temp; 
    }
    head->next = delete(head->next,data); 
    return head; 
}

void display(Node *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    display(head->next);
}

int main() {
    Node *head = NULL;
    int choice, value;

    do {
        printf("\n\nLinked List Operations\n");
        printf("1.Insert node\n2.Delete node\n3.Display list\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                head = insert(head, value);
                break;
            case 2:
                if (head == NULL) {
                    printf("List is empty!\n");
                } else {
                    printf("Enter the value to be deleted: ");
                    scanf("%d", &value);
                    head = delete(head, value);
                }
                break;
            case 3:
                if (head == NULL) {
                    printf("List is empty!\n");
                } else {
                    printf("The list is : ");
                    display(head);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}