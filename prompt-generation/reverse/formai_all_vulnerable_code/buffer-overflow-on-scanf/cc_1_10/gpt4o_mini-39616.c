//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "contacts.txt"
#define MAX_CONTACTS 100
#define NAME_SIZE 50
#define PHONE_SIZE 15

typedef struct {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
} Contact;

void addContact();
void viewContacts();
void deleteContact();
int contactExists(const char *name);

int main() {
    int choice;

    while (1) {
        printf("Contact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline character

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addContact() {
    FILE *file;
    Contact contact;

    printf("Enter name: ");
    fgets(contact.name, NAME_SIZE, stdin);
    contact.name[strcspn(contact.name, "\n")] = '\0'; // Remove newline

    printf("Enter phone number: ");
    fgets(contact.phone, PHONE_SIZE, stdin);
    contact.phone[strcspn(contact.phone, "\n")] = '\0'; // Remove newline

    if (contactExists(contact.name)) {
        printf("Contact already exists!\n");
        return;
    }

    file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }
    fprintf(file, "%s:%s\n", contact.name, contact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

void viewContacts() {
    FILE *file;
    char line[NAME_SIZE + PHONE_SIZE + 2]; // Enough to hold a single line of "name:phone"

    file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("\nContacts:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, ":");
        if (token != NULL) {
            printf("Name: %s, Phone: ", token);
            token = strtok(NULL, "\n");
            if (token != NULL) {
                printf("%s\n", token);
            }
        }
    }
    fclose(file);
}

void deleteContact() {
    FILE *file, *tempFile;
    char name[NAME_SIZE];
    char line[NAME_SIZE + PHONE_SIZE + 2];
    int found = 0;

    printf("Enter the name of the contact to delete: ");
    fgets(name, NAME_SIZE, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Unable to create temporary file");
        fclose(file);
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, ":");
        if (token != NULL && strcmp(token, name) != 0) {
            fprintf(tempFile, "%s", line); // Write to temp if not the contact to delete
        } else if (token != NULL) {
            found = 1; // Mark as found for user feedback
        }
    }

    fclose(file);
    fclose(tempFile);
    
    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
        remove("temp.txt"); // Clean up temporary file if not found
    }
}

int contactExists(const char *name) {
    FILE *file;
    char line[NAME_SIZE + PHONE_SIZE + 2];

    file = fopen(FILENAME, "r");
    if (file == NULL) {
        return 0; // If the file does not exist, return false
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, ":");
        if (token != NULL && strcmp(token, name) == 0) {
            fclose(file);
            return 1; // Contact exists
        }
    }
    
    fclose(file);
    return 0; // Contact does not exist
}