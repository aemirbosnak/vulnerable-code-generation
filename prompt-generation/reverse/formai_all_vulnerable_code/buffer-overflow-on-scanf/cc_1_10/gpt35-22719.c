//FormAI DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;

node* create_node(int data){
    node* temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert_node(node** head, int data){
    node* temp = create_node(data);
    if(*head == NULL){
        *head = temp;
    } else {
        node* ptr = *head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    printf("%d has been inserted into the list successfully.\n", data);
}

void delete_node(node** head, int data){
    if(*head == NULL){
        printf("The list is empty.\n");
    } else {
        node* ptr = *head;
        node* prev = NULL;
        while(ptr != NULL && ptr->data != data){
            prev = ptr;
            ptr = ptr->next;
        }
        if(ptr == NULL){
            printf("%d is not present in the list.\n", data);
        } else if(prev == NULL){
            *head = ptr->next;
            free(ptr);
            printf("%d has been deleted from the list successfully.\n", data);
        } else {
            prev->next = ptr->next;
            free(ptr);
            printf("%d has been deleted from the list successfully.\n", data);
        }
    }
}

void display_list(node* head){
    if(head == NULL){
        printf("The list is empty.\n");
    } else {
        printf("The list is:\n");
        node* ptr = head;
        while(ptr != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void reverse_list(node** head){
    if(*head == NULL){
        printf("The list is empty.\n");
    } else {
        node* current = *head;
        node* prev = NULL;
        node* next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *head = prev;
        printf("The list has been reversed successfully.\n");
    }
}

int main(){
    node* head = NULL;
    int choice, data;
    while(choice != 5){
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the list\n");
        printf("4. Reverse the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the data: ");
                    scanf("%d", &data);
                    insert_node(&head, data);
                    break;
            case 2: printf("Enter the data: ");
                    scanf("%d", &data);
                    delete_node(&head, data);
                    break;
            case 3: display_list(head);
                    break;
            case 4: reverse_list(&head);
                    break;
            case 5: printf("Exiting...\n");
                    break;
            default:printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}