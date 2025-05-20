//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} email_address;

int main() {
    email_address addresses[MAX_EMAILS];
    char input[256];
    int count = 0;

    printf("Welcome to the mailing list manager.\n");

    while (1) {
        printf("Enter a command (add, list, quit): ");
        fgets(input, 256, stdin);
        input[strlen(input) - 1] = '\0';

        if (strcmp(input, "add") == 0) {
            if (count >= MAX_EMAILS) {
                printf("Error: mailing list is full.\n");
                continue;
            }
            printf("Enter name: ");
            fgets(addresses[count].name, MAX_NAME_LENGTH, stdin);
            addresses[count].name[strlen(addresses[count].name) - 1] = '\0';

            printf("Enter email address: ");
            fgets(addresses[count].email, MAX_EMAIL_LENGTH, stdin);
            addresses[count].email[strlen(addresses[count].email) - 1] = '\0';

            count++;
            printf("Added email address: %s\n", addresses[count - 1].email);
        }

        else if (strcmp(input, "list") == 0) {
            if (count == 0) {
                printf("Mailing list is empty.\n");
                continue;
            }
            printf("Mailing list:\n");
            for (int i = 0; i < count; i++) {
                printf("- %s <%s>\n", addresses[i].name, addresses[i].email);
            }
        }

        else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        else {
            printf("Error: invalid command.\n");
        }
    }

    return 0;
}