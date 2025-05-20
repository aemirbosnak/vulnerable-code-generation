//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct contact {
    char name[50];
    char phone_number[15];
} Contact;

void add_contact(Contact contacts[], int num_contacts) {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].phone_number);
    printf("\n");
    num_contacts++;
}

void display_contact(Contact contact) {
    printf("%-20s %-15s\n", contact.name, contact.phone_number);
}

void search_contact(Contact contacts[], int num_contacts, char name[]) {
    int i;
    for(i = 0; i < num_contacts; i++) {
        if(strcmp(contacts[i].name, name) == 0) {
            display_contact(contacts[i]);
        }
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    
    printf("\n\nWelcome to the C Phone Book!\n\n");
    printf("Please enter your name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("You are now in the phone book.\n\n");
    
    while(1) {
        printf("\nEnter 1 to add a contact\nEnter 2 to search for a contact\nEnter 3 to exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact(contacts, num_contacts);
                break;
            case 2:
                printf("\nEnter name to search for: ");
                char name_search[50];
                scanf("%s", name_search);
                search_contact(contacts, num_contacts, name_search);
                break;
            case 3:
                printf("\nThank you for using the C Phone Book.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}