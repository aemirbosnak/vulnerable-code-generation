//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Claude Shannon
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

// Function prototypes
void initPhoneBook(PhoneBook *pb);
void addContact(PhoneBook *pb);
void displayContacts(const PhoneBook *pb);
void searchContact(const PhoneBook *pb);
void handleUserInput(PhoneBook *pb);
void saveToFile(const PhoneBook *pb);
void loadFromFile(PhoneBook *pb);

int main() {
    PhoneBook pb;
    initPhoneBook(&pb);
    loadFromFile(&pb);
    handleUserInput(&pb);
    saveToFile(&pb);
    return 0;
}

void initPhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

void addContact(PhoneBook *pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Phonebook is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]", pb->contacts[pb->count].name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", pb->contacts[pb->count].phone);
    pb->count++;
    printf("Contact added!\n");
}

void displayContacts(const PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No contacts found!\n");
        return;
    }
    printf("\nYour Phone Book:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1,
            pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(const PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Found: Name: %s, Phone: %s\n", 
                pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void handleUserInput(PhoneBook *pb) {
    int choice;
    
    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(pb);
                break;
            case 2:
                displayContacts(pb);
                break;
            case 3:
                searchContact(pb);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);
}

void saveToFile(const PhoneBook *pb) {
    FILE *file = fopen("phonebook.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < pb->count; i++) {
        fprintf(file, "%s;%s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
    fclose(file);
    printf("Contacts saved to file!\n");
}

void loadFromFile(PhoneBook *pb) {
    FILE *file = fopen("phonebook.txt", "r");
    if (!file) {
        printf("No previous phonebook file found, starting fresh!\n");
        return;
    }
    while (fscanf(file, " %[^\n];%[^\n]", pb->contacts[pb->count].name,
                  pb->contacts[pb->count].phone) == 2) {
        pb->count++;
        if (pb->count >= MAX_CONTACTS) break;
    }
    fclose(file);
    printf("Contacts loaded from file!\n");
}