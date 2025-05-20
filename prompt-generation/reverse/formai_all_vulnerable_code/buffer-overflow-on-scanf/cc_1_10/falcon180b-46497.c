//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[100];
    char phone[20];
    char email[100];
} Contact;

Contact contacts[MAX_ENTRIES];
int num_contacts = 0;

void add_contact() {
    char name[100];
    char phone[20];
    char email[100];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    printf("Enter email: ");
    scanf("%s", email);

    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].phone, phone);
    strcpy(contacts[num_contacts].email, email);

    num_contacts++;
}

void search_contact() {
    char search_name[100];

    printf("Enter name to search: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
        }
    }
}

void delete_contact() {
    char delete_name[100];

    printf("Enter name to delete: ");
    scanf("%s", delete_name);

    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, delete_name) == 0) {
            strcpy(contacts[i].name, "");
            strcpy(contacts[i].phone, "");
            strcpy(contacts[i].email, "");
            num_contacts--;
        }
    }
}

void view_contacts() {
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("Name: %s\nPhone: %s\nEmail: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. View all contacts\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                view_contacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}