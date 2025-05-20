//FormAI DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include<stdio.h>  
#include<stdlib.h>  

struct node{  
    int data;  
    struct node *next;  
};  

void insert_at_beginning(struct node **head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
    printf("%d inserted successfully at the beginning.\n", data);
}

void insert_at_end(struct node **head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) { 
        *head = newNode; 
    } else {
        struct node *lastNode = *head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    printf("%d inserted successfully at the end.\n", data);
}

void display_list(struct node *head) {
    printf("The content of the list is: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Display list\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                insert_at_beginning(&head, data);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 3:
                display_list(head);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please make a valid choice.\n");
        }
    }

    return 0;
}