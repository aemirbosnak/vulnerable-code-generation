//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_EMAIL_LENGTH 50
#define MAX_MESSAGE_LENGTH 256

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int member_count;
} MailingList;

void add_member(MailingList *list, const char *email) {
    if (list->member_count >= MAX_MEMBERS) {
        printf("Mailing list is full!\n");
        return;
    }

    strncpy(list->members[list->member_count].email, email, MAX_EMAIL_LENGTH);
    list->member_count++;
    printf("Added member: %s\n", email);
}

void remove_member(MailingList *list, const char *email) {
    for (int i = 0; i < list->member_count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            for (int j = i; j < list->member_count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->member_count--;
            printf("Removed member: %s\n", email);
            return;
        }
    }
    printf("Member %s not found!\n", email);
}

void view_members(MailingList *list) {
    if (list->member_count == 0) {
        printf("No members in the mailing list.\n");
        return;
    }
    printf("Mailing List Members:\n");
    for (int i = 0; i < list->member_count; i++) {
        printf("%d: %s\n", i + 1, list->members[i].email);
    }
}

void send_message(MailingList *list, const char *message) {
    if (list->member_count == 0) {
        printf("No members to send message to.\n");
        return;
    }
    for (int i = 0; i < list->member_count; i++) {
        printf("Sending message to %s: %s\n", list->members[i].email, message);
    }
}

int main() {
    MailingList list;
    list.member_count = 0;

    int choice;
    char email[MAX_EMAIL_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. View Members\n");
        printf("4. Send Message\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // to consume newline character after number input

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;  // Remove the newline character
                add_member(&list, email);
                break;

            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;
                remove_member(&list, email);
                break;

            case 3:
                view_members(&list);
                break;

            case 4:
                printf("Enter message to send: ");
                fgets(message, MAX_MESSAGE_LENGTH, stdin);
                message[strcspn(message, "\n")] = 0;
                send_message(&list, message);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}