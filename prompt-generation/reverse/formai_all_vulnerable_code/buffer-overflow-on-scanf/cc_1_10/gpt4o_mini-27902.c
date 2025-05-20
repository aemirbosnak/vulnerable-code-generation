//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 100

typedef struct EmailList {
    char emails[MAX_EMAILS][EMAIL_LENGTH];
    int count;
} EmailList;

void initList(EmailList *list) {
    list->count = 0;
}

void addEmail(EmailList *list, const char *email) {
    if (list->count < MAX_EMAILS) {
        strcpy(list->emails[list->count], email);
        list->count++;
        printf("Dear Juliet, thou hast been added to our list of love.\n");
    } else {
        printf("Alas! The list is full, fair maiden!\n");
    }
}

void removeEmail(EmailList *list, const char *email) {
    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            found = 1;
            printf("O Romeo, I shall cast thee out from our circle!\n");

            // Shift remaining emails left
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            break;
        }
    }
    if (!found) {
        printf("I have searched, yet found thee not, sweet heart!\n");
    }
}

void displayList(const EmailList *list) {
    printf("Behold the list of our dearest hearts:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
}

void clearList(EmailList *list) {
    list->count = 0;
    printf("All hearts have been set free, as if by magic.\n");
}

int main() {
    EmailList list;
    initList(&list);

    int choice;
    char email[EMAIL_LENGTH];

    do {
        printf("\n1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Clear List\n");
        printf("5. Exit\n");
        printf("What dost thou desire, kind friend? ");
        scanf("%d", &choice);
        getchar(); // To consume newline character after choice

        switch (choice) {
            case 1:
                printf("Enter the email to be added, sweet romeo: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                addEmail(&list, email);
                break;
            case 2:
                printf("Enter the email to be removed, oh gentle heart: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                removeEmail(&list, email);
                break;
            case 3:
                displayList(&list);
                break;
            case 4:
                clearList(&list);
                break;
            case 5:
                printf("Good night, my love! Till we meet again.\n");
                break;
            default:
                printf("O, I am no fool! Choose again, dear heart.\n");
        }
    } while (choice != 5);

    return 0;
}