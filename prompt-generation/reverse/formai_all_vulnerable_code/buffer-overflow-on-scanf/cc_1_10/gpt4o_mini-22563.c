//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *phone;
} Contact;

Contact* create_contact(const char *name, const char *phone) {
    Contact *new_contact = (Contact *)malloc(sizeof(Contact));
    if (new_contact == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    new_contact->name = (char *)malloc(strlen(name) + 1);
    new_contact->phone = (char *)malloc(strlen(phone) + 1);
    if (new_contact->name == NULL || new_contact->phone == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(new_contact);
        exit(EXIT_FAILURE);
    }
    
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);
    
    return new_contact;
}

void free_contact(Contact *contact) {
    if (contact != NULL) {
        free(contact->name);
        free(contact->phone);
        free(contact);
    }
}

void display_contact(Contact *contact) {
    if (contact != NULL) {
        printf("Name: %s, Phone: %s\n", contact->name, contact->phone);
    }
}

int main() {
    int size = 2;
    int count = 0;

    // Initially allocate space for 2 contacts
    Contact **contacts = (Contact **)malloc(size * sizeof(Contact *));
    if (contacts == NULL) {
        fprintf(stderr, "Memory allocation for contacts array failed!\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Contact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        
        int option;
        scanf("%d", &option);
        getchar(); // Consume newline character left in the input buffer.

        if (option == 1) {
            if (count >= size) {
                size *= 2; // Double the size
                contacts = (Contact **)realloc(contacts, size * sizeof(Contact *));
                if (contacts == NULL) {
                    fprintf(stderr, "Memory reallocation failed!\n");
                    exit(EXIT_FAILURE);
                }
            }

            char name[100], phone[15];
            printf("Enter name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0; // Remove newline
            
            printf("Enter phone number: ");
            fgets(phone, sizeof(phone), stdin);
            phone[strcspn(phone, "\n")] = 0; // Remove newline

            contacts[count] = create_contact(name, phone);
            count++;
            printf("Contact added!\n");
        } else if (option == 2) {
            printf("All Contacts:\n");
            for (int i = 0; i < count; i++) {
                display_contact(contacts[i]);
            }
        } else if (option == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }

    // Free all allocated contacts
    for (int i = 0; i < count; i++) {
        free_contact(contacts[i]);
    }
    free(contacts);

    return 0;
}