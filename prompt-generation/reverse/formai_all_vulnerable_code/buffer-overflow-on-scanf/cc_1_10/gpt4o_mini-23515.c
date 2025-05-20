//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILE_NAME "contacts.txt"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int contact_count = 0;

// Function prototypes
void load_contacts();
void save_contacts();
void add_contact(const char *name, const char *phone);
void view_contacts();
void clear_buffer();

int main() {
    load_contacts();
    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];

    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer(); // Clear input buffer

        switch (choice) {
            case 1:
                if (contact_count < MAX_CONTACTS) {
                    printf("Enter Name: ");
                    fgets(name, NAME_LENGTH, stdin);
                    name[strcspn(name, "\n")] = 0; // Remove trailing newline
                    
                    printf("Enter Phone: ");
                    fgets(phone, PHONE_LENGTH, stdin);
                    phone[strcspn(phone, "\n")] = 0; // Remove trailing newline

                    add_contact(name, phone);
                } else {
                    printf("Contact list is full!\n");
                }
                break;

            case 2:
                view_contacts();
                break;

            case 3:
                save_contacts();
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

void load_contacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file) {
        while (fscanf(file, "%49[^,], %14s\n", contacts[contact_count].name, contacts[contact_count].phone) == 2) {
            contact_count++;
        }
        fclose(file);
    } else {
        printf("No existing contacts found. Starting fresh.\n");
    }
}

void save_contacts() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file) {
        for (int i = 0; i < contact_count; i++) {
            fprintf(file, "%s, %s\n", contacts[i].name, contacts[i].phone);
        }
        fclose(file);
    } else {
        printf("Failed to save contacts.\n");
    }
}

void add_contact(const char *name, const char *phone) {
    strcpy(contacts[contact_count].name, name);
    strcpy(contacts[contact_count].phone, phone);
    contact_count++;
    printf("Contact added!\n");
}

void view_contacts() {
    if (contact_count == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("\nContacts:\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void clear_buffer() {
    while (getchar() != '\n') {} // Clear the input buffer
}