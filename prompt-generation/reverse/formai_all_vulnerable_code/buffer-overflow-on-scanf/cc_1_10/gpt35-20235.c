//FormAI DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char email[50];
    struct node *next;
}Node;

void addEmail(Node **head, char *email) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Unable to allocate memory.\n");
        return;
    }
    strcpy(newNode->email, email);
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        printf("%s added successfully!\n", email);
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    printf("%s added successfully!\n", email);
}

void removeEmail(Node **head, char *email) {
    if (*head == NULL) {
        printf("Error: Mailing list is empty!\n");
        return;
    }
    Node *temp = *head, *prev = NULL;
    while (temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: %s not found in mailing list!\n", email);
        return;
    }
    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;
    free(temp);
    printf("%s removed successfully!\n", email);
}

void printList(Node *head) {
    if (head == NULL) {
        printf("Mailing list is empty!\n");
        return;
    }
    printf("Current Mailing List:\n");
    Node *temp = head;
    while (temp != NULL) {
        printf("-> %s\n", temp->email);
        temp = temp->next;
    }
}

int main() {
    Node *mailingList = NULL;
    int choice;
    char email[50];
    do {
        printf("Menu:\n1. Add email to mailing list\n2. Remove email from mailing list\n3. Print current mailing list\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter email address to be added: ");
                scanf("%s", email);
                addEmail(&mailingList, email);
                break;
            case 2:
                printf("Enter email address to be removed: ");
                scanf("%s", email);
                removeEmail(&mailingList, email);
                break;
            case 3:
                printList(mailingList);
                break;
            case 4:
                printf("Exiting Mailing List Manager...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}