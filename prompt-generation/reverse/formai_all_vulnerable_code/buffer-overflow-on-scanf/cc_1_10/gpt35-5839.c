//FormAI DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

void insert_at_beginning(node **head){
    node *n = (node*) malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &n->data);
    n->next = *head;
    *head = n;
}

void insert_at_end(node **head){
    node *n = (node*) malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &n->data);
    n->next = NULL;
    if(*head == NULL){
        *head = n;
        return;
    }
    node *temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = n;
}

void delete_element(node **head, int element){
    node *temp = *head, *prev;
    if(temp != NULL && temp->data == element){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != element){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Element not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void print_list(node *head){
    printf("List elements: ");
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void delete_list(node **head){
    *head = NULL;
    printf("List deleted.\n");
}

int main(){
    node *head = NULL;
    int choice, element;
    do{
        printf("1. Insert at beginning\n2. Insert at end\n3. Delete element\n4. Print list\n5. Delete list\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: insert_at_beginning(&head); break;
            case 2: insert_at_end(&head); break;
            case 3:
                printf("Enter element to be deleted: ");
                scanf("%d", &element);
                delete_element(&head, element);
                break;
            case 4: print_list(head); break;
            case 5: delete_list(&head); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }while(choice != 6);
    return 0;
}