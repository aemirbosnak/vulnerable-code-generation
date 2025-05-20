//FormAI DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    char email[50];
} Contact;

void read_contact(Contact* contact) {
    contact->id = 0;
    printf("Enter name: ");
    scanf("%s", contact->name);
    printf("Enter email: ");
    scanf("%s", contact->email);
}

void print_contact(Contact contact) {
    printf("ID: %d, Name: %s, Email: %s\n", contact.id, contact.name, contact.email);
}

void create_table() {
    FILE* fp = fopen("contacts.db", "w");
    fclose(fp);
}

void insert_contact(Contact contact) {
    FILE* fp = fopen("contacts.db", "a");
    fprintf(fp, "%d %s %s\n", contact.id, contact.name, contact.email);
    fclose(fp);
}

void list_contacts() {
    FILE* fp = fopen("contacts.db", "r");
    Contact contact;
    while (fscanf(fp, "%d %s %s\n", &contact.id, contact.name, contact.email) != EOF) {
        print_contact(contact);
    }
    fclose(fp);
}

void delete_contact(int id) {
    FILE* fp = fopen("contacts.db", "r");
    FILE* tmp = fopen("tmp.db", "w");
    Contact contact;
    int found = 0;
    while (fscanf(fp, "%d %s %s\n", &contact.id, contact.name, contact.email) != EOF) {
        if (contact.id != id) {
            fprintf(tmp, "%d %s %s\n", contact.id, contact.name, contact.email);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(tmp);
    if (found) {
        remove("contacts.db");
        rename("tmp.db", "contacts.db");
    } else {
        remove("tmp.db");
    }
}

int main() {
    create_table();
    int choice;
    do {
        printf("\nCONTACTS DATABASE\n");
        printf("1. Add contact\n");
        printf("2. List contacts\n");
        printf("3. Delete contact\n");
        printf("0. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Contact contact;
                read_contact(&contact);
                insert_contact(contact);
                printf("Contact added!\n");
                break;
            }
            case 2: {
                list_contacts();
                break;
            }
            case 3: {
                int id;
                printf("Enter ID of contact to delete: ");
                scanf("%d", &id);
                delete_contact(id);
                printf("Contact deleted!\n");
                break;
            }
            case 0:
                printf("Bye!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}