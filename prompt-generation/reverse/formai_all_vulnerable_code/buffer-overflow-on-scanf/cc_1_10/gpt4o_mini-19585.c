//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: happy
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

void addContact();
void viewContacts();
void deleteContact();
void clearScreen();

int main() {
    int choice;

    while (1) {
        clearScreen();
        printf("🎉 Welcome to Contact Manager! 🎉\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

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
                printf("😊 Thank you for using Contact Manager! Goodbye! 😊\n");
                exit(0);
            default:
                printf("🚫 Invalid choice. Please try again!\n");
                break;
        }

        printf("Press Enter to continue...");
        getchar();
    }
    return 0;
}

void addContact() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("❌ Unable to open file!\n");
        return;
    }

    Contact newContact;
    printf("Enter contact name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Remove newline

    printf("Enter contact phone: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0'; // Remove newline

    fprintf(file, "%s,%s\n", newContact.name, newContact.phone);
    fclose(file);
    printf("✅ Contact added successfully!\n");
}

void viewContacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("❌ Unable to open file!\n");
        return;
    }

    char line[NAME_LENGTH + PHONE_LENGTH + 2]; // Name + Phone + comma + newline
    printf("📜 Your Contacts:\n");
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, ",");
        printf("Name: %s, Phone: %s", name, phone);
    }
    
    fclose(file);
}

void deleteContact() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("❌ Unable to open file!\n");
        return;
    }

    Contact contacts[MAX_CONTACTS];
    int count = 0;

    while (fscanf(file, "%[^,],%s\n", contacts[count].name, contacts[count].phone) != EOF) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("😢 No contacts to delete!\n");
        return;
    }

    printf("📜 Your Contacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s", i + 1, contacts[i].name, contacts[i].phone);
    }

    int index;
    printf("Enter the number of the contact to delete: ");
    scanf("%d", &index);
    getchar(); // Consume newline

    if (index < 1 || index > count) {
        printf("🚫 Invalid number! No contact deleted.\n");
        return;
    }

    file = fopen(FILE_NAME, "w"); // Open file for writing (to overwrite)
    for (int i = 0; i < count; i++) {
        if (i != index - 1) { // Skip the contact to delete
            fprintf(file, "%s,%s\n", contacts[i].name, contacts[i].phone);
        }
    }
    fclose(file);
    printf("✅ Contact deleted successfully!\n");
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the console
}