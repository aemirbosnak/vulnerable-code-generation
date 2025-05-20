//FormAI DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[15];
};

void displayContacts(struct Contact contacts[], int count) {
    printf("\nContacts:\n\n");
    printf("Name \t Phone\n\n");
    for(int i=0; i<count; i++) {
        printf("%s \t %s\n", contacts[i].name, contacts[i].phone);
    }
    printf("\n");
}

void addContact(struct Contact contacts[], int* count, char name[], char phone[]) {
    if(*count < MAX_CONTACTS) {
        strcpy(contacts[*count].name, name);
        strcpy(contacts[*count].phone, phone);
        printf("\nContact added successfully.\n\n");
        (*count)++;
    }
    else {
        printf("\nSorry, maximum contacts limit reached!\n\n");
    }
}

void searchContact(struct Contact contacts[], int count, char name[]) {
    int found = 0;
    for(int i=0; i<count; i++) {
        if(strcmp(contacts[i].name, name) == 0) {
            printf("\nContact found:\n\n");
            printf("%s \t %s\n\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("\nSorry, contact not found!\n\n");
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;
    char name[50];
    char phone[15];
    
    printf("\nWelcome to the C Phone Book!\n\n");
    
    do {
        printf("Choose an option:\n");
        printf("1. Display contacts\n");
        printf("2. Add a contact\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayContacts(contacts, count);
                break;
            case 2:
                printf("\nEnter contact name: ");
                scanf("%s", name);
                printf("Enter contact phone: ");
                scanf("%s", phone);
                addContact(contacts, &count, name, phone);
                break;
            case 3:
                printf("\nEnter contact name: ");
                scanf("%s", name);
                searchContact(contacts, count, name);
                break;
            case 4:
                printf("\nGoodbye!\n\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n\n");
        }
    } while(choice != 4);

    return 0;
}