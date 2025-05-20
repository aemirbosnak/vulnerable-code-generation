//FormAI DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    char phone[15];
} Contact;

void add_contact(Contact *contacts, int *count) {
    Contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter phone number: ");
    scanf("%s", new_contact.phone);
    contacts[*count] = new_contact;
    *count += 1;
    printf("\nContact added successfully!\n\n");
}

void remove_contact(Contact *contacts, int *count) {
    char name[30];
    printf("Enter name to remove: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            found = 1;
            *count -= 1;
            for (int j = i; j < *count; j++) {
                contacts[j] = contacts[j+1];
            }
            printf("\nContact %s removed successfully!\n\n", name);
        }
    }
    if (!found) {
        printf("\nContact %s not found!\n\n", name);
    }
}

void print_contacts(Contact *contacts, int count) {
    if (count == 0) {
        printf("\nNo contacts found!\n\n");
        return;
    }
    printf("\nContacts:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\nPhone: %s\n\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    Contact contacts[100];
    int count = 0;
    int choice;
    while (1) {
        printf("Enter 1 to add contact, 2 to remove contact, 3 to print contacts, or 4 to exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(contacts, &count);
                break;
            case 2:
                remove_contact(contacts, &count);
                break;
            case 3:
                print_contacts(contacts, count);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}