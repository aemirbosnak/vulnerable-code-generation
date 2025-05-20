//FormAI DATASET v1.0 Category: Phone Book ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 20
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} Contact;

void print_menu() {
    printf("\n--Phone Book Menu--\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact\n");
    printf("4. Print All Contacts\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
}

void add_contact(Contact* contacts, int* num_contacts) {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
    printf("\nEnter name: ");
    scanf("%s", name);
    printf("Enter number: ");
    scanf("%s", number);
    if (*num_contacts == MAX_CONTACTS) {
        printf("Error: Phone book is full.\n");
        return;
    }
    strcpy(contacts[*num_contacts].name, name);
    strcpy(contacts[*num_contacts].number, number);
    (*num_contacts)++;
    printf("Contact added successfully.\n");
}

void delete_contact(Contact* contacts, int* num_contacts) {
    char name[MAX_NAME_LEN];
    printf("\nEnter name of contact to delete: ");
    scanf("%s", name);
    int i, j;
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (j = i; j < *num_contacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*num_contacts)--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    printf("Error: Contact not found.\n");
}

void search_contact(Contact* contacts, int num_contacts) {
    char name[MAX_NAME_LEN];
    printf("\nEnter name of contact to search for: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("%s: %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }
    printf("Error: Contact not found.\n");
}

void print_all_contacts(Contact* contacts, int num_contacts) {
    int i;
    printf("\n--All Contacts--\n");
    for (i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].number);
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                delete_contact(contacts, &num_contacts);
                break;
            case 3:
                search_contact(contacts, num_contacts);
                break;
            case 4:
                print_all_contacts(contacts, num_contacts);
                break;
            case 5:
                printf("Quitting phone book.\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}