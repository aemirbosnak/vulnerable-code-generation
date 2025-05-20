//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insert(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(struct Node **head_ref, int key){
    struct Node* temp = *head_ref;
    struct Node* prev;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp);            
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void search(struct Node* head, int key){
    struct Node* current = head;
    while(current!= NULL){
        if(current->data == key){
            printf("Element found\n");
            return;
        }
        current = current->next;
    }
    printf("Element not found\n");
}

void printList(struct Node* node){
    while(node!= NULL){
        printf("%d ",node->data);
        node = node->next;
    }
}

int main(){
    struct Node* head = NULL;
    insert(&head,7);
    insert(&head,1);
    insert(&head,3);
    insert(&head,2);
    insert(&head,6);
    insert(&head,5);
    printList(head);
    search(head,6);
    deleteNode(&head,3);
    printList(head);
    return 0;
}