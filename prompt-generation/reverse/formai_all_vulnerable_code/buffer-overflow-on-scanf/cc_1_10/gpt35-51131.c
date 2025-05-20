//FormAI DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

/* Contact struct */
struct Contact {
    char name[50];
    char phone_number[20];
};

/* Phonebook struct */
struct Phonebook {
    struct Contact contacts[MAX_CONTACTS];
    int size;
};

/* Function prototypes */
void init_phonebook(struct Phonebook* phonebook);
void add_contact(struct Phonebook* phonebook, char* name, char* phone_number);
void delete_contact(struct Phonebook* phonebook, char* name);
void print_phonebook(struct Phonebook* phonebook);
void clear_phonebook(struct Phonebook* phonebook);

/* Main function */
int main(void) {
    struct Phonebook my_phonebook;
    char name[50];
    char phone_number[20];
    int choice;

    init_phonebook(&my_phonebook); // Initialize the phonebook

    do {
        printf("\nPhonebook Menu\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Print Phonebook\n");
        printf("4. Clear Phonebook\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone_number);
                add_contact(&my_phonebook, name, phone_number);
                printf("Contact added.\n");
                break;

            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                delete_contact(&my_phonebook, name);
                break;

            case 3:
                print_phonebook(&my_phonebook);
                break;

            case 4:
                clear_phonebook(&my_phonebook);
                printf("Phonebook cleared.\n");
                break;

            case 5:
                printf("Exiting phonebook.\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

/* Initialize the phonebook */
void init_phonebook(struct Phonebook* phonebook) {
    phonebook->size = 0; // Set size to 0
}

/* Add a contact to the phonebook */
void add_contact(struct Phonebook* phonebook, char* name, char* phone_number) {
    if (phonebook->size == MAX_CONTACTS) {
        printf("Phonebook is full. Contact not added.\n");
        return;
    }

    struct Contact new_contact = {0};
    strcpy(new_contact.name, name);
    strcpy(new_contact.phone_number, phone_number);

    phonebook->contacts[phonebook->size++] = new_contact; // Add contact to phonebook and increment size
}

/* Delete a contact from the phonebook */
void delete_contact(struct Phonebook* phonebook, char* name) {
    int i, j;
    int found = 0;

    for (i = 0; i < phonebook->size; i++) {
        if (strcmp(phonebook->contacts[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (j = i; j < phonebook->size - 1; j++) {
            phonebook->contacts[j] = phonebook->contacts[j+1];
        }

        phonebook->size--; // Decrement size
        printf("Contact deleted.\n");
    } else {
        printf("Contact not found.\n");
    }
}

/* Print the phonebook */
void print_phonebook(struct Phonebook* phonebook) {
    int i;

    if (phonebook->size == 0) {
        printf("Phonebook is empty.\n");
        return;
    }

    printf("Phonebook:\n");
    printf("Number of contacts: %d\n", phonebook->size);

    for (i = 0; i < phonebook->size; i++) {
        printf("%s: %s\n", phonebook->contacts[i].name, phonebook->contacts[i].phone_number);
    }
}

/* Clear the phonebook */
void clear_phonebook(struct Phonebook* phonebook) {
    phonebook->size = 0; // Set size to 0
}