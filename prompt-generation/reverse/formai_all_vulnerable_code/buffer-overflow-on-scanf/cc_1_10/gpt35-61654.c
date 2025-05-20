//FormAI DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone[20];
} Contact;

Contact *create_contact(char *name, char *phone) {
    Contact *contact = malloc(sizeof(Contact));
    if (contact != NULL) {
        strcpy(contact->name, name);
        strcpy(contact->phone, phone);
    }
    return contact;
}

void print_contact(Contact *contact) {
    printf("%-30s %-20s\n", contact->name, contact->phone);
}

void print_contacts(Contact **contacts, int num_contacts) {
    printf("%-30s %-20s\n", "Name", "Phone");
    printf("---------------------------------------\n");
    for (int i = 0; i < num_contacts; i++) {
        print_contact(contacts[i]);
    }
    printf("\n");
}

int main() {
    int max_contacts;
    printf("Enter the maximum number of contacts: ");
    scanf("%d", &max_contacts);

    Contact **contacts = malloc(max_contacts * sizeof(Contact *));
    if (contacts == NULL) {
        printf("Error: could not allocate memory for contacts.\n");
        return 1;
    }
    int num_contacts = 0;
    char name[50], phone[20];
    while (1) {
        printf("Enter a name (or 'q' to quit): ");
        scanf("%s", name);
        if (name[0] == 'q') {
            break;
        }
        printf("Enter a phone number: ");
        scanf("%s", phone);
        Contact *contact = create_contact(name, phone);
        if (contact == NULL) {
            printf("Error: could not create contact.\n");
            return 1;
        }
        if (num_contacts == max_contacts) {
            printf("Error: maximum number of contacts reached.\n");
            return 1;
        }
        contacts[num_contacts] = contact;
        num_contacts++;
    }
    print_contacts(contacts, num_contacts);

    for (int i = 0; i < num_contacts; i++) {
        free(contacts[i]);
    }
    free(contacts);
    return 0;
}