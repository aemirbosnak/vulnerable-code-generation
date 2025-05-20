//FormAI DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LEN 50

typedef struct {
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    Contact list[MAX_EMAILS];
    int numContacts;
} MailingList;

int addContact(MailingList *list, char* email) {
    if (list->numContacts == MAX_EMAILS) {
        return 0; // Mailing list is full
    }
    
    strcpy(list->list[list->numContacts].email, email);
    list->numContacts++;
    return 1;
}

int removeContact(MailingList *list, char* email) {
    int i, j;
    
    for (i = 0; i < list->numContacts; i++) {
        if (strcmp(list->list[i].email, email) == 0) {
            for (j = i; j < list->numContacts - 1; j++) {
                strcpy(list->list[j].email, list->list[j+1].email);
            }
            list->numContacts--;
            return 1;
        }
    }
    
    return 0; // Email not found in mailing list
}

void printList(MailingList *list) {
    int i;
    for (i = 0; i < list->numContacts; i++) {
        printf("%s\n", list->list[i].email);
    }
}

int main() {
    MailingList myMailingList;
    int choice;
    char email[MAX_EMAIL_LEN];
    
    myMailingList.numContacts = 0;
    
    printf("--- Welcome to the Mailing List Manager! ---\n\n");
    
    while(1) {
        printf("Please choose an option:\n1. Add contact to mailing list\n2. Remove contact from mailing list\n3. Print mailing list\n4. Exit program\n\n");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                
                if (addContact(&myMailingList, email)) {
                    printf("Contact added!\n\n");
                } else {
                    printf("Mailing list is full!\n\n");
                }
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", email);
                
                if (removeContact(&myMailingList, email)) {
                    printf("Contact removed!\n\n");
                } else {
                    printf("Email not found in mailing list!\n\n");
                }
                break;
            case 3:
                printf("Mailing list:\n");
                printList(&myMailingList);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
    
    return 0;
}