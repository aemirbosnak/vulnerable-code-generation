//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 256
#define NAME_LENGTH 64

typedef struct Member {
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Member;

typedef struct MailingList {
    Member members[MAX_EMAILS];
    int member_count;
} MailingList;

void initialize_list(MailingList *list) {
    list->member_count = 0;
}

bool add_member(MailingList *list, const char *name, const char *email) {
    if (list->member_count >= MAX_EMAILS) {
        printf("Mailing list is full! Cannot add more members.\n");
        return false;
    }
    strncpy(list->members[list->member_count].name, name, NAME_LENGTH);
    strncpy(list->members[list->member_count].email, email, EMAIL_LENGTH);
    list->member_count++;
    printf("Added: %s <%s>\n", name, email);
    return true;
}

void display_members(const MailingList *list) {
    if (list->member_count == 0) {
        printf("No members in the mailing list.\n");
        return;
    }
    printf("Members in the mailing list:\n");
    for (int i = 0; i < list->member_count; i++) {
        printf("%d. %s <%s>\n", i + 1, list->members[i].name, list->members[i].email);
    }
}

bool remove_member(MailingList *list, const char *email) {
    for (int i = 0; i < list->member_count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("Removing: %s <%s>\n", list->members[i].name, list->members[i].email);
            for (int j = i; j < list->member_count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->member_count--;
            return true;
        }
    }
    printf("Member with email %s not found.\n", email);
    return false;
}

void send_email(const MailingList *list, const char *subject, const char *message) {
    printf("Sending email with subject: '%s'\n", subject);
    printf("Message content:\n%s\n\n", message);
    for (int i = 0; i < list->member_count; i++) {
        printf("To: %s <%s>\n", list->members[i].name, list->members[i].email);
        // Simulate sending email process...
        sleep(1);
        printf("Email sent to %s <%s>\n", list->members[i].name, list->members[i].email);
    }
}

int main() {
    MailingList mailing_list;
    initialize_list(&mailing_list);
    
    int choice;
    char name[NAME_LENGTH], email[EMAIL_LENGTH], subject[100], message[512];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Display Members\n");
        printf("3. Remove Member\n");
        printf("4. Send Email\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter email: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                add_member(&mailing_list, name, email);
                break;

            case 2:
                display_members(&mailing_list);
                break;

            case 3:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                remove_member(&mailing_list, email);
                break;

            case 4:
                printf("Enter email subject: ");
                fgets(subject, 100, stdin);
                subject[strcspn(subject, "\n")] = 0; // Remove newline
                printf("Enter message content: ");
                fgets(message, 512, stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline
                send_email(&mailing_list, subject, message);
                break;

            case 5:
                printf("Exiting Mailing List Manager.\n");
                break;

            default:
                printf("Invalid choice. Please select between 1-5.\n");
        }
    } while (choice != 5);

    return 0;
}