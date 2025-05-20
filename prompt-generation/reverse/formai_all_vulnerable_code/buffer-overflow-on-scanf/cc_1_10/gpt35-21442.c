//FormAI DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

struct node {  //creating the structure of the node
    int data;
    struct node *next;
};

typedef struct node Node;  //creating the alias Node for struct node

Node* createLinkedList(int n){  //function to create a linked list of n nodes
    Node *head = NULL, *temp = NULL;
    for (int i = 1; i <= n; i++){
        Node *newNode = (Node*)malloc(sizeof(Node));  //dynamic memory allocation
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL){
            head = temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void displayLinkedList(Node *head){  //function to display a linked list
    if (head == NULL){
        printf("Linked list is empty.\n");
    }
    else{
        printf("Linked list is: ");
        Node *temp = head;
        while (temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

Node* insertAtBeginning(Node *head){  //function to insert a node at the beginning
    Node *newNode = (Node*)malloc(sizeof(Node));
    printf("Enter data for the new node: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertAtEnd(Node *head){  //function to insert a node at the end
    Node *newNode = (Node*)malloc(sizeof(Node));
    printf("Enter data for the new node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL){
        head = newNode;
    }
    else{
        Node *temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

Node* insertAtPosition(Node *head){  //function to insert a node at a given position
    int pos, count = 0;
    printf("Enter the position where you want to insert a new node: ");
    scanf("%d", &pos);
    Node *newNode = (Node*)malloc(sizeof(Node));
    printf("Enter data for the new node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    Node *temp = head, *prev = NULL;
    while (temp != NULL){
        count++;
        if (count == pos){
            if (prev == NULL){
                head = newNode;
            }
            else{
                prev->next = newNode;
            }
            newNode->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (count < pos){
        printf("Invalid position.\n");
    }
    return head;
}

Node* deleteAtBeginning(Node *head){  //function to delete a node from the beginning
    if (head == NULL){
        printf("Linked list is empty.\n");
    }
    else{
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

Node* deleteAtEnd(Node *head){  //function to delete a node from the end
    if (head == NULL){
        printf("Linked list is empty.\n");
    }
    else if (head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        Node *temp = head, *prev = NULL;
        while (temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    return head;
}

Node* deleteAtPosition(Node *head){  //function to delete a node from a given position
    int pos, count = 0;
    printf("Enter the position where you want to delete a node: ");
    scanf("%d", &pos);
    if (head == NULL){
        printf("Linked list is empty.\n");
    }
    else{
        Node *temp = head, *prev = NULL;
        while (temp != NULL){
            count++;
            if (count == pos){
                if (prev == NULL){
                    head = temp->next;
                }
                else{
                    prev->next = temp->next;
                }
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if (count < pos){
            printf("Invalid position.\n");
        }
    }
    return head;
}

int main(){
    Node *head = NULL;
    int choice, n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    head = createLinkedList(n);
    while (1){
        printf("Menu:\n");
        printf("1. Display linked list\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Insert at a position\n");
        printf("5. Delete from the beginning\n");
        printf("6. Delete from the end\n");
        printf("7. Delete from a position\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                displayLinkedList(head);
                break;
            case 2:
                head = insertAtBeginning(head);
                displayLinkedList(head);
                break;
            case 3:
                head = insertAtEnd(head);
                displayLinkedList(head);
                break;
            case 4:
                head = insertAtPosition(head);
                displayLinkedList(head);
                break;
            case 5:
                head = deleteAtBeginning(head);
                displayLinkedList(head);
                break;
            case 6:
                head = deleteAtEnd(head);
                displayLinkedList(head);
                break;
            case 7:
                head = deleteAtPosition(head);
                displayLinkedList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}