//FormAI DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 50
#define MAX_PHONE 15
#define MAX_ENTRIES 10

struct phonebook_entry {
    char name[MAX_NAME];
    char phone_number[MAX_PHONE];
};

struct phonebook_entry phonebook[MAX_ENTRIES];

int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, the phonebook is full!\n");
        return;
    }

    char name[MAX_NAME];
    char phone_number[MAX_PHONE];

    printf("What is the name of the person you want to add? ");
    scanf("%s", name);

    printf("What is their phone number? ");
    scanf("%s", phone_number);

    struct phonebook_entry new_entry = {0};

    strcpy(new_entry.name, name);

    for (int i = 0, j = 0; i < strlen(phone_number); i++) {
        if (isdigit(phone_number[i])) {
            new_entry.phone_number[j] = phone_number[i];
            j++;
        }
    }

    phonebook[num_entries] = new_entry;
    num_entries++;
    printf("%s added to the phonebook\n", new_entry.name);
}

void search_entry() {
    char name[MAX_NAME];

    printf("What is the name of the person you want to search for? ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s's phone number is %s\n", phonebook[i].name, phonebook[i].phone_number);
            return;
        }
    }

    printf("Sorry, %s was not found in the phonebook\n", name);
}

void display_phonebook() {
    if (num_entries == 0) {
        printf("The phonebook is currently empty\n");
        return;
    }

    printf("-----------------------\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].phone_number);
    }
    printf("-----------------------\n");
}

int main() {
    char choice;

    printf("Welcome to the C Phone Book!\n");

    do {
        printf("What would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Display the phone book\n");
        printf("4. Quit\n");
        printf("Your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1': add_entry(); break;
        case '2': search_entry(); break;
        case '3': display_phonebook(); break;
        case '4': printf("Goodbye!\n"); break;
        default: printf("Sorry, I don't understand that choice\n"); break;
        }

    } while (choice != '4');

    return 0;
}