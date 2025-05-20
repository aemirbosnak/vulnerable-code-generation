//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 200

struct contact {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

int main() {
    struct contact contacts[100];
    int numContacts = 0;
    int numCommands = 0;

    while (1) {
        char command[100];
        printf("Enter command (add, delete, list, quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_NAME_LEN];
            char email[MAX_EMAIL_LEN];
            printf("Enter name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Enter email: ");
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\n")] = '\0';
            strcpy(contacts[numContacts].name, name);
            strcpy(contacts[numContacts].email, email);
            numContacts++;
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_NAME_LEN];
            printf("Enter name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            for (int i = 0; i < numContacts; i++) {
                if (strcmp(contacts[i].name, name) == 0) {
                    for (int j = i; j < numContacts - 1; j++) {
                        contacts[j] = contacts[j + 1];
                    }
                    numContacts--;
                    break;
                }
            }
        } else if (strcmp(command, "list") == 0) {
            for (int i = 0; i < numContacts; i++) {
                printf("Name: %s, Email: %s\n", contacts[i].name, contacts[i].email);
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}