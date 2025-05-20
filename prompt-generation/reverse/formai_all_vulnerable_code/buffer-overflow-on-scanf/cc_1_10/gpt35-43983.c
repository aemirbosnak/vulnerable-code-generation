//FormAI DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    A unique mailing list manager for C enthusiasts
*/

// Node struct to hold email addresses
typedef struct node {
    char email[50];
    struct node *next;
} Node;

// Function to add email to mailing list
void addEmail(Node **head, char email[]) {
    Node *newEmail = (Node*) malloc(sizeof(Node));
    strcpy(newEmail->email, email);
    newEmail->next = NULL;
    if(*head == NULL) {
        *head = newEmail;
    } else {
        Node *temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEmail;
    }
    printf("%s added to mailing list!\n", email);
}

// Function to display mailing list
void displayList(Node *head) {
    if(head == NULL) {
        printf("Mailing list is empty!\n");
    } else {
        Node *temp = head;
        printf("Mailing list:\n");
        while(temp != NULL) {
            printf("%s\n", temp->email);
            temp = temp->next;
        }
    }
}

// Function to remove email from mailing list
void deleteEmail(Node **head, char email[]) {
    Node *temp = *head;
    Node *prev = NULL;
    if(temp != NULL && strcmp(temp->email, email) == 0) {
        *head = temp->next;
        free(temp);
        printf("%s removed from mailing list!\n", email);
        return;
    }
    while(temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("%s not found in mailing list!\n", email);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%s removed from mailing list!\n", email);
}

int main() {
    Node *head = NULL;
    int choice;
    char email[50];
    do {
        printf("Mailing List Manager\n");
        printf("1. Add email\n");
        printf("2. Display list\n");
        printf("3. Delete email\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addEmail(&head, email);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter email to delete: ");
                scanf("%s", email);
                deleteEmail(&head, email);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);
    return 0;
}