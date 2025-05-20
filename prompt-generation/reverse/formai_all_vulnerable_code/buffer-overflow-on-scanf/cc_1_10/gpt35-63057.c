//FormAI DATASET v1.0 Category: Phone Book ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct PhoneBook {
    char name[50];
    char phone_number[20];
};

int phonebook_size = 10;
struct PhoneBook phonebook[10];

// Utility function to clear the console
void clear() {
    system("clear || cls");
}

// Utility function to print the header of the program
void print_header() {
    clear();
    printf("===============================================\n");
    printf("|                  PHONEBOOK                   |\n");
    printf("===============================================\n\n");
}

// Utility function to display the menu
void display_menu() {
    printf("1. Add a contact\n");
    printf("2. Display all contacts\n");
    printf("3. Search a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Exit\n\n");
    printf("Enter your choice: ");
}

// Utility function to add a contact to the phonebook
void add_contact() {
    clear();
    printf("Enter the name: ");
    scanf(" %[^\n]s", phonebook[phonebook_size].name);
    printf("Enter the phone number: ");
    scanf(" %[^\n]s", phonebook[phonebook_size].phone_number);
    phonebook_size++;
    printf("\nContact added successfully!\n");
    printf("Press ENTER to return to the main menu...");
    while(getchar() != '\n');
    getchar();
}

// Utility function to display all the contacts in the phonebook
void display_contacts() {
    clear();
    printf("===============================================\n");
    printf("|                  CONTACTS                    |\n");
    printf("===============================================\n\n");

    if(phonebook_size == 0) {
        printf("No contacts found!\n");
    }
    else {
        for(int i=0; i<phonebook_size; i++) {
            printf("%d. Name: %s\n   Phone Number: %s\n", i+1, phonebook[i].name, phonebook[i].phone_number);
        }
    }

    printf("\nPress ENTER to return to the main menu...");
    while(getchar() != '\n');
    getchar();
}

// Utility function to search for a contact
void search_contact() {
    clear();
    printf("Enter the name: ");
    char search_name[50];
    scanf(" %[^\n]s", search_name);

    bool found = false;
    for(int i=0; i<phonebook_size; i++) {
        if(strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", phonebook[i].name, phonebook[i].phone_number);
            found = true;
            break;
        }
    }

    if(!found) {
        printf("No match found for %s\n", search_name);
    }

    printf("\nPress ENTER to return to the main menu...");
    while(getchar() != '\n');
    getchar();
}

// Utility function to delete a contact from the phonebook
void delete_contact() {
    clear();
    printf("Enter the name: ");
    char search_name[50];
    scanf(" %[^\n]s", search_name);

    bool found = false;
    for(int i=0; i<phonebook_size; i++) {
        if(strcmp(phonebook[i].name, search_name) == 0) {
            for(int j=i; j<phonebook_size-1; j++) {
                strcpy(phonebook[j].name, phonebook[j+1].name);
                strcpy(phonebook[j].phone_number, phonebook[j+1].phone_number);
            }
            phonebook_size--;
            found = true;
            break;
        }
    }

    if(found) {
        printf("Contact deleted successfully!\n");
    }
    else {
        printf("No match found for %s\n", search_name);
    }

    printf("Press ENTER to return to the main menu...");
    while(getchar() != '\n');
    getchar();
}

int main() {
    while(true) {
        print_header();
        display_menu();

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact();
                break;

            case 2:
                display_contacts();
                break;

            case 3:
                search_contact();
                break;

            case 4:
                delete_contact();
                break;

            case 5:
                clear();
                printf("Thank you for using the phonebook!\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
                printf("\nPress ENTER to return to the main menu...");
                while(getchar() != '\n');
                getchar();
        }
    }
    return 0;
}