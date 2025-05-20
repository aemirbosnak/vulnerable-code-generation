//FormAI DATASET v1.0 Category: Phone Book ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[30];
    int phone_number;
};

void add_contact(struct Contact[], int*);
void remove_contact(struct Contact[], int*);
void search_contact(struct Contact[], int*);
void display_contacts(struct Contact[], int*);

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int num_of_contacts = 0;

    printf("\tWelcome to the Invasive Phone Book!");

    while(1) {
        printf("\n\n\tMenu\n\t1. Add Contact\n\t2. Remove Contact\n\t3. Search Contact\n\t4. Display All Contacts\n\t5. Exit\n\tEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact(contacts, &num_of_contacts);
                break;
            case 2:
                remove_contact(contacts, &num_of_contacts);
                break;
            case 3:
                search_contact(contacts, &num_of_contacts);
                break;
            case 4:
                display_contacts(contacts, &num_of_contacts);
                break;
            case 5:
                printf("\n\tThank you for using the Invasive Phone Book!");
                exit(0);
                break;
            default:
                printf("\n\tInvalid choice.");
        }
    }

    return 0;
}

void add_contact(struct Contact contacts[], int *p_num_of_contacts) {
    if(*p_num_of_contacts == MAX_CONTACTS) {
        printf("\n\tMax number of contacts reached.");
        return;
    }

    struct Contact new_contact;

    printf("\n\tEnter Name: ");
    scanf(" %[^\n]", new_contact.name);

    printf("\tEnter Phone Number: ");
    scanf("%d", &new_contact.phone_number);

    contacts[*p_num_of_contacts] = new_contact;
    (*p_num_of_contacts)++;

    printf("\n\tContact added successfully.");
}

void remove_contact(struct Contact contacts[], int *p_num_of_contacts) {
    if(*p_num_of_contacts == 0) {
        printf("\n\tNo contacts to remove.");
        return;
    }

    char name[30];

    printf("\n\tEnter Name: ");
    scanf(" %[^\n]", name);

    int found = 0;

    for(int i=0; i<*p_num_of_contacts; i++) {
        if(strcmp(contacts[i].name, name) == 0) {
            found = 1;

            for(int j=i; j<(*p_num_of_contacts)-1; j++) {
                contacts[j] = contacts[j+1];
            }

            (*p_num_of_contacts)--;

            printf("\n\tContact removed successfully.");
            break;
        }
    }

    if(!found) {
        printf("\n\tContact not found.");
    }
}

void search_contact(struct Contact contacts[], int *p_num_of_contacts) {
    if(*p_num_of_contacts == 0) {
        printf("\n\tNo contacts to search.");
        return;
    }

    char name[30];

    printf("\n\tEnter Name: ");
    scanf(" %[^\n]", name);

    int found = 0;

    for(int i=0; i<*p_num_of_contacts; i++) {
        if(strcmp(contacts[i].name, name) == 0) {
            found = 1;

            printf("\n\tName: %s\n\tPhone Number: %d", contacts[i].name, contacts[i].phone_number);

            break;
        }
    }

    if(!found) {
        printf("\n\tContact not found.");
    }
}

void display_contacts(struct Contact contacts[], int *p_num_of_contacts) {
    if(*p_num_of_contacts == 0) {
        printf("\n\tNo contacts to display.");
        return;
    }

    printf("\n\n\tContacts\n");

    for(int i=0; i<*p_num_of_contacts; i++) {
        printf("\n\tName: %s\n\tPhone Number: %d\n", contacts[i].name, contacts[i].phone_number);
    }
}