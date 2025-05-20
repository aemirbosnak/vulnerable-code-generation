//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTS 10
#define MAX_MEMBERS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    char members[MAX_MEMBERS][NAME_LEN];
    int member_count;
} MailingList;

MailingList mailingLists[MAX_LISTS];
int list_count = 0;

void createList() {
    if (list_count >= MAX_LISTS) {
        printf("Maximum number of mailing lists reached!\n");
        return;
    }
    
    printf("Enter the name of the mailing list: ");
    scanf(" %49[^\n]", mailingLists[list_count].name);
    mailingLists[list_count].member_count = 0;
    list_count++;
    printf("Mailing list '%s' created successfully!\n", mailingLists[list_count - 1].name);
}

void addMemberToList() {
    char listName[NAME_LEN];
    printf("Enter the name of the mailing list to add a member: ");
    scanf(" %49[^\n]", listName);
    
    for (int i = 0; i < list_count; i++) {
        if (strcmp(mailingLists[i].name, listName) == 0) {
            if (mailingLists[i].member_count >= MAX_MEMBERS) {
                printf("Maximum number of members in this list reached!\n");
                return;
            }
            printf("Enter the name of the member: ");
            scanf(" %49[^\n]", mailingLists[i].members[mailingLists[i].member_count]);
            mailingLists[i].member_count++;
            printf("Member '%s' added to list '%s'.\n", mailingLists[i].members[mailingLists[i].member_count - 1], mailingLists[i].name);
            return;
        }
    }
    printf("Mailing list '%s' not found!\n", listName);
}

void removeMemberFromList() {
    char listName[NAME_LEN];
    char memberName[NAME_LEN];
    printf("Enter the name of the mailing list to remove a member: ");
    scanf(" %49[^\n]", listName);
    
    for (int i = 0; i < list_count; i++) {
        if (strcmp(mailingLists[i].name, listName) == 0) {
            printf("Enter the name of the member to remove: ");
            scanf(" %49[^\n]", memberName);
            
            for (int j = 0; j < mailingLists[i].member_count; j++) {
                if (strcmp(mailingLists[i].members[j], memberName) == 0) {
                    for (int k = j; k < mailingLists[i].member_count - 1; k++) {
                        strcpy(mailingLists[i].members[k], mailingLists[i].members[k + 1]);
                    }
                    mailingLists[i].member_count--;
                    printf("Member '%s' removed from list '%s'.\n", memberName, mailingLists[i].name);
                    return;
                }
            }
            printf("Member '%s' not found in list '%s'.\n", memberName, mailingLists[i].name);
            return;
        }
    }
    printf("Mailing list '%s' not found!\n", listName);
}

void displayListMembers() {
    char listName[NAME_LEN];
    printf("Enter the name of the mailing list to display members: ");
    scanf(" %49[^\n]", listName);
    
    for (int i = 0; i < list_count; i++) {
        if (strcmp(mailingLists[i].name, listName) == 0) {
            printf("Members of list '%s':\n", mailingLists[i].name);
            for (int j = 0; j < mailingLists[i].member_count; j++) {
                printf("- %s\n", mailingLists[i].members[j]);
            }
            return;
        }
    }
    printf("Mailing list '%s' not found!\n", listName);
}

void listAllMailingLists() {
    printf("Existing Mailing Lists:\n");
    for (int i = 0; i < list_count; i++) {
        printf("- %s\n", mailingLists[i].name);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Create Mailing List\n");
        printf("2. Add Member to Mailing List\n");
        printf("3. Remove Member from Mailing List\n");
        printf("4. Display Members of Mailing List\n");
        printf("5. List All Mailing Lists\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: addMemberToList(); break;
            case 3: removeMemberFromList(); break;
            case 4: displayListMembers(); break;
            case 5: listAllMailingLists(); break;
            case 6: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}