//FormAI DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct mailing_list {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    struct mailing_list *next;
} MailingList;

//Function to create a new mailing list node
MailingList* create_node(char *name, char *email) {
    MailingList *node = (MailingList*) malloc(sizeof(MailingList));
    if(node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    strcpy(node->name, name);
    strcpy(node->email, email);
    node->next = NULL;
    return node;
}

//Function to add a new node to the mailing list
MailingList* add_node(MailingList *list, char *name, char *email) {
    MailingList *node = create_node(name, email);
    if(list == NULL) {
        list = node;
    } else {
        MailingList *temp = list;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    printf("Successfully added '%s' with email '%s' to the mailing list.\n", name, email);
    return list;
}

//Function to print the entire mailing list
void print_list(MailingList *list) {
    if(list == NULL) {
        printf("Mailing list is empty.\n");
    } else {
        printf("Mailing list:\n");
        while(list != NULL) {
            printf("Name: %s\tEmail: %s\n", list->name, list->email);
            list = list->next;
        }
    }
}

//Function to find a node by email id and delete it
MailingList* delete_node(MailingList *list, char *email) {
    if(list == NULL) {
        printf("Error: Mailing list is empty.\n");
    } else if(strcmp(list->email, email) == 0) {
        MailingList *temp = list;
        list = list->next;
        printf("Successfully deleted '%s' from the mailing list.\n", temp->name);
        free(temp);
    } else {
        MailingList *temp = list;
        while(temp->next != NULL && strcmp(temp->next->email, email) != 0) {
            temp = temp->next;
        }
        if(temp->next == NULL) {
            printf("Error: Email id not found.\n");
        } else {
            MailingList *delete_node = temp->next;
            temp->next = delete_node->next;
            printf("Successfully deleted '%s' from the mailing list.\n", delete_node->name);
            free(delete_node);
        }
    }
    return list;
}

int main() {

    printf("Welcome to the Mailing List Manager!\n");

    MailingList *list = NULL; //Initializing empty mailing list

    int option;
    char name[MAX_NAME_LEN], email[MAX_EMAIL_LEN];

    do {
        printf("\nChoose an option:\n");
        printf("1. Add a new entry\n");
        printf("2. View the entire mailing list\n");
        printf("3. Delete an entry\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email id: ");
                scanf("%s", email);
                list = add_node(list, name, email);
                break;
            case 2:
                print_list(list);
                break;
            case 3:
                printf("Enter email id to delete: ");
                scanf("%s", email);
                list = delete_node(list, email);
                break;
            case 4:
                printf("Exiting Mailing List Manager...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

    } while(option != 4);

    return 0;
}