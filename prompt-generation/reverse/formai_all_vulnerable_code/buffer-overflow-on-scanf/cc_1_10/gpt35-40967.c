//FormAI DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure of linked list node
struct node {
    char data[50];
    struct node* next;
};

// Function to add email id to linked list
void add_email(struct node** head_ref, char* email) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->data, email);
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("Email id added successfully!\n");
}

// Function to delete an email id from the linked list
void delete_email(struct node** head_ref, char* email) {
    struct node* temp = *head_ref;
    struct node* prev;
    if (temp != NULL && strcmp(temp->data, email) == 0) {
        *head_ref = temp->next;
        free(temp);
        printf("Email id deleted successfully!\n");
        return;
    }
    while (temp != NULL && strcmp(temp->data, email) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Email id not found in the list!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Email id deleted successfully!\n");
}

// Function to display all the email ids in the linked list
void display_emails(struct node* head) {
    if (head == NULL) {
        printf("No email ids found!\n");
        return;
    }
    printf("The email ids in the list are:\n");
    while (head != NULL) {
        printf("%s\n", head->data);
        head = head->next;
    }
}

int main() {
    struct node* head = NULL;
    int choice;
    char email[50];
    printf("***** Mailing List Manager *****\n");
    do {
        printf("1. Add Email\n2. Delete Email\n3. Display Emails\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the email id to add: ");
                scanf("%s", email);
                add_email(&head, email);
                break;
            case 2:
                printf("Enter the email id to delete: ");
                scanf("%s", email);
                delete_email(&head, email);
                break;
            case 3:
                display_emails(head);
                break;
            case 4:
                printf("Thank you for using Mailing List Manager!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    } while (choice != 4);
    return 0;
}