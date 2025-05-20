//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define EMAIL_LENGTH 100

typedef struct {
    char email[EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0; 
}

int addMember(MailingList *list, const char *email) {
    if (list->count >= MAX_MEMBERS) {
        return -1; // List is full
    }
    strncpy(list->members[list->count].email, email, EMAIL_LENGTH);
    list->count++;
    return 0; // Success
}

int removeMember(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            // Shift members down
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            return 0; // Success
        }
    }
    return -1; // Email not found
}

void displayMembers(const MailingList *list) {
    if (list->count == 0) {
        printf("The mailing list is empty.\n");
    } else {
        printf("Current Mailing List Members:\n");
        for (int i = 0; i < list->count; i++) {
            printf("%s\n", list->members[i].email);
        }
    }
}

void sendEmail(const MailingList *list, const char *subject, const char *message) {
    printf("Sending Email...\n");
    printf("Subject: %s\n", subject);
    printf("Message: %s\n\n", message);
    for (int i = 0; i < list->count; i++) {
        printf("To: %s\n", list->members[i].email);
    }
}

void menu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Member\n");
    printf("2. Remove Member\n");
    printf("3. Display Members\n");
    printf("4. Send Email\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList list;
    initializeList(&list);
    int choice;
    char email[EMAIL_LENGTH];
    char subject[EMAIL_LENGTH];
    char message[256];

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1: // Add Member
                printf("Enter email to add: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                if (addMember(&list, email) == 0) {
                    printf("Added member: %s\n", email);
                } else {
                    printf("Failed to add member. List is full.\n");
                }
                break;

            case 2: // Remove Member
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                if (removeMember(&list, email) == 0) {
                    printf("Removed member: %s\n", email);
                } else {
                    printf("Email not found in mailing list.\n");
                }
                break;

            case 3: // Display Members
                displayMembers(&list);
                break;

            case 4: // Send Email
                printf("Enter email subject: ");
                fgets(subject, EMAIL_LENGTH, stdin);
                subject[strcspn(subject, "\n")] = 0; // Remove newline
                printf("Enter email message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline
                sendEmail(&list, subject, message);
                break;

            case 5: // Exit
                printf("Exiting the Mailing List Manager.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}