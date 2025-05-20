//FormAI DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <string.h>

struct Contact {
    int id;
    char name[50];
    char phone_number[20];
};

void print_menu(void);
void add_contact(struct Contact contact_list[], int *num_contacts);
void search_contact(struct Contact contact_list[], int num_contacts);
void edit_contact(struct Contact contact_list[], int num_contacts);
void delete_contact(struct Contact contact_list[], int *num_contacts);

int main(void) {
    struct Contact contact_list[100]; // maximum 100 contacts
    int num_contacts = 0;
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character left by scanf

        switch (choice) {
            case 1:
                add_contact(contact_list, &num_contacts);
                break;
            case 2:
                search_contact(contact_list, num_contacts);
                break;
            case 3:
                edit_contact(contact_list, num_contacts);
                break;
            case 4:
                delete_contact(contact_list, &num_contacts);
                break;
            case 5:
                puts("Goodbye!");
                break;
            default:
                puts("Invalid choice!");
        }

        puts(""); // print a blank line for readability
    } while (choice != 5);

    return 0;
}

void print_menu(void) {
    puts("Phone Book Menu");
    puts("----------------");
    puts("1. Add contact");
    puts("2. Search contact");
    puts("3. Edit contact");
    puts("4. Delete contact");
    puts("5. Exit");
}

void add_contact(struct Contact contact_list[], int *num_contacts) {
    if (*num_contacts == 100) {
        puts("Phone book is full!");
        return;
    }

    printf("Enter name: ");
    fgets(contact_list[*num_contacts].name, 50, stdin);
    contact_list[*num_contacts].name[strcspn(contact_list[*num_contacts].name, "\n")] = '\0'; // remove the newline character from the end

    printf("Enter phone number: ");
    fgets(contact_list[*num_contacts].phone_number, 20, stdin);
    contact_list[*num_contacts].phone_number[strcspn(contact_list[*num_contacts].phone_number, "\n")] = '\0';

    contact_list[*num_contacts].id = *num_contacts + 1; // assign a unique ID to the contact
    (*num_contacts)++; // increment the number of contacts
    puts("Contact added successfully!");
}

void search_contact(struct Contact contact_list[], int num_contacts) {
    char search_term[50];
    printf("Enter search term: ");
    fgets(search_term, 50, stdin);
    search_term[strcspn(search_term, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strstr(contact_list[i].name, search_term) != NULL || strstr(contact_list[i].phone_number, search_term) != NULL) {
            printf("%d. %s - %s\n", contact_list[i].id, contact_list[i].name, contact_list[i].phone_number);
            found = 1;
        }
    }

    if (!found) {
        puts("No matching contacts found.");
    }
}

void edit_contact(struct Contact contact_list[], int num_contacts) {
    int id;
    printf("Enter ID of contact to edit: ");
    scanf("%d", &id);
    getchar(); // consume the newline character left by scanf

    struct Contact *contact = NULL;
    for (int i = 0; i < num_contacts; i++) {
        if (contact_list[i].id == id) {
            contact = &contact_list[i];
            break;
        }
    }

    if (contact == NULL) {
        printf("Contact with ID %d not found.\n", id);
        return;
    }

    printf("Current name: %s\n", contact->name);
    printf("Enter new name (leave blank to keep current name): ");
    fgets(contact->name, 50, stdin);
    contact->name[strcspn(contact->name, "\n")] = '\0';

    printf("Current phone number: %s\n", contact->phone_number);
    printf("Enter new phone number (leave blank to keep current phone number): ");
    fgets(contact->phone_number, 20, stdin);
    contact->phone_number[strcspn(contact->phone_number, "\n")] = '\0';

    puts("Contact edited successfully!");
}

void delete_contact(struct Contact contact_list[], int *num_contacts) {
    int id;
    printf("Enter ID of contact to delete: ");
    scanf("%d", &id);
    getchar(); // consume the newline character left by scanf

    int found = 0;
    for (int i = 0; i < *num_contacts; i++) {
        if (contact_list[i].id == id) {
            found = 1;
            *num_contacts = *num_contacts - 1;
            for (int j = i; j < *num_contacts; j++) {
                contact_list[j] = contact_list[j+1];
                contact_list[j].id = j+1; // reassign the IDs of the remaining contacts
            }
            break;
        }
    }

    if (found) {
        puts("Contact deleted successfully!");
    } else {
        printf("Contact with ID %d not found.\n", id);
    }
}