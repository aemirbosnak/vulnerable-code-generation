//FormAI DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50
#define MAX_NUM_CONTACTS 100

struct Contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

int main() {
    struct Contact contacts[MAX_NUM_CONTACTS];
    int num_contacts = 0;

    char command;
    do {
        printf("---------------------\n");
        printf("Mailing list manager\n");
        printf("---------------------\n");
        printf("Commands:\n");
        printf("a - add contact\n");
        printf("r - remove contact\n");
        printf("l - list contacts\n");
        printf("q - quit\n");
        printf("Enter command: ");
        scanf(" %c", &command);

        switch (command) {
            case 'a': {
                if (num_contacts >= MAX_NUM_CONTACTS) {
                    printf("Error: Maximum number of contacts reached\n");
                    break;
                }
                printf("Enter name: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter email: ");
                scanf("%s", contacts[num_contacts].email);
                num_contacts++;
                printf("Contact added\n");
                break;
            }
            case 'r': {
                if (num_contacts == 0) {
                    printf("Error: No contacts to remove\n");
                    break;
                }
                char name[MAX_NAME_LENGTH];
                printf("Enter name: ");
                scanf("%s", name);
                int i;
                for (i = 0; i < num_contacts; i++) {
                    if (strcmp(contacts[i].name, name) == 0) {
                        printf("Contact removed\n");
                        num_contacts--;
                        contacts[i] = contacts[num_contacts];
                        break;
                    }
                }
                if (i == num_contacts) {
                    printf("Error: Contact not found\n");
                }
                break;
            }
            case 'l': {
                if (num_contacts == 0) {
                    printf("No contacts\n");
                } else {
                    printf("Contacts:\n");
                    int i;
                    for (i = 0; i < num_contacts; i++) {
                        printf("%s - %s\n", contacts[i].name, contacts[i].email);
                    }
                }
                break;
            }
            case 'q': {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Error: Invalid command\n");
                break;
            }
        }
    } while (command != 'q');

    return 0;
}