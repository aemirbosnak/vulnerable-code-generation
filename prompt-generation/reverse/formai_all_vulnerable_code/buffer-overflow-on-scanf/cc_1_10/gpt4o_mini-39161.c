//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
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
        printf("Error: Mailing list is full!\n");
        return -1;
    }
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("Error: Email already exists in the mailing list!\n");
            return -1;
        }
    }
    strncpy(list->members[list->count].email, email, MAX_EMAIL_LENGTH);
    list->count++;
    printf("Added: %s\n", email);
    return 0;
}

void removeMember(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            printf("Removed: %s\n", email);
            return;
        }
    }
    printf("Error: Email not found in the mailing list!\n");
}

void displayMembers(MailingList *list) {
    if (list->count == 0) {
        printf("Mailing list is empty.\n");
        return;
    }
    printf("Current members in the mailing list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s\n", list->members[i].email);
    }
}

void sendEmailToAll(MailingList *list, const char *message) {
    if (list->count == 0) {
        printf("Mailing list is empty, no emails to send.\n");
        return;
    }
    printf("Sending email to all members:\n");
    for (int i = 0; i < list->count; i++) {
        printf("To: %s\nMessage: %s\n", list->members[i].email, message);
    }
}

void displayMenu() {
    printf("\nMailing List Manager\n");
    printf("1. Add member\n");
    printf("2. Remove member\n");
    printf("3. Display members\n");
    printf("4. Send email to all\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    MailingList list;
    initializeList(&list);
    
    int choice;
    char email[MAX_EMAIL_LENGTH];
    char message[256];

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // Consume newline character left in the buffer

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = '\0';  // Remove newline character
                addMember(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = '\0';  // Remove newline character
                removeMember(&list, email);
                break;
            case 3:
                displayMembers(&list);
                break;
            case 4:
                printf("Enter message to send: ");
                fgets(message, 256, stdin);
                message[strcspn(message, "\n")] = '\0';  // Remove newline character
                sendEmailToAll(&list, message);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}