//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 100
#define MAX_LISTS 50
#define MAX_LIST_NAME 50

typedef struct {
    char name[MAX_LIST_NAME];
    char emails[MAX_EMAILS][MAX_EMAIL_LENGTH];
    int email_count;
} MailingList;

MailingList lists[MAX_LISTS];
int list_count = 0;

void printTitle() {
    printf("*******************************\n");
    printf("*     Mailing List Manager     *\n");
    printf("*******************************\n");
}

void createList() {
    if (list_count >= MAX_LISTS) {
        printf("Maximum number of mailing lists reached.\n");
        return;
    }
    MailingList newList;
    printf("Enter the name of the new mailing list: ");
    scanf("%s", newList.name);
    newList.email_count = 0;
    lists[list_count++] = newList;
    printf("Mailing list '%s' created!\n", newList.name);
}

void addEmail() {
    char listName[MAX_LIST_NAME];
    char email[MAX_EMAIL_LENGTH];
    printf("Enter the mailing list name: ");
    scanf("%s", listName);
    printf("Enter the email address to add: ");
    scanf("%s", email);

    for (int i = 0; i < list_count; i++) {
        if (strcmp(lists[i].name, listName) == 0) {
            if (lists[i].email_count >= MAX_EMAILS) {
                printf("Max emails reached for this list.\n");
                return;
            }
            strcpy(lists[i].emails[lists[i].email_count++], email);
            printf("Email '%s' added to list '%s'.\n", email, listName);
            return;
        }
    }
    printf("Mailing list '%s' not found.\n", listName);
}

void viewList() {
    char listName[MAX_LIST_NAME];
    printf("Enter the mailing list name: ");
    scanf("%s", listName);

    for (int i = 0; i < list_count; i++) {
        if (strcmp(lists[i].name, listName) == 0) {
            printf("Mailing List: %s\n", lists[i].name);
            for (int j = 0; j < lists[i].email_count; j++) {
                printf("  - %s\n", lists[i].emails[j]);
            }
            return;
        }
    }
    printf("Mailing list '%s' not found.\n", listName);
}

void deleteEmail() {
    char listName[MAX_LIST_NAME];
    char email[MAX_EMAIL_LENGTH];
    printf("Enter the mailing list name: ");
    scanf("%s", listName);
    printf("Enter the email address to delete: ");
    scanf("%s", email);

    for (int i = 0; i < list_count; i++) {
        if (strcmp(lists[i].name, listName) == 0) {
            for (int j = 0; j < lists[i].email_count; j++) {
                if (strcmp(lists[i].emails[j], email) == 0) {
                    for (int k = j; k < lists[i].email_count - 1; k++) {
                        strcpy(lists[i].emails[k], lists[i].emails[k + 1]);
                    }
                    lists[i].email_count--;
                    printf("Email '%s' deleted from list '%s'.\n", email, listName);
                    return;
                }
            }
            printf("Email '%s' not found in list '%s'.\n", email, listName);
            return;
        }
    }
    printf("Mailing list '%s' not found.\n", listName);
}

void menu() {
    int choice;
    while (1) {
        printTitle();
        printf("1. Create Mailing List\n");
        printf("2. Add Email\n");
        printf("3. View Mailing List\n");
        printf("4. Delete Email\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: addEmail(); break;
            case 3: viewList(); break;
            case 4: deleteEmail(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }
}

int main() {
    menu();
    return 0;
}