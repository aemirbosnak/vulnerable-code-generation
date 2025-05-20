//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 100

typedef struct {
    char emails[MAX_EMAILS][MAX_LENGTH];
    int count;
} MailingList;

void initMailingList(MailingList* list) {
    list->count = 0;
    printf("🎉 Welcome to the Mailing List Manager! 🎉\n");
}

void addEmail(MailingList* list) {
    if (list->count >= MAX_EMAILS) {
        printf("🚫 Sorry, mailing list is full! Cannot add more emails.\n");
        return;
    }
    
    char email[MAX_LENGTH];
    printf("✉️ Enter an email to add: ");
    scanf("%s", email);
    
    // Check for duplicates
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            printf("🚫 This email is already in the mailing list!\n");
            return;
        }
    }
    
    strcpy(list->emails[list->count], email);
    list->count++;
    printf("✅ Successfully added %s to the mailing list!\n", email);
}

void removeEmail(MailingList* list) {
    char email[MAX_LENGTH];
    printf("🗑️ Enter an email to remove: ");
    scanf("%s", email);
    
    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            found = 1;
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("✅ Successfully removed %s from the mailing list!\n", email);
            break;
        }
    }
    
    if (!found) {
        printf("🚫 This email does not exist in the mailing list!\n");
    }
}

void displayEmails(MailingList* list) {
    if (list->count == 0) {
        printf("📭 The mailing list is currently empty!\n");
        return;
    }
    
    printf("📬 Current Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->emails[i]);
    }
}

void menu() {
    printf("\n🔧 Mailing List Manager Menu 🔧\n");
    printf("1. Add Email\n");
    printf("2. Remove Email\n");
    printf("3. Display Emails\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    MailingList list;
    initMailingList(&list);
    
    while (1) {
        menu();
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmail(&list);
                break;
            case 2:
                removeEmail(&list);
                break;
            case 3:
                displayEmails(&list);
                break;
            case 4:
                printf("👋 Thank you for using the Mailing List Manager! Goodbye!\n");
                exit(0);
                break;
            default:
                printf("🚫 Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}