//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAMES 100
#define MAX_PHONES 10
#define MAX_NAME_LENGTH 30
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

int getName(char* name) {
    printf("Enter name: ");
    scanf("%s", name);
    while (strlen(name) == 0) {
        printf("Name cannot be empty. Enter name: ");
        scanf("%s", name);
    }
    return 1;
}

int getPhone(char* phone) {
    printf("Enter phone: ");
    scanf("%s", phone);
    while (strlen(phone) == 0) {
        printf("Phone number cannot be empty. Enter phone: ");
        scanf("%s", phone);
    }
    return 1;
}

int compareName(const void* a, const void* b) {
    Contact* contactA = (Contact*)a;
    Contact* contactB = (Contact*)b;
    return strcmp(contactA->name, contactB->name);
}

int comparePhone(const void* a, const void* b) {
    Contact* contactA = (Contact*)a;
    Contact* contactB = (Contact*)b;
    return strcmp(contactA->phone, contactB->phone);
}

void printContact(Contact contact) {
    printf("%s: %s\n", contact.name, contact.phone);
}

int main() {
    Contact* contacts = (Contact*)malloc(MAX_NAMES * sizeof(Contact));
    int numContacts = 0;

    while (numContacts < MAX_NAMES) {
        Contact contact;
        if (getName(contact.name) && getPhone(contact.phone)) {
            contacts[numContacts] = contact;
            numContacts++;
        } else {
            printf("Invalid input. Try again.\n");
        }
    }

    printf("Sort by name? (y/n): ");
    char sortByName;
    scanf("%c", &sortByName);

    if (sortByName == 'y' || sortByName == 'Y') {
        qsort(contacts, numContacts, sizeof(Contact), compareName);
    } else {
        qsort(contacts, numContacts, sizeof(Contact), comparePhone);
    }

    printf("Sorted by %c:\n", sortByName);
    for (int i = 0; i < numContacts; i++) {
        printContact(contacts[i]);
    }

    free(contacts);
    return 0;
}