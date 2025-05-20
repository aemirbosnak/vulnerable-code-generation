//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTS 10
#define MAX_MEMBERS 50
#define EMAIL_LENGTH 100

typedef struct {
    char email[EMAIL_LENGTH];
} Member;

typedef struct {
    char listName[30];
    Member members[MAX_MEMBERS];
    int memberCount;
} MailingList;

MailingList mailingLists[MAX_LISTS];
int listCount = 0;

void createMailingList() {
    if (listCount >= MAX_LISTS) {
        printf("Maximum number of mailing lists reached.\n");
        return;
    }

    printf("Enter the name of the new mailing list: ");
    scanf("%s", mailingLists[listCount].listName);
    mailingLists[listCount].memberCount = 0;
    listCount++;
    printf("Mailing list '%s' created successfully!\n", mailingLists[listCount - 1].listName);
}

void addMemberToList() {
    char listName[30];
    printf("Enter the name of the mailing list: ");
    scanf("%s", listName);

    for (int i = 0; i < listCount; i++) {
        if (strcmp(mailingLists[i].listName, listName) == 0) {
            if (mailingLists[i].memberCount >= MAX_MEMBERS) {
                printf("Maximum members in the list reached.\n");
                return;
            }
            printf("Enter the email to add: ");
            scanf("%s", mailingLists[i].members[mailingLists[i].memberCount].email);
            mailingLists[i].memberCount++;
            printf("Email '%s' added to list '%s'.\n", 
                   mailingLists[i].members[mailingLists[i].memberCount - 1].email, listName);
            return;
        }
    }
    printf("Mailing list '%s' not found.\n", listName);
}

void removeMemberFromList() {
    char listName[30];
    char email[EMAIL_LENGTH];
    printf("Enter the mailing list name: ");
    scanf("%s", listName);

    for (int i = 0; i < listCount; i++) {
        if (strcmp(mailingLists[i].listName, listName) == 0) {
            printf("Enter the email to remove: ");
            scanf("%s", email);
            for (int j = 0; j < mailingLists[i].memberCount; j++) {
                if (strcmp(mailingLists[i].members[j].email, email) == 0) {
                    // Shift members
                    for (int k = j; k < mailingLists[i].memberCount - 1; k++) {
                        mailingLists[i].members[k] = mailingLists[i].members[k + 1];
                    }
                    mailingLists[i].memberCount--;
                    printf("Email '%s' removed from list '%s'.\n", email, listName);
                    return;
                }
            }
            printf("Email '%s' not found in list '%s'.\n", email, listName);
            return;
        }
    }
    printf("Mailing list '%s' not found.\n", listName);
}

void displayMailingLists() {
    if (listCount == 0) {
        printf("No mailing lists available.\n");
        return;
    }
    printf("Available Mailing Lists:\n");
    for (int i = 0; i < listCount; i++) {
        printf("List %d: %s\n", i + 1, mailingLists[i].listName);
        printf("Members:\n");
        for (int j = 0; j < mailingLists[i].memberCount; j++) {
            printf(" - %s\n", mailingLists[i].members[j].email);
        }
    }
}

void menu() {
    int choice;
    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Create Mailing List\n");
        printf("2. Add Member to List\n");
        printf("3. Remove Member from List\n");
        printf("4. Display Mailing Lists\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createMailingList();
                break;
            case 2:
                addMemberToList();
                break;
            case 3:
                removeMemberFromList();
                break;
            case 4:
                displayMailingLists();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}