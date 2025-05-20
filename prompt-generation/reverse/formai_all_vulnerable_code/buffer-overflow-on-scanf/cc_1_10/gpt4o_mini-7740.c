//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
};

struct PhoneBook {
    struct Contact entries[MAX_ENTRIES];
    int size;
};

void initPhoneBook(struct PhoneBook* pb) {
    pb->size = 0;
}

void addContact(struct PhoneBook* pb, const char* name, const char* phone) {
    if (pb->size < MAX_ENTRIES) {
        strncpy(pb->entries[pb->size].name, name, NAME_LENGTH - 1);
        strncpy(pb->entries[pb->size].phone, phone, PHONE_LENGTH - 1);
        pb->entries[pb->size].name[NAME_LENGTH - 1] = '\0'; // Ensure null-termination
        pb->entries[pb->size].phone[PHONE_LENGTH - 1] = '\0'; // Ensure null-termination
        pb->size++;
        printf("Added contact: %s, Phone: %s\n", name, phone);
    } else {
        printf("Phone Book is full! Cannot add more contacts.\n");
    }
}

void displayContacts(const struct PhoneBook* pb) {
    if (pb->size == 0) {
        printf("The phone book is empty.\n");
        return;
    }
    
    printf("Phone Book Entries:\n");
    for (int i = 0; i < pb->size; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, pb->entries[i].name, pb->entries[i].phone);
    }
}

void searchContact(const struct PhoneBook* pb, const char* name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            printf("Found contact: Name: %s, Phone: %s\n", pb->entries[i].name, pb->entries[i].phone);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

void deleteContact(struct PhoneBook* pb, const char* name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            for (int j = i; j < pb->size - 1; j++) {
                pb->entries[j] = pb->entries[j + 1];
            }
            pb->size--;
            printf("Deleted contact: %s\n", name);
            return;
        }
    }
    printf("Contact not found, cannot delete: %s\n", name);
}

void savePhoneBook(const struct PhoneBook* pb, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for saving.\n");
        return;
    }
    
    fwrite(pb, sizeof(struct PhoneBook), 1, file);
    fclose(file);
    printf("Phone book saved to %s\n", filename);
}

void loadPhoneBook(struct PhoneBook* pb, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for loading.\n");
        return;
    }
    
    fread(pb, sizeof(struct PhoneBook), 1, file);
    fclose(file);
    printf("Phone book loaded from %s\n", filename);
}

int main() {
    struct PhoneBook pb;
    initPhoneBook(&pb);

    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char filename[] = "phonebook.dat";

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save Phone Book\n");
        printf("6. Load Phone Book\n");
        printf("7. Exit\n");
        printf("Select an option: ");
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
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteContact(&pb, name);
                break;
            case 5:
                savePhoneBook(&pb, filename);
                break;
            case 6:
                loadPhoneBook(&pb, filename);
                break;
            case 7:
                printf("Exiting phone book application.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}