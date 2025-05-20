//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_LISTS 10
#define NAME_LENGTH 50
#define LIST_NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
} Member;

typedef struct {
    char list_name[LIST_NAME_LENGTH];
    Member members[MAX_MEMBERS];
    int member_count;
} MailingList;

MailingList mailing_lists[MAX_LISTS];
int list_count = 0;

void create_list() {
    if (list_count >= MAX_LISTS) {
        printf("Maximum number of mailing lists reached.\n");
        return;
    }
    
    MailingList new_list;
    printf("Enter mailing list name: ");
    scanf("%s", new_list.list_name);
    new_list.member_count = 0;
    
    mailing_lists[list_count++] = new_list;
    printf("Mailing list '%s' created successfully.\n", new_list.list_name);
}

void add_member() {
    char list_name[LIST_NAME_LENGTH];
    printf("Enter mailing list name to add member: ");
    scanf("%s", list_name);

    for (int i = 0; i < list_count; i++) {
        if (strcmp(mailing_lists[i].list_name, list_name) == 0) {
            if (mailing_lists[i].member_count >= MAX_MEMBERS) {
                printf("Maximum number of members reached in '%s'.\n", list_name);
                return;
            }

            printf("Enter member name: ");
            scanf("%s", mailing_lists[i].members[mailing_lists[i].member_count].name);
            mailing_lists[i].member_count++;
            printf("Member added successfully to '%s'.\n", list_name);
            return;
        }
    }
    
    printf("Mailing list '%s' not found.\n", list_name);
}

void remove_member() {
    char list_name[LIST_NAME_LENGTH];
    printf("Enter mailing list name to remove member from: ");
    scanf("%s", list_name);

    for (int i = 0; i < list_count; i++) {
        if (strcmp(mailing_lists[i].list_name, list_name) == 0) {
            char member_name[NAME_LENGTH];
            int found = 0;

            printf("Enter member name to remove: ");
            scanf("%s", member_name);

            for (int j = 0; j < mailing_lists[i].member_count; j++) {
                if (strcmp(mailing_lists[i].members[j].name, member_name) == 0) {
                    found = 1;
                    for (int k = j; k < mailing_lists[i].member_count - 1; k++) {
                        mailing_lists[i].members[k] = mailing_lists[i].members[k + 1];
                    }
                    mailing_lists[i].member_count--;
                    printf("Member '%s' removed successfully from '%s'.\n", member_name, list_name);
                    return;
                }
            }

            if (!found) {
                printf("Member '%s' not found in '%s'.\n", member_name, list_name);
            }
            return;
        }
    }
    
    printf("Mailing list '%s' not found.\n", list_name);
}

void display_list() {
    char list_name[LIST_NAME_LENGTH];
    printf("Enter mailing list name to display: ");
    scanf("%s", list_name);

    for (int i = 0; i < list_count; i++) {
        if (strcmp(mailing_lists[i].list_name, list_name) == 0) {
            printf("Mailing list '%s' has the following members:\n", mailing_lists[i].list_name);
            for (int j = 0; j < mailing_lists[i].member_count; j++) {
                printf("- %s\n", mailing_lists[i].members[j].name);
            }
            return;
        }
    }

    printf("Mailing list '%s' not found.\n", list_name);
}

void menu() {
    int choice;
    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Create Mailing List\n");
        printf("2. Add Member\n");
        printf("3. Remove Member\n");
        printf("4. Display Mailing List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_list();
                break;
            case 2:
                add_member();
                break;
            case 3:
                remove_member();
                break;
            case 4:
                display_list();
                break;
            case 5:
                printf("Exiting the program...\n");
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