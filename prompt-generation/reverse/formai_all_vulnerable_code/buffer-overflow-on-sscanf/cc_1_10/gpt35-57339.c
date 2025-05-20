//FormAI DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

struct MailingList {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

int addContact(struct MailingList *list, int numContacts);
int deleteContact(struct MailingList *list, int numContacts);
void printList(struct MailingList *list, int numContacts);
void saveToFile(struct MailingList *list, int numContacts);
void loadFromFile(struct MailingList *list, int *numContacts);
void clearList(struct MailingList *list, int *numContacts);

int main() {
    struct MailingList list[MAX_EMAILS];
    int numContacts = 0;
    int choice;
    char buffer[256];
    
    while(1) {
        printf("\n\n===== Mailing List Manager =====\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Print List\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Clear List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%d", &choice);
        
        switch(choice) {
            case 1:
                numContacts = addContact(list, numContacts);
                break;
            case 2:
                numContacts = deleteContact(list, numContacts);
                break;
            case 3:
                printList(list, numContacts);
                break;
            case 4:
                saveToFile(list, numContacts);
                break;
            case 5:
                loadFromFile(list, &numContacts);
                break;
            case 6:
                clearList(list, &numContacts);
                break;
            case 7:
                printf("\nExiting...\n");
                return 0;
            default:
                printf("\nInvalid input. Try again.\n");
        }
    }
    
    return 0;
}

int addContact(struct MailingList *list, int numContacts) {
    if(numContacts == MAX_EMAILS) {
        printf("\nThe mailing list is full. Cannot add any more contacts.\n");
        return numContacts;
    }
    
    char buffer[256];
    struct MailingList newContact;
    
    printf("\nEnter contact name: ");
    fgets(buffer, 256, stdin);
    sscanf(buffer, "%49[^\n]", newContact.name);
    
    printf("\nEnter contact email: ");
    fgets(buffer, 256, stdin);
    sscanf(buffer, "%49[^\n]", newContact.email);
    
    list[numContacts] = newContact;
    
    printf("\nContact added successfully!\n");
    
    return numContacts + 1;
}

int deleteContact(struct MailingList *list, int numContacts) {
    if(numContacts == 0) {
        printf("\nThe mailing list is empty. Cannot delete any contacts.\n");
        return numContacts;
    }
    
    char buffer[256];
    int indexToDelete;
    
    printf("\nEnter index of contact to delete: ");
    fgets(buffer, 256, stdin);
    sscanf(buffer, "%d", &indexToDelete);
    
    if(indexToDelete < 1 || indexToDelete > numContacts) {
        printf("\nInvalid index. Try again.\n");
        return numContacts;
    }
    
    indexToDelete--;
    
    for(int i = indexToDelete; i < numContacts - 1; i++) {
        list[i] = list[i+1];
    }
    
    printf("\nContact deleted successfully!\n");
    
    return numContacts - 1;
}

void printList(struct MailingList *list, int numContacts) {
    if(numContacts == 0) {
        printf("\nThe mailing list is empty.\n");
        return;
    }
    
    printf("\nMailing List:\n");
    
    for(int i = 0; i < numContacts; i++) {
        printf("%d. %s (%s)\n", i+1, list[i].name, list[i].email);
    }
}

void saveToFile(struct MailingList *list, int numContacts) {
    if(numContacts == 0) {
        printf("\nThe mailing list is empty. Nothing to save.\n");
        return;
    }
    
    FILE *fp;
    fp = fopen("mailinglist.txt", "w+");
    
    if(fp == NULL) {
        printf("\nError opening file for saving.\n");
        return;
    }
    
    for(int i = 0; i < numContacts; i++) {
        fprintf(fp, "%s|%s\n", list[i].name, list[i].email);
    }
    
    fclose(fp);
    
    printf("\nMailing List saved to file successfully!\n");
}

void loadFromFile(struct MailingList *list, int *numContacts) {
    FILE *fp;
    fp = fopen("mailinglist.txt", "r");
    
    if(fp == NULL) {
        printf("\nError opening file for loading.\n");
        return;
    }
    
    char buffer[256];
    struct MailingList newContact;
    int count = 0;
    
    while(fgets(buffer, 256, fp) != NULL) {
        sscanf(buffer, "%[^|]|%s", newContact.name, newContact.email);
        list[count] = newContact;
        count++;
    }
    
    *numContacts = count;
    
    fclose(fp);
    
    printf("\nMailing List loaded from file successfully!\n");
}

void clearList(struct MailingList *list, int *numContacts) {
    *numContacts = 0;
    
    printf("\nMailing List cleared successfully!\n");
}