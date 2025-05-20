//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define NAME_LENGTH 50

typedef struct Member {
    char name[NAME_LENGTH];
    char email[NAME_LENGTH];
} Member;

typedef struct MailingList {
    Member members[MAX_MEMBERS];
    int memberCount;
} MailingList;

// Function prototypes
void initializeList(MailingList *list);
void addMember(MailingList *list);
void removeMember(MailingList *list);
void displayMembers(const MailingList *list);
void clearList(MailingList *list);
int isEmailUnique(const MailingList *list, const char *email);

int main() {
    MailingList mailingList;
    initializeList(&mailingList);
    int choice;

    do {
        printf("\n*** Mailing List Manager ***\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Clear List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from the input buffer

        switch(choice) {
            case 1:
                addMember(&mailingList);
                break;
            case 2:
                removeMember(&mailingList);
                break;
            case 3:
                displayMembers(&mailingList);
                break;
            case 4:
                clearList(&mailingList);
                break;
            case 0:
                printf("Exiting the Mailing List Manager.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 0);

    return 0;
}

void initializeList(MailingList *list) {
    list->memberCount = 0;
}

void addMember(MailingList *list) {
    if (list->memberCount >= MAX_MEMBERS) {
        printf("The mailing list is full. Cannot add more members.\n");
        return;
    }

    Member newMember;
    printf("Enter member name: ");
    fgets(newMember.name, NAME_LENGTH, stdin);
    newMember.name[strcspn(newMember.name, "\n")] = 0; // Remove the newline character

    printf("Enter member email: ");
    fgets(newMember.email, NAME_LENGTH, stdin);
    newMember.email[strcspn(newMember.email, "\n")] = 0; // Remove the newline character

    if (isEmailUnique(list, newMember.email)) {
        list->members[list->memberCount++] = newMember;
        printf("Member added successfully!\n");
    } else {
        printf("Email already exists in the mailing list.\n");
    }
}

void removeMember(MailingList *list) {
    if (list->memberCount == 0) {
        printf("The mailing list is empty. No members to remove.\n");
        return;
    }

    char email[NAME_LENGTH];
    printf("Enter the email of the member to remove: ");
    fgets(email, NAME_LENGTH, stdin);
    email[strcspn(email, "\n")] = 0; // Remove the newline character

    for (int i = 0; i < list->memberCount; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            list->members[i] = list->members[list->memberCount - 1]; // Replace with the last member
            list->memberCount--;
            printf("Member removed successfully!\n");
            return;
        }
    }
    printf("No member found with that email.\n");
}

void displayMembers(const MailingList *list) {
    if (list->memberCount == 0) {
        printf("The mailing list is empty.\n");
    } else {
        printf("\nCurrent members of the mailing list:\n");
        for (int i = 0; i < list->memberCount; i++) {
            printf("Name: %s, Email: %s\n", list->members[i].name, list->members[i].email);
        }
    }
}

void clearList(MailingList *list) {
    list->memberCount = 0;
    printf("All members have been removed from the mailing list.\n");
}

int isEmailUnique(const MailingList *list, const char *email) {
    for (int i = 0; i < list->memberCount; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            return 0; // Email is not unique
        }
    }
    return 1; // Email is unique
}