//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 20
#define MAX_CONTACTS 100

typedef struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts;

void add_contact() {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);

    printf("Enter number: ");
    scanf("%s", contacts[num_contacts].number);

    num_contacts++;
}

void remove_contact() {
    int idx;
    printf("Enter index of contact to remove: ");
    scanf("%d", &idx);

    if (idx >= 0 && idx < num_contacts) {
        num_contacts--;
        for (int i = idx; i < num_contacts; i++) {
            strcpy(contacts[i].name, contacts[i+1].name);
            strcpy(contacts[i].number, contacts[i+1].number);
        }
    } else {
        printf("Invalid index.\n");
    }
}

void search_contact() {
    char name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }

    printf("Contact not found.\n");
}

void print_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
    }
}

int main() {
    num_contacts = 0;

    while (1) {
        printf("1. Add contact\n2. Remove contact\n3. Search contact\n4. Print all contacts\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                print_contacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}