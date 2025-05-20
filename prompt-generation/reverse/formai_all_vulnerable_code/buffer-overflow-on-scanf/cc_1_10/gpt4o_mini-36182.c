//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define FILENAME "address_book.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void add_contact();
void view_contacts();
void delete_contact();

int main() {
    int choice;

    while (1) {
        printf("\n==== Address Book ====\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

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
                printf("Thank you for using the Address Book!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}

void add_contact() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Contact new_contact;
    printf("Enter Name: ");
    fgets(new_contact.name, MAX_NAME_LENGTH, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = '\0'; // Remove newline

    printf("Enter Phone: ");
    fgets(new_contact.phone, MAX_PHONE_LENGTH, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = '\0'; // Remove newline

    fprintf(file, "%s|%s\n", new_contact.name, new_contact.phone);
    fclose(file);

    printf("Contact added successfully!\n");
}

void view_contacts() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("\n=== Contact List ===\n");
    char buffer[200];

    while (fgets(buffer, sizeof(buffer), file)) {
        char *name = strtok(buffer, "|");
        char *phone = strtok(NULL, "|");
        if (phone) {
            printf("Name: %s, Phone: %s", name, phone);
        }
    }
    fclose(file);
}

void delete_contact() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("Enter the name of the contact to delete: ");
    char name_to_delete[MAX_NAME_LENGTH];
    fgets(name_to_delete, MAX_NAME_LENGTH, stdin);
    name_to_delete[strcspn(name_to_delete, "\n")] = '\0'; // Remove newline

    FILE *temp_file = fopen("temp.txt", "w");
    if (!temp_file) {
        perror("Unable to open temporary file");
        fclose(file);
        return;
    }

    char buffer[200];
    int found = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        char *name = strtok(buffer, "|");
        if (strcmp(name, name_to_delete) != 0) {
            fprintf(temp_file, "%s", buffer);
        } else {
            found = 1;
        }
    }
    
    fclose(file);
    fclose(temp_file);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Contact deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("Contact not found!\n");
    }
}