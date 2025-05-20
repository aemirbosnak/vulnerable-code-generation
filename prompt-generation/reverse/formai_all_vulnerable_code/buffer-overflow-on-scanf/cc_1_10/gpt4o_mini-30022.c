//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

void add_contact(Contact contacts[], int *count);
void display_contacts(const Contact contacts[], int count);
void save_contacts_to_file(const Contact contacts[], int count);
void load_contacts_from_file(Contact contacts[], int *count);
void clear_screen();

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    load_contacts_from_file(contacts, &count);

    while (1) {
        clear_screen();
        printf("Simple Address Book\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Save Contacts to File\n");
        printf("4. Load Contacts from File\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                add_contact(contacts, &count);
                break;
            case 2:
                display_contacts(contacts, count);
                break;
            case 3:
                save_contacts_to_file(contacts, count);
                break;
            case 4:
                load_contacts_from_file(contacts, &count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("Press Enter to continue...\n");
        getchar(); // wait for user to press Enter
    }

    return 0;
}

void add_contact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Address book is full! Cannot add more contacts.\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[*count].name, NAME_LEN, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0; // remove newline

    printf("Enter phone: ");
    fgets(contacts[*count].phone, PHONE_LEN, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0; // remove newline

    (*count)++;
    printf("Contact added successfully!\n");
}

void display_contacts(const Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts to display...\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < count; i++) {
        printf("Contact %d: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void save_contacts_to_file(const Contact contacts[], int count) {
    FILE *file = fopen("contacts.txt", "w");
    if (!file) {
        printf("Unable to open file for writing!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n", contacts[i].name, contacts[i].phone);
    }
    fclose(file);
    printf("Contacts saved successfully to contacts.txt!\n");
}

void load_contacts_from_file(Contact contacts[], int *count) {
    FILE *file = fopen("contacts.txt", "r");
    if (!file) {
        printf("No contacts file found. Starting a new contact list...\n");
        return;
    }

    while (fgets(contacts[*count].name, NAME_LEN, file) && *count < MAX_CONTACTS) {
        contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0; // remove newline
        fgets(contacts[*count].phone, PHONE_LEN, file);
        contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0; // remove newline
        (*count)++;
    }

    fclose(file);
    printf("Contacts loaded successfully from contacts.txt!\n");
}

void clear_screen() {
    // Linux/Unix specific command to clear screen
    printf("\033[H\033[J");
}