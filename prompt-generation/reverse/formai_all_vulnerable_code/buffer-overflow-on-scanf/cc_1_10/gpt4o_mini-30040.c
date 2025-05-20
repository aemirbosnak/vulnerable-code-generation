//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define NUMBER_LENGTH 15
#define FILE_NAME "phonebook.dat"

typedef struct {
    char name[NAME_LENGTH];
    char number[NUMBER_LENGTH];
} Contact;

void displayContacts(Contact contacts[], int count) {
    printf("========================================\n");
    printf("       🥀 Cyberpunk Phone Book 🥀       \n");
    printf("========================================\n");
    for (int i = 0; i < count; i++) {
        printf("Contact %d: %s - %s\n", i + 1, contacts[i].name, contacts[i].number);
    }
    printf("========================================\n");
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("⚠️ Cannot add more contacts! Phone book is full.\n");
        return;
    }
    printf("🔦 Enter the name of the contact: ");
    scanf("%s", contacts[*count].name);
    printf("📞 Enter the number of the contact: ");
    scanf("%s", contacts[*count].number);
    (*count)++;
    printf("✅ Contact added: %s - %s\n", contacts[*count - 1].name, contacts[*count - 1].number);
}

void searchContact(Contact contacts[], int count) {
    char name[NAME_LENGTH];
    printf("🔍 Enter the name to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("📡 Found: %s - %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }
    printf("❌ Contact not found!\n");
}

void deleteContact(Contact contacts[], int *count) {
    char name[NAME_LENGTH];
    printf("🗑️  Enter the name of the contact to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("✅ Deleted contact: %s\n", name);
            return;
        }
    }
    printf("❌ Contact not found for deletion!\n");
}

void saveContactsToFile(Contact contacts[], int count) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("⚠️ Error saving contacts...\n");
        return;
    }
    fwrite(contacts, sizeof(Contact), count, file);
    fclose(file);
    printf("💾 Contacts saved to %s\n", FILE_NAME);
}

int loadContactsFromFile(Contact contacts[]) {
    FILE *file = fopen(FILE_NAME, "rb");
    int count = 0;
    if (file != NULL) {
        count = fread(contacts, sizeof(Contact), MAX_CONTACTS, file);
        fclose(file);
    }
    return count;
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = loadContactsFromFile(contacts);
    int choice;

    do {
        printf("\n========================================\n");
        printf("    🦾 Cyberpunk Phone Book Menu 🦾   \n");
        printf("========================================\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Save Contacts\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                searchContact(contacts, count);
                break;
            case 3:
                deleteContact(contacts, &count);
                break;
            case 4:
                displayContacts(contacts, count);
                break;
            case 5:
                saveContactsToFile(contacts, count);
                break;
            case 6:
                printf("🚀 Exiting Cyberpunk Phone Book. Stay safe out there!\n");
                break;
            default:
                printf("❗ Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}