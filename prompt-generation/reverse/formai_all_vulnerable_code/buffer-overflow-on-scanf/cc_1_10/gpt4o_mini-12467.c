//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15
#define FILE_NAME "contacts.txt"

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

// Function prototypes
void add_contact();
void view_contacts();
void delete_contact();
void display_contacts();
void save_contacts(Contact contacts[], int count);
int load_contacts(Contact contacts[]);

int main() {
    int choice;

    while (1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add new contact\n");
        printf("2. View all contacts\n");
        printf("3. Delete a contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void add_contact() {
    Contact new_contact;
    FILE *file;

    printf("Enter name: ");
    fgets(new_contact.name, NAME_LEN, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0;  // Remove newline

    printf("Enter phone number: ");
    fgets(new_contact.phone, PHONE_LEN, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = 0;  // Remove newline

    file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%s,%s\n", new_contact.name, new_contact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

void view_contacts() {
    Contact contacts[MAX_CONTACTS];
    int count = load_contacts(contacts);
    display_contacts(contacts, count);
}

void delete_contact() {
    char name[NAME_LEN];
    Contact contacts[MAX_CONTACTS];
    int count = load_contacts(contacts);
    
    printf("Enter the name of the contact to delete: ");
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0;  // Remove newline

    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            found = 1;
            printf("Contact %s deleted successfully!\n", name);
            continue;  // Skip writing this contact
        }
        fprintf(file, "%s,%s\n", contacts[i].name, contacts[i].phone);
    }
    
    fclose(file);
    if (!found) {
        printf("Contact %s not found!\n", name);
    }
}

void display_contacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts found!\n");
        return;
    }

    printf("\n--- List of Contacts ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
    }
}

int load_contacts(Contact contacts[]) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return 0;  // File doesn't exist, return count as 0
    }

    int count = 0;
    while (fgets(contacts[count].name, NAME_LEN, file) != NULL) {
        contacts[count].name[strcspn(contacts[count].name, "\n")] = 0;  // Remove newline
        fgets(contacts[count].phone, PHONE_LEN, file);
        contacts[count].phone[strcspn(contacts[count].phone, "\n")] = 0;  // Remove newline
        count++;
        if (count >= MAX_CONTACTS) break;  // Prevent overflow
    }

    fclose(file);
    return count;
}