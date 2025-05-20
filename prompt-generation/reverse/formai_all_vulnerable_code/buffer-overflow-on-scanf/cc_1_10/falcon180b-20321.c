//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct {
    char email[MAX_EMAILS][100];
    int count;
} EmailList;

void addEmail(EmailList* list, char* email) {
    int i = 0;
    while (i < MAX_EMAILS && list->email[i][0]!= '\0') {
        i++;
    }
    if (i < MAX_EMAILS) {
        strcpy(list->email[i], email);
        list->count++;
    }
}

void removeEmail(EmailList* list, char* email) {
    int i = 0;
    while (i < MAX_EMAILS && list->email[i][0]!= '\0') {
        if (strcmp(list->email[i], email) == 0) {
            list->email[i][0] = '\0';
            list->count--;
            break;
        }
        i++;
    }
}

void printEmails(EmailList* list) {
    int i = 0;
    while (i < MAX_EMAILS && list->email[i][0]!= '\0') {
        printf("%s\n", list->email[i]);
        i++;
    }
}

int main() {
    EmailList list;
    list.count = 0;
    char email[100];
    int choice;

    do {
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Print emails\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                addEmail(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeEmail(&list, email);
                break;
            case 3:
                printf("Emails:\n");
                printEmails(&list);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}