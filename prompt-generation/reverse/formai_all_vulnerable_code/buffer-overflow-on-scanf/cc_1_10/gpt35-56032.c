//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for mailing list entry
typedef struct mailing_list_entry {
    char* name;
    char* email;
    struct mailing_list_entry* next;
} MailingListEntry;

// Initialize the head of the mailing list to NULL
MailingListEntry* head = NULL;

// Function to add a new entry to the mailing list
void add_mailing_list_entry(char* name, char* email) {
    MailingListEntry* new_entry = (MailingListEntry*)malloc(sizeof(MailingListEntry));
    new_entry->name = (char*)malloc(strlen(name)+1);
    new_entry->email = (char*)malloc(strlen(email)+1);
    strcpy(new_entry->name, name);
    strcpy(new_entry->email, email);
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        MailingListEntry* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

// Function to delete an entry from the mailing list based on email
void delete_mailing_list_entry(char* email) {
    if (head == NULL) {
        printf("The mailing list is empty.\n");
        return;
    } else if (strcmp(email, head->email) == 0) {
        MailingListEntry* to_delete = head;
        head = head->next;
        free(to_delete->name);
        free(to_delete->email);
        free(to_delete);
        return;
    } else {
        MailingListEntry* current = head;
        while (current->next != NULL && strcmp(email, current->next->email) != 0) {
            current = current->next;
        }
        if (current->next == NULL) {
            printf("No entry with email %s was found.\n", email);
            return;
        } else {
            MailingListEntry* to_delete = current->next;
            current->next = to_delete->next;
            free(to_delete->name);
            free(to_delete->email);
            free(to_delete);
            return;
        }
    }
}

// Function to print out the entire mailing list
void show_mailing_list() {
    if (head == NULL) {
        printf("The mailing list is empty.\n");
        return;
    } else {
        MailingListEntry* current = head;
        printf("Mailing List Entries:\n");
        printf("---------------------\n");
        while (current != NULL) {
            printf("Name: %s\n", current->name);
            printf("Email: %s\n", current->email);
            printf("---------------------\n");
            current = current->next;
        }
    }
}

int main() {
    // Cyberpunk style welcome message
    printf("============================================\n");
    printf("WELCOME TO YOUR CYBERPUNK MAILING LIST MANAGER\n");
    printf("============================================\n\n");

    // Main program loop
    char command;
    do {
        printf("What would you like to do?\n");
        printf("[A]dd an entry\n");
        printf("[D]elete an entry\n");
        printf("[S]how the mailing list\n");
        printf("[Q]uit the program\n");
        printf("Enter your command: ");
    
        scanf(" %c", &command);
        switch (command) {
            case 'a':
            case 'A': {
                char name[50];
                char email[50];
                printf("Enter the name: ");
                scanf("%s", name);
                printf("Enter the email: ");
                scanf("%s", email);
                add_mailing_list_entry(name, email);
                printf("New entry added!\n\n");
                break;
            }
            case 'd':
            case 'D': {
                char email[50];
                printf("Enter the email to delete: ");
                scanf("%s", email);
                delete_mailing_list_entry(email);
                printf("\n");
                break;
            }
            case 's':
            case 'S':
                show_mailing_list();
                printf("\n");
                break;
            case 'q':
            case 'Q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid command. Please try again.\n\n");
                break;
        }
    } while (command != 'q' && command != 'Q');

    // Free all allocated memory before quitting
    MailingListEntry* current = head;
    while (current != NULL) {
        MailingListEntry* to_delete = current;
        current = current->next;
        free(to_delete->name);
        free(to_delete->email);
        free(to_delete);
    }

    return 0;
}