//FormAI DATASET v1.0 Category: Linked list operations ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning successfully!\n\n", value);
}

void insertAtEnd(int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        printf("Inserted %d at end successfully!\n\n", value);
        return;
    }else{
        struct Node* last = head;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = newNode;
        printf("Inserted %d at end successfully!\n\n", value);
        return;
    }
}

void insertAtPosition(int value, int position){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    if(position == 0){
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at position %d successfully!\n\n", value, position);
        return;
    }else{
        int count = 0;
        struct Node* temp = head;
        while(temp != NULL && count < position - 1){
            temp = temp->next;
            count++;
        }
        if(temp == NULL){
            printf("Invalid position!!\n\n");
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d at position %d successfully!\n\n", value, position);
        return;
    }
}

void deleteAtBeginning(){
    if(head == NULL){
        printf("List is empty!!\n\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Deleted element from beginning successfully!\n\n");
}

void deleteAtEnd(){
    if(head == NULL){
        printf("List is empty!!\n\n");
        return;
    }
    struct Node* last = head;
    struct Node* prev = NULL;
    while(last->next != NULL){
        prev = last;
        last = last->next;
    }
    if(prev == NULL){
        head = NULL;
    }else{
        prev->next = NULL;
    }
    free(last);
    printf("Deleted element from end successfully!\n\n");
}

void deleteAtPosition(int position){
    if(head == NULL){
        printf("List is empty!!\n\n");
        return;
    }
    if(position == 0){
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Deleted element from position %d successfully!\n\n", position);
        return;
    }else{
        int count = 0;
        struct Node* temp1 = head;
        struct Node* temp2 = NULL;
        while(temp1 != NULL && count < position){
            temp2 = temp1;
            temp1 = temp1->next;
            count++;
        }
        if(temp1 == NULL){
            printf("Invalid position!!\n\n");
            return;
        }
        temp2->next = temp1->next;
        free(temp1);
        printf("Deleted element from position %d successfully!\n\n", position);
        return;
    }
}

void displayList(){
    struct Node* temp = head;
    printf("List contains: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int main(){
    int choice, value, position;
    do{
        printf("Please enter your choice:\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Display list\n8. Exit\n\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("Please enter the value to be inserted: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Please enter the value to be inserted: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Please enter the value to be inserted: ");
                scanf("%d", &value);
                printf("Please enter the position: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Please enter the position: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                displayList();
                break;
            case 8:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice!! Please try again.\n\n");
        }
    }while(choice != 8);
    return 0;
}