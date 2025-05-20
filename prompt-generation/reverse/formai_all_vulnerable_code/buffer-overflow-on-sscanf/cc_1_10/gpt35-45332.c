//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for each node in our linked list
struct Node {
    char email[50];
    struct Node* next;
};

// add a new email to the mailing list
void addEmail(struct Node** head, char email[]) {
    // create a new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    // copy the email into the new node
    strcpy(newNode->email, email);
    // set the next node pointer to null
    newNode->next = NULL;
    // if the head is null, set the head to the new node
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    // otherwise traverse to the end of the list and add the new node
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// remove an email from the mailing list
void removeEmail(struct Node** head, char email[]) {
    struct Node* current = *head;
    // if the head is null, return
    if (current == NULL) {
        return;
    }
    // if the head matches the email, set the head to the next node and free the current node
    if (strcmp(current->email, email) == 0) {
        *head = current->next;
        free(current);
        return;
    }
    // otherwise traverse the list and remove the node with the matching email
    while (current->next != NULL) {
        if (strcmp(current->next->email, email) == 0) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

// print all emails in the mailing list
void printMailingList(struct Node* head) {
    struct Node* current = head;
    printf("Current Mailing List: \n");
    while (current != NULL) {
        printf("- %s\n", current->email);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    char input[50];
    while (1) {
        printf("Enter an option:\n1. Add email\n2. Remove email\n3. Print mailing list\n4. Exit\n");
        fgets(input, 50, stdin);
        int option = atoi(input);
        switch (option) {
            case 1:
                printf("Enter email to add:\n");
                fgets(input, 50, stdin);
                sscanf(input, "%s", input);
                addEmail(&head, input);
                printf("Email added.\n\n");
                break;
            case 2:
                printf("Enter email to remove:\n");
                fgets(input, 50, stdin);
                sscanf(input, "%s", input);
                removeEmail(&head, input);
                printf("Email removed.\n\n");
                break;
            case 3:
                printMailingList(head);
                break;
            case 4:
                printf("Exiting...\n\n");
                exit(0);
            default:
                printf("Invalid option.\n\n");
                break;
        }
    }
    return 0;
}