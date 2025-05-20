//FormAI DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone_number[20];
    char email[50];
    char address[100];
};

struct Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if(num_contacts < MAX_CONTACTS) {
        printf("Please enter the name: ");
        scanf("%s", contacts[num_contacts].name);
        printf("Please enter the phone number: ");
        scanf("%s", contacts[num_contacts].phone_number);
        printf("Please enter the email address: ");
        scanf("%s", contacts[num_contacts].email);
        printf("Please enter the address: ");
        scanf("%s", contacts[num_contacts].address);
        printf("Contact added successfully!\n");
        num_contacts++;
    } else {
        printf("Cannot add more contacts!\n");
    }
}

void search_contact() {
    char name[50];
    printf("Please enter the name to search: ");
    scanf("%s", name);
    for(int i=0;i<num_contacts;i++) {
        if(strcmp(name, contacts[i].name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone number: %s\n", contacts[i].phone_number);
            printf("Email: %s\n", contacts[i].email);
            printf("Address: %s\n", contacts[i].address);
            return;
        }
    }
    printf("Contact not found!\n");
}

void delete_contact() {
    char name[50];
    printf("Please enter the name to delete: ");
    scanf("%s", name);
    for(int i=0;i<num_contacts;i++) {
        if(strcmp(name, contacts[i].name) == 0) {
            for(int j=i;j<num_contacts-1;j++) {
                strcpy(contacts[j].name, contacts[j+1].name);
                strcpy(contacts[j].phone_number, contacts[j+1].phone_number);
                strcpy(contacts[j].email, contacts[j+1].email);
                strcpy(contacts[j].address, contacts[j+1].address);
            }
            printf("Contact deleted successfully!\n");
            num_contacts--;
            return;
        }
    }
    printf("Contact not found!\n");
}

void display_contacts() {
    for(int i=0;i<num_contacts;i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone number: %s\n", contacts[i].phone_number);
        printf("Email: %s\n", contacts[i].email);
        printf("Address: %s\n", contacts[i].address);
        printf("\n");
    }
}

int main() {
    int choice;
    while(1) {
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                display_contacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}