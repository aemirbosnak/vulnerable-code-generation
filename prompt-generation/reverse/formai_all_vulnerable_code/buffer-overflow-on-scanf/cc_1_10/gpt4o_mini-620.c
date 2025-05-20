//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "contacts.txt"
#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void add_contact();
void view_contacts();
void delete_contact();
void clear_buffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        clear_buffer(); // Clear buffer to avoid issues with fgets

        switch (choice) {
            case 1: add_contact(); break;
            case 2: view_contacts(); break;
            case 3: delete_contact(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void add_contact() {
    Contact new_contact;
    FILE *file;

    printf("Enter Name: ");
    fgets(new_contact.name, NAME_LENGTH, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0; // Remove new line character

    printf("Enter Phone: ");
    fgets(new_contact.phone, PHONE_LENGTH, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = 0; // Remove new line character

    file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s,%s\n", new_contact.name, new_contact.phone);
    fclose(file);
    printf("Contact added successfully.\n");
}

void view_contacts() {
    FILE *file;
    char line[256];

    file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- List of Contacts ---\n");
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, ",");

        if (phone != NULL) {
            printf("Name: %s, Phone: %s", name, phone);
        }
    }
    fclose(file);
}

void delete_contact() {
    FILE *file, *temp;
    Contact current_contact;
    char name_to_delete[NAME_LENGTH];
    int found = 0;

    printf("Enter the name of the contact to delete: ");
    fgets(name_to_delete, NAME_LENGTH, stdin);
    name_to_delete[strcspn(name_to_delete, "\n")] = 0;

    file = fopen(FILENAME, "r");
    temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fgets(current_contact.name, sizeof(current_contact.name), file)) {
        strtok(current_contact.name, ","); // Get only name part
        if (strcmp(strtok(current_contact.name, ","), name_to_delete) != 0) {
            fprintf(temp, "%s", current_contact.name);
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Contact deleted successfully.\n");
    } else {
        printf("Contact not found.\n");
        remove("temp.txt");
    }
}

void clear_buffer() {
    while (getchar() != '\n'); // Clear input buffer
}