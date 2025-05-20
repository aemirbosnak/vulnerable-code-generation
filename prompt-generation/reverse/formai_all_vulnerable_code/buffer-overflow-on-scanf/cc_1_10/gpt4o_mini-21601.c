//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
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
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    strncpy(pb->contacts[pb->count].name, name, NAME_LENGTH);
    strncpy(pb->contacts[pb->count].phone, phone, PHONE_LENGTH);
    pb->count++;
    printf("Contact added: %s - %s\n", name, phone);
}

void displayContacts(const PhoneBook* pb) {
    if (pb->count == 0) {
        printf("No contacts in the phone book.\n");
        return;
    }
    printf("\n=== Phone Book ===\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d. %s - %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
    printf("===================\n");
}

int findContactIndex(const PhoneBook* pb, const char* name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteContact(PhoneBook* pb, const char* name) {
    int index = findContactIndex(pb, name);
    if (index == -1) {
        printf("Contact '%s' not found.\n", name);
        return;
    }
    for (int i = index; i < pb->count - 1; i++) {
        pb->contacts[i] = pb->contacts[i + 1];
    }
    pb->count--;
    printf("Contact '%s' deleted.\n", name);
}

void searchContact(const PhoneBook* pb, const char* name) {
    int index = findContactIndex(pb, name);
    if (index == -1) {
        printf("Contact '%s' not found.\n", name);
    } else {
        printf("Contact found: %s - %s\n", pb->contacts[index].name, pb->contacts[index].phone);
    }
}

void updateContact(PhoneBook* pb, const char* name, const char* newPhone) {
    int index = findContactIndex(pb, name);
    if (index == -1) {
        printf("Contact '%s' not found. Update failed.\n", name);
        return;
    }
    strncpy(pb->contacts[index].phone, newPhone, PHONE_LENGTH);
    printf("Contact '%s' updated with new phone number: %s\n", name, newPhone);
}

void saveContactsToFile(const PhoneBook* pb, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for saving.\n");
        return;
    }
    for (int i = 0; i < pb->count; i++) {
        fprintf(file, "%s;%s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
    fclose(file);
    printf("Contacts saved to '%s'.\n", filename);
}

void loadContactsFromFile(PhoneBook* pb, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for loading.\n");
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), file) && pb->count < MAX_CONTACTS) {
        char* token = strtok(line, ";");
        if (token != NULL) {
            strncpy(pb->contacts[pb->count].name, token, NAME_LENGTH);
            token = strtok(NULL, "\n");
            if (token != NULL) {
                strncpy(pb->contacts[pb->count].phone, token, PHONE_LENGTH);
                pb->count++;
            }
        }
    }
    fclose(file);
    printf("Contacts loaded from '%s'.\n", filename);
}

void displayMenu() {
    printf("\n=== Phone Book Menu ===\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Update Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Save Contacts\n");
    printf("7. Load Contacts\n");
    printf("8. Exit\n");
    printf("=========================\n");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);
    
    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char filename[100];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                addContact(&pb, name, phone);
                break;
            case 2:
                displayContacts(&pb);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchContact(&pb, name);
                break;
            case 4:
                printf("Enter name to update: ");
                scanf("%s", name);
                printf("Enter new phone: ");
                scanf("%s", phone);
                updateContact(&pb, name, phone);
                break;
            case 5:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteContact(&pb, name);
                break;
            case 6:
                printf("Enter filename to save: ");
                scanf("%s", filename);
                saveContactsToFile(&pb, filename);
                break;
            case 7:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                loadContactsFromFile(&pb, filename);
                break;
            case 8:
                printf("Exiting phone book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}