//FormAI DATASET v1.0 Category: Mailing list manager ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50

typedef struct node {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct node *next;
} Node;

// function to insert a new node into the linked list
void insert(Node **head_ref, char name[], char email[]) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// function to delete a node from the linked list
void delete(Node **head_ref, char email[]) {
    Node *temp = *head_ref, *prev = NULL;
    if (temp != NULL && strcmp(temp->email, email) == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// function to print the entire linked list
void print_list(Node *node) {
    while (node != NULL) {
        printf("Name: %s, ", node->name);
        printf("Email: %s\n", node->email);
        node = node->next;
    }
}

int main() {
    Node *head = NULL;

    printf("Mailing List Manager\n");

    while (1) {
        printf("Enter 1 to add contact, 2 to delete contact, 3 to view contact list, or 4 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];
            printf("Name: ");
            scanf("%s", name);
            printf("Email: ");
            scanf("%s", email);
            insert(&head, name, email);
            printf("%s has been added to the mailing list.\n", name);
        }
        else if (choice == 2) {
            char email[MAX_EMAIL_LENGTH];
            printf("Enter the email of the contact you want to delete: ");
            scanf("%s", email);
            delete(&head, email);
            printf("Contact with email %s has been deleted from the mailing list.\n", email);
        }
        else if (choice == 3) {
            if (head == NULL) printf("There are no contacts in the mailing list.\n");
            else print_list(head);
        }
        else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    // free memory allocated to linked list
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}