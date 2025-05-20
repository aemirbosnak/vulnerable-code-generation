//FormAI DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_LIST_LENGTH 100

struct MailingList {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

int main() {
    struct MailingList list[MAX_LIST_LENGTH];
    int count = 0;

    while (1) {
        // Clear input buffer
        fflush(stdin);

        printf("1. Add email to list\n");
        printf("2. Remove email from list\n");
        printf("3. Print all emails in the list\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        int option = 0;
        scanf("%d", &option);

        switch (option) {
            case 1: {
                // Add email to list
                if (count >= MAX_LIST_LENGTH) {
                    printf("Error: list is full\n");
                    break;
                }

                struct MailingList newEmail;

                printf("Enter name: ");
                scanf("%s", newEmail.name);

                printf("Enter email: ");
                scanf("%s", newEmail.email);

                list[count] = newEmail;

                count++;

                printf("Email added to list\n");
                break;
            }

            case 2: {
                // Remove email from list
                if (count <= 0) {
                    printf("Error: list is empty\n");
                    break;
                }

                printf("Enter email to remove: ");
                char emailToRemove[MAX_EMAIL_LENGTH];
                scanf("%s", emailToRemove);

                int found = 0;
                int removeIndex = -1;

                for (int i = 0; i < count; i++) {
                    if (strcmp(list[i].email, emailToRemove) == 0) {
                        found = 1;
                        removeIndex = i;
                        break;
                    }
                }

                if (found) {
                    // Shift emails after removed email
                    for (int i = removeIndex; i < count - 1; i++) {
                        list[i] = list[i + 1];
                    }

                    count--;

                    printf("Email removed from list\n");
                } else {
                    printf("Error: email not found in list\n");
                }

                break;
            }

            case 3: {
                // Print list of emails
                printf("List of Emails:\n");

                for (int i = 0; i < count; i++) {
                    printf("%s <%s>\n", list[i].name, list[i].email);
                }

                break;
            }

            case 4: {
                // Exit program
                printf("Goodbye!\n");
                exit(0);
            }

            default: {
                printf("Error: invalid option\n");
                break;
            }
        }
    }

    return 0;
}