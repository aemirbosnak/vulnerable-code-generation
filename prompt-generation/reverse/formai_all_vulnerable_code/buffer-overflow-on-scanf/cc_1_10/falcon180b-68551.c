//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_node(struct node** head, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    printf("%d inserted successfully\n", data);
}

void delete_node(struct node** head, int data){
    struct node* temp = *head;
    struct node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        printf("%d deleted successfully\n", data);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Element not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%d deleted successfully\n", data);
}

void display_list(struct node* head){
    printf("Linked List: ");
    while(head!= NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;
    int choice, data;
    while(1){
        printf("Enter 1 to insert an element\n");
        printf("Enter 2 to delete an element\n");
        printf("Enter 3 to display the list\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert_node(&head, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;
            case 3:
                display_list(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}