//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    struct Contact* next;
} Contact;

int main() {
    Contact* head = NULL;
    Contact* tail = NULL;
    char command[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];

    printf("Welcome to the Totally Rad Contact Manager!\n");

    while (1) {
        printf("Enter a command (add, remove, list, quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter the name: ");
            scanf("%s", name);

            printf("Enter the email: ");
            scanf("%s", email);

            Contact* new_contact = malloc(sizeof(Contact));
            new_contact->next = NULL;
            strcpy(new_contact->name, name);
            strcpy(new_contact->email, email);

            if (head == NULL) {
                head = new_contact;
                tail = new_contact;
            } else {
                tail->next = new_contact;
                tail = new_contact;
            }
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter the name: ");
            scanf("%s", name);

            Contact* current = head;
            Contact* previous = NULL;

            while (current) {
                if (strcmp(current->name, name) == 0) {
                    if (previous) {
                        previous->next = current->next;
                        tail = previous;
                    } else {
                        head = current->next;
                        tail = head;
                    }
                    free(current);
                    break;
                }
                previous = current;
                current = current->next;
            }
        } else if (strcmp(command, "list") == 0) {
            Contact* current = head;

            while (current) {
                printf("%s - %s\n", current->name, current->email);
                current = current->next;
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}