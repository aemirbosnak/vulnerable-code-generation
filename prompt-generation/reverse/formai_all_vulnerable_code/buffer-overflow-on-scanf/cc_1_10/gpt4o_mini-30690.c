//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook* pb) {
    pb->count = 0;
}

void addContact(PhoneBook* pb, const char* name, const char* phone) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Phonebook is full, cannot add more contacts.\n");
        return;
    }
    strcpy(pb->contacts[pb->count].name, name);
    strcpy(pb->contacts[pb->count].phone, phone);
    pb->count++;
    printf("Contact added: %s, %s\n", name, phone);
}

void displayContacts(const PhoneBook* pb) {
    if (pb->count == 0) {
        printf("Phonebook is empty.\n");
        return;
    }
    printf("\n--- Phonebook Contacts ---\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Contact %d: %s, %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
    printf("---------------------------\n");
}

void searchContact(const PhoneBook* pb, const char* name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            printf("Contact found: %s, %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact \"%s\" not found.\n", name);
}

void deleteContact(PhoneBook* pb, const char* name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            // Shift the remaining contacts left
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            printf("Contact \"%s\" deleted successfully.\n", name);
            return;
        }
    }
    printf("Contact \"%s\" not found for deletion.\n", name);
}

void saveContactsToFile(const PhoneBook* pb, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }
    for (int i = 0; i < pb->count; i++) {
        fprintf(file, "%s,%s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
    fclose(file);
    printf("Contacts saved to \"%s\".\n", filename);
}

void loadContactsFromFile(PhoneBook* pb, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), file) && pb->count < MAX_CONTACTS) {
        char* name = strtok(line, ",");
        char* phone = strtok(NULL, "\n"); // Remove newline character
        if (name && phone) {
            addContact(pb, name, phone);
        }
    }
    fclose(file);
    printf("Contacts loaded from \"%s\".\n", filename);
}

int main() {
    PhoneBook phoneBook;
    initializePhoneBook(&phoneBook);
    
    int choice;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    const char* filename = "contacts.txt";

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save Contacts to File\n");
        printf("6. Load Contacts from File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                strtok(name, "\n"); // Remove newline
                printf("Enter phone: ");
                fgets(phone, MAX_PHONE_LENGTH, stdin);
                strtok(phone, "\n"); // Remove newline
                addContact(&phoneBook, name, phone);
                break;
            case 2:
                displayContacts(&phoneBook);
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                strtok(name, "\n"); // Remove newline
                searchContact(&phoneBook, name);
                break;
            case 4:
                printf("Enter name to delete: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                strtok(name, "\n"); // Remove newline
                deleteContact(&phoneBook, name);
                break;
            case 5:
                saveContactsToFile(&phoneBook, filename);
                break;
            case 6:
                loadContactsFromFile(&phoneBook, filename);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}