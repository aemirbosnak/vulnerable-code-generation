//FormAI DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} Contact;

int num_contacts = 0;
Contact contacts[MAX_CONTACTS];

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Cannot add more contacts. Phone book is full.\n");
        return;
    }
    printf("\nEnter contact name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter contact number: ");
    scanf("%s", contacts[num_contacts].number);
    num_contacts++;
    printf("\nContact added successfully.\n");
}

void display_contacts() {
    if (num_contacts == 0) {
        printf("No contacts found.\n");
        return;
    }
    printf("\nContacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf(" %d. %s: %s\n", i+1, contacts[i].name, contacts[i].number);
    }
}

void search_contact() {
    if (num_contacts == 0) {
        printf("No contacts found.\n");
        return;
    }
    printf("\nEnter contact name to search: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("%s: %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }
    printf("Contact %s not found.\n", name);
}

void delete_contact() {
    if (num_contacts == 0) {
        printf("No contacts found.\n");
        return;
    }
    printf("\nEnter contact name to delete: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            for (int j = i+1; j < num_contacts; j++) {
                strcpy(contacts[j-1].name, contacts[j].name);
                strcpy(contacts[j-1].number, contacts[j].number);
            }
            num_contacts--;
            printf("Contact %s deleted successfully.\n", name);
            return;
        }
    }
    printf("Contact %s not found.\n", name);
}

int main() {
    int choice = 0;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}