//FormAI DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Node structure for the linked list
struct Node {
    char email[50];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char* email) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    strcpy(temp->email, email);
    temp->next = NULL;
    return temp;
}

// Function to add a new email to the mailing list
void addEmail(struct Node** head, char* email) {
    struct Node* temp = createNode(email);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
}

// Function to remove a specified email from the mailing list
void removeEmail(struct Node** head, char* email) {
    struct Node* temp = *head;
    if (temp != NULL && strcmp(temp->email, email) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && strcmp(temp->email, email) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    struct Node* prev = *head;
    while (prev->next != temp) {
        prev = prev->next;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to display all the emails in the mailing list
void displayList(struct Node* head) {
    printf("\nMailing List:\n");
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%s\n", curr->email);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice;
    char email[50];
    while (1) {
        printf("1. Add Email\n2. Remove Email\n3. Display List\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                addEmail(&head, email);
                printf("Added %s to the mailing list.\n", email);
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", email);
                removeEmail(&head, email);
                printf("Removed %s from the mailing list.\n", email);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    return 0;
}