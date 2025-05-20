//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 30
#define MAX_NUMBER_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts;

void add_contact() {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter number: ");
    scanf("%s", contacts[num_contacts].number);
    num_contacts++;
    printf("Contact added successfully.\n");
}

void delete_contact() {
    printf("Enter name to delete: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            for (int j = i; j < num_contacts - 1; j++) {
                strcpy(contacts[j].name, contacts[j + 1].name);
                strcpy(contacts[j].number, contacts[j + 1].number);
            }
            num_contacts--;
            printf("Contact deleted successfully.\n");
            break;
        }
    }
}

void search_contact() {
    printf("Enter name to search: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
            break;
        }
    }
}

void view_all_contacts() {
    printf("Name\tNumber\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t\t%s\n", contacts[i].name, contacts[i].number);
    }
}

int main() {
    printf("Welcome to the Phone Book!\n");
    printf("1. Add contact\n2. Delete contact\n3. Search contact\n4. View all contacts\n5. Exit\n");
    int choice;
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_contact();
            break;
        case 2:
            delete_contact();
            break;
        case 3:
            search_contact();
            break;
        case 4:
            view_all_contacts();
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