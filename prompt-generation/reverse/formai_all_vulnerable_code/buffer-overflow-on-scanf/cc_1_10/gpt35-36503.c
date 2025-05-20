//FormAI DATASET v1.0 Category: Mailing list manager ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

typedef struct node {
    char email[MAX];
    struct node *next;
}Node;

void insert(Node **head, char new_email[]) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Error in memory allocation\n");
        return;
    }
    strcpy(new_node->email, new_email);
    new_node->next = NULL;
    if(*head == NULL) {
        *head = new_node;
        return;
    }

    Node *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}

void printList(Node *head) {
    if(head == NULL) {
        printf("The mailing list is empty\n");
        return;
    }
    printf("The current mailing list is:\n");
    while(head != NULL) {
        printf("%s\n", head->email);
        head = head->next;
    }
}

void delete(Node **head, char email[]) {
    if(*head == NULL) {
        printf("The mailing list is empty\n");
        return;
    }
    if(strcmp((*head)->email, email) == 0) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node *prev = *head;
    Node *curr = prev->next;

    while(curr != NULL && strcmp(curr->email, email) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL) {
        printf("%s is not in the mailing list\n", email);
        return;
    }
    prev->next = curr->next;
    free(curr);
    return;
}

int main() {
    Node *head = NULL;
    while(1) {
        printf("**********Mailing list management system**********\n");
        printf("1. Add an email to the mailing list\n");
        printf("2. Remove an email from the mailing list\n");
        printf("3. View the current mailing list\n");
        printf("4. Exit\n\n");

        int choice;
        printf("Please enter your choice(1-4): ");
        scanf("%d", &choice);

        if(choice == 1) {
            char new_email[MAX];
            printf("Please enter the new email to add: ");
            scanf("%s", new_email);
            insert(&head, new_email);
            printf("Email added successfully!\n");
        }
        else if(choice == 2) {
            char email[MAX];
            printf("Please enter the email to remove: ");
            scanf("%s", email);
            delete(&head, email);
        }
        else if(choice == 3) {
            printList(head);
        }
        else if(choice == 4) {
            printf("Exiting the program, thank you!\n");
            break;
        }
        else{
            printf("Invalid choice, please enter 1-4\n");
        }
    }
    return 0;
}