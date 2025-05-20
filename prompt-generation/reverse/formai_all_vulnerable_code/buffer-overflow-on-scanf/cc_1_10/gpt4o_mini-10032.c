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

void initializePhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

int addContact(PhoneBook *pb, const char *name, const char *phone) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return -1;
    }
    strncpy(pb->contacts[pb->count].name, name, NAME_LENGTH);
    strncpy(pb->contacts[pb->count].phone, phone, PHONE_LENGTH);
    pb->count++;
    return 0;
}

void listContacts(const PhoneBook *pb) {
    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
}

int findContact(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return i;
        }
    }
    printf("Contact with name '%s' not found.\n", name);
    return -1;
}

int deleteContact(PhoneBook *pb, const char *name) {
    int index = findContact(pb, name);
    if (index == -1) {
        return -1;
    }
    for (int i = index; i < pb->count - 1; i++) {
        pb->contacts[i] = pb->contacts[i + 1];
    }
    pb->count--;
    printf("Contact '%s' deleted successfully.\n", name);
    return 0;
}

void savePhoneBookToFile(const PhoneBook *pb, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }
    for (int i = 0; i < pb->count; i++) {
        fprintf(file, "%s;%s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
    fclose(file);
    printf("Phone book saved to '%s'.\n", filename);
}

void loadPhoneBookFromFile(PhoneBook *pb, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }
    char line[NAME_LENGTH + PHONE_LENGTH + 2]; // +2 for the delimiter and null terminator
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ";");
        char *phone = strtok(NULL, "\n");
        if (name && phone) {
            addContact(pb, name, phone);
        }
    }
    fclose(file);
    printf("Phone book loaded from '%s'.\n", filename);
}

int main() {
    PhoneBook myPhoneBook;
    initializePhoneBook(&myPhoneBook);
    
    int choice;
    char name[NAME_LENGTH], phone[PHONE_LENGTH];
    const char *filename = "phonebook.txt";

    loadPhoneBookFromFile(&myPhoneBook, filename);

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Find Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save Phone Book\n");
        printf("6. Load Phone Book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
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
                addContact(&myPhoneBook, name, phone);
                break;
            case 2:
                listContacts(&myPhoneBook);
                break;
            case 3:
                printf("Enter name to find: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                findContact(&myPhoneBook, name);
                break;
            case 4:
                printf("Enter name to delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                deleteContact(&myPhoneBook, name);
                break;
            case 5:
                savePhoneBookToFile(&myPhoneBook, filename);
                break;
            case 6:
                loadPhoneBookFromFile(&myPhoneBook, filename);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    printf("Exiting Phone Book. Goodbye!\n");
    return 0;
}