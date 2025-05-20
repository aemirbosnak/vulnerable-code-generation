//FormAI DATASET v1.0 Category: Memory management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

//Define the structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

//Function to add a new node to the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//Function to traverse and print the linked list
void printList(struct Node* node) {
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int n, x;
    struct Node* head = NULL;
 
    //Prompt the user for input
    printf("Enter the number of elements to store in the linked list: ");
    scanf("%d", &n);
    printf("Enter %d integers to be inserted into the linked list:\n", n);
 
    //Loop through all the elements and add them to the linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(&head, x);
    }
 
    //Print the linked list before deleting a node
    printf("The linked list before deleting a node:\n");
    printList(head);
 
    //Delete the second node
    struct Node* temp = head->next;
    head->next = temp->next;
    free(temp);
 
    //Print the linked list after deleting a node
    printf("The linked list after deleting a node:\n");
    printList(head);

    //Free the memory allocated for the linked list
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}