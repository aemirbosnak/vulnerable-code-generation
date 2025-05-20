//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15
#define FILE_NAME "phonebook.txt"

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

void addContact();
void displayContacts();
void searchContact();
void deleteContact();
void loadContacts();
void saveContacts(Contact contacts[], int count);
void clearInputBuffer();

int main() {
    int choice;

    do {
        printf("\n=== Phone Book ===\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("===================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

void addContact() {
    Contact newContact;
    FILE *file;

    printf("Enter name: ");
    fgets(newContact.name, NAME_LEN, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline
    printf("Enter phone number: ");
    fgets(newContact.phone, PHONE_LEN, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline

    file = fopen(FILE_NAME, "a");
    if(file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }
    fprintf(file, "%s,%s\n", newContact.name, newContact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

void displayContacts() {
    FILE *file;
    char line[100];

    file = fopen(FILE_NAME, "r");
    if(file == NULL) {
        fprintf(stderr, "Error opening file for reading.\n");
        return;
    }
    printf("\nContact List:\n");
    while(fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, ",");
        printf("Name: %s, Phone: %s\n", name, phone);
    }
    fclose(file);
}

void searchContact() {
    char searchName[NAME_LEN];
    FILE *file;
    char line[100];
    int found = 0;

    printf("Enter name to search: ");
    fgets(searchName, NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    file = fopen(FILE_NAME, "r");
    if(file == NULL) {
        fprintf(stderr, "Error opening file for reading.\n");
        return;
    }

    while(fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, ",");
        if (strcmp(name, searchName) == 0) {
            printf("Found: Name: %s, Phone: %s\n", name, phone);
            found = 1;
            break;
        }
    }

    fclose(file);
    if (!found) {
        printf("Contact not found!\n");
    }
}

void deleteContact() {
    char deleteName[NAME_LEN];
    FILE *file, *tempFile;
    char line[100];

    printf("Enter name to delete: ");
    fgets(deleteName, NAME_LEN, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0; // Remove newline

    file = fopen(FILE_NAME, "r");
    tempFile = fopen("temp.txt", "w");
    if(file == NULL || tempFile == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return;
    }

    int deleted = 0;
    while(fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        if (strcmp(name, deleteName) != 0) {
            fprintf(tempFile, "%s", line);
        } else {
            deleted = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (deleted) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}