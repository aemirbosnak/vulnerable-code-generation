//FormAI DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>  
#include <stdlib.h>  

struct list_node    // defining the structure of node
{  
    int data;    // variable to store data
    struct list_node *next;  // pointer to the next node
};  

void add_node_at_beginning(struct list_node **head, int data_value)    // adding node at the beginning of the linked list
{  
    struct list_node *new_node = (struct list_node*) malloc(sizeof(struct list_node));  
    new_node->data = data_value;  
    new_node->next = *head;  
    *head = new_node;  
    printf("\n Node with value %d is added at the beginning.", data_value);  
}  
   

void add_node_at_end(struct list_node *head, int data_value)    // adding node at the end of the linked list
{  
    while(head->next!=NULL)  
    {  
        head = head->next;  
    }  
    //now, we can add the new node safely
    struct list_node *new_node = (struct list_node*) malloc(sizeof(struct list_node));  
    new_node->data = data_value;  
    new_node->next = NULL;  
    head->next = new_node;  
    printf("\n Node with value %d is added at the end.", data_value);  
}  
   

void delete_node_from_end(struct list_node *head)    // deleting the node from the end of the linked list
{  
    struct list_node *previous_node;  
    while(head->next!=NULL)  
    {  
        previous_node = head;  
        head = head->next;  
    }  
    previous_node->next = NULL;  
    free(head);  
    printf("\n Node from the end is deleted from the list.");  
}  
   

void display_list(struct list_node *head)    // displaying the linked list
{  
    int node_number=1;
    printf("\n\nDisplaying the Linked List....\n");  
    while(head!=NULL)  
    {  
        printf("\nNode %d :: Data = %d\n",node_number,head->data);  
        head = head->next;  
        node_number++;
    }  
}  

int main()  
{  
    struct list_node *head = NULL;  // declaring the variables
    int choice, data_value;  

    printf("Welcome to the Linked List program!\n");  

    do  
    {  
        printf("\n\n***********MENU************\n\n");  
        printf("1. Add a node at the beginning.\n");  
        printf("2. Add a node at the end.\n");  
        printf("3. Delete a node from the end.\n");  
        printf("4. Display the linked list.\n");  
        printf("5. Exit the program.\n");  
        printf("\nEnter your choice : ");  
        scanf("%d",&choice);  

        switch(choice)  
        {  
            case 1:  
                printf("\nEnter the value to be added at the beginning : ");  
                scanf("%d",&data_value);  
                add_node_at_beginning(&head, data_value);  
                break;  
            case 2:  
                printf("\nEnter the value to be added at the end : ");  
                scanf("%d",&data_value);  
                if(head!=NULL)  
                    add_node_at_end(head, data_value);  
                else  
                    printf("\nList is empty, Node %d is added at the beginning.\n",data_value);         
                break;  
            case 3:  
                if(head!=NULL)  
                    delete_node_from_end(head);  
                else  
                    printf("\nList is empty.\n");         
                break;  
            case 4:  
                if(head!=NULL)  
                    display_list(head);  
                else  
                    printf("\nList is empty.\n");         
                break;  
            case 5:  
                printf("\nExiting the program....\n");  
                exit(0);  
            default:  
                printf("\nInvalid Choice. Please try again!\n");  
        }  
    } while(choice!=5);  
    return 0;  
}