//FormAI DATASET v1.0 Category: Phone Book ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Phone Book Entry
struct phone_book_entry {
    char name[50];
    char phone_number[15];
};

// Function to add a new entry to the Phone Book
void add_new_entry(struct phone_book_entry* phone_book, int* number_of_entries) {
    int i;
    printf("\nEnter the Name: ");
    scanf("%s", phone_book[*number_of_entries].name);
    printf("Enter the Phone Number: ");
    scanf("%s", phone_book[*number_of_entries].phone_number);
    (*number_of_entries)++;
    printf("\nEntry Added to Phone Book Successfully!\n");
}

// Function to modify an existing Phone Book Entry
void modify_entry(struct phone_book_entry* phone_book, int number_of_entries) {
    char name[50], phone_number[15];
    int i, found = 0;
    printf("\nEnter the Name of Entry to Modify: ");
    scanf("%s", name);
    for (i = 0; i < number_of_entries; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Enter the New Phone Number: ");
            scanf("%s", phone_number);
            strcpy(phone_book[i].phone_number, phone_number);
            found = 1;
            break;
        }
    }
    if (found == 1) {
        printf("\nEntry Modified Successfully!\n");
    } else {
        printf("\nNo Entry Found with Given Name!\n");
    }
}

// Function to display all the Phone Book Entries
void display_all_entries(struct phone_book_entry* phone_book, int number_of_entries) {
    int i;
    printf("\nPhone Book Entries:\n");
    for (i = 0; i < number_of_entries; i++) {
        printf("Name: %s | Phone Number: %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

int main() {
    struct phone_book_entry phone_book[100];
    int number_of_entries = 0, choice, i;
    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add New Entry\n2. Modify Existing Entry\n3. Display All Entries\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_new_entry(phone_book, &number_of_entries);
                break;
            case 2:
                modify_entry(phone_book, number_of_entries);
                break;
            case 3:
                display_all_entries(phone_book, number_of_entries);
                break;
            case 4:
                printf("\nThank You for using Phone Book. Exiting...\n");
                exit(0);
            default:
                printf("\nInvalid Choice. Please try again!\n");
                break;
        }
    }
    return 0;
}