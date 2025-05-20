//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILE_NAME "phonebook.dat"

struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
};

void add_contact(struct Contact contacts[], int *count);
void search_contact(struct Contact contacts[], int count);
void display_contacts(struct Contact contacts[], int count);
void save_contacts(struct Contact contacts[], int count);
void load_contacts(struct Contact contacts[], int *count);

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    load_contacts(contacts, &count);

    while (1) {
        printf("Phone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                add_contact(contacts, &count);
                break;
            case 2:
                search_contact(contacts, count);
                break;
            case 3:
                display_contacts(contacts, count);
                break;
            case 4:
                save_contacts(contacts, count);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_contact(struct Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Phone book is full, cannot add more contacts.\n");
        return;
    }
    
    printf("Enter name: ");
    fgets(contacts[*count].name, NAME_LENGTH, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(contacts[*count].phone, PHONE_LENGTH, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Contact added successfully.\n");
}

void search_contact(struct Contact contacts[], int count) {
    char name[NAME_LENGTH];

    printf("Enter name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact Found: %s, Phone Number: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void display_contacts(struct Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }
    
    printf("Contact List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void save_contacts(struct Contact contacts[], int count) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    fwrite(contacts, sizeof(struct Contact), count, file);
    fclose(file);
    printf("Contacts saved successfully.\n");
}

void load_contacts(struct Contact contacts[], int *count) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("No saved contacts found, starting fresh.\n");
        return;
    }
    *count = fread(contacts, sizeof(struct Contact), MAX_CONTACTS, file);
    fclose(file);
    printf("%d contacts loaded successfully.\n", *count);
}