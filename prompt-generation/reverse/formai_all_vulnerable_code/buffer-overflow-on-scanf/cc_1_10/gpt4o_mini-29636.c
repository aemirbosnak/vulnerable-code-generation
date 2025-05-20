//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define EMAIL_SIZE 100

typedef struct {
    char email[EMAIL_SIZE];
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
        printf("Mailing list is full. Cannot add more members.\n");
        return -1;
    }
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("Email already exists in the mailing list.\n");
            return -1;
        }
    }
    strcpy(list->members[list->count].email, email);
    list->count++;
    printf("Added member: %s\n", email);
    return 0;
}

void removeMember(MailingList *list, const char *email) {
    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            found = 1;
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            printf("Removed member: %s\n", email);
            break;
        }
    }
    if (!found) {
        printf("Email not found in the mailing list: %s\n", email);
    }
}

void displayMembers(const MailingList *list) {
    if (list->count == 0) {
        printf("The mailing list is currently empty.\n");
        return;
    }
    printf("Current members in the mailing list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->members[i].email);
    }
}

void freeList(MailingList *list) {
    list->count = 0; // Reset the count to empty the list
    printf("Cleared the mailing list.\n");
}

int main() {
    MailingList mailingList;
    initializeList(&mailingList);
    char email[EMAIL_SIZE];
    int choice;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Clear Mailing List\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, EMAIL_SIZE, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                addMember(&mailingList, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_SIZE, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                removeMember(&mailingList, email);
                break;
            case 3:
                displayMembers(&mailingList);
                break;
            case 4:
                freeList(&mailingList);
                break;
            case 5:
                printf("Exiting the mailing list manager.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}