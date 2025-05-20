//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTS 100
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 100
#define LOG_FILE "mailing_list.log"

// Structure to hold email list data
typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Email;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Email emails[MAX_LISTS];
    int count;
} MailingList;

MailingList mailingLists[MAX_LISTS];
int listCount = 0;

// Logging function
void logAction(const char *action) {
    FILE *logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }
    fprintf(logFile, "%s\n", action);
    fclose(logFile);
}

// Function to create a new mailing list
void createMailingList() {
    if (listCount >= MAX_LISTS) {
        printf("Maximum list limit reached!\n");
        logAction("Attempted to create a mailing list beyond max limit");
        return;
    }
    
    MailingList newList;
    printf("Enter mailing list name: ");
    scanf("%s", newList.name);
    newList.count = 0;

    mailingLists[listCount++] = newList;
    printf("Mailing list '%s' created.\n", newList.name);
    logAction(newList.name);
}

// Function to add an email to the mailing list
void addEmailToList() {
    char listName[MAX_NAME_LENGTH];
    printf("Enter mailing list name to add email to: ");
    scanf("%s", listName);
    
    for (int i = 0; i < listCount; i++) {
        if (strcmp(mailingLists[i].name, listName) == 0) {
            if (mailingLists[i].count >= MAX_LISTS) {
                printf("Mailing list is full!\n");
                logAction("Attempted to add email to a full mailing list");
                return;
            }
            char email[MAX_EMAIL_LENGTH];
            printf("Enter email to add: ");
            scanf("%s", email);
            strcpy(mailingLists[i].emails[mailingLists[i].count++].email, email);
            printf("Email '%s' added to mailing list '%s'.\n", email, listName);
            logAction(email);
            return;
        }
    }
    printf("Mailing list '%s' not found!\n", listName);
    logAction("Attempted to add email to non-existing mailing list");
}

// Function to remove an email from a mailing list
void removeEmailFromList() {
    char listName[MAX_NAME_LENGTH];
    printf("Enter mailing list name to remove email from: ");
    scanf("%s", listName);
    
    for (int i = 0; i < listCount; i++) {
        if (strcmp(mailingLists[i].name, listName) == 0) {
            char email[MAX_EMAIL_LENGTH];
            printf("Enter email to remove: ");
            scanf("%s", email);
            
            for (int j = 0; j < mailingLists[i].count; j++) {
                if (strcmp(mailingLists[i].emails[j].email, email) == 0) {
                    // Shift emails down to remove
                    for (int k = j; k < mailingLists[i].count - 1; k++) {
                        mailingLists[i].emails[k] = mailingLists[i].emails[k + 1];
                    }
                    mailingLists[i].count--;
                    printf("Email '%s' removed from mailing list '%s'.\n", email, listName);
                    logAction(email);
                    return;
                }
            }
            printf("Email '%s' not found in mailing list '%s'.\n", email, listName);
            logAction("Attempted to remove non-existing email from mailing list");
            return;
        }
    }
    printf("Mailing list '%s' not found!\n", listName);
    logAction("Attempted to remove email from non-existing mailing list");
}

// Function to display mailing list
void displayMailingLists() {
    printf("Mailing Lists:\n");
    for (int i = 0; i < listCount; i++) {
        printf("List: %s, Emails: ", mailingLists[i].name);
        for (int j = 0; j < mailingLists[i].count; j++) {
            printf("%s ", mailingLists[i].emails[j].email);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("Mailing List Manager\n");
        printf("1. Create Mailing List\n");
        printf("2. Add Email to Mailing List\n");
        printf("3. Remove Email from Mailing List\n");
        printf("4. Display Mailing Lists\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createMailingList();
                break;
            case 2:
                addEmailToList();
                break;
            case 3:
                removeEmailFromList();
                break;
            case 4:
                displayMailingLists();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice! Try again.\n");
                logAction("Invalid choice in menu");
        }
    } while (choice != 5);
    
    return 0;
}