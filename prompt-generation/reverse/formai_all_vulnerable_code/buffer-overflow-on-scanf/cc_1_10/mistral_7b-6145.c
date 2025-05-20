//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

void addContact(Contact contacts[], int *numContacts, const char *name, const char *phone, const char *email) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Shocking! You've reached the maximum number of contacts!\n");
        return;
    }

    strcpy(contacts[*numContacts].name, name);
    strcpy(contacts[*numContacts].phone, phone);
    strcpy(contacts[*numContacts].email, email);
    (*numContacts)++;
}

void printContacts(const Contact contacts[], int numContacts) {
    printf("-----%s-----\n", "SHOCKING PHONEBOOK");

    for (int i = 0; i < numContacts; i++) {
        printf("|%-15s|%-20s|\n", contacts[i].name, contacts[i].phone);
    }

    printf("-----%s-----\n", "SHOCKING PHONEBOOK");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;

    char name[50], phone[20], email[50];

again:
    printf("Enter name, phone, or email to add a contact (or type 'exit' to quit): ");
    scanf("%s", name);

    if (strcmp(name, "exit") == 0) {
        goto end;
    }

    printf("Enter phone number: ");
    scanf("%s", phone);

    printf("Enter email address: ");
    scanf("%s", email);

    addContact(contacts, &numContacts, name, phone, email);

    goto again;

end:
    printContacts(contacts, numContacts);

    return 0;
}