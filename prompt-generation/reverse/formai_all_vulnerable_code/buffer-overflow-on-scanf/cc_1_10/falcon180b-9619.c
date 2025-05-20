//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int data){
    Node* newNode = createNode(data);
    Node* temp = head;
    if(head == NULL){
        return newNode;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* deleteNode(Node* head, int key){
    Node* temp = head;
    if(head == NULL){
        printf("List is Empty\n");
        return head;
    }
    if(head->data == key){
        head = head->next;
        free(temp);
        return head;
    }
    while(temp->next!= NULL && temp->next->data!= key){
        temp = temp->next;
    }
    if(temp->next == NULL){
        printf("Key Not Found\n");
        return head;
    }
    Node* temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    return head;
}

void displayList(Node* head){
    Node* temp = head;
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    printf("List: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;
    int choice, data, key;
    while(1){
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                head = insertNode(head, data);
                break;
            case 2:
                printf("Enter the key: ");
                scanf("%d", &key);
                head = deleteNode(head, key);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}