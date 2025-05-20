//FormAI DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char email[50];
    struct Node* next;
};

// Function prototypes
void addEmail(struct Node** head, char* email);
void deleteEmail(struct Node** head, char* email);
void printList(struct Node *head);

int main() {
    struct Node* head = NULL;
    char email[50];
    int choice;

    do {
        printf("\nMailing List Manager\n");
        printf("--------------------\n");
        printf("\n1. Add Email\n");
        printf("2. Delete Email\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("\nEnter your choice (1-4): ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the email: ");
                scanf("%s", email);
                addEmail(&head, email);
                break;
            case 2:
                printf("\nEnter the email to delete: ");
                scanf("%s", email);
                deleteEmail(&head, email);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to add an email to the list
void addEmail(struct Node** head, char* email) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        printf("\nEmail added to the list!");
        return;
    }

    // Check if email already exists in list
    struct Node* temp = *head;

    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0) {
            printf("\nEmail already exists in the list!");
            free(newNode); // Free the newly allocated node memory
            return;
        }
        temp = temp->next;
    }

    // Add email to end of list
    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    printf("\nEmail added to the list!");
}

// Function to delete an email from the list
void deleteEmail(struct Node** head, char* email) {
    if (*head == NULL) {
        printf("\nThe list is empty!");
        return;
    }

    // Check if email exists in list
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0) {
            // Delete the node
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("\nEmail deleted from the list!");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("\nEmail not found in the list!");
}

// Function to print the list of emails
void printList(struct Node* head) {
    if (head == NULL) {
        printf("\nThe list is empty!");
        return;
    }

    printf("\nMailing List:\n");

    while (head != NULL) {
        printf("%s\n", head->email);
        head = head->next;
    }
}