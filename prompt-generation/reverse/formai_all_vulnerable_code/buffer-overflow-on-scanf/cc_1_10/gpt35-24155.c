//FormAI DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

struct phonebook_entry {
    char name[30];
    char phone_number[12];
};

int num_entries = 0;
struct phonebook_entry phonebook[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full\n");
        return;
    }
    struct phonebook_entry new_entry;
    printf("Enter name: ");
    scanf("%s", new_entry.name);
    printf("Enter phone number (xxx-xxx-xxxx): ");
    scanf("%s", new_entry.phone_number);
    phonebook[num_entries++] = new_entry;
    printf("Entry added successfully\n");
}

void search_entry() {
    char search_name[30];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("%s's phone number is %s\n", phonebook[i].name, phonebook[i].phone_number);
            return;
        }
    }
    printf("%s not found in phonebook\n", search_name);
}

void print_entries() {
    if (num_entries == 0) {
        printf("Phonebook is empty\n");
        return;
    }
    printf("Phonebook Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", phonebook[i].name, phonebook[i].phone_number);
    }
}

int main() {
    char choice;
    while (1) {
        printf("\nEnter choice:\n");
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Print Entries\n");
        printf("4. Quit\n");
        scanf(" %c", &choice);
        switch(choice) {
          case '1':
            add_entry();
            break;
          case '2':
            search_entry();
            break;
          case '3':
            print_entries();
            break;
          case '4':
            printf("Goodbye!\n");
            return 0;
          default:
            printf("Invalid choice. Try again\n");
        }
    }
}