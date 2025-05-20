//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

node_t* create_node(int data){
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if(new_node == NULL){
        printf("Memory Error\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append_node(node_t** head, int data){
    node_t* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void prepend_node(node_t** head, int data){
    node_t* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void delete_node(node_t** head, int data){
    node_t* temp = *head;
    if(temp == NULL){
        printf("List is Empty\n");
        return;
    }
    if(temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp->next!= NULL && temp->next->data!= data){
        temp = temp->next;
    }
    if(temp->next == NULL){
        printf("Element not found\n");
        return;
    }
    node_t* del_node = temp->next;
    temp->next = temp->next->next;
    free(del_node);
}

void traverse_list(node_t* head){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    printf("List Elements are: ");
    while(head!= NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    node_t* head = NULL;
    int choice, data;
    while(1){
        printf("Enter your choice:\n");
        printf("1. Append Node\n");
        printf("2. Prepend Node\n");
        printf("3. Delete Node\n");
        printf("4. Traverse List\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be appended:\n");
                scanf("%d", &data);
                append_node(&head, data);
                break;
            case 2:
                printf("Enter the data to be prepended:\n");
                scanf("%d", &data);
                prepend_node(&head, data);
                break;
            case 3:
                printf("Enter the data to be deleted:\n");
                scanf("%d", &data);
                delete_node(&head, data);
                break;
            case 4:
                traverse_list(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}