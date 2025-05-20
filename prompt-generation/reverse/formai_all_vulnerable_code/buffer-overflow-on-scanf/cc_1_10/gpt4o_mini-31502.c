//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
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

void init_contacts(Contact contacts[], int *count) {
    *count = 0;
}

void add_contact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Data node access limit reached. Remove a contact before adding new.\n");
        return;
    }
    
    printf("Enter Name: ");
    getchar();  // consume newline character
    fgets(contacts[*count].name, NAME_LENGTH, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0; // Remove newline

    printf("Enter Phone Number: ");
    fgets(contacts[*count].phone, PHONE_LENGTH, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0; // Remove newline
    
    (*count)++;
    printf("Contact stored in the digital hive.\n");
}

void display_contacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("The digital memory is empty. No contacts to display.\n");
        return;
    }
    
    printf("\nContacts in the neural net:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void delete_contact(Contact contacts[], int *count) {
    if (*count == 0) {
        printf("No contacts to delete. Dive deeper into the void.\n");
        return;
    }
    
    int id;
    display_contacts(contacts, *count);
    printf("Enter the ID of the contact to remove: ");
    scanf("%d", &id);
    
    if (id < 1 || id > *count) {
        printf("Invalid ID. No alteration was made in the digital matrix.\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    (*count)--;
    printf("Contact removed from the digital layer.\n");
}

void search_contact(Contact contacts[], int count) {
    if (count == 0) {
        printf("Access denied. No contacts found in the system.\n");
        return;
    }
    
    char query[NAME_LENGTH];
    printf("Enter Name to Search: ");
    getchar();  // consume newline character
    fgets(query, NAME_LENGTH, stdin);
    query[strcspn(query, "\n")] = 0; // Remove newline
    
    int found = 0;
    printf("\nSearching for contacts in the neural web...\n");
    for (int i = 0; i < count; i++) {
        if (strstr(contacts[i].name, query) != NULL) {
            printf("Found - ID: %d | Name: %s | Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("No contact found in this realm with that name.\n");
    }
}

void save_contacts(Contact contacts[], int count) {
    FILE *file = fopen("contacts.dat", "wb");
    if (file == NULL) {
        printf("Failed to write data to storage node.\n");
        return;
    }
    fwrite(contacts, sizeof(Contact), count, file);
    fclose(file);
    printf("Contacts saved in the storage node.\n");
}

void load_contacts(Contact contacts[], int *count) {
    FILE *file = fopen("contacts.dat", "rb");
    if (file == NULL) {
        printf("No contact data found in the dark web.\n");
        return;
    }
    *count = fread(contacts, sizeof(Contact), MAX_CONTACTS, file);
    fclose(file);
    printf("Contacts retrieved from the dark zone.\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    load_contacts(contacts, &count);

    do {
        printf("\n--- Cyberpunk Phone Book ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n");
        printf("5. Save Contacts\n");
        printf("6. Exit\n");
        printf("Choose your path (1-6): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: add_contact(contacts, &count); break;
            case 2: display_contacts(contacts, count); break;
            case 3: delete_contact(contacts, &count); break;
            case 4: search_contact(contacts, count); break;
            case 5: save_contacts(contacts, count); break;
            case 6: printf("Shutting down the system. Until next time...\n"); break;
            default: printf("Invalid choice. Please, traverse through the options properly.\n");
        }
    } while (choice != 6);
    
    return 0;
}