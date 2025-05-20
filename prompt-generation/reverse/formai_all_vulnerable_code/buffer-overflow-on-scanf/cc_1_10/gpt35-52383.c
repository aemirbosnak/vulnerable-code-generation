//FormAI DATASET v1.0 Category: Linked list operations ; Style: lively
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_beginning(struct node **head, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    printf("%d inserted at the beginning\n", data);
}

void insert_end(struct node **head, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL) {
        *head = new_node;
        printf("%d inserted at the end\n", data);
    }
    else {
        struct node *temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        printf("%d inserted at the end\n", data);
    }
}

void delete_beginning(struct node **head) {
    if(*head == NULL) {
        printf("List is empty, nothing to delete\n");
    }
    else {
        struct node *temp = *head;
        *head = temp->next;
        printf("%d deleted from the beginning\n", temp->data);
        free(temp);
    }
}

void delete_end(struct node **head) {
    if(*head == NULL) {
        printf("List is empty, nothing to delete\n");
    }
    else {
        struct node *temp = *head;
        if(temp->next == NULL) {
            *head = NULL;
            printf("%d deleted from the end\n", temp->data);
            free(temp);
            return;
        }
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        struct node *del_node = temp->next;
        temp->next = NULL;
        printf("%d deleted from the end\n", del_node->data);
        free(del_node);
    }
}

void display_list(struct node *head) {
    if(head == NULL) {
        printf("List is empty\n");
    }
    else {
        printf("List: ");
        while(head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

int main() {
    struct node *head = NULL;
    int choice, data;
    do {
        printf("\n************************MENU************************\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete from the beginning\n");
        printf("4. Delete from the end\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the data to be inserted at the beginning: ");
                scanf("%d", &data);
                insert_beginning(&head, data);
                break;
            case 2:
                printf("Enter the data to be inserted at the end: ");
                scanf("%d", &data);
                insert_end(&head, data);
                break;
            case 3:
                delete_beginning(&head);
                break;
            case 4:
                delete_end(&head);
                break;
            case 5:
                display_list(head);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    }while(1);
    return 0;
}