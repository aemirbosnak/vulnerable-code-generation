//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL 100
#define EMAIL_LENGTH 50

typedef struct {
    char emails[MAX_EMAIL][EMAIL_LENGTH];
    int count;
} MailingList;

void initList(MailingList *list) {
    list->count = 0;
}

int addEmail(MailingList *list, const char *email) {
    if (list->count >= MAX_EMAIL) {
        return -1; // List full
    }
    strcpy(list->emails[list->count], email);
    list->count++;
    return 0; // Success
}

int removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            return 0; // Success
        }
    }
    return -1; // Email not found
}

void displayList(const MailingList *list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s\n", list->emails[i]);
    }
    if (list->count == 0) {
        printf("The mailing list is empty.\n");
    }
}

int main() {
    MailingList list;
    initList(&list);
    
    char command[10];
    char email[EMAIL_LENGTH];

    while (1) {
        printf("Enter command (add/remove/display/exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            printf("Enter email to add: ");
            scanf("%s", email);
            if (addEmail(&list, email) == 0) {
                printf("Email added: %s\n", email);
            } else {
                printf("Mailing list is full. Cannot add more emails.\n");
            }
        } 
        else if (strcmp(command, "remove") == 0) {
            printf("Enter email to remove: ");
            scanf("%s", email);
            if (removeEmail(&list, email) == 0) {
                printf("Email removed: %s\n", email);
            } else {
                printf("Email not found.\n");
            }
        } 
        else if (strcmp(command, "display") == 0) {
            displayList(&list);
        } 
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        } 
        else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}