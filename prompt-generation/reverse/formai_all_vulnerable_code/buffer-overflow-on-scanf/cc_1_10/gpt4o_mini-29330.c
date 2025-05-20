//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_LISTS 10
#define MAX_MEMBERS 50

typedef struct {
    char name[MAX_NAME_LENGTH];
} Member;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Member members[MAX_MEMBERS];
    int member_count;
} MailingList;

MailingList lists[MAX_LISTS];
int list_count = 0;

void create_mailing_list() {
    if (list_count >= MAX_LISTS) {
        printf("Maximum number of mailing lists reached.\n");
        return;
    }
    
    MailingList new_list;
    printf("Enter the name for the new mailing list: ");
    scanf("%s", new_list.name);
    new_list.member_count = 0;
    lists[list_count++] = new_list;

    printf("Mailing list '%s' created successfully!\n", new_list.name);
}

void add_member() {
    char list_name[MAX_NAME_LENGTH];
    printf("Enter the mailing list name to add a member to: ");
    scanf("%s", list_name);

    for (int i = 0; i < list_count; i++) {
        if (strcmp(lists[i].name, list_name) == 0) {
            if (lists[i].member_count >= MAX_MEMBERS) {
                printf("Maximum number of members in this list reached.\n");
                return;
            }
            
            printf("Enter the name of the member to add: ");
            scanf("%s", lists[i].members[lists[i].member_count].name);
            lists[i].member_count++;
            printf("Member '%s' added to list '%s'.\n", lists[i].members[lists[i].member_count - 1].name, lists[i].name);
            return;
        }
    }
    
    printf("Mailing list '%s' not found.\n", list_name);
}

void view_list_members() {
    char list_name[MAX_NAME_LENGTH];
    printf("Enter the mailing list name to view members: ");
    scanf("%s", list_name);

    for (int i = 0; i < list_count; i++) {
        if (strcmp(lists[i].name, list_name) == 0) {
            printf("Members of mailing list '%s':\n", lists[i].name);
            for (int j = 0; j < lists[i].member_count; j++) {
                printf("%d. %s\n", j + 1, lists[i].members[j].name);
            }
            return;
        }
    }
    
    printf("Mailing list '%s' not found.\n", list_name);
}

void delete_mailing_list() {
    char list_name[MAX_NAME_LENGTH];
    printf("Enter the mailing list name to delete: ");
    scanf("%s", list_name);

    for (int i = 0; i < list_count; i++) {
        if (strcmp(lists[i].name, list_name) == 0) {
            for (int j = i; j < list_count - 1; j++) {
                lists[j] = lists[j + 1];
            }
            list_count--;
            printf("Mailing list '%s' deleted successfully!\n", list_name);
            return;
        }
    }
    
    printf("Mailing list '%s' not found.\n", list_name);
}

void display_menu() {
    printf("\nMailing List Manager\n");
    printf("1. Create Mailing List\n");
    printf("2. Add Member\n");
    printf("3. View Members\n");
    printf("4. Delete Mailing List\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice = 0;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_mailing_list();
                break;
            case 2:
                add_member();
                break;
            case 3:
                view_list_members();
                break;
            case 4:
                delete_mailing_list();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    
    return 0;
}