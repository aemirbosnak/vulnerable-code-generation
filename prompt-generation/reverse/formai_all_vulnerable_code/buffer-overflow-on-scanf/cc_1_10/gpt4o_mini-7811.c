//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define NAME_LEN 50
#define EMAIL_LEN 100

typedef struct {
    char name[NAME_LEN];
    char email[EMAIL_LEN];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0;
}

void addMember(MailingList *list) {
    if (list->count >= MAX_MEMBERS) {
        printf("Mailing List is full!\n");
        return;
    }
    Member newMember;
    printf("Enter the name of the member: ");
    fgets(newMember.name, NAME_LEN, stdin);
    newMember.name[strcspn(newMember.name, "\n")] = 0; // Remove newline

    printf("Enter the email of the member: ");
    fgets(newMember.email, EMAIL_LEN, stdin);
    newMember.email[strcspn(newMember.email, "\n")] = 0; // Remove newline

    list->members[list->count] = newMember;
    list->count++;
    printf("Member added successfully!\n");
}

void removeMember(MailingList *list) {
    if (list->count == 0) {
        printf("No members to remove!\n");
        return;
    }
    char email[EMAIL_LEN];
    printf("Enter the email of the member to remove: ");
    fgets(email, EMAIL_LEN, stdin);
    email[strcspn(email, "\n")] = 0; // Remove newline

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            // Remove member by shifting subsequent members left
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            printf("Member removed successfully!\n");
            return;
        }
    }
    printf("Member with email %s not found!\n", email);
}

void listMembers(MailingList *list) {
    if (list->count == 0) {
        printf("No members in the mailing list.\n");
        return;
    }
    printf("Mailing List Members:\n");
    for (int i = 0; i < list->count; i++) {
        printf("Name: %s, Email: %s\n", list->members[i].name, list->members[i].email);
    }
}

void displayMenu() {
    printf("\n=== Mailing List Manager ===\n");
    printf("1. Add Member\n");
    printf("2. Remove Member\n");
    printf("3. List Members\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    MailingList mailingList;
    initializeList(&mailingList);
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline after integer input
        switch (choice) {
            case 1:
                addMember(&mailingList);
                break;
            case 2:
                removeMember(&mailingList);
                break;
            case 3:
                listMembers(&mailingList);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}