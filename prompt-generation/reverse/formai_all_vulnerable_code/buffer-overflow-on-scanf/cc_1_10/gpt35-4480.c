//FormAI DATASET v1.0 Category: Database simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000 // Maximum number of records in the database
#define MAX_NAME_LENGTH 50 // Maximum length of a name
#define MAX_ADDRESS_LENGTH 100 // Maximum length of an address
#define MAX_PHONE_LENGTH 12 // Maximum length of a phone number


// Structure defining a record in the database
typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

// Array to store the records
Record records[MAX_RECORDS];

// Number of records in the database
int num_records = 0;


// Function to print the menu and get the user's choice
int get_menu_choice() {
    int choice;
    
    printf("\n----------------------------\n");
    printf("CYBER DATABASE SIMULATION\n");
    printf("----------------------------\n");
    printf("1. Add a record\n");
    printf("2. Remove a record\n");
    printf("3. Search for a record\n");
    printf("4. View all records\n");
    printf("5. Exit\n");
    
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    return choice;
}

// Function to add a record to the database
void add_record() {
    Record new_record;
    
    printf("\nEnter the following information for the new record:\n");
    
    printf("\nName: ");
    scanf("%s", new_record.name);
    
    printf("\nAddress: ");
    scanf("%s", new_record.address);
    
    printf("\nPhone Number: ");
    scanf("%s", new_record.phone);
    
    if (num_records >= MAX_RECORDS) {
        printf("\nError: Database full, cannot add record.\n");
    } else {
        records[num_records] = new_record;
        num_records++;
        printf("\nRecord added successfully.\n");
    }
}

// Function to remove a record from the database
void remove_record() {
    char name[MAX_NAME_LENGTH];
    int i, found = 0;
    
    printf("\nEnter the name of the record to be removed: ");
    scanf("%s", name);
    
    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, name) == 0) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        for (; i < num_records - 1; i++) {
            records[i] = records[i+1];
        }
        num_records--;
        printf("\nRecord removed successfully.\n");
    } else {
        printf("\nError: Record not found.\n");
    }
}

// Function to search for a record in the database
void search_record() {
    char name[MAX_NAME_LENGTH];
    int i, found = 0;
    
    printf("\nEnter the name of the record to search for: ");
    scanf("%s", name);
    
    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, name) == 0) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("\nRecord found:\n");
        printf("Name: %s\n", records[i].name);
        printf("Address: %s\n", records[i].address);
        printf("Phone Number: %s\n", records[i].phone);
    } else {
        printf("\nError: Record not found.\n");
    }
}

// Function to view all records in the database
void view_records() {
    int i;
    
    printf("\nCurrent records in the database:\n");
    
    for (i = 0; i < num_records; i++) {
        printf("\n%d)\n", i+1);
        printf("Name: %s\n", records[i].name);
        printf("Address: %s\n", records[i].address);
        printf("Phone Number: %s\n", records[i].phone);
    }
}

int main() {
    int choice, i;
    
    while (1) {
        choice = get_menu_choice();
        
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                remove_record();
                break;
            case 3:
                search_record();
                break;
            case 4:
                view_records();
                break;
            case 5:
                printf("\nExiting database.\n");
                exit(0);
            default:
                printf("\nError: Invalid choice.\n");
        }
    }
    
    return 0;
}