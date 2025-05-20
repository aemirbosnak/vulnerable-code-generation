//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_MAX_LEN 30
#define PHONE_MAX_LEN 15

typedef struct {
    char name[NAME_MAX_LEN];
    char phone[PHONE_MAX_LEN];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].phone);
    num_contacts++;
}

void view_all_contacts() {
    printf("Phone Book:\n");
    printf("=============\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i+1, contacts[i].name, contacts[i].phone);
    }
}

void search_contact() {
    printf("Enter name to search: ");
    char name[NAME_MAX_LEN];
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("%s - %s\n", name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nPhone Book Menu:\n");
        printf("=================\n");
        printf("1. Add contact\n");
        printf("2. View all contacts\n");
        printf("3. Search contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                view_all_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);
    return 0;
}