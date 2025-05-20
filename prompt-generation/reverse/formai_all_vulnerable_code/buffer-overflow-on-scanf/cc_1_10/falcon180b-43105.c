//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Contact;

int num_contacts = 0;
Contact contacts[MAX_CONTACTS];

void add_contact() {
    printf("Enter contact name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter contact number: ");
    scanf("%s", contacts[num_contacts].number);
    num_contacts++;
}

void search_contact() {
    char name[MAX_NAME_LEN];
    printf("Enter contact name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Contact found: %s - %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }
    printf("Contact not found.\n");
}

void delete_contact() {
    char name[MAX_NAME_LEN];
    printf("Enter contact name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            memmove(&contacts[i], &contacts[i+1], (num_contacts - i - 1) * sizeof(Contact));
            num_contacts--;
            break;
        }
    }
}

void print_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].number);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        printf("4. Print contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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