//FormAI DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list {
    char name[30];
    char email[50];
    struct mailing_list* next;
};

typedef struct mailing_list MailingList;

MailingList* head = NULL;

void add_to_list(char* name, char* email) {
    MailingList* new_contact = (MailingList*)malloc(sizeof(MailingList));
    strncpy(new_contact->name, name, 30);
    strncpy(new_contact->email, email, 50);
    new_contact->next = head;
    head = new_contact;
    printf("%s added to mailing list with email %s!\n", name, email);
}

void print_list() {
    MailingList* current_contact = head;
    while (current_contact != NULL) {
        printf("Name: %s\nEmail: %s\n", current_contact->name, current_contact->email);
        current_contact = current_contact->next;
    }
}

void remove_from_list(char* email) {
    MailingList* current_contact = head;
    MailingList* previous_contact = NULL;
    while (current_contact != NULL && strcmp(current_contact->email, email) != 0) {
        previous_contact = current_contact;
        current_contact = current_contact->next;
    }
    if (current_contact == NULL) {
        printf("Email %s is not in the mailing list!\n", email);
    } else if (previous_contact == NULL) {
        head = current_contact->next;
        free(current_contact);
        printf("Email %s has been removed from the mailing list!\n", email);
    } else {
        previous_contact->next = current_contact->next;
        free(current_contact);
        printf("Email %s has been removed from the mailing list!\n", email);
    }
}

int main() {
    printf("Welcome to the mailing list manager!\n");
    while (1) {
        printf("\nEnter a command (add, remove, print, or exit): ");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            printf("Enter name: ");
            char name[30];
            scanf("%s", name);
            printf("Enter email: ");
            char email[50];
            scanf("%s", email);
            add_to_list(name, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter email: ");
            char email[50];
            scanf("%s", email);
            remove_from_list(email);
        } else if (strcmp(command, "print") == 0) {
            print_list();
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid command entered!\n");
        }
    }
    return 0;
}