//FormAI DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defining a structure to hold the email details */
typedef struct email {
    char emailName[50];
    char emailID[100];
    char contactNumber[20];
} Email;

/* Defining a structure to hold the node details */
typedef struct node {
    Email e;
    struct node* next;
} Node;

/* Defining the head of the linked list */
Node* head = NULL;

/* Function to add a new email to the linked list */
void addEmail(char emailName[], char emailID[], char contactNumber[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->e.emailName, emailName);
    strcpy(newNode->e.emailID, emailID);
    strcpy(newNode->e.contactNumber, contactNumber);
    newNode->next = head;
    head = newNode;
}

/* Function to display all the emails in the linked list */
void displayEmails() {
    Node* tempNode = head;
    printf("***************Mailing List***************\n");
    while (tempNode != NULL) {
        printf("Name: %s\n", tempNode->e.emailName);
        printf("Email ID: %s\n", tempNode->e.emailID);
        printf("Contact Number: %s\n", tempNode->e.contactNumber);
        printf("------------------------------------------\n");
        tempNode = tempNode->next;
    }
    printf("***************End of List***************\n");
}

/* Function to search for an email in the linked list */
void searchEmail(char emailID[]) {
    Node* tempNode = head;
    printf("***************Search Results**************\n");
    int found = 0;
    while (tempNode != NULL) {
        if (strcmp(tempNode->e.emailID, emailID) == 0) {
            printf("Name: %s\n", tempNode->e.emailName);
            printf("Email ID: %s\n", tempNode->e.emailID);
            printf("Contact Number: %s\n", tempNode->e.contactNumber);
            printf("------------------------------------------\n");
            found = 1;
            break;
        }
        tempNode = tempNode->next;
    }
    if (!found) {
        printf("Email ID not found in the mailing list.\n");
    }
    printf("***************End of Results**************\n");
}

/* Main function to test the program */
int main() {
    printf("***Welcome to Mailing List Manager***\n");
    printf("Enter the number of emails to be added to the mailing list: ");
    int numEmails;
    scanf("%d", &numEmails);
    for (int i = 0; i < numEmails; i++) {
        printf("\nEnter details of email %d:\n", i + 1);
        char emailName[50], emailID[100], contactNumber[20];
        printf("Enter email name: ");
        scanf("%s", emailName);
        printf("Enter email ID: ");
        scanf("%s", emailID);
        printf("Enter contact number: ");
        scanf("%s", contactNumber);
        addEmail(emailName, emailID, contactNumber);
    }
    printf("\n\n");
    displayEmails();
    char emailID[100];
    printf("Enter the email ID to be searched: ");
    scanf("%s", emailID);
    searchEmail(emailID);
    return 0;
}