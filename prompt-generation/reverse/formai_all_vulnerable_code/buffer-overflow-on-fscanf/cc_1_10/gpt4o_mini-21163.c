//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 100
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void addContact(Contact phoneBook[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Phonebook is full. Cannot add more contacts.\n");
        return;
    }
    
    printf("Enter Name: ");
    scanf(" %[^\n]s", phoneBook[*count].name); // Read string with spaces
    printf("Enter Phone Number: ");
    scanf(" %[^\n]s", phoneBook[*count].phone);

    (*count)++;
    printf("Contact added successfully!\n");
}

void displayContacts(const Contact phoneBook[], int count) {
    if (count == 0) {
        printf("No contacts in the phonebook.\n");
        return;
    }

    printf("\nContacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact(const Contact phoneBook[], int count) {
    char name[NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < count; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            printf("Contact found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact(Contact phoneBook[], int *count) {
    char name[NAME_LENGTH];
    printf("Enter the name to delete: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < *count; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            // Shift contacts left to fill the deleted spot
            for (int j = i; j < *count - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void saveContacts(const Contact phoneBook[], int count) {
    FILE *file = fopen("phonebook.txt", "w");
    if (!file) {
        printf("Error saving contacts to file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s\n", phoneBook[i].name, phoneBook[i].phone);
    }
    fclose(file);
    printf("Contacts saved to phonebook.txt\n");
}

void loadContacts(Contact phoneBook[], int *count) {
    FILE *file = fopen("phonebook.txt", "r");
    if (!file) {
        printf("No existing phonebook found, starting fresh.\n");
        return;
    }

    while (fscanf(file, " %[^\n],%[^\n]\n", phoneBook[*count].name, phoneBook[*count].phone) != EOF) {
        (*count)++;
        if (*count >= MAX_CONTACTS) break; // Avoid overflow
    }
    fclose(file);
    printf("Contacts loaded successfully!\n");
}

int main() {
    Contact phoneBook[MAX_CONTACTS];
    int count = 0;
    int choice;

    loadContacts(phoneBook, &count);

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save Contacts\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(phoneBook, &count);
                break;
            case 2:
                displayContacts(phoneBook, count);
                break;
            case 3:
                searchContact(phoneBook, count);
                break;
            case 4:
                deleteContact(phoneBook, &count);
                break;
            case 5:
                saveContacts(phoneBook, count);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}