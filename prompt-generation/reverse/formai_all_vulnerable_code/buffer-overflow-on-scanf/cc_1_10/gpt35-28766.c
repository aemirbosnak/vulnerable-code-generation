//FormAI DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct email {
    char *address;
    struct email *next;
} Email;

Email *create_email_list(char *address) {
    Email *new_email = (Email *)malloc(sizeof(Email));
    new_email->address = strdup(address);
    new_email->next = NULL;
    return new_email;
}

void add_email_to_list(Email **list, char *address) {
    Email *new_email = create_email_list(address);
    new_email->next = *list;
    *list = new_email;
}

void print_email_list(Email *list) {
    printf("Current Mailing List:\n");
    int i = 0;
    while(list) {
        printf("%d. %s\n", ++i, list->address);
        list = list->next;
    }
    printf("\n");
}

void delete_email_from_list(Email **list, char *address) {
    Email *current = *list;
    Email *previous = NULL;
    while(current != NULL) {
        if(strcmp(current->address, address) == 0) {
            if(previous == NULL) {
                *list = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->address);
            free(current);
            printf("Successfully deleted email address.\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Email address not found in list.\n");
}

int main() {
    Email *mailing_list = NULL;
    char input[256];
    while(1) {
        printf("Enter command (add, delete, print, quit): ");
        scanf("%s", input);
        if(strcmp(input, "add") == 0) {
            printf("Enter email address: ");
            scanf("%s", input);
            add_email_to_list(&mailing_list, input);
            printf("Successfully added email address.\n\n");
        } else if(strcmp(input, "delete") == 0) {
            printf("Enter email address: ");
            scanf("%s", input);
            delete_email_from_list(&mailing_list, input);
            printf("\n");
        } else if(strcmp(input, "print") == 0) {
            print_email_list(mailing_list);
        } else if(strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid command, please try again.\n\n");
        }
    }
}