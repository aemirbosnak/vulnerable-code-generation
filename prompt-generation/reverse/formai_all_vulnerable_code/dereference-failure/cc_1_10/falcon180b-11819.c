//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

/* Function to create a new node with the given data */
struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* Function to add a node at the beginning of the list */
void push(struct node** head_ref, int new_data){
    struct node* node = newNode(new_data);
    node->next = *head_ref;
    *head_ref = node;
}

/* Function to add a node at the end of the list */
void append(struct node** head_ref, int new_data){
    struct node* node = newNode(new_data);
    struct node* last = *head_ref;
    if(*head_ref == NULL){
        node->next = NULL;
        *head_ref = node;
        return;
    }
    while(last->next!= NULL){
        last = last->next;
    }
    last->next = node;
    return;
}

/* Function to delete a node with the given data */
void deleteNode(struct node **head_ref, int key){
    struct node* temp = *head_ref, *prev;
    if(temp!= NULL && temp->data == key){
        temp = temp->next;
        *head_ref = temp;
        free(prev);
        return;
    }
    while(temp!= NULL && temp->data!= key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
    return;
}

/* Function to search for a node with the given data */
struct node* search(struct node* head, int x){
    struct node* current = head;
    while(current!= NULL){
        if(current->data == x){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* Function to print the list */
void printList(struct node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Driver program to test above functions */
int main(){
    struct node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    printList(head);
    append(&head, 50);
    append(&head, 60);
    printList(head);
    deleteNode(&head, 30);
    printList(head);
    struct node* result = search(head, 50);
    if(result!= NULL){
        printf("Found\n");
    }
    else{
        printf("Not found\n");
    }
    return 0;
}