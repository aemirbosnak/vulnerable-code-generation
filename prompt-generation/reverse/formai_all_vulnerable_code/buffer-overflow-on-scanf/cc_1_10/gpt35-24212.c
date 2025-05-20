//FormAI DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} contact;

void print_contacts(contact contacts[], int num_contacts) {
    printf("Contact List:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s, %s, %s\n", i+1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
    printf("\n");
}

void add_contact(contact contacts[], int *num_contacts) {
    printf("Enter contact name: ");
    scanf("%s", contacts[*num_contacts].name);
    printf("Enter contact phone: ");
    scanf("%s", contacts[*num_contacts].phone);
    printf("Enter contact email: ");
    scanf("%s", contacts[*num_contacts].email);
    (*num_contacts)++;
}

void remove_contact(contact contacts[], int *num_contacts) {
    printf("Enter contact number to delete: ");
    int num;
    scanf("%d", &num);
    if (num < 1 || num > *num_contacts) {
        printf("Invalid contact number.\n\n");
        return;
    }
    for (int i = num-1; i < *num_contacts-1; i++) {
        contacts[i] = contacts[i+1];
    }
    (*num_contacts)--;
    printf("Contact deleted.\n\n");
}

void search_contact(contact contacts[], int num_contacts) {
    printf("Enter name to search: ");
    char name[50];
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found.\n");
            printf("%s, %s, %s\n\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            return;
        }
    }
    printf("Contact not found.\n\n");
}

void save_contacts(contact contacts[], int num_contacts) {
    FILE *file = fopen("contacts.txt", "w");
    for (int i = 0; i < num_contacts; i++) {
        fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
    fclose(file);
    printf("Contacts saved to contacts.txt.\n\n");
}

void load_contacts(contact contacts[], int *num_contacts) {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("No contacts found.\n\n");
        return;
    }
    *num_contacts = 0;
    char line[100];
    while (fgets(line, 100, file)) {
        sscanf(line, "%[^,],%[^,],%[^,]", contacts[*num_contacts].name, contacts[*num_contacts].phone, contacts[*num_contacts].email);
        (*num_contacts)++;
    }
    fclose(file);
    printf("Contacts loaded from contacts.txt.\n\n");
}

int main() {
    contact contacts[100];
    int num_contacts = 0;
    char command;
    do {
        printf("Enter command (p/r/s/a/q): ");
        scanf(" %c", &command);
        switch (command) {
            case 'p':
                print_contacts(contacts, num_contacts);
                break;
            case 'r':
                remove_contact(contacts, &num_contacts);
                break;
            case 's':
                search_contact(contacts, num_contacts);
                break;
            case 'a':
                add_contact(contacts, &num_contacts);
                break;
            case 'q':
                save_contacts(contacts, num_contacts);
                printf("Exiting Phone Book.\n");
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    } while (command != 'q');
    return 0;
}