//FormAI DATASET v1.0 Category: Mailing list manager ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50
#define MAX_LIST_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

int main() {
    Contact list[MAX_LIST_LENGTH];
    int list_size = 0;

    char command[10];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        } else if (strcmp(command, "add") == 0) {
            if (list_size == MAX_LIST_LENGTH) {
                printf("The list is full.\n");
                continue;
            }

            printf("Enter name: ");
            scanf("%s", list[list_size].name);

            printf("Enter email: ");
            scanf("%s", list[list_size].email);

            list_size++;
            printf("Contact added.\n");
        } else if (strcmp(command, "list") == 0) {
            printf("Contacts:\n");
            for (int i = 0; i < list_size; i++) {
                printf("%d. %s <%s>\n", i + 1, list[i].name, list[i].email);
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}