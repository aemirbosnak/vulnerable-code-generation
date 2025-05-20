//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAILS_PER_RECIPIENT 10

typedef struct recipient {
    char name[MAX_NAME_LEN];
    char emails[MAX_EMAILS_PER_RECIPIENT][50];
    int num_emails;
} recipient_t;

void add_email(recipient_t* recipient) {
    if (recipient->num_emails >= MAX_EMAILS_PER_RECIPIENT) {
        printf("Error: Maximum number of emails per recipient reached.\n");
        return;
    }

    printf("Enter email address: ");
    scanf("%s", recipient->emails[recipient->num_emails]);
    recipient->num_emails++;
}

int main() {
    FILE* mailing_list_file;
    mailing_list_file = fopen("mailing_list.txt", "w");

    if (mailing_list_file == NULL) {
        printf("Error: Could not create mailing_list.txt.\n");
        return 1;
    }

    recipient_t recipient;
    strcpy(recipient.name, "");
    recipient.num_emails = 0;

    while (1) {
        printf("\nOptions:\n1. Add recipient\n2. Save and exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter recipient name: ");
                scanf("%s", recipient.name);
                break;
            case 2:
                fprintf(mailing_list_file, "Recipient: %s\n", recipient.name);

                for (int i = 0; i < recipient.num_emails; i++) {
                    fprintf(mailing_list_file, "Email %d: %s\n", i+1, recipient.emails[i]);
                }

                fprintf(mailing_list_file, "\n");
                fclose(mailing_list_file);
                printf("Mailing list saved to mailing_list.txt.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}