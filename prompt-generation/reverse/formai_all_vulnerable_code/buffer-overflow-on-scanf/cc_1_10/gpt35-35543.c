//FormAI DATASET v1.0 Category: Linked list operations ; Style: careful
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void display(Node* head){
    Node* current = head;
    while(current!=NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* insertBeg(Node* head, int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

Node* insertEnd(Node* head, int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head==NULL){
        head = newNode;
    }
    else{
        Node* current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

Node* deleteBeg(Node* head){
    if(head==NULL){
        printf("List is Empty\n");
    }
    else{
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

Node* deleteEnd(Node* head){
    if(head==NULL){
        printf("List is Empty\n");
    }
    else{
        if(head->next==NULL){//List has only one element
            free(head);
            head = NULL;
        }
        else{
            Node* current = head;
            while(current->next->next!=NULL){
                current = current->next;
            }
            Node* temp = current->next;
            current->next = NULL;
            free(temp);
        }
    }
    return head;
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main(){
    Node* head = NULL;
    int choice = 0;
    int value = 0;
    do{
        printf("\nEnter choice:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete from the beginning\n");
        printf("4. Delete from the end\n");
        printf("5. Reverse the list\n");
        printf("6. Display the list\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                head = insertBeg(head, value);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;
            case 3:
                head = deleteBeg(head);
                break;
            case 4:
                head = deleteEnd(head);
                break;
            case 5:
                head = reverse(head);
                break;
            case 6:
                display(head);
                break;
            case 7:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=7);
    return 0;
}