//FormAI DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
/*************************************************************
 * C Phone Book Example Program
 * Written by [Your Name]
 * Inspired by Donald E. Knuth
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} phonebook_entry;

phonebook_entry phonebook[MAX_ENTRIES];
int num_entries = 0;

int add_entry(char *name, char *phone) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Phonebook is full.\n");
        return 0;
    }
    if (strlen(name) >= MAX_NAME_LENGTH || strlen(phone) >= MAX_PHONE_LENGTH) {
        printf("Error: Name or phone number is too long.\n");
        return 0;
    }
    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].phone, phone);
    num_entries++;
    printf("Entry added.\n");
    return 1;
}

int search_entry(char *name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s, Phone: %s\n", phonebook[i].name, phonebook[i].phone);
            return 1;
        }
    }
    printf("Entry not found.\n");
    return 0;
}

int main() {
    printf("Welcome to the C Phone Book!\n");
    while (1) {
        printf("Please choose an option:\n1. Add Entry\n2. Search Entry\n3. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                add_entry(name, phone);
                break;
            }
            case 2: {
                char name[MAX_NAME_LENGTH];
                printf("Enter name to search for: ");
                scanf("%s", name);
                search_entry(name);
                break;
            }
            case 3: {
                printf("Thank you for using the C Phone Book!");
                return 0;
            }
            default: {
                printf("Error: Invalid option.\n");
                break;
            }
        }
    }
    return 0;
}