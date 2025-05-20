//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_ENTRIES];
int entryCount = 0;

void addContact() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }
    printf("Enter name: ");
    fgets(phoneBook[entryCount].name, NAME_LENGTH, stdin);
    phoneBook[entryCount].name[strcspn(phoneBook[entryCount].name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(phoneBook[entryCount].phone, PHONE_LENGTH, stdin);
    phoneBook[entryCount].phone[strcspn(phoneBook[entryCount].phone, "\n")] = 0; // Remove newline

    entryCount++;
    printf("Contact added successfully!\n");
}

void viewContacts() {
    if (entryCount == 0) {
        printf("No contacts in the phone book!\n");
        return;
    }
    printf("\n--- Phone Book Contacts ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
    printf("---------------------------\n");
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < entryCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            printf("Found Contact: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < entryCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < entryCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            entryCount--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void saveContacts() {
    FILE *file = fopen("phonebook.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s,%s\n", phoneBook[i].name, phoneBook[i].phone);
    }
    fclose(file);
    printf("Contacts saved successfully!\n");
}

void loadContacts() {
    FILE *file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("No saved contacts found, starting fresh.\n");
        return;
    }
    while (fscanf(file, "%49[^,],%14[^\n]\n", phoneBook[entryCount].name, phoneBook[entryCount].phone) == 2) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) {
            break;
        }
    }
    fclose(file);
    printf("Contacts loaded successfully!\n");
}

void showMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Save Contacts\n");
    printf("6. Load Contacts\n");
    printf("7. Exit\n");
    printf("-----------------------\n");
}

int main() {
    int choice;

    loadContacts();

    do {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                saveContacts();
                break;
            case 6:
                loadContacts();
                break;
            case 7:
                printf("Exiting the phone book application. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}