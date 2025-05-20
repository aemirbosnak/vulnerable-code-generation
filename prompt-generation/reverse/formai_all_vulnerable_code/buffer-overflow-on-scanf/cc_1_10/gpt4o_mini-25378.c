//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: genius
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

void initialize_phone_book(PhoneBook *pb) {
    pb->count = 0;
}

void add_contact(PhoneBook *pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    printf("Enter Name: ");
    scanf("%s", pb->contacts[pb->count].name);
    printf("Enter Phone: ");
    scanf("%s", pb->contacts[pb->count].phone);
    pb->count++;
    printf("Contact added successfully!\n");
}

void list_contacts(PhoneBook *pb) {
    if (pb->count == 0) {
        printf("Phone book is empty!\n");
        return;
    }
    printf("\n---- Phone Book ----\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d. %s - %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
    printf("---------------------\n");
}

int find_contact(PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void edit_contact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to edit: ");
    scanf("%s", name);
    
    int index = find_contact(pb, name);
    if (index == -1) {
        printf("Contact not found!\n");
        return;
    }
    
    printf("Editing contact:\n");
    printf("Current Phone: %s\n", pb->contacts[index].phone);
    printf("Enter new Phone: ");
    scanf("%s", pb->contacts[index].phone);
    printf("Contact updated successfully!\n");
}

void delete_contact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);
    
    int index = find_contact(pb, name);
    if (index == -1) {
        printf("Contact not found!\n");
        return;
    }
    
    for (int i = index; i < pb->count - 1; i++) {
        pb->contacts[i] = pb->contacts[i+1];
    }
    pb->count--;
    printf("Contact deleted successfully!\n");
}

void search_contact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    scanf("%s", name);
    
    int index = find_contact(pb, name);
    if (index == -1) {
        printf("Contact not found!\n");
    } else {
        printf("Contact found: %s - %s\n", pb->contacts[index].name, pb->contacts[index].phone);
    }
}

void save_phone_book(PhoneBook *pb) {
    FILE *file = fopen("phonebook.txt", "w");
    if (!file) {
        printf("Error saving phone book!\n");
        return;
    }
    for (int i = 0; i < pb->count; i++) {
        fprintf(file, "%s %s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
    fclose(file);
    printf("Phone book saved successfully!\n");
}

void load_phone_book(PhoneBook *pb) {
    FILE *file = fopen("phonebook.txt", "r");
    if (!file) {
        printf("No saved phone book found.\n");
        return;
    }
    
    while (fscanf(file, "%s %s", pb->contacts[pb->count].name, pb->contacts[pb->count].phone) != EOF && pb->count < MAX_CONTACTS) {
        pb->count++;
    }
    fclose(file);
    printf("Phone book loaded successfully!\n");
}

void display_menu() {
    printf("\n----- Phone Book Menu -----\n");
    printf("1. Add Contact\n");
    printf("2. List Contacts\n");
    printf("3. Edit Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Search Contact\n");
    printf("6. Save Phone Book\n");
    printf("7. Load Phone Book\n");
    printf("8. Exit\n");
    printf("---------------------------\n");
}

int main() {
    PhoneBook phoneBook;
    initialize_phone_book(&phoneBook);
    load_phone_book(&phoneBook);

    int choice;
    
    do {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_contact(&phoneBook);
                break;
            case 2:
                list_contacts(&phoneBook);
                break;
            case 3:
                edit_contact(&phoneBook);
                break;
            case 4:
                delete_contact(&phoneBook);
                break;
            case 5:
                search_contact(&phoneBook);
                break;
            case 6:
                save_phone_book(&phoneBook);
                break;
            case 7:
                load_phone_book(&phoneBook);
                break;
            case 8:
                printf("Exiting the phone book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);
    
    return 0;
}