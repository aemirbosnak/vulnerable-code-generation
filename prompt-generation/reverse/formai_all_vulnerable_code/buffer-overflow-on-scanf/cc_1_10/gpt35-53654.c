//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct node {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct node* next;
} Node;

Node* head = NULL;

/**
 * Function to add a new email to the list
 */
void addEmail(char* name, char* email) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = head;
    head = newNode;
}

/**
 * Function to print all the emails in the list
 */
void printEmails() {
    Node* node = head;
    while(node) {
        printf("Name: %s, Email: %s\n", node->name, node->email);
        node = node->next;
    }
}

/**
 * Function to remove an email from the list
 */
void removeEmail(char* email) {
    Node* node = head;
    Node* prev = NULL;
    while(node) {
        if(strcmp(node->email, email) == 0) {
            if(prev)
                prev->next = node->next;
            else
                head = node->next;
            free(node);
            break;
        }
        prev = node;
        node = node->next;
    }
}

/**
 * Main function to run the program
 */
int main() {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int option;

    printf("*** Simple Mailing List Manager ***\n");
    printf("1. Add Email\n");
    printf("2. Print Emails\n");
    printf("3. Remove Email\n");
    printf("4. Exit\n");

    while(1) {
        printf("Select an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addEmail(name, email);
                printf("Email added.\n");
                break;
            case 2:
                printEmails();
                break;
            case 3:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeEmail(email);
                printf("Email removed.\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }

    return 0;
}