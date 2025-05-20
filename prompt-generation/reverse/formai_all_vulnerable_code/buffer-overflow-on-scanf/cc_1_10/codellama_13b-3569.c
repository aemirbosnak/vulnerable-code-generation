//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: sophisticated
/*
 * Phone Book
 *
 * A sophisticated C program to manage a phone book with advanced features
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the phone book structure
struct phone_book {
    char name[50];
    char phone_number[15];
};

// Function to add a new entry to the phone book
void add_entry(struct phone_book *phone_book, int index) {
    printf("Enter the name: ");
    scanf("%s", phone_book[index].name);
    printf("Enter the phone number: ");
    scanf("%s", phone_book[index].phone_number);
}

// Function to delete an entry from the phone book
void delete_entry(struct phone_book *phone_book, int index) {
    phone_book[index].name[0] = '\0';
    phone_book[index].phone_number[0] = '\0';
}

// Function to search for an entry in the phone book
void search_entry(struct phone_book *phone_book, int index) {
    char search_name[50];
    printf("Enter the name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < index; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", phone_book[i].name, phone_book[i].phone_number);
            return;
        }
    }
    printf("Entry not found.\n");
}

// Function to print all entries in the phone book
void print_all_entries(struct phone_book *phone_book, int index) {
    for (int i = 0; i < index; i++) {
        printf("Name: %s\nPhone Number: %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

// Main function
int main() {
    // Create an array of 100 phone book entries
    struct phone_book phone_book[100];
    int index = 0;

    // Loop until the user chooses to exit
    while (1) {
        printf("\n1. Add new entry\n2. Delete entry\n3. Search entry\n4. Print all entries\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(phone_book, index);
                index++;
                break;
            case 2:
                delete_entry(phone_book, index);
                index--;
                break;
            case 3:
                search_entry(phone_book, index);
                break;
            case 4:
                print_all_entries(phone_book, index);
                break;
            case 5:
                return 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}