//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Defining the structure of a node
struct Node{
    int data;
    struct Node *next;
};

//Function to insert a node at the end of the list
void insert(struct Node **head_ref, int new_data){
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if(*head_ref == NULL){
        new_node->next = new_node;
        *head_ref = new_node;
    }
    else{
        while(last->next!= *head_ref){
            last = last->next;
        }
        last->next = new_node;
        new_node->next = *head_ref;
    }
}

//Function to print the list
void printList(struct Node *node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    struct Node *head = NULL;
    int choice, data;

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insert(&head, data);
                break;

            case 2:
                printf("List: ");
                printList(head);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }

    return 0;
}