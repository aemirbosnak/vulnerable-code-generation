//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: surrealist
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

// Function to add a contact to the phone book
void add_contact(Contact *contacts, int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("The phone book is full, the stars are falling in despair.\n");
        return;
    }
    printf("Whisper the name of the ethereal being:\n");
    scanf(" %[^\n]", contacts[*count].name);
    printf("Now, inscribe its number in the fabric of reality:\n");
    scanf(" %[^\n]", contacts[*count].phone);
    (*count)++;
    printf("Contact added! A new constellation has been formed.\n");
}

// Function to display contacts in a dreamscape
void display_contacts(Contact *contacts, int count) {
    if (count == 0) {
        printf("The void cradles no souls; the phone book is empty.\n");
        return;
    }
    printf("\nIn the realm of contacts, we find:\n");
    for (int i = 0; i < count; i++) {
        printf("Contact %d: %s | Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

// Function to search for a contact that dances among the clouds
void search_contact(Contact *contacts, int count) {
    char name[NAME_LENGTH];
    printf("Invoke the name of the contact you seek:\n");
    scanf(" %[^\n]", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("The contact you sought is a marionette of fate: %s | Phone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("The name resonates through the universe yet finds no home.\n");
}

// Function to delete a contact lost in the infinite loop
void delete_contact(Contact *contacts, int *count) {
    char name[NAME_LENGTH];
    printf("Name the specter you wish to banish:\n");
    scanf(" %[^\n]", name);
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("The contact has been erased from our memories, like sand through fingers.\n");
            return;
        }
    }
    printf("The specter remains, unscathed in its absence.\n");
}

// Function to show the menu of cosmic choices
void show_menu() {
    printf("\n--- Cosmic Phone Book ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit the dimension\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while (1) {
        show_menu();
        printf("Choose your path through the cosmic void:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, &count);
                break;
            case 2:
                display_contacts(contacts, count);
                break;
            case 3:
                search_contact(contacts, count);
                break;
            case 4:
                delete_contact(contacts, &count);
                break;
            case 5:
                printf("The journey ends here. Farewell, wanderer of the galaxies!\n");
                exit(0);
            default:
                printf("The choice is an enigma; please select again.\n");
                break;
        }
    }

    return 0;
}