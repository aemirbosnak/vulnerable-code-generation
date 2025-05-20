//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define MAX_FIELDS 5

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
    char notes[100];
} Contact;

void createContact(Contact* contact, int fieldCount);
void printContact(const Contact* contact);

int main() {
    int numEntries, fieldCount;
    Contact contacts[MAX_ENTRIES];

    printf("Enter the maximum number of entries: ");
    scanf("%d", &numEntries);

    if (numEntries > MAX_ENTRIES) {
        printf("Error: maximum number of entries exceeded.\n");
        return 1;
    }

    printf("Enter the maximum number of fields per entry: ");
    scanf("%d", &fieldCount);

    if (fieldCount > MAX_FIELDS) {
        printf("Error: maximum number of fields per entry exceeded.\n");
        return 1;
    }

    for (int i = 0; i < numEntries; i++) {
        createContact(&contacts[i], fieldCount);
    }

    for (int i = 0; i < numEntries; i++) {
        printContact(&contacts[i]);
        printf("\n");
    }

    return 0;
}

void createContact(Contact* contact, int fieldCount) {
    for (int i = 0; i < fieldCount; i++) {
        switch (i) {
            case 0:
                printf("Enter name: ");
                scanf("%s", contact->name);
                break;
            case 1:
                printf("Enter phone number: ");
                scanf("%s", contact->phone);
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", contact->email);
                break;
            case 3:
                printf("Enter address: ");
                scanf("%s", contact->address);
                break;
            case 4:
                printf("Enter notes: ");
                scanf("%s", contact->notes);
                break;
            default:
                printf("Invalid field index.\n");
                return;
        }
    }
}

void printContact(const Contact* contact) {
    printf("Name: %s\n", contact->name);
    printf("Phone: %s\n", contact->phone);
    printf("Email: %s\n", contact->email);
    printf("Address: %s\n", contact->address);
    printf("Notes: %s\n", contact->notes);
}