//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: detailed
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
        printf("Error: Mailing list is full. Cannot add more members.\n");
        return 0;
    }
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("Error: Email %s is already in the mailing list.\n", email);
            return 0;
        }
    }
    strncpy(list->members[list->count].email, email, MAX_EMAIL_LENGTH);
    list->count++;
    printf("Added %s to the mailing list.\n", email);
    return 1;
}

int removeMember(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            list->members[i] = list->members[list->count - 1]; // Replace with the last member
            list->count--;
            printf("Removed %s from the mailing list.\n", email);
            return 1;
        }
    }
    printf("Error: Email %s not found in the mailing list.\n", email);
    return 0;
}

void displayMembers(const MailingList *list) {
    if (list->count == 0) {
        printf("Mailing list is currently empty.\n");
        return;
    }

    printf("Mailing List Members:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->members[i].email);
    }
}

void showMenu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Member\n");
    printf("2. Remove Member\n");
    printf("3. Display Members\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList list;
    initializeList(&list);
    
    int choice;
    char email[MAX_EMAIL_LENGTH];

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addMember(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeMember(&list, email);
                break;
            case 3:
                displayMembers(&list);
                break;
            case 4:
                printf("Exiting the mailing list manager.\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}