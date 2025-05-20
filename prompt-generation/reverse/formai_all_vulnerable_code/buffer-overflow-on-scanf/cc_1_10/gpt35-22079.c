//FormAI DATASET v1.0 Category: Phone Book ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone_number[20];
};

void add_contact(struct Contact contacts[], int* num_contacts);
void search_contact(struct Contact contacts[], int num_contacts, char search_name[]);
void print_contacts(struct Contact contacts[], int num_contacts);

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    int option;
    char search_name[50];

    printf("Welcome to Visionary Phone Book!\n");
    do {
        printf("\nChoose an option:\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Print all contacts\n");
        printf("4. Exit\n");

        scanf("%d", &option);
        scanf("%*[^\n]");
        scanf("%*c");

        switch(option) {
            case 1: add_contact(contacts, &num_contacts); break;
            case 2: 
                printf("Enter the name of the contact you want to search:\n");
                fgets(search_name, 50, stdin);
                search_contact(contacts, num_contacts, search_name); 
                break;
            case 3: print_contacts(contacts, num_contacts); break;
            case 4: break;
            default: printf("Invalid option. Please try again.\n");
        }
    } while(option != 4);

    printf("Thank you for using Visionary Phone Book!\n");
    return 0;
}

void add_contact(struct Contact contacts[], int* num_contacts) {
    if(*num_contacts == MAX_CONTACTS) {
        printf("Sorry, the phone book is full.\n");
        return;
    }

    printf("\nEnter contact name:\n");
    fgets(contacts[*num_contacts].name, 50, stdin);
    printf("Enter phone number:\n");
    fgets(contacts[*num_contacts].phone_number, 20, stdin);

    printf("Contact added successfully!\n");
    (*num_contacts)++;
}

void search_contact(struct Contact contacts[], int num_contacts, char search_name[]) {
    int i;
    for(i = 0; i < num_contacts; i++) {
        if(strcmp(contacts[i].name, search_name) == 0) {
            printf("Contact found:\n");
            printf("Name: %sPhone number: %s", contacts[i].name, contacts[i].phone_number);
            return;
        }
    }

    printf("Contact not found.\n");
}

void print_contacts(struct Contact contacts[], int num_contacts) {
    int i;
    for(i = 0; i < num_contacts; i++) {
        printf("Name: %sPhone number: %s", contacts[i].name, contacts[i].phone_number);
    }
}