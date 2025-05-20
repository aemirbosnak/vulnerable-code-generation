//FormAI DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char name[30];
    char phone[15];
    char email[30];
} Contact;

void addContact(Contact* contacts, int* count);
void displayContacts(Contact* contacts, int count);
void searchContacts(Contact* contacts, int count);
void deleteContact(Contact* contacts, int* count);

int main() {
    Contact contacts[50];
    int count = 0;
    int choice;

    while(1) {
        printf("\nWelcome to PhoneBook\n");
        printf("1. Add contact\n2. Display contacts\n3. Search contacts\n4. Delete contact\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                displayContacts(contacts, count);
                break;
            case 3:
                searchContacts(contacts, count);
                break;
            case 4:
                deleteContact(contacts, &count);
                break;
            case 5:
                printf("\nThank you for using PhoneBook\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addContact(Contact* contacts, int* count) {
    Contact temp;
    printf("\nEnter contact name: ");
    getchar();
    fgets(temp.name, 30, stdin);
    printf("Enter phone number: ");
    fgets(temp.phone, 15, stdin);
    printf("Enter email address: ");
    fgets(temp.email, 30, stdin);

    contacts[*count] = temp;
    *count += 1;

    printf("\nContact added successfully!\n");
}

void displayContacts(Contact* contacts, int count) {
    if(count == 0) {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\nContacts:\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %s%s%s", i+1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void searchContacts(Contact* contacts, int count) {
    if(count == 0) {
        printf("\nNo contacts found.\n");
        return;
    }

    char term[30];
    printf("\nEnter search term: ");
    getchar();
    fgets(term, 30, stdin);

    printf("\nSearch results:\n");
    for(int i = 0; i < count; i++) {
        if(strstr(contacts[i].name, term) != NULL || strstr(contacts[i].phone, term) != NULL || strstr(contacts[i].email, term) != NULL) {
            printf("%d. %s%s%s", i+1, contacts[i].name, contacts[i].phone, contacts[i].email);
        }
    }
}

void deleteContact(Contact* contacts, int* count) {
    if(*count == 0) {
        printf("\nNo contacts found.\n");
        return;
    }

    int choice;
    printf("\nSelect contact to delete:\n");
    displayContacts(contacts, *count);
    printf("Enter choice (number): ");
    scanf("%d", &choice);

    if(choice < 1 || choice > *count) {
        printf("\nInvalid choice. Please try again.\n");
        return;
    }

    for(int i = choice-1; i < *count-1; i++) {
        contacts[i] = contacts[i+1];
    }

    *count -= 1;

    printf("\nContact deleted successfully!\n");
}