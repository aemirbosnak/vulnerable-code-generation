//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 50

struct Email {
    char name[50];
    char email[50];
};

struct MailingList {
    char name[50];
    struct Email emails[MAX_EMAILS];
    int num_emails;
};

void print_menu() {
    printf("\n1. Create a new mailing list\n");
    printf("2. Add an email to a mailing list\n");
    printf("3. Remove an email from a mailing list\n");
    printf("4. Print a mailing list\n");
    printf("5. Exit\n");
}

void create_list(struct MailingList *lists, int *num_lists) {
    printf("Enter the name of the new mailing list: ");
    scanf("%s", lists[*num_lists].name);
    lists[*num_lists].num_emails = 0;
    (*num_lists)++;
    printf("Mailing list created successfully\n");
}

void add_email(struct MailingList *lists, int num_lists) {
    char list_name[50];
    char name[50];
    char email[50];
    int i, j;

    printf("Enter the name of the mailing list: ");
    scanf("%s", list_name);

    for (i = 0; i < num_lists; i++) {
        if (strcmp(lists[i].name, list_name) == 0) {
            printf("Enter the name of the person: ");
            scanf("%s", name);
            printf("Enter the email address: ");
            scanf("%s", email);
            for (j = 0; j < lists[i].num_emails; j++) {
                if (strcmp(lists[i].emails[j].email, email) == 0) {
                    printf("Email address already exists in the mailing list\n");
                    return;
                }
            }
            strncpy(lists[i].emails[lists[i].num_emails].name, name, 50);
            strncpy(lists[i].emails[lists[i].num_emails].email, email, 50);
            lists[i].num_emails++;
            printf("Email added to the mailing list successfully\n");
            return;
        }
    }
    printf("Mailing list not found\n");
}

void remove_email(struct MailingList *lists, int num_lists) {
    char list_name[50];
    char email[50];
    int i, j, k;

    printf("Enter the name of the mailing list: ");
    scanf("%s", list_name);

    for (i = 0; i < num_lists; i++) {
        if (strcmp(lists[i].name, list_name) == 0) {
            printf("Enter the email address to remove: ");
            scanf("%s", email);
            for (j = 0; j < lists[i].num_emails; j++) {
                if (strcmp(lists[i].emails[j].email, email) == 0) {
                    for (k = j; k < lists[i].num_emails - 1; k++) {
                        strncpy(lists[i].emails[k].name, lists[i].emails[k+1].name, 50);
                        strncpy(lists[i].emails[k].email, lists[i].emails[k+1].email, 50);
                    }
                    lists[i].num_emails--;
                    printf("Email removed from the mailing list successfully\n");
                    return;
                }
            }
            printf("Email not found in the mailing list\n");
            return;
        }
    }
    printf("Mailing list not found\n");
}

void print_list(struct MailingList *lists, int num_lists) {
    char list_name[50];
    int i, j;

    printf("Enter the name of the mailing list: ");
    scanf("%s", list_name);

    for (i = 0; i < num_lists; i++) {
        if (strcmp(lists[i].name, list_name) == 0) {
            printf("Mailing list name: %s\n", lists[i].name);
            printf("Number of emails: %d\n", lists[i].num_emails);
            for (j = 0; j < lists[i].num_emails; j++) {
                printf("Name: %s\n", lists[i].emails[j].name);
                printf("Email: %s\n", lists[i].emails[j].email);
            }
            return;
        }
    }
    printf("Mailing list not found\n");
}

int main() {
    int choice;
    int num_lists = 0;
    struct MailingList lists[10];

    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_list(lists, &num_lists);
                break;
            case 2:
                add_email(lists, num_lists);
                break;
            case 3:
                remove_email(lists, num_lists);
                break;
            case 4:
                print_list(lists, num_lists);
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}