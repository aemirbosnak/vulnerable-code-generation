//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

// Node structure definition
struct Node{
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if(!node){
        printf("Memory error\n");
        exit(0);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(struct Node** head, int data){
    struct Node* node = newNode(data);
    node->next = *head;
    *head = node;
}

// Function to add a node at the end of the list
void append(struct Node** head, int data){
    struct Node* node = newNode(data);
    struct Node* last = *head;
    if(*head == NULL){
        node->next = NULL;
        *head = node;
        return;
    }
    while(last->next!= NULL){
        last = last->next;
    }
    last->next = node;
    return;
}

// Function to add a node at a given position in the list
void insertAtPosition(struct Node** head, int data, int pos){
    struct Node* node = newNode(data);
    struct Node* temp = *head;
    if(pos == 1){
        node->next = temp;
        *head = node;
        return;
    }
    for(int i=1;i<pos-1 && temp!= NULL;i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Invalid position\n");
        exit(0);
    }
    node->next = temp->next;
    temp->next = node;
    return;
}

// Function to delete a node with given data from the list
void deleteNode(struct Node** head, int data){
    struct Node* temp = *head;
    struct Node* prev;
    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Node not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    return;
}

// Function to display the list
void display(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main(){
    struct Node* head = NULL;
    int choice, data;
    while(1){
        printf("1. Push\n2. Append\n3. Insert at position\n4. Delete node\n5. Display\n6. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                append(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &data);
                insertAtPosition(&head, data, data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}