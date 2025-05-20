//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: excited
#include<stdio.h>
#include<stdlib.h>

/* Define node structure */
struct node{
    int data;
    struct node* next;
};

/* Function to create a new node */
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

/* Function to add a node after a given position */
void insertAfter(struct node* prev_node, int new_data){
    if(prev_node == NULL){
        printf("The given previous node cannot be NULL");
        return;
    }

    struct node* node = newNode(new_data);
    node->next = prev_node->next;
    prev_node->next = node;
    return;
}

/* Function to delete a node */
void deleteNode(struct node **head_ref, struct node* del){
    struct node* temp = *head_ref;

    if(temp == del){
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp!= del){
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    temp->next = temp->next->next;
    free(del);
    return;
}

/* Function to search for a node */
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

int main(){
    struct node* head = NULL;

    /* Add nodes to the list */
    push(&head, 3);
    append(&head, 4);
    insertAfter(head->next, 2);

    /* Print the list */
    printf("List after insertion: ");
    printList(head);

    /* Delete a node */
    deleteNode(&head, head->next);

    /* Print the list after deletion */
    printf("\nList after deletion: ");
    printList(head);

    return 0;
}