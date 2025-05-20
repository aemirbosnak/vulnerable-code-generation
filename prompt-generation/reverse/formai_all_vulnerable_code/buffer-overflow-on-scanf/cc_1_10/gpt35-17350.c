//FormAI DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 100

typedef struct contact {
    char name[30];
    char phone[15];
    char email[50];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int contactsCount = 0;

// function prototypes
int addContact();
int searchContact(char* name);
void printContacts();
void saveContactsToFile();
void loadContactsFromFile();

int main() {
    int choice;
    while (1) {
        printf("\t--- Phone Book ---\n\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Print all contacts\n");
        printf("4. Save contacts to file\n");
        printf("5. Load contacts from file\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2: {
                char name[30];
                printf("Enter the name to search: ");
                scanf("%s", name);
                int index = searchContact(name);
                if (index == -1) {
                    printf("Contact not found.\n");
                } else {
                    printf("Contact found:\n");
                    printf("Name: %s\n", phoneBook[index].name);
                    printf("Phone: %s\n", phoneBook[index].phone);
                    printf("Email: %s\n", phoneBook[index].email);
                }
                break;
            }
            case 3:
                printContacts();
                break;
            case 4:
                saveContactsToFile();
                break;
            case 5:
                loadContactsFromFile();
                break;
            case 6:
                printf("Exiting Phone Book...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
        printf("Press any key to continue...");
        getchar();
        getchar();
        system("clear");
    }
    return 0;
}

// Adds a contact to the phone book
int addContact() {
    if (contactsCount == MAX_CONTACTS) {
        printf("Phone book is full, cannot add more contacts.\n");
        return 0;
    }
    Contact newContact;
    printf("Enter the name: ");
    scanf("%s", newContact.name);
    printf("Enter the phone number: ");
    scanf("%s", newContact.phone);
    printf("Enter the email address: ");
    scanf("%s", newContact.email);
    phoneBook[contactsCount] = newContact;
    contactsCount++;
    printf("Contact added successfully!\n");
    return 1;
}

// Searches for a contact by name
int searchContact(char* name) {
    for (int i = 0; i < contactsCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0)
            return i;
    }
    return -1;
}

// Prints all contacts in the phone book
void printContacts() {
    if (contactsCount == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("Contacts in the phone book:\n");
    for (int i = 0; i < contactsCount; i++) {
        printf("%d. %s - %s, %s\n", i+1, phoneBook[i].name, phoneBook[i].phone, phoneBook[i].email);
    }
}

// Saves all contacts to file
void saveContactsToFile() {
    if (contactsCount == 0) {
        printf("Phone book is empty, nothing to save.\n");
        return;
    }
    char filename[30];
    FILE* fp;
    printf("Enter the file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    fwrite(&contactsCount, sizeof(int), 1, fp);
    fwrite(phoneBook, sizeof(Contact), contactsCount, fp);
    fclose(fp);
    printf("Contacts saved to file successfully!\n");
}

// Loads all contacts from file
void loadContactsFromFile() {
    char filename[30];
    FILE* fp;
    printf("Enter the file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    fread(&contactsCount, sizeof(int), 1, fp);
    fread(phoneBook, sizeof(Contact), contactsCount, fp);
    fclose(fp);
    printf("Contacts loaded from file successfully!\n");
}