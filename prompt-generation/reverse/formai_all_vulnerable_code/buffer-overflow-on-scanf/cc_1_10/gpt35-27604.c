//FormAI DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} contact;

contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if(num_contacts < MAX_CONTACTS) {
        printf("Enter name: ");
        scanf("%s", contacts[num_contacts].name);
        printf("Enter number: ");
        scanf("%s", contacts[num_contacts].number);
        num_contacts++;
        printf("Contact added!\n");
    } else {
        printf("Phone book full!\n");
    }
}

void delete_contact() {
    if(num_contacts > 0) {
        char name[MAX_NAME_LENGTH];
        printf("Enter name of contact to delete: ");
        scanf("%s", name);
        int found = 0;
        for(int i = 0; i < num_contacts; i++) {
            if(strcmp(name, contacts[i].name) == 0) {
                found = 1;
                for(int j = i; j < num_contacts - 1; j++) {
                    contacts[j] = contacts[j + 1];
                
                }
                break;
            }
        }
        if(found) {
            num_contacts--;
            printf("Contact deleted!\n");
        } else {
            printf("Contact not found!\n");
        }
    } else {
        printf("Phone book empty!\n");
    }
}

void search_contact() {
    if(num_contacts > 0) {
        char name[MAX_NAME_LENGTH];
        printf("Enter name of contact to search for: ");
        scanf("%s", name);
        int found = 0;
        for(int i = 0; i < num_contacts; i++) {
            if(strcmp(name, contacts[i].name) == 0) {
                found = 1;
                printf("%s - %s\n", contacts[i].name, contacts[i].number);
            }
        }
        if(!found) {
            printf("Contact not found!\n");
        }
    } else {
        printf("Phone book empty!\n");
    }
}

void display_contacts() {
    if(num_contacts > 0) {
        for(int i = 0; i < num_contacts; i++) {
            printf("%s - %s\n", contacts[i].name, contacts[i].number);
        }
    } else {
        printf("Phone book empty!\n");
    }
}

int main() {
    printf("Welcome to the artistic C Phone Book!\n");

    while(1) {
        printf("\nOptions:\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search contacts\n");
        printf("4. Display all contacts\n");
        printf("5. Quit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                delete_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                display_contacts();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}