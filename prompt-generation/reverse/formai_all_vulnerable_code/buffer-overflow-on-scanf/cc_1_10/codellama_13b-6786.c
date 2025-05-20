//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: imaginative
// mailing_list.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct {
    char name[50];
    char email[50];
} Email;

int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;
    char command[50];

    while (1) {
        printf("Enter command (add, remove, list): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter name and email: ");
            scanf("%s %s", emails[num_emails].name, emails[num_emails].email);
            num_emails++;
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter email to remove: ");
            char email[50];
            scanf("%s", email);
            for (int i = 0; i < num_emails; i++) {
                if (strcmp(emails[i].email, email) == 0) {
                    for (int j = i; j < num_emails - 1; j++) {
                        emails[j] = emails[j + 1];
                    }
                    num_emails--;
                    break;
                }
            }
        } else if (strcmp(command, "list") == 0) {
            printf("Emails:\n");
            for (int i = 0; i < num_emails; i++) {
                printf("%s <%s>\n", emails[i].name, emails[i].email);
            }
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}