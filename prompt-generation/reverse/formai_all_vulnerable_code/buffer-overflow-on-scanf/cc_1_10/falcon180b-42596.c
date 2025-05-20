//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

//Defining structure for a node in linked list
struct Node{
    int data;
    struct Node* next;
};

//Function to create a new node with given data
struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

//Function to add a node at the end of the list
void push(struct Node** head_ref, int new_data){
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;
 
    /* If the list is empty, set the head to new node */
    if (*head_ref == NULL) {
        new_node->next = NULL;
        return;
    }
 
    /* Traverse till the end of list */
    while (last->next!= NULL)
        last = last->next;
 
    /* Add new node to end of list */
    last->next = new_node;
    return;
}

//Function to search for an element in the linked list
struct Node* search(struct Node* head, int x){
    struct Node* current = head;
 
    /* Loop through the linked list */
    while (current!= NULL) {
        /* If the element is found, return the node */
        if (current->data == x)
            return current;
        current = current->next;
    }
    /* If the element is not found, return NULL */
    return NULL;
}

//Main function
int main(){
    int choice, data;
    struct Node* head = NULL;
 
    /* Loop until the user chooses to exit */
    while(1){
        /* Display the menu */
        printf("\n");
        printf("1. Push\n");
        printf("2. Search\n");
        printf("3. Exit\n");
        printf("\n");
        scanf("%d", &choice);
 
        /* Perform the chosen operation */
        switch(choice){
            case 1:
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(&head, data);
                printf("\nData pushed successfully!\n");
                break;
            case 2:
                printf("Enter the data to be searched: ");
                scanf("%d", &data);
                struct Node* result = search(head, data);
                if (result == NULL)
                    printf("\nElement not found!\n");
                else
                    printf("\nElement found!\n");
                break;
            case 3:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}