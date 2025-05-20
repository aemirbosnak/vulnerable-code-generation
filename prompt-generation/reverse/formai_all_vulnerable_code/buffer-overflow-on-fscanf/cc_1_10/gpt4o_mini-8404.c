//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: scalable
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

void initPhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

void addContact(PhoneBook *pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    printf("Enter Name: ");
    scanf(" %[^\n]", pb->contacts[pb->count].name);
    printf("Enter Phone: ");
    scanf(" %[^\n]", pb->contacts[pb->count].phone);
    pb->count++;
    printf("Contact added successfully!\n");
}

void displayContacts(const PhoneBook *pb) {
    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
}

int findContact(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void updateContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to update: ");
    scanf(" %[^\n]", name);

    int index = findContact(pb, name);
    if (index != -1) {
        printf("Enter new Phone: ");
        scanf(" %[^\n]", pb->contacts[index].phone);
        printf("Contact updated successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

void deleteContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", name);

    int index = findContact(pb, name);
    if (index != -1) {
        for (int i = index; i < pb->count - 1; i++) {
            pb->contacts[i] = pb->contacts[i + 1];
        }
        pb->count--;
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

void saveContactsToFile(const PhoneBook *pb, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving!\n");
        return;
    }
    for (int i = 0; i < pb->count; i++) {
        fprintf(file, "%s,%s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
    fclose(file);
    printf("Contacts saved successfully!\n");
}

void loadContactsFromFile(PhoneBook *pb, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for loading!\n");
        return;
    }
    while (fscanf(file, " %[^\n],%[^\n]", pb->contacts[pb->count].name, pb->contacts[pb->count].phone) != EOF) {
        pb->count++;
        if (pb->count >= MAX_CONTACTS) {
            break;
        }
    }
    fclose(file);
    printf("Contacts loaded successfully!\n");
}

void displayMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Update Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Save Contacts\n");
    printf("6. Load Contacts\n");
    printf("7. Exit\n");
}

int main() {
    PhoneBook phoneBook;
    initPhoneBook(&phoneBook);
    char filename[] = "contacts.txt";
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(&phoneBook);
                break;
            case 2:
                displayContacts(&phoneBook);
                break;
            case 3:
                updateContact(&phoneBook);
                break;
            case 4:
                deleteContact(&phoneBook);
                break;
            case 5:
                saveContactsToFile(&phoneBook, filename);
                break;
            case 6:
                loadContactsFromFile(&phoneBook, filename);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}