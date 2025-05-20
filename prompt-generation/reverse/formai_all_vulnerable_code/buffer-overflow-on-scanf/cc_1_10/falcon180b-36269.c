//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct contact {
    char name[50];
    char phone[15];
};

void add_contact(struct contact contacts[], int size, char* name, char* phone) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("This contact already exists.\n");
            return;
        }
    }
    strcpy(contacts[size].name, name);
    strcpy(contacts[size].phone, phone);
    printf("Contact added successfully.\n");
}

void search_contact(struct contact contacts[], int size, char* name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void delete_contact(struct contact contacts[], int size, char* name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            memmove(&contacts[i], &contacts[i+1], (size - i - 1) * sizeof(struct contact));
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void display_contacts(struct contact contacts[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    struct contact contacts[MAX];
    int size = 0;
    char choice;
    do {
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Display all contacts\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                char name[50], phone[15];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                add_contact(contacts, size, name, phone);
                break;
            }
            case 2: {
                char name[50];
                printf("Enter name to search: ");
                scanf("%s", name);
                search_contact(contacts, size, name);
                break;
            }
            case 3: {
                char name[50];
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_contact(contacts, size, name);
                break;
            }
            case 4: {
                display_contacts(contacts, size);
                break;
            }
            case 5: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while(choice!= 5);
    return 0;
}