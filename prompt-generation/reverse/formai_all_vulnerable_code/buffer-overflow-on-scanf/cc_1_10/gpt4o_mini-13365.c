//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: optimized
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

typedef struct {
    Contact contacts[MAX_ENTRIES];
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

void addContact(PhoneBook *pb, const char *name, const char *phone) {
    if (pb->count < MAX_ENTRIES) {
        strncpy(pb->contacts[pb->count].name, name, NAME_LENGTH - 1);
        pb->contacts[pb->count].name[NAME_LENGTH - 1] = '\0';
        strncpy(pb->contacts[pb->count].phone, phone, PHONE_LENGTH - 1);
        pb->contacts[pb->count].phone[PHONE_LENGTH - 1] = '\0';
        pb->count++;
    } else {
        printf("Phonebook is full. Cannot add more contacts.\n");
    }
}

void displayContacts(const PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No contacts in the phonebook.\n");
        return;
    }
    printf("Phone Book Contacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Contact %d: %s, Phone: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            printf("Found: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact %s not found.\n", name);
}

void deleteContact(PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            printf("Contact %s deleted successfully.\n", name);
            return;
        }
    }
    printf("Contact %s not found.\n", name);
}

void saveToFile(const PhoneBook *pb, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }
    fwrite(pb, sizeof(PhoneBook), 1, file);
    fclose(file);
    printf("Phonebook saved to %s\n", filename);
}

void loadFromFile(PhoneBook *pb, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }
    fread(pb, sizeof(PhoneBook), 1, file);
    fclose(file);
    printf("Phonebook loaded from %s\n", filename);
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);
    
    int choice;
    char name[NAME_LENGTH], phone[PHONE_LENGTH];
    const char *filename = "phonebook.dat";

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save Phonebook\n");
        printf("6. Load Phonebook\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

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
                displayContacts(&pb);
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;
                searchContact(&pb, name);
                break;
            case 4:
                printf("Enter name to delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;
                deleteContact(&pb, name);
                break;
            case 5:
                saveToFile(&pb, filename);
                break;
            case 6:
                loadFromFile(&pb, filename);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}