//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 2
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char **emails;
    int size;
    int capacity;
} MailingList;

MailingList* createMailingList() {
    MailingList *list = (MailingList *)malloc(sizeof(MailingList));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    list->emails = (char **)malloc(sizeof(char *) * list->capacity);
    return list;
}

void freeMailingList(MailingList *list) {
    for (int i = 0; i < list->size; ++i) {
        free(list->emails[i]);
    }
    free(list->emails);
    free(list);
}

void resizeMailingList(MailingList *list) {
    list->capacity *= 2;
    list->emails = (char **)realloc(list->emails, sizeof(char *) * list->capacity);
}

void addEmail(MailingList *list, const char *email) {
    if (list->size >= list->capacity) {
        resizeMailingList(list);
    }
    list->emails[list->size] = (char *)malloc(strlen(email) + 1);
    strcpy(list->emails[list->size], email);
    list->size++;
    printf("Email '%s' added to the mailing list.\n", email);
}

void removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            free(list->emails[i]);
            for (int j = i; j < list->size - 1; j++) {
                list->emails[j] = list->emails[j + 1];
            }
            list->size--;
            printf("Email '%s' removed from the mailing list.\n", email);
            return;
        }
    }
    printf("Email '%s' not found in the mailing list.\n", email);
}

void displayEmails(MailingList *list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
}

void menu() {
    printf("Mailing List Manager\n");
    printf("1. Add Email\n");
    printf("2. Remove Email\n");
    printf("3. Display Emails\n");
    printf("4. Exit\n");
}

int main() {
    MailingList *list = createMailingList();
    int choice;
    char email[MAX_EMAIL_LENGTH];

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addEmail(list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeEmail(list, email);
                break;
            case 3:
                displayEmails(list);
                break;
            case 4:
                freeMailingList(list);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}