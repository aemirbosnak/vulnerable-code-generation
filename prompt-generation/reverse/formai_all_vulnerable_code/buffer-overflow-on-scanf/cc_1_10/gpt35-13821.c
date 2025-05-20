//FormAI DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char *email;
    struct Node *next;
}Node;

Node *head = NULL;

/* Function to insert a new email into the mailing list */
void insertEmail(char *email){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error: Memory allocation failed!\n");
        return;
    }
    newNode->email = (char *)malloc(sizeof(char) * (strlen(email)+1));
    if(newNode->email == NULL){
        printf("Error: Memory allocation failed!\n");
        free(newNode);
        return;
    }
    strcpy(newNode->email, email);
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        Node *current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Email %s added to the mailing list!\n", email);
}

/* Function to delete an email from the mailing list */
void deleteEmail(char *email){
    if(head == NULL){
        printf("Error: Mailing list is empty!\n");
        return;
    }
    Node *previous = NULL;
    Node *current = head;
    while(current != NULL){
        if(strcmp(current->email, email) == 0){
            break;
        }
        previous = current;
        current = current->next;
    }
    if(current == NULL){
        printf("Error: Email %s not found in the mailing list!\n", email);
        return;
    }
    if(previous == NULL){
        head = current->next;
    }
    else{
        previous->next = current->next;
    }
    free(current->email);
    free(current);
    printf("Email %s deleted from the mailing list!\n", email);
}

/* Function to display all emails in the mailing list */
void displayEmails(){
    if(head == NULL){
        printf("Mailing list is empty!\n");
        return;
    }
    Node *current = head;
    printf("Emails in the mailing list:\n");
    while(current != NULL){
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main(){
    int choice;
    char email[50];
    printf("\n*************************\n");
    printf("Mailing List Manager\n");
    printf("*************************\n");
    while(1){
        printf("1. Add email\n");
        printf("2. Delete email\n");
        printf("3. Display emails\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                insertEmail(email);
                break;
            case 2:
                printf("Enter email to delete: ");
                scanf("%s", email);
                deleteEmail(email);
                break;
            case 3:
                displayEmails();
                break;
            case 4:
                printf("Exiting Mailing List Manager. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}