//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void addNode(node** head, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(node** head, int key){
    node* temp = *head;
    node* prev = NULL;
    while(temp!=NULL&&temp->data!=key){
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL) return;
    if(prev==NULL){
        *head = temp->next;
        free(temp);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void searchNode(node* head, int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key)
            printf("%d found\n",key);
        temp = temp->next;
    }
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    node* head = NULL;
    int n,key,i;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&key);
        addNode(&head,key);
    }
    printf("Linked List:\n");
    display(head);
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    searchNode(head,key);
    printf("Enter the element to be deleted: ");
    scanf("%d",&key);
    deleteNode(&head,key);
    printf("Linked List after deletion:\n");
    display(head);
    return 0;
}