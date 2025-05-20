//FormAI DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact {
    char name[50];
    char phone[20];
};

struct contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    struct contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter phone number: ");
    scanf("%s", new_contact.phone);
    contacts[num_contacts] = new_contact;
    num_contacts++;
}

void delete_contact() {
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);
    int found = 0;
    for(int i = 0; i < num_contacts; i++) {
        if(strcmp(name, contacts[i].name) == 0) {
            found = 1;
            for(int j = i; j < num_contacts-1; j++) {
                contacts[j] = contacts[j+1];
            }
            num_contacts--;
            printf("%s deleted successfully.\n", name);
            break;
        }
    }
    if(!found) {
        printf("%s not found in phone book.\n", name);
    }
}

void display_contacts() {
    printf("Contacts:\n");
    for(int i = 0; i < num_contacts; i++) {
        printf("%d) %s: %s\n", i+1, contacts[i].name, contacts[i].phone);
    }
}

int main() {
    int choice;
    while(1) {
        printf("Phone Book\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                delete_contact();
                break;
            case 3:
                display_contacts();
                break;
            case 4:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}