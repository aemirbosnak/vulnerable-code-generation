//FormAI DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declare linked list node for email addresses
struct EmailNode {
    char email[50];
    struct EmailNode* next;
};

// function to create a new email node
struct EmailNode* createEmailNode(char email[]) {
    struct EmailNode* newNode = (struct EmailNode*) malloc(sizeof(struct EmailNode));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

// function to add email to mailing list
void addToMailingList(struct EmailNode** headRef, char email[]) {
    struct EmailNode* newNode = createEmailNode(email);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct EmailNode* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// function to remove email from mailing list
void removeFromMailingList(struct EmailNode** headRef, char email[]) {
    if (*headRef == NULL) {
        printf("Mailing list is empty.\n");
        return;
    }
    struct EmailNode* currentNode = *headRef;
    struct EmailNode* previousNode = NULL;
    while (currentNode != NULL && strcmp(currentNode->email, email) != 0) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) {
        printf("Email address not found in mailing list.\n");
        return;
    }
    if (previousNode == NULL) {
        *headRef = currentNode->next;
    } else {
        previousNode->next = currentNode->next;
    }
    free(currentNode);
}

// function to print all emails in mailing list
void printMailingList(struct EmailNode* head) {
    if (head == NULL) {
        printf("Mailing list is empty.\n");
        return;
    }
    printf("Mailing list:\n");
    struct EmailNode* currentNode = head;
    while (currentNode != NULL) {
        printf("- %s\n", currentNode->email);
        currentNode = currentNode->next;
    }
}

// main function
int main() {
    struct EmailNode* mailingList = NULL; // initialize mailing list to empty
    int option;
    char email[50];
    do {
        printf("\nEnter an option:\n");
        printf("1 - Add email to mailing list\n");
        printf("2 - Remove email from mailing list\n");
        printf("3 - Print all emails in mailing list\n");
        printf("4 - Exit program\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nEnter email address to add: ");
                scanf("%s", email);
                addToMailingList(&mailingList, email);
                printf("%s added to mailing list.\n", email);
                break;
            case 2:
                printf("\nEnter email address to remove: ");
                scanf("%s", email);
                removeFromMailingList(&mailingList, email);
                printf("%s removed from mailing list.\n", email);
                break;
            case 3:
                printMailingList(mailingList);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nEnter a valid option.\n");
        }
    } while (option != 4);
    return 0;
}