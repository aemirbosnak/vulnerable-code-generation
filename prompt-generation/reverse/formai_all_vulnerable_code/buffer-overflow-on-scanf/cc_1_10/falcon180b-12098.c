//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000 //Maximum number of entries in the phone book

typedef struct {
    char name[50]; //Name of the contact
    char phone_number[20]; //Phone number of the contact
} contact; //Structure for each contact in the phone book

contact phone_book[MAX_ENTRIES]; //Array of contacts in the phone book
int num_entries = 0; //Number of entries in the phone book

void add_contact() {
    printf("Enter name: ");
    scanf("%s", phone_book[num_entries].name); //Get name from user
    printf("Enter phone number: ");
    scanf("%s", phone_book[num_entries].phone_number); //Get phone number from user
    num_entries++; //Increase number of entries in the phone book
}

void search_contact() {
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name); //Get name to search from user
    int i;
    for(i=0; i<num_entries; i++) {
        if(strcmp(search_name, phone_book[i].name) == 0) { //If name matches, print contact details
            printf("Name: %s\nPhone number: %s\n", phone_book[i].name, phone_book[i].phone_number);
        }
    }
    if(i==num_entries) {
        printf("Contact not found.\n"); //If contact not found, print message
    }
}

void delete_contact() {
    char name_to_delete[50];
    printf("Enter name to delete: ");
    scanf("%s", name_to_delete); //Get name to delete from user
    int i;
    for(i=0; i<num_entries; i++) {
        if(strcmp(name_to_delete, phone_book[i].name) == 0) { //If name matches, delete contact
            memset(&phone_book[i], 0, sizeof(contact)); //Set contact to null
            num_entries--; //Decrease number of entries in the phone book
        }
    }
    if(i==num_entries) {
        printf("Contact not found.\n"); //If contact not found, print message
    }
}

void print_phone_book() {
    int i;
    for(i=0; i<num_entries; i++) {
        printf("Name: %s\nPhone number: %s\n\n", phone_book[i].name, phone_book[i].phone_number); //Print each contact in the phone book
    }
}

int main() {
    int choice;
    do {
        printf("\nPhone Book\n");
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Print phone book\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice); //Get choice from user
        switch(choice) {
            case 1:
                add_contact(); //Add contact
                break;
            case 2:
                search_contact(); //Search contact
                break;
            case 3:
                delete_contact(); //Delete contact
                break;
            case 4:
                print_phone_book(); //Print phone book
                break;
            case 5:
                printf("Exiting...\n"); //Exit program
                break;
            default:
                printf("Invalid choice.\n"); //If choice is invalid, print message
        }
    } while(choice!=5); //Loop until user chooses to exit
    return 0;
}