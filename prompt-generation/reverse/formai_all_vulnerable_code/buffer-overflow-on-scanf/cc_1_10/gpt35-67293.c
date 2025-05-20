//FormAI DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining a struct for the contact information
struct Contact {
    char name[100];
    char phoneNo[20];
    char email[100];
    char address[200];
};

//Function to add a contact to the phone book
void addContact(struct Contact phonebook[], int *pIndex) {
    struct Contact newContact;
    printf("Enter Name: ");
    scanf("%s", newContact.name);
    printf("Enter Phone number: ");
    scanf("%s", newContact.phoneNo);
    printf("Enter Email Address: ");
    scanf("%s", newContact.email);
    printf("Enter Address: ");
    scanf("%s", newContact.address);
    phonebook[*pIndex] = newContact;
    printf("Contact added successfully!\n");
    (*pIndex)++;
}

//Function to display all the contacts in the phone book
void displayPhoneBook(struct Contact phonebook[], int noOfContacts) {
    printf("%-20s %-20s %-30s %-40s\n", "Name", "Phone Number", "Email Address", "Address");
    printf("-------------------------------------------------------------------------------------------------------\n");
    for (int i=0; i<noOfContacts; i++) {
        printf("%-20s %-20s %-30s %-40s\n", phonebook[i].name, phonebook[i].phoneNo, phonebook[i].email, phonebook[i].address);
    }
}

//Function to search for a contact by name
int searchByName(struct Contact phonebook[], int noOfContacts, char name[]) {
    for (int i=0; i<noOfContacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

//Function to edit the contact information
void editContact(struct Contact phonebook[], int noOfContacts) {
    char name[100];
    printf("Enter the name of the contact you want to edit: ");
    scanf("%s", name);
    int index = searchByName(phonebook, noOfContacts, name);
    if (index == -1) {
        printf("No contact with the name %s found.\n", name);
        return;
    }
    char choice;
    struct Contact updatedContact;
    while (1) {
        printf("Press 1 to edit name\n");
        printf("Press 2 to edit phone number\n");
        printf("Press 3 to edit email address\n");
        printf("Press 4 to edit address\n");
        printf("Press 5 to exit edit mode\n");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                printf("Enter new name: ");
                scanf("%s", updatedContact.name);
                strcpy(phonebook[index].name, updatedContact.name);
                printf("Name updated successfully!\n");
                break;
            case '2':
                printf("Enter new phone number: ");
                scanf("%s", updatedContact.phoneNo);
                strcpy(phonebook[index].phoneNo, updatedContact.phoneNo);
                printf("Phone number updated successfully!\n");
                break;
            case '3':
                printf("Enter new email address: ");
                scanf("%s", updatedContact.email);
                strcpy(phonebook[index].email, updatedContact.email);
                printf("Email address updated successfully!\n");
                break;
            case '4':
                printf("Enter new address: ");
                scanf("%s", updatedContact.address);
                strcpy(phonebook[index].address, updatedContact.address);
                printf("Address updated successfully!\n");
                break;
            case '5':
                printf("Exiting edit mode...\n");
                return;
            default:
                printf("Invalid input!\n");
        }
    } 
}

int main() {
    printf("Welcome to CyberPunk Phone Book!\n");
    printf("Please select an option:\n");
    printf("1. Add Contact\n");
    printf("2. Display All Contacts\n");
    printf("3. Search for a Contact\n");
    printf("4. Edit Contact Information\n");
    printf("5. Exit\n");

    struct Contact phonebook[1000];
    int noOfContacts = 0;

    while (1) {
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addContact(phonebook, &noOfContacts);
                break;
            case 2:
                displayPhoneBook(phonebook, noOfContacts);
                break;
            case 3: {
                char name[100];
                printf("Enter the name to search: ");
                scanf("%s", name);
                int index = searchByName(phonebook, noOfContacts, name);
                if (index == -1) {
                    printf("No contact with the name %s found.\n", name);
                } else {
                    printf("Contact %s found:\n", name);
                    printf("Name: %s\n", phonebook[index].name);
                    printf("Phone Number: %s\n", phonebook[index].phoneNo);
                    printf("Email Address: %s\n", phonebook[index].email);
                    printf("Address: %s\n", phonebook[index].address);
                }
                break;
            }
            case 4:
                editContact(phonebook, noOfContacts);
                break;
            case 5:
                printf("Exiting Phone Book....\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}