//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILE_NAME "phonebook.txt"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void add_contact();
void view_contacts();
void search_contact();
void delete_contact();
void load_contacts(Contact contacts[], int *count);
void save_contacts(Contact contacts[], int count);
void clear_buffer();

int main() {
    int choice;
    while (1) {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void add_contact() {
    Contact new_contact;
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("Enter Name: ");
    fgets(new_contact.name, NAME_LENGTH, stdin);
    strtok(new_contact.name, "\n"); // Remove newline character

    printf("Enter Phone: ");
    fgets(new_contact.phone, PHONE_LENGTH, stdin);
    strtok(new_contact.phone, "\n"); // Remove newline character

    fprintf(file, "%s,%s\n", new_contact.name, new_contact.phone);
    fclose(file);

    printf("Contact added successfully!\n");
}

void view_contacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    char line[NAME_LENGTH + PHONE_LENGTH + 2];
    printf("\n--- Contacts ---\n");
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, "\n");
        printf("Name: %s, Phone: %s\n", name, phone);
    }
    fclose(file);
}

void search_contact() {
    char search_name[NAME_LENGTH];
    char line[NAME_LENGTH + PHONE_LENGTH + 2];
    int found = 0;

    printf("Enter Name to search: ");
    fgets(search_name, NAME_LENGTH, stdin);
    strtok(search_name, "\n"); // Remove newline character

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, "\n");

        if (strcasecmp(name, search_name) == 0) {
            printf("Found - Name: %s, Phone: %s\n", name, phone);
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("Contact not found.\n");
    }
}

void delete_contact() {
    char delete_name[NAME_LENGTH];
    Contact contacts[MAX_ENTRIES];
    int count = 0;

    printf("Enter Name to delete: ");
    fgets(delete_name, NAME_LENGTH, stdin);
    strtok(delete_name, "\n"); // Remove newline character

    load_contacts(contacts, &count);
    
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, delete_name) != 0) {
            fprintf(file, "%s,%s\n", contacts[i].name, contacts[i].phone);
        } else {
            found = 1;
        }
    }
    
    fclose(file);
    if (found) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found.\n");
    }
}

void load_contacts(Contact contacts[], int *count) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return; // No contacts to load
    }

    while (fgets(contacts[*count].name, NAME_LENGTH, file)) {
        strtok(contacts[*count].name, "\n");
        fgets(contacts[*count].phone, PHONE_LENGTH, file);
        strtok(contacts[*count].phone, "\n");
        (*count)++;
    }
    fclose(file);
}

void clear_buffer() {
    while (getchar() != '\n');
}