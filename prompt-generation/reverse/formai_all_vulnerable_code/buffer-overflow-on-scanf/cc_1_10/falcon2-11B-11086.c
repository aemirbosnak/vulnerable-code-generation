//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[20];
} Contact;

Contact contacts[100];
int numContacts = 0;

void addContact() {
    char name[50], phone[20];
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter phone number: ");
    fgets(phone, sizeof(phone), stdin);
    strncpy(contacts[numContacts].name, name, sizeof(contacts[numContacts].name));
    strncpy(contacts[numContacts].phone, phone, sizeof(contacts[numContacts].phone));
    numContacts++;
}

void searchContact() {
    char name[50];
    printf("Enter name to search: ");
    fgets(name, sizeof(name), stdin);
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("%s: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found\n");
}

void displayContacts() {
    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add Contact\n2. Search Contact\n3. Display Contacts\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addContact(); break;
            case 2: searchContact(); break;
            case 3: displayContacts(); break;
            case 4: exit(0); break;
            default: printf("Invalid choice\n"); break;
        }
    }
    return 0;
}