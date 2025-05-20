//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone_number[15];
} Contact;

void add_contact(Contact contacts[], int num_contacts) {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].phone_number);
    num_contacts++;
}

void view_contact(Contact contacts[], int num_contacts, int index) {
    printf("Name: %s\n", contacts[index].name);
    printf("Phone number: %s\n", contacts[index].phone_number);
}

void delete_contact(Contact contacts[], int num_contacts) {
    printf("Enter contact to delete: ");
    int index;
    scanf("%d", &index);
    if (index >= 0 && index < num_contacts) {
        for (int i = index; i < num_contacts - 1; i++) {
            strcpy(contacts[i].name, contacts[i+1].name);
            strcpy(contacts[i].phone_number, contacts[i+1].phone_number);
        }
        num_contacts--;
    } else {
        printf("Invalid contact\n");
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    while (1) {
        printf("1. Add contact\n2. View contact\n3. Delete contact\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact(contacts, num_contacts);
            break;
        case 2:
            printf("Enter contact to view: ");
            int index;
            scanf("%d", &index);
            view_contact(contacts, num_contacts, index);
            break;
        case 3:
            delete_contact(contacts, num_contacts);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}