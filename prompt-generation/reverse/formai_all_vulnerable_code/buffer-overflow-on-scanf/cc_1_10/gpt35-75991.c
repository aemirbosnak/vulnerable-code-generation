//FormAI DATASET v1.0 Category: Mailing list manager ; Style: lively
/* Mailing List Manager */
/* Developed by [Your name here] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_MAILING_LIST_SIZE 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} MailingListEntry;

void addEntry(MailingListEntry list[], int *size) {
    if (*size >= MAX_MAILING_LIST_SIZE) {
        printf("Mailing list is full!\n");
        return;
    }
    
    printf("Enter name: ");
    scanf("%s", list[*size].name);
    
    printf("Enter email: ");
    scanf("%s", list[*size].email);
    
    *size += 1;
}

void deleteEntry(MailingListEntry list[], int *size) {
    if (*size == 0) {
        printf("Mailing list is empty!\n");
        return;
    }
    
    int i, found = 0;
    char name[MAX_NAME_LENGTH];
    
    printf("Enter name to delete: ");
    scanf("%s", name);
    
    for (i = 0; i < *size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        for (int j = i; j < *size - 1; j++) {
            strcpy(list[j].name, list[j + 1].name);
            strcpy(list[j].email, list[j + 1].email);
        }
        *size -= 1;
        printf("%s has been deleted from mailing list.\n", name);
    } else {
        printf("%s is not in the mailing list.\n", name);
    }
}

void printList(MailingListEntry list[], int size) {
    if (size == 0) {
        printf("Mailing list is empty!");
        return;
    }
    
    printf("Mailing List:\n");
    for (int i = 0; i < size; i++) {
        printf("%s (%s)\n", list[i].name, list[i].email);
    }
}

int main() {
    MailingListEntry mailingList[MAX_MAILING_LIST_SIZE];
    int size = 0, choice;
    
    while (1) {
        printf("\nWelcome to the Mailing List Manager!\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry(mailingList, &size);
                break;
            case 2:
                deleteEntry(mailingList, &size);
                break;
            case 3:
                printList(mailingList, size);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}