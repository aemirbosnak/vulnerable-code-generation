//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBERS_PER_CONTACT 5
#define MAX_CONTACTS 100

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS_PER_CONTACT][16];
    int num_numbers;
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    char name[MAX_NAME_LENGTH];
    int num_numbers;
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter number of phone numbers: ");
    scanf("%d", &num_numbers);

    if (num_contacts >= MAX_CONTACTS) {
        printf("Cannot add more contacts.\n");
        return;
    }

    int i;
    for (i = 0; i < num_numbers; i++) {
        char number[16];
        printf("Enter phone number %d: ", i+1);
        scanf("%s", number);
        strcpy(contacts[num_contacts].numbers[i], number);
    }

    strcpy(contacts[num_contacts].name, name);
    contacts[num_contacts].num_numbers = num_numbers;
    num_contacts++;
}

void search_contact() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found contact:\n");
            printf("Name: %s\n", contacts[i].name);

            int j;
            for (j = 0; j < contacts[i].num_numbers; j++) {
                printf("Phone number %d: %s\n", j+1, contacts[i].numbers[j]);
            }

            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    int choice;
    do {
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}