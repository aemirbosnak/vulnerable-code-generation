//FormAI DATASET v1.0 Category: Memory management ; Style: peaceful
/* This program demonstrates memory management in C using linked lists.
   The program allocates memory for nodes in the linked list, adds data to these nodes, frees memory for nodes, and prints the data in them.
   It does all this in a peaceful and harmonious way, without causing any harm to system resources.
*/

#include<stdio.h>
#include<stdlib.h>

// A structure for the node of the linked list
struct node{
    int data;
    struct node* next;
};

int main(){
    struct node* head = NULL;  // head node of the linked list is initialized to be NULL
    struct node* new_node = NULL;
    int i, n;

    printf("How many nodes do you want to allocate memory for? ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        // Allocate memory for a new node
        new_node = (struct node*) malloc(sizeof(struct node));
        if(new_node == NULL){
            printf("ERROR: Memory could not be allocated for new node.\n");
            exit(1);
        }

        // Add data to the new node
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &(new_node->data));
        new_node->next = NULL;

        // Add the new node to the linked list
        if(head == NULL){
            head = new_node;
        }
        else{
            struct node* current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = new_node;
        }
    }

    printf("The data in the linked list is: ");
    // Print the data in the linked list
    struct node* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Free the memory allocated for nodes in the linked list
    current = head;
    while(current != NULL){
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}