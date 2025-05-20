//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct PhoneBook {
    char name[50];
    char phone[20];
    char address[100];
};

void add_contact(struct PhoneBook *pb, char *name, char *phone, char *address) {
    if (strlen(name) < 50 && strlen(phone) < 20 && strlen(address) < 100) {
        strcpy(pb->name, name);
        strcpy(pb->phone, phone);
        strcpy(pb->address, address);
    } else {
        printf("Invalid name, phone, or address.\n");
    }
}

void display_contact(struct PhoneBook *pb) {
    printf("Name: %s\n", pb->name);
    printf("Phone: %s\n", pb->phone);
    printf("Address: %s\n", pb->address);
}

int main() {
    struct PhoneBook contacts[100];
    int numContacts = 0;

    printf("Enter the number of contacts you want to add: ");
    scanf("%d", &numContacts);

    for (int i = 0; i < numContacts; i++) {
        char name[50];
        char phone[20];
        char address[100];
        printf("Enter name for contact %d: ", i + 1);
        fgets(name, sizeof(name), stdin);
        char *nameCopy = strdup(name);
        nameCopy[strcspn(nameCopy, "\n")] = '\0'; // remove newline character

        printf("Enter phone for contact %d: ", i + 1);
        fgets(phone, sizeof(phone), stdin);
        char *phoneCopy = strdup(phone);
        phoneCopy[strcspn(phoneCopy, "\n")] = '\0'; // remove newline character

        printf("Enter address for contact %d: ", i + 1);
        fgets(address, sizeof(address), stdin);
        char *addressCopy = strdup(address);
        addressCopy[strcspn(addressCopy, "\n")] = '\0'; // remove newline character

        add_contact(contacts + i, nameCopy, phoneCopy, addressCopy);
    }

    printf("Contacts added successfully.\n");

    printf("Enter a number of a contact you want to display: ");
    scanf("%d", &numContacts);

    for (int i = 0; i < numContacts; i++) {
        display_contact(contacts + i);
    }

    return 0;
}