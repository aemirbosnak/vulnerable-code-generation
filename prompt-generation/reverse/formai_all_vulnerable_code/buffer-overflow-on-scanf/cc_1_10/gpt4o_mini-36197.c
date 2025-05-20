//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define NUMBER_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char number[NUMBER_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int total_contacts;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->total_contacts = 0;
}

void addContact(PhoneBook *pb, const char *name, const char *number) {
    if (pb->total_contacts < MAX_CONTACTS) {
        strncpy(pb->contacts[pb->total_contacts].name, name, NAME_LENGTH);
        strncpy(pb->contacts[pb->total_contacts].number, number, NUMBER_LENGTH);
        pb->total_contacts++;
        printf("Contact added successfully!\n");
    } else {
        printf("Phone book is full. Cannot add more contacts.\n");
    }
}

void displayContacts(PhoneBook *pb) {
    if (pb->total_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("\n--- Phone Book ---\n");
    for (int i = 0; i < pb->total_contacts; i++) {
        printf("Contact #%d: %s - %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].number);
    }
}

void searchContact(PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->total_contacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Found contact: %s - %s\n", pb->contacts[i].name, pb->contacts[i].number);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact(PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->total_contacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            pb->contacts[i] = pb->contacts[pb->total_contacts - 1]; // Move last contact to the deleted spot
            pb->total_contacts--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void displayStatistics(PhoneBook *pb) {
    int total_length = 0;
    for (int i = 0; i < pb->total_contacts; i++) {
        total_length += strlen(pb->contacts[i].name);
    }
    double average_length = pb->total_contacts > 0 ? (double)total_length / pb->total_contacts : 0;

    printf("\n--- Statistics ---\n");
    printf("Total Contacts: %d\n", pb->total_contacts);
    printf("Average Name Length: %.2f\n", average_length);
}

int main() {
    PhoneBook myPhoneBook;
    initializePhoneBook(&myPhoneBook);

    int choice;
    char name[NAME_LENGTH];
    char number[NUMBER_LENGTH];

    do {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Show Statistics\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline character

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline

                printf("Enter number: ");
                fgets(number, NUMBER_LENGTH, stdin);
                number[strcspn(number, "\n")] = '\0'; // Remove newline

                addContact(&myPhoneBook, name, number);
                break;
            case 2:
                displayContacts(&myPhoneBook);
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                searchContact(&myPhoneBook, name);
                break;
            case 4:
                printf("Enter name to delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                deleteContact(&myPhoneBook, name);
                break;
            case 5:
                displayStatistics(&myPhoneBook);
                break;
            case 6:
                printf("Exiting Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}