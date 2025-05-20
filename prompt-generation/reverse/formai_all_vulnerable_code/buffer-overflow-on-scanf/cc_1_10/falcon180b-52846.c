//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_ADDRESS_LEN 100
#define MAX_MESSAGE_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char address[MAX_ADDRESS_LEN];
    char message[MAX_MESSAGE_LEN];
} Contact;

void add_contact(Contact* contacts, int* num_contacts) {
    printf("Enter your name: ");
    scanf(" %[^\n]", contacts[*num_contacts].name);
    printf("Enter your phone number: ");
    scanf(" %[^\n]", contacts[*num_contacts].phone);
    printf("Enter your address: ");
    scanf(" %[^\n]", contacts[*num_contacts].address);
    printf("Enter your message: ");
    scanf(" %[^\n]", contacts[*num_contacts].message);
    (*num_contacts)++;
}

void display_contacts(Contact* contacts, int num_contacts) {
    printf("Name\tPhone\tAddress\tMessage\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\t%s\t%s\n", contacts[i].name, contacts[i].phone, contacts[i].address, contacts[i].message);
    }
}

int main() {
    Contact contacts[100];
    int num_contacts = 0;

    add_contact(contacts, &num_contacts);

    while (1) {
        system("clear");
        printf("1. Add contact\n2. Display contacts\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                display_contacts(contacts, num_contacts);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}