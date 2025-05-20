//FormAI DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
// Program to create a unique phone book
// Written in the style of Donald Knuth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 12
#define MAX_ENTRIES 100

// Define the structure for each entry in the phone book
struct phonebook_entry {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

// Define the array to hold the phone book
struct phonebook_entry phonebook[MAX_ENTRIES];

// Define the index of the last entry in the phone book
int last_entry_index = -1;

// Function to add a new entry to the phone book
void add_entry(char name[], char phone[]) {
    if (last_entry_index == MAX_ENTRIES - 1) {
        printf("Phone book is full!\n");
        return;
    }
    last_entry_index++;
    strcpy(phonebook[last_entry_index].name, name);
    strcpy(phonebook[last_entry_index].phone, phone);
    printf("%s has been added to the phone book!\n", name);
}

// Function to search for an entry in the phone book
void search_entry(char name[]) {
    int index = -1;
    for (int i = 0; i <= last_entry_index; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("%s not found in the phone book!\n", name);
    } else {
        printf("Name: %s\n", phonebook[index].name);
        printf("Phone: %s\n", phonebook[index].phone);
    }
}

// Function to display the entire phone book
void display_phonebook() {
    printf("Phone Book Entries:\n");
    for (int i = 0; i <= last_entry_index; i++) {
        printf("Name: %s\n", phonebook[i].name);
        printf("Phone: %s\n", phonebook[i].phone);
    }
}

int main() {
    char choice, name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];
    
    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add new entry\n");
        printf("2. Search for an entry\n");
        printf("3. Display the phone book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        getchar(); // consume the newline character left by scanf
        
        switch (choice) {
            case '1':
                printf("\nEnter the name: ");
                gets(name);
                printf("Enter the phone number: ");
                gets(phone);
                add_entry(name, phone);
                break;
            case '2':
                printf("\nEnter the name to search for: ");
                gets(name);
                search_entry(name);
                break;
            case '3':
                display_phonebook();
                break;
            case '4':
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    
    return 0;
}