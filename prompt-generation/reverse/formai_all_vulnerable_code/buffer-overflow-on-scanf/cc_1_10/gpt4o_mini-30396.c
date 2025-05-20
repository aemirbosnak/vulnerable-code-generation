//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: mind-bending
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

void addContact(PhoneBook *pb, const char *name, const char *phone) {
    if (pb->count < MAX_CONTACTS) {
        strncpy(pb->contacts[pb->count].name, name, NAME_LENGTH);
        strncpy(pb->contacts[pb->count].phone, phone, PHONE_LENGTH);
        pb->count++;
        printf("Contact added: %s - %s\n", name, phone);
    } else {
        printf("Phone book is full!\n");
    }
}

void listContacts(const PhoneBook *pb) {
    printf("\n--- Phone Book Contacts ---\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d. %s - %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
    printf("----------------------------\n");
}

void searchContact(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            printf("Found: %s - %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact(PhoneBook *pb, const char *name) {
    int found = 0;
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            printf("Deleted contact: %s\n", name);
            break;
        }
    }
    if (!found) {
        printf("Contact not found to delete.\n");
    }
}

void saveToFile(const PhoneBook *pb, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < pb->count; i++) {
            fprintf(file, "%s,%s\n", pb->contacts[i].name, pb->contacts[i].phone);
        }
        fclose(file);
        printf("Contacts saved to %s\n", filename);
    } else {
        printf("Error saving to file.\n");
    }
}

void loadFromFile(PhoneBook *pb, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        pb->count = 0;
        char line[100];
        while (fgets(line, sizeof(line), file) && pb->count < MAX_CONTACTS) {
            char *token = strtok(line, ",");
            if (token) {
                strncpy(pb->contacts[pb->count].name, token, NAME_LENGTH);
                token = strtok(NULL, "\n");
                if (token) {
                    strncpy(pb->contacts[pb->count].phone, token, PHONE_LENGTH);
                    pb->count++;
                }
            }
        }
        fclose(file);
        printf("Contacts loaded from %s\n", filename);
    } else {
        printf("Error loading from file.\n");
    }
}

int main() {
    PhoneBook pb = { .count = 0 };
    int choice;
    char name[NAME_LENGTH], phone[PHONE_LENGTH];
    char filename[] = "phonebook.txt";

    loadFromFile(&pb, filename);

    do {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save Contacts\n");
        printf("6. Load Contacts\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                printf("Enter phone: ");
                fgets(phone, PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = 0; // remove newline
                addContact(&pb, name, phone);
                break;
            case 2:
                listContacts(&pb);
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                searchContact(&pb, name);
                break;
            case 4:
                printf("Enter name to delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                deleteContact(&pb, name);
                break;
            case 5:
                saveToFile(&pb, filename);
                break;
            case 6:
                loadFromFile(&pb, filename);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, try again.\n");
        }
    } while (choice != 0);

    return 0;
}