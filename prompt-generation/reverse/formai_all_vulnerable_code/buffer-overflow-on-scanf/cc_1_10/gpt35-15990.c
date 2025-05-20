//FormAI DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_CONTACTS 100
#define NAME_LENGTH 30
#define PHONE_LENGTH 10

struct contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
};

void remove_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void display_menu() {
    printf("\n\n********** Cyberpunk Phone Book **********\n");
    printf("\n\t1. Add a Contact\n");
    printf("\t2. Search a Contact\n");
    printf("\t3. Display all Contacts\n");
    printf("\t4. Exit\n");
}

void add_contact(struct contact *contacts, int *num_contacts) {
    printf("\nEnter name: ");
    fgets(contacts[*num_contacts].name, NAME_LENGTH, stdin);
    remove_newline(contacts[*num_contacts].name);

    printf("Enter phone number: ");
    fgets(contacts[*num_contacts].phone, PHONE_LENGTH, stdin);
    remove_newline(contacts[*num_contacts].phone);

    (*num_contacts)++;
    printf("\n*** Contact added! ***\n");
}

void search_contact(struct contact *contacts, int num_contacts) {
    char name[NAME_LENGTH];
    printf("\nEnter name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    remove_newline(name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("\nName: %s\nPhone Number: %s\n", 
                contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("\n*** Contact not found ***\n");
}

void display_contacts(struct contact *contacts, int num_contacts) {
    if (num_contacts == 0) {
        printf("\n*** No Contacts ***\n");
    }
    for (int i = 0; i < num_contacts; i++) {
        printf("\nName: %s\nPhone Number: %s\n", 
            contacts[i].name, contacts[i].phone);
    }
}

int main() {
    struct contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    int choice;

    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // clear input buffer
        
        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                search_contact(contacts, num_contacts);
                break;
            case 3:
                display_contacts(contacts, num_contacts);
                break;
            case 4:
                printf("\n*** Exiting program ***\n");
                break;
            default:
                printf("\n*** Invalid choice, try again... ***\n");
        }
    } while (choice != 4);

    return 0;
}