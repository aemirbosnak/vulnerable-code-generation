//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_PHONE_LEN 15
#define MAX_CONTACTS 100

struct Contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
};

void add_contact(FILE *file);
void view_contacts(FILE *file);
void delete_contact(FILE *file);
void save_contacts_to_file(struct Contact *contacts, int count);
void load_contacts_from_file(struct Contact *contacts, int *count);
void display_menu();
int get_choice();

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int count = 0;
    FILE *file = fopen("contacts.txt", "a+");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    load_contacts_from_file(contacts, &count);
    int choice;
    do {
        display_menu();
        choice = get_choice();
        
        switch (choice) {
            case 1:
                add_contact(file);
                count++;
                break;
            case 2:
                view_contacts(file);
                break;
            case 3:
                delete_contact(file);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    save_contacts_to_file(contacts, count);
    fclose(file);
    return EXIT_SUCCESS;
}

void display_menu() {
    printf("\n--- Contact Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
}

int get_choice() {
    int choice;
    scanf("%d", &choice);
    getchar(); // consume newline
    return choice;
}

void add_contact(FILE *file) {
    struct Contact new_contact;
    printf("Enter contact name: ");
    fgets(new_contact.name, MAX_NAME_LEN, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0; // remove newline

    printf("Enter contact phone: ");
    fgets(new_contact.phone, MAX_PHONE_LEN, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = 0; // remove newline

    fprintf(file, "%s;%s\n", new_contact.name, new_contact.phone);
    printf("Contact added successfully.\n");
}

void view_contacts(FILE *file) {
    rewind(file);
    char buffer[256];
    printf("\n--- Contacts ---\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        char *name = strtok(buffer, ";");
        char *phone = strtok(NULL, ";");
        printf("Name: %s, Phone: %s\n", name, phone);
    }
}

void delete_contact(FILE *file) {
    struct Contact contacts[MAX_CONTACTS];
    char name_to_delete[MAX_NAME_LEN];
    int count = 0;

    rewind(file);
    // Load existing contacts into memory
    while (fgets(contacts[count].name, sizeof(contacts[count].name), file)) {
        strtok(contacts[count].name, ";"); // Separate name
        char *phone = strtok(NULL, ";");
        if (phone != NULL) {
            strtok(phone, "\n"); // Remove newline
            strcpy(contacts[count].phone, phone);
            count++;
        }
    }

    printf("Enter the name of the contact to delete: ");
    fgets(name_to_delete, MAX_NAME_LEN, stdin);
    name_to_delete[strcspn(name_to_delete, "\n")] = 0; // remove newline

    // Create a new file to store contacts except the one deleted
    FILE *temp_file = fopen("temp_contacts.txt", "w");
    if (!temp_file) {
        perror("Failed to open temp file");
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name_to_delete) != 0) {
            fprintf(temp_file, "%s;%s\n", contacts[i].name, contacts[i].phone);
        } else {
            found = 1;
        }
    }

    if (found) {
        printf("Contact '%s' deleted successfully.\n", name_to_delete);
    } else {
        printf("Contact '%s' not found.\n", name_to_delete);
    }

    fclose(temp_file);
    remove("contacts.txt");
    rename("temp_contacts.txt", "contacts.txt");
}

void save_contacts_to_file(struct Contact *contacts, int count) {
    FILE *file = fopen("contacts.txt", "w");
    if (file) {
        for (int i = 0; i < count; i++) {
            fprintf(file, "%s;%s\n", contacts[i].name, contacts[i].phone);
        }
        fclose(file);
    }
}

void load_contacts_from_file(struct Contact *contacts, int *count) {
    FILE *file = fopen("contacts.txt", "r");
    if (!file) {
        return; // No previous contacts
    }

    while (fgets(contacts[*count].name, sizeof(contacts[*count].name), file)) {
        strtok(contacts[*count].name, ";"); // Separate name
        char *phone = strtok(NULL, ";");
        if (phone != NULL) {
            strtok(phone, "\n"); // Remove newline
            strcpy(contacts[*count].phone, phone);
            (*count)++;
        }
    }

    fclose(file);
}