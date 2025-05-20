//FormAI DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 25
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} phonebook_entry;

phonebook_entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void menu();
void add_entry();
void search_name();
void search_phone();
void print_phonebook();
void save_phonebook();

int main() {
    printf("Welcome to the Phone Book!\n\n");

    // Load phone book from file
    FILE *fp = fopen("phonebook.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%s %s", phonebook[num_entries].name, phonebook[num_entries].phone) != EOF) {
            num_entries++;
        }
        fclose(fp);
    }

    menu();

    return 0;
}

void menu() {
    printf("Please select an option:\n");
    printf("1. Add entry\n");
    printf("2. Search by name\n");
    printf("3. Search by phone number\n");
    printf("4. Print phone book\n");
    printf("5. Save phone book\n");
    printf("6. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            search_name();
            break;
        case 3:
            search_phone();
            break;
        case 4:
            print_phonebook();
            break;
        case 5:
            save_phonebook();
            break;
        case 6:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            menu();
            break;
    }
}

void add_entry() {
    // Check if phone book is full
    if (num_entries == MAX_ENTRIES) {
        printf("Phone book is full. Cannot add any more entries.\n");
        return;
    }

    // Get name and phone number
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    printf("Enter name:\n");
    scanf("%s", name);
    printf("Enter phone number:\n");
    scanf("%s", phone);

    // Add entry to phone book
    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].phone, phone);
    num_entries++;

    printf("Entry added successfully!\n");
    menu();
}

void search_name() {
    // Get name to search for
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search for:\n");
    scanf("%s", name);

    // Search for entry
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone: %s\n", phonebook[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }

    menu();
}

void search_phone() {
    // Get phone number to search for
    char phone[MAX_PHONE_LENGTH];
    printf("Enter phone number to search for:\n");
    scanf("%s", phone);

    // Search for entry
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].phone, phone) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone: %s\n", phonebook[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }

    menu();
}

void print_phonebook() {
    // Print all entries in phone book
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\n", phonebook[i].name);
        printf("Phone: %s\n", phonebook[i].phone);
        printf("\n");
    }

    menu();
}

void save_phonebook() {
    // Save phone book to file
    FILE *fp = fopen("phonebook.txt", "w");
    for (int i = 0; i < num_entries; i++) {
        fprintf(fp, "%s %s\n", phonebook[i].name, phonebook[i].phone);
    }
    fclose(fp);

    printf("Phone book saved successfully!\n");
    menu();
}