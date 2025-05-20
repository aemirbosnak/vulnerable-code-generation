//FormAI DATASET v1.0 Category: Linked list operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to represent a node in the linked list */
typedef struct node {
    int data;           // data stored in the node
    struct node* next;  // pointer to the next node in the list
} node;

/* Function to create a new node */
node* create_node(int data) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to print the linked list */
void print_list(node* head) {
    node* current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* Function to add a node to the front of the linked list */
void insert_front(node** head, int data) {
    node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

/* Function to add a node to the end of the linked list */
void insert_end(node** head, int data) {
    node* new_node = create_node(data);
    if(*head == NULL){
        *head = new_node;
        return;
    }
    node* current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

/* Function to remove a node from the linked list */
void remove_node(node** head, int data) {
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    if((*head)->data == data){
        node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    node* current = *head;
    while(current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if(current->next == NULL) {
        printf("Node not found\n");
        return;
    }
    node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

int main() {
    node* head = NULL;
    int option, data;

    printf("Welcome to the C Linked List game!\n");
    printf("In this game, you and your friends will take turns modifying a linked list.\n");
    printf("The game will continue until one player reaches the winning score of 10.\n\n");

    while(1) {
        printf("Player %d's turn:\n", (head != NULL) ? head->data : 1);
        printf("Choose an option:\n");
        printf("1 - Insert a node to the front of the list\n");
        printf("2 - Insert a node to the end of the list\n");
        printf("3 - Remove a node from the list\n");
        printf("4 - Print the list\n");
        printf("Option: ");

        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insert_front(&head, data);
                break;
            case 2:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insert_end(&head, data);
                break;
            case 3:
                printf("Enter the data to be removed: ");
                scanf("%d", &data);
                remove_node(&head, data);
                break;
            case 4:
                print_list(head);
                break;

            default:
                printf("Invalid option\n");
                break;
        }

        /* Check if a player has won */
        if(head != NULL && head->data >= 10) {
            printf("\nCongratulations Player %d! You have won the game!\n", head->data);
            break;
        }

        /* Move to the next player */
        if(head != NULL) {
            node* temp = head->next;
            if(temp == NULL) {
                temp = head;
            }
            head = temp;
        }
    }

    /* Free up memory used by the linked list */
    node* current = head;
    while(current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}