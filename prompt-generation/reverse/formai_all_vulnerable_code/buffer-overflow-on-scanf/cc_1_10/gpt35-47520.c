//FormAI DATASET v1.0 Category: Mailing list manager ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

struct node {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct node* next;
};

/*
 * Function to create a new node with given name and email
 */
struct node* create_node(char* name, char* email) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Out of memory\n");
        exit(1);
    }

    strncpy(new_node->name, name, MAX_NAME_LENGTH);
    strncpy(new_node->email, email, MAX_EMAIL_LENGTH);
    new_node->next = NULL;

    return new_node;
}

/*
 * Function to add a new node to the end of the list
 */
struct node* add_node(struct node* head, char* name, char* email) {
    if (head == NULL) {
        return create_node(name, email);
    } else {
        head->next = add_node(head->next, name, email);
        return head;
    }
}

/*
 * Function to print all nodes in the list
 */
void print_list(struct node* head) {
    if (head == NULL) {
        return;
    }

    printf("Name: %s\nEmail: %s\n\n", head->name, head->email);

    print_list(head->next);
}

/*
 * Function to recursively search for a node with a given name
 */
struct node* find_node(struct node* head, char* name) {
    if (head == NULL) {
        return NULL;
    }

    if (strcmp(head->name, name) == 0) {
        return head;
    } else {
        return find_node(head->next, name);
    }
}

/*
 * Function to delete a node with a given name
 */
struct node* delete_node(struct node* head, char* name) {
    if (head == NULL) {
        return NULL;
    }

    if (strcmp(head->name, name) == 0) {
        struct node* temp = head->next;
        free(head);
        return temp;
    } else {
        head->next = delete_node(head->next, name);
        return head;
    }
}

int main() {
    struct node* head = NULL;
    int choice;
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];

    while (1) {
        printf("1. Add a new member\n");
        printf("2. Print all members\n");
        printf("3. Search for a member\n");
        printf("4. Delete a member\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                head = add_node(head, name, email);
                break;
            case 2:
                printf("\nAll members:\n\n");
                print_list(head);
                break;
            case 3:
                printf("\nEnter name to search for: ");
                scanf("%s", name);

                struct node* result = find_node(head, name);
                if (result == NULL) {
                    printf("\nMember not found.\n\n");
                } else {
                    printf("\nMatching member:\n\n");
                    printf("Name: %s\nEmail: %s\n\n", result->name, result->email);
                }

                break;
            case 4:
                printf("\nEnter name to delete: ");
                scanf("%s", name);
                head = delete_node(head, name);
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n\n");
        }
    }

    return 0;
}