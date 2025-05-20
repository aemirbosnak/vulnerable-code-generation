//FormAI DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *newNode(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to print the linked list
void printList(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct node **head, int data) {
    struct node *new_node = newNode(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct node **head, int data) {
    struct node *new_node = newNode(data);
    struct node *temp = *head;
    if(*head == NULL) {
        *head = new_node;
    } else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to insert a node at a given position in the linked list
void insertAtPosition(struct node **head, int data, int position) {
    struct node *new_node = newNode(data);
    struct node *temp = *head;
    if(position == 1) {
        new_node->next = *head;
        *head = new_node;
    }
    else {
        for(int i=1; i<position-1 && temp!=NULL; i++) {
            temp = temp->next;
        }
        if(temp == NULL) {
            printf("Position out of range\n");
        } else {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

// Function to delete a node from the beginning of the linked list
void deleteFromBeginning(struct node **head) {
    if(*head == NULL) {
        printf("List is empty\n");
    } else {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Function to delete a node from the end of the linked list
void deleteFromEnd(struct node **head) {
    if(*head == NULL) {
        printf("List is empty\n");
    } else {
        struct node *temp = *head;
        struct node *prev = NULL;
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if(prev == NULL) {
            *head = NULL;
        } else {
            prev->next = NULL;
        }
        free(temp);
    }
}

// Function to delete a node from a given position in the linked list
void deleteFromPosition(struct node **head, int position) {
    if(*head == NULL) {
        printf("List is empty\n");
    } else {
        struct node *temp = *head;
        struct node *prev = NULL;
        if(position == 1) {
            *head = (*head)->next;
            free(temp);
        } else {
            for(int i=1; i<position && temp!=NULL; i++) {
                prev = temp;
                temp = temp->next;
            }
            if(temp == NULL) {
                printf("Position out of range\n");
            } else {
                prev->next = temp->next;
                free(temp);
            }
        }
    }
}

int main() {
    struct node *head = NULL;
    int choice, data, position;
    
    while(1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n7. Print List\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 7:
                printf("List: ");
                printList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}