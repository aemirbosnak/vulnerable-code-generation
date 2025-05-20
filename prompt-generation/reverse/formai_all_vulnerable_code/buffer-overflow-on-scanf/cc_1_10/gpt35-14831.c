//FormAI DATASET v1.0 Category: Phone Book ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
};

void add_contact(struct Contact *contacts, int *num_contacts) {
    char name[50];
    char phone[20];
    printf("Enter contact name: ");
    scanf("%s", name);
    printf("Enter contact phone number: ");
    scanf("%s", phone);
    strcpy(contacts[*num_contacts].name, name);
    strcpy(contacts[*num_contacts].phone, phone);
    (*num_contacts)++;
}

void print_contacts(struct Contact *contacts, int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    struct Contact contacts[100];
    int num_contacts = 0;
    int choice;

    while (1) {
        printf("1. Add contact\n");
        printf("2. Print contacts\n");
        printf("3. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                print_contacts(contacts, num_contacts);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}