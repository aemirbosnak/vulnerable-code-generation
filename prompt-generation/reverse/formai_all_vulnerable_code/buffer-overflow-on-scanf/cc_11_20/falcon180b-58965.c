//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    time_t timestamp;
} MailingListEntry;

int main() {
    // Initialize mailing list
    MailingListEntry mailingList[100];
    int mailingListSize = 0;

    // Main loop
    while (1) {
        // Print menu
        printf("Mailing List Manager\n");
        printf("1. Add entry\n");
        printf("2. Remove entry\n");
        printf("3. Print entries\n");
        printf("4. Exit\n");

        // Get user input
        int choice;
        scanf("%d", &choice);

        // Process user input
        switch (choice) {
        case 1:
            // Add entry
            if (mailingListSize >= 100) {
                printf("Mailing list is full.\n");
            } else {
                printf("Enter name: ");
                scanf("%s", mailingList[mailingListSize].name);

                printf("Enter email: ");
                scanf("%s", mailingList[mailingListSize].email);

                printf("Enter subject: ");
                scanf("%s", mailingList[mailingListSize].subject);

                printf("Enter message: ");
                fgets(mailingList[mailingListSize].message, MAX_MESSAGE_LENGTH, stdin);

                mailingList[mailingListSize].timestamp = time(NULL);
                mailingListSize++;
            }
            break;

        case 2:
            // Remove entry
            if (mailingListSize == 0) {
                printf("Mailing list is empty.\n");
            } else {
                printf("Enter email to remove: ");
                scanf("%s", mailingList[0].email);

                for (int i = 0; i < mailingListSize; i++) {
                    if (strcmp(mailingList[i].email, mailingList[0].email) == 0) {
                        for (int j = i; j < mailingListSize - 1; j++) {
                            memcpy(&mailingList[j], &mailingList[j + 1], sizeof(MailingListEntry));
                        }
                        mailingListSize--;
                        break;
                    }
                }
            }
            break;

        case 3:
            // Print entries
            if (mailingListSize == 0) {
                printf("Mailing list is empty.\n");
            } else {
                printf("Name\tEmail\tSubject\tMessage\tTimestamp\n");
                for (int i = 0; i < mailingListSize; i++) {
                    printf("%s\t%s\t%s\t%s\t%ld\n", mailingList[i].name, mailingList[i].email, mailingList[i].subject, mailingList[i].message, mailingList[i].timestamp);
                }
            }
            break;

        case 4:
            // Exit
            exit(0);

        default:
            // Invalid choice
            printf("Invalid choice.\n");
        }
    }

    return 0;
}